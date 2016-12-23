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

/*���������ҹ��ɣ�1 ��һ��Ԫ�غ����һ��Ԫ��һ����1;2 ÿһ�е�Ԫ�ظ�����������������vector�Ǵ�0��ʼ�ģ����Ҫע�⣩
3 ÿһ���м��Ԫ�أ�������һ�ж�Ӧ��ǰ����Ԫ�����*/


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
            for(int i = 2;i <= numRows;i++) 				/*�ӵڶ��п�ʼ*/
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