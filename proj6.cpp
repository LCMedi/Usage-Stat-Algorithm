#include <string>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Custom aliases
typedef pair<int, int> TokenInfo;
typedef pair<string, TokenInfo> TokenEntry;

void insertToken(unordered_map<string, TokenInfo>& table, const string& token, int& token_pos) {
    if (table.find(token) != table.end())
        table[token].first++;
    else
        table[token] = {1, token_pos++};
}

/* Functor for use with max heap to sort based on frequency, and break ties based 
   on where first appeared in input */
// Functor used to compare words and numbers
class MoreUsed {
    public:
    bool operator() (const TokenEntry& a, const TokenEntry& b) const {
        if (a.second.first == b.second.first) { // same frequency
            return a.second.second > b.second.second;   // compare where was first seen in input
        }
        return a.second.first < b.second.first; // higher frequency goes first
    }
};

// Custom functor used to compare characters only
class MoreUsedChar {
    public:
    bool operator() (const pair<char, int>& a, const pair<char, int>& b) const {
        if (a.second == b.second) { // same frequency
            return a.first > b.first;   // smaller ASCII value goes first
        }
        return a.second < b.second; // higher frequency goes first
    }
};

// Sorting Algorithm for Top Ten elements in table
// Heapifies hash table, and pops and prints top 10 elements of heap
void sortTopTen(const unordered_map<string, TokenInfo>& table) {
    // Heapify hash table
    priority_queue<TokenEntry, vector<TokenEntry>, MoreUsed> max_heap(table.begin(), table.end());

    int word_count = 0;

    // Save current flags
    auto old_flags = cout.flags();

    // Access top 10 elements and print them
    while (!max_heap.empty() && word_count < 10) {
        auto current = max_heap.top();
        max_heap.pop();
        cout << "No. " << word_count++ << ": " << setw(10) << left << current.first << "\t" << current.second.first << endl;
    }

    // Restore flags
    cout.flags(old_flags);
}

// Overload for character hash table
void sortTopTen(const unordered_map<char, int>& table) {
    // Heapify hash table
    priority_queue<pair<char, int>, vector<pair<char, int>>, MoreUsedChar> max_heap(table.begin(), table.end());

    int word_count = 0;

    // Save current flags
    auto old_flags = cout.flags();

    // Access top 10 elements and print them
    while (!max_heap.empty() && word_count < 10) {
        auto current = max_heap.top();
        max_heap.pop();
        
        if (current.first == '\n') 
            cout << "No. " << word_count++ << ": " << setw(10) << left << "\\n" << "\t" << current.second << endl;
        else if (current.first == '\t') 
            cout << "No. " << word_count++ << ": " << setw(10) << left << "\\t" << "\t" << current.second << endl;
        else 
            cout << "No. " << word_count++ << ": " << setw(10) << left << current.first << "\t" << current.second << endl;
    }

    // Restore flags
    cout.flags(old_flags);
}

int main() {
    unordered_map<char, int> char_table;
    /* For each entry's value in the hash table, first = frequency
       second = position where token first appeared in input */
    unordered_map<string, TokenInfo> word_table;
    unordered_map<string, TokenInfo> num_table;

    string line;
    int token_pos = 0;

    // Main Loop to Read Input and Store in containers
    while (getline(cin, line)) {
        string word = "", num = "";

        for (char c : line) {
            // Insert character
            char_table[c]++;

            if (isalpha(c)) {
                if (!num.empty()) { // handle numbers
                    insertToken(num_table, num, token_pos);
                    num.clear();
                }
                word+=tolower(c);
            } else if (isdigit(c)) {
                if (!word.empty()) {    // handle words
                    insertToken(word_table, word, token_pos);
                    word.clear();
                }
                num+= c;
            } else {    // handle spaces between numbers and/or words
                if (!num.empty()) {
                    insertToken(num_table, num, token_pos);
                    num.clear();
                }
                if (!word.empty()) {
                    insertToken(word_table, word, token_pos);
                    word.clear();
                }
            }
        }
        // If reached newline
        char_table['\n']++;

        if (!word.empty()) {
            insertToken(word_table, word, token_pos);
        }
        if (!num.empty()) {
            insertToken(num_table, num, token_pos);
        }

    }

    int top_nums = min(10, static_cast<int>(char_table.size()));

    cout << "Total " << char_table.size() << " different characters, "<< top_nums << " most used characters:\n";
    sortTopTen(char_table);
    cout << endl;    

    top_nums = min(10, static_cast<int>(word_table.size()));

    cout << "Total " << word_table.size() << " different words, " << top_nums << " most used words:\n";
    sortTopTen(word_table);
    cout << endl;

    top_nums = min(10, static_cast<int>(num_table.size()));

    cout << "Total " << num_table.size() << " different numbers, " << top_nums << " most used numbers:\n";
    sortTopTen(num_table);

    return 0;
}