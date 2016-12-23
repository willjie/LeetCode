/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value 
appears at least twice in the array, and it should return false if every element is distinct.
*/
这道题就是寻找数组中是否包含两个相同的数
//主要是考察时间复杂度

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //利用哈希表
        map<int,int> m;
        for(int i = 0; i < nums.size();i++)
        {
            if(m.find(nums[i]) != m.end()) return true;     //找到了
            else
            ++m[nums[i]];                                  //插入哈希表（重要）
        }
        
        return false;
    
    }
};