/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] 
and the difference between i and j is at most k.
*/

//这道题就是在一个数组中找到两个相同的值，是否两个的下标《=k，如果存在就返回TRUE；否则就FALSE

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
       for(int i = 0; i < nums.size();i++)
       {
           if(m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)   //重复数字有可能不止两个（用到了map)
           {
           
                return true;
            
           }
         else
            {
                m[nums[i]] = i;
            }
       }
       return false;
        
    }
};