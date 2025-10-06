# Usage-Stat-Algorithm

Final project for COP 4530 - Data Structures II course.  
Summer 2025

Algorithm design to collect the statistics of word, number, and character usage in a file (redirected as the standard input). This program aims to practice selecting and making use of appropriate STL containers and algorithms to perform such tasks.  

The program reads input (from standard input) until the end of input is reached ("end of file") and counts the number of times each word, number, and character appears in the input.  

## Program Specifications:  
- A word is defined as a consecutive sequence of letters (case insensitive)
- Words are separated by any non-letter characters
- A number is defined as any consecutive sequence of digits
- Numbers are separated by any non-digit characters
- Both numbers and words can be of length 1

## Program Tasks:
- The program tracks the number of times each word, number, and character appears
- The program outputs the 10 most used characters, numbers, and words, along with the number of times each of these characters/numbers/words are used
- Words are displayed in lower case, since they are case-insensitive
- Characters, numbers, and words are displayed in descending order based on the number of times they are used
- Breaking Ties for Top 10s
  - When two characters occur the same number of times, the character with the smaller ASCII value should be considered as being used more frequently
  - When two words (or numbers) occur the same number of times, the word (or number) that occurs earlier in the input should be considered as being used more frequently

## Time-Complexity Analysis  
"Analysis.txt" explores and discusses the time-complexity analyses of the important algorithms and procedures of the program, as well as where these are performed/completed.
