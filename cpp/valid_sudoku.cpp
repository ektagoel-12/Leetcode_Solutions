# Approach
This solution uses three vectors, row, col, and box, to store the characters that have been seen in each row, column, and 3x3 box of the Sudoku board.
This function iterates through each cell of the puzzle and checks whether the current cell is empty. If it is, the function continues to the next iteration. If the character is not empty, the function checks whether it has already been seen in the same row, column, or 3x3 box. If it has, the function returns false to indicate that the puzzle is invalid. If the character has not been seen before in the same row, column, or 3x3 box, the function adds it to the appropriate sets and continues to the next iteration.

Finally, if the function has not returned false by the end, it returns true to indicate that the puzzle is valid.

The indices of the box vector for the cells in the first 3x3 box would be box[0], the cells in the second 3x3 box would be box[1], and so on.

The expression (i/3)*3 + (j/3) calculates the index of the 3x3 box as follows:

- i/3 calculates the index of the row within the 3x3 box. For example, the cells in the top row of the first 3x3 box have i/3 equal to 0, the cells in the middle row of the first 3x3 box have i/3 equal to 1, and so on.

- j/3 calculates the index of the column within the 3x3 box. For example, the cells in the left column of the first 3x3 box have j/3 equal to 0, the cells in the middle column of the first 3x3 box have j/3 equal to 1, and so on.

- (i/3)*3 + (j/3) combines the indices of the row and column within the 3x3 box to calculate the index of the 3x3 box itself. For example, the cells in the top-left corner of the first 3x3 box have (i/3)*3 + (j/3) equal to 0, the cells in the top-middle of the first 3x3 box have (i/3)*3 + (j/3) equal to 1, and so on.

# Complexity
- Time complexity: $$O(n^2)$$ where n is the size of the input board (i.e., the number of cells in the board). This is because the solution iterates through each cell of the board and performs a constant amount of work for each cell.

- Space complexity: $$O(n^2)$$ since the solution uses three vectors of size n^2 to store the characters that have been seen in each row, column, and 3x3 box.


# Code
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Declare vectors to store seen characters
        vector<unordered_set<char>>row(9);
        vector<unordered_set<char>>col(9);
        vector<unordered_set<char>>box(9);

         // Iterate through each cell of the board
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                char curr=board[i][j];
                // If the cell is empty, skip it
                if(board[i][j]=='.') continue;

                // Check if the current character has been seen before in the same row, column, or box
                if (row[i].count(curr) || col[j].count(curr) || box[i / 3 * 3 + j / 3].count(curr))
                {return false;}
                
                 // If the character has not been seen before, add it to the appropriate sets
                else
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[(i/3)*3+j/3].insert(board[i][j]);
                
            }
        }
        // If the function has not returned false by this point, the board is valid
        return true;
    
    }
};

```
