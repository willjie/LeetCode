
/*Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
这道题让我们验证一个方阵是否为数独矩阵，判断标准是看各行各列是否有重复数字，
以及每个小的3x3的小方阵里面是否有重复数字，如果都无重复，则当前矩阵是数独矩阵，
但不代表待数独矩阵有解，只是单纯的判断当前未填完的矩阵是否是数独矩阵。那么根据数独矩阵的定义，
我们在遍历每个数字的时候，就看看包含当前位置的行和列以及3x3小方阵中是否已经出现该数字，
那么我们需要三个标志矩阵，分别记录各行，各列，各小方阵是否出现某个数字，
其中行和列标志下标很好对应，就是小方阵的下标需要稍稍转换一下
*/

/*这道题就是数独，判断是否满足条件*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> RowFlag(m,vector<bool>(n,false));    /*这个表达方式第一次见，表示创建m个vector<bool>个对象，每个对象包含n的false对象，形式就像一个二维数组*/
        vector<vector<bool>> ColFlag(m,vector<bool>(n,false));
        vector<vector<bool>> CellFlag(m,vector<bool>(n,false));
        
        for(int i = 0; i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9' )
                {
                    int c = board[i][j] -'1';
                    if(RowFlag[i][c] || ColFlag[c][j] || CellFlag[3 * (i/3) + j/3][c])  /*把一个九宫格里面的数放在一个二维数组的一行里*/
                    {
                        return false;
                    }
                    else
                    {
                        RowFlag[i][c] =  true;
                        ColFlag[c][j] = true;
                        CellFlag[3 * (i/3) + j/3][c] = true;
                    }
                }
            }
        }
        return true;
        
        
        
        
    }
};
        vector<vector<bool>> ColFlag(m,vector<bool>(n,false));
        vector<vector<bool>> CellFlag(m,vector<bool>(n,false));
        
        for(int i = 0; i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9' )
                {
                    int c = board[i][j] -'1';
                    if(RowFlag[i][c] || ColFlag[c][j] || CellFlag[3 * (i/3) + j/3][c])  /*把一个九宫格里面的数放在一个二维数组的一行里*/
                    {
                        return false;
                    }
                    else
                    {
                        RowFlag[i][c] =  true;
                        ColFlag[c][j] = true;
                        CellFlag[3 * (i/3) + j/3][c] = true;
                    }
                }
            }
        }
        return true;
        
        
        
        
    }
};