# PR1
# Search Algorithms Performance Measurement

## Project Description

This project implements and compares four search algorithms on ordered integer arrays:

- Iterative Sequential Search
- Recursive Sequential Search  
- Iterative Binary Search
- Recursive Binary Search

## How to Compile and Run

### Using Dev-C++
1. Open `PR1code.c` in Dev-C++
2. Press F11 to compile and run

### Using GCC
```bash
gcc PR1code.c -o search
./search

Test Cases
The program tests the following input sizes:

N = 100, 500, 1000, 2000, 4000, 6000, 8000, 10000

Results
	N	SeqIter	SeqRecur	BinIter	BinRecur
	100	0.002938	0.011733	0.000237	0.000374
	500	0.002591	0.010648	0.000459	0.000687
	1000	0.002928	0.012646	0.000534	0.000805
	2000	0.002891	0.012443	0.000585	0.000927
	4000	0.003012	0.01307	0.00067	0.00097
	6000	0.002915	0.013017	0.000738	0.001057
	8000	0.002938	0.011593	0.000662	0.000998
	10000	0.002958	0.011784	0.000783	0.001099


Complexity Analysis
Algorithm	Time Complexity	Space Complexity
Iterative Sequential Search	O(N)	O(1)
Recursive Sequential Search	O(N)	O(N)
Iterative Binary Search	O(log N)	O(1)
Recursive Binary Search	O(log N)	O(log N)

Author
杨忆南
