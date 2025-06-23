#include <stdio.h>

int puzzle[9][9] = {
    {3, 0, 0, 0, 2, 0, 0, 7, 0},
    {9, 0, 0, 5, 0, 0, 0, 1, 4},
    {0, 1, 6, 3, 7, 0, 0, 0, 8},
    {2, 0, 0, 8, 0, 0, 0, 0, 1},
    {5, 0, 0, 0, 4, 1, 8, 0, 0},
    {0, 8, 9, 0, 0, 0, 0, 5, 0},
    {0, 0, 5, 0, 1, 0, 2, 8, 0},
    {0, 4, 0, 0, 0, 6, 0, 9, 3},
    {7, 3, 1, 0, 8, 2, 0, 0, 0},
};

void print_puzzle(void);
int valid_puzzle(int puzzle[9][9], int row, int col, int val);
int solve_puzzle(int puzzle[9][9], int row, int col);

int main()
{
    printf("\n Welcome to sudoku solver");
    printf("\n Original sudoku");
    print_puzzle();
    if (solve_puzzle(puzzle, 0, 0))
    {
        printf("\n The puzzle is solved");
        print_puzzle();
    }
    else
    {
        printf("\n This puzzle is unsolvable");
    }
    return 0;
}

int solve_puzzle(int puzzle[9][9], int row, int col)
{
    if (col == 9)
    {
        col = 0;
        row++;
        if (row == 9)
            return 1;
    }
    if (puzzle[row][col] > 0)
    {
        return solve_puzzle(puzzle, row, col + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (valid_puzzle(puzzle, row, col, i))
        {
            puzzle[row][col] = i;
            if (solve_puzzle(puzzle, row, col + 1))
            {
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

void print_puzzle(void)
{
    printf("\n\n +-------+-------+-------+ \n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                printf(" |");
            }
            if (puzzle[i][j] == 0)
            {
                printf("  ");
            }
            else
            {
                printf(" %d", puzzle[i][j]);
            }
        }
        printf(" |\n");
        if (i == 2 || i == 5)
        {
            printf(" |-------+-------+-------|\n");
        }
    }
    printf(" +-------+-------+-------+\n");
}

int valid_puzzle(int puzzle[9][9], int row, int col, int val)
{
    // valid row
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[row][i] == val)
        {
            return 0;
        }
    }

    // valid col
    for (int j = 0; j < 9; j++)
    {
        if (puzzle[j][col] == val)
        {
            return 0;
        }
    }

    // valid square
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (puzzle[r + i][c + j] == val)
            {
                return 0;
            }
        }
    }
    return 1;
}