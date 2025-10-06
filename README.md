# Usage-Stat-Algorithm

**Final project for COP 4530 - Data Structures II course**
**Summer 2025**

---

## Overview

Algorithm designed to collect the statistics of word, number, and character usage in a file (redirected as the standard input). This program aims to practice selecting and making use of appropriate STL containers and algorithms to perform such tasks.  

The program reads input (from standard input) until the end of input is reached ("end of file") and counts the number of times each word, number, and character appears in the input.  

---

## Program Specifications:  

- A word is defined as a consecutive sequence of letters (case insensitive)
- Words are separated by any non-letter characters
- A number is defined as any consecutive sequence of digits
- Numbers are separated by any non-digit characters
- Both numbers and words can be of length 1

---

## Program Tasks:
- **Tracks** the number of times each word, number, and character appears
- **Outputs** the 10 most used characters, numbers, and words, along with the number of times each of these characters/numbers/words are used
- **Displays** words in lower case, since they are case-insensitive
- **Displays** characters, numbers, and words in descending order based on the number of times they are used

### Breaking Ties for Top 10s
- When two characters occur the same number of times, the character with the smaller ASCII value should be considered as being used more frequently
- When two words (or numbers) occur the same number of times, the word (or number) that occurs earlier in the input should be considered as being used more frequently

---

## Time-Complexity Analysis  
"Analysis.txt" explores and discusses the time-complexity analyses of the important algorithms and procedures of the program, as well as where these are performed/completed.

---

## Compilation & Execution

The **makefile** automates compilation of the project.

### Requirements
- **Compiler:** `g++` (C++ 14 or higher recommended)
- **Operating System:** Linux, macOS, or Windows (with terminal/PowerShell)

### Compilation

```bash
make
```
Generates:
- `proj5.x` - executable

### Execution
The program reads from **standard input**. Redirect an input as follows:  
```bash
./proj5.x < "input.txt"
```
Alternatively, you can type directly into the console and press **Ctrl + D** (Linux/macOS) or **Ctrl+Z + Enter** (Windows) to signal EOF.

---

## Sample Output
```
Total 96 different characters, 10 most used characters:
No. 0:  		216507
No. 1: e		134425
No. 2: t		95379
No. 3: i		91966
No. 4: n		87675
No. 5: o		85147
No. 6: a		82103
No. 7: s		70726
No. 8: r		67876
No. 9: c		50629

Total 8499 different words, 10 most used words:
No. 0: the		16726
No. 1: in		7408
No. 2: of		4820
No. 3: a		4492
No. 4: and		4215
No. 5: to		4188
No. 6: is		4188
No. 7: communication		3606
No. 8: for		2814
No. 9: that		2259

Total 931 different numbers, 10 most used numbers:
No. 0: 1		7798
No. 1: 2		5858
No. 2: 0		2713
No. 3: 3		2447
No. 4: 4		1667
No. 5: 5		1440
No. 6: 6		992
No. 7: 8		933
No. 8: 7		623
No. 9: 9		602
```

## Concepts Practiced
- STL containers: `unordered_map`, `priority_queue`, `vector`
- Custom functors and heap-based sorting
- Algorithmic complexity analysis
- Data parsing and token classification
- Case-insensitive string handling

## Author
**Luis Cesar Medina**  
**Computer Science Major | Aspiring Software Developer**  
**Email:** luis.c.medina2003@gmail.com  
**LinkedIn Profile:** [linkedin.com/luis-medina-cs/](https://linkedin.com/in/luis-medina-cs)  
**GitHub Profile:** [github.com/LCMedi/](https://github.com/LCMedi)  

## License
This project is provided for educational and portfolio purposes.  
Free to reference or adapt for non-commercial use.
