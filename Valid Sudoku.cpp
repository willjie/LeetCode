
/*Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
�������������֤һ�������Ƿ�Ϊ���������жϱ�׼�ǿ����и����Ƿ����ظ����֣�
�Լ�ÿ��С��3x3��С���������Ƿ����ظ����֣���������ظ�����ǰ��������������
������������������н⣬ֻ�ǵ������жϵ�ǰδ����ľ����Ƿ�������������ô������������Ķ��壬
�����ڱ���ÿ�����ֵ�ʱ�򣬾Ϳ���������ǰλ�õ��к����Լ�3x3С�������Ƿ��Ѿ����ָ����֣�
��ô������Ҫ������־���󣬷ֱ��¼���У����У���С�����Ƿ����ĳ�����֣�
�����к��б�־�±�ܺö�Ӧ������С������±���Ҫ����ת��һ��
*/

/*���������������ж��Ƿ���������*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> RowFlag(m,vector<bool>(n,false));    /*�����﷽ʽ��һ�μ�����ʾ����m��vector<bool>������ÿ���������n��false������ʽ����һ����ά����*/
        vector<vector<bool>> ColFlag(m,vector<bool>(n,false));
        vector<vector<bool>> CellFlag(m,vector<bool>(n,false));
        
        for(int i = 0; i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(board[i][j] >= '1' && board[i][j] <= '9' )
                {
                    int c = board[i][j] -'1';
                    if(RowFlag[i][c] || ColFlag[c][j] || CellFlag[3 * (i/3) + j/3][c])  /*��һ���Ź��������������һ����ά�����һ����*/
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
                    if(RowFlag[i][c] || ColFlag[c][j] || CellFlag[3 * (i/3) + j/3][c])  /*��һ���Ź��������������һ����ά�����һ����*/
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