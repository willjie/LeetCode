/*
1. Two Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 298962
Total Submissions: 1124161
Difficulty: Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v1;
         
        for(int i = 0;i< nums.size();i++)     /*不能用迭代器，类似于iter1 = iter+1这种表达*/   
        { 
            
           for(int j = i+1;j<nums.size();j++)
           {
               if ((nums[i]+nums[j]) == target)
               {
                   v1.push_back(i);
                   v1.push_back(j);
                   return v1;
               }
           }
        }
    
         return v1;
    }
};
