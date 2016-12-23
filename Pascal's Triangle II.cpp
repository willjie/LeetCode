/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

/*这道题就是递归调用(从上往下）*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> num;
        if(rowIndex == 0)
        {
            num.push_back(1);
            return num;
        }
        else
        {
            vector<int> temp = getRow(rowIndex - 1);
            num.push_back(1);
            for(int j = 0;j<temp.size()-1;j++)
            {
             num.push_back(temp[j] + temp[j+1]);   
            }
            num.push_back(1);
        }
        return num;
    }
};