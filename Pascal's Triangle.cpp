/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/*这道题就是找规律：1 第一个元素和最后一个元素一定是1;2 每一行的元素个数等于行数（但是vector是从0开始的，这点要注意）
3 每一行中间的元素，等于上一行对应的前两个元素相加*/


	class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> num;
        vector<int> level;
        if(numRows == 0)
        {
            return num;
        }
        if(numRows == 1)
        {
            level.push_back(1);
            num.push_back(level);
            return num;
        }
        else
        {
            level.push_back(1);
            num.push_back(level);
            level.clear();
            for(int i = 2;i <= numRows;i++) 				/*从第二行开始*/
            {
                level.push_back(1);
                for(int j = 0;j < num[i-2].size() - 1;j++)
                {
                    int temp = num[i-2][j] + num[i-2][j+1];
                    level.push_back(temp);
                }
                level.push_back(1);
                num.push_back(level);
                level.clear();
            }
        }
        return num;
        
        
    }
};