A simple console-based Sudoku solver written in C that uses recursive backtracking to solve a 9x9 puzzle. It visually displays the original puzzle and the solved one (if solvable) in a neat grid format.

📌 Features
Solves standard 9x9 Sudoku puzzles

Uses recursive backtracking to find solutions

Neatly formatted board display with box outlines

Clear message if the puzzle is unsolvable

🛠️ Technologies Used
Language: C

Compiler: GCC / MinGW

Libraries: stdio.h

🔍 How It Works
The puzzle is defined as a 9x9 array.

The solve_puzzle() function fills empty cells (represented as 0) by checking:

If the number is valid in the current row

If it's valid in the column

If it's valid in the 3x3 subgrid

If the board can be filled completely with valid values, the solution is printed.

Otherwise, a message is displayed saying the puzzle is unsolvable.

🧪 Sample Output
lua
Copy code
Welcome to sudoku solver
Original sudoku

 +-------+-------+-------+
 | 3     |   2   |   7
 | 9     | 5     |   1 4
 |   1 6 | 3 7   |     8
 | 2     | 8     |     1
 | 5     |   4 1 | 8
 |   8 9 |       |   5
 |     5 |   1   | 2 8
 |   4   |   6   | 9 3
 | 7 3 1 |   8 2 |
 +-------+-------+-------+

The puzzle is solved

 +-------+-------+-------+
 | 3 5 8 | 1 2 4 | 6 7 9
 | 9 7 2 | 5 6 8 | 3 1 4
 | 4 1 6 | 3 7 9 | 5 2 8
 | 2 6 4 | 8 5 3 | 9 0 1
 ...
📄 File Structure
puzzle[9][9]: 2D array storing Sudoku grid

print_puzzle(): Nicely prints the current puzzle

solve_puzzle(): Main solver using recursion & backtracking

valid_puzzle(): Checks if a value is valid at a given position

✅ How to Run
On Windows / Linux (GCC):
bash
Copy code
gcc sudoku_solver.c -o sudoku_solver
./sudoku_solver
⚠️ Limitations
Only works for 9x9 standard puzzles

Input puzzle is hardcoded in the code

No user input support or puzzle generation

🚀 Possible Improvements
Allow user input for puzzle

Add GUI using ncurses or a graphics library

Solve multiple puzzles from file input

🙌 Author
Made by Utkrisht Thakur as a learning project for recursion and logical problem solving in C.
