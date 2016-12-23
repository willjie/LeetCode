/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
*/

这道题就是一个动态规划
class Solution {
public:
    int rob(vector<int>& nums) {
        /*这道题想到了动态规划，但是没有把递推公式推出来*/
        if(nums.size() < 2) 
        {
            return nums.empty() ? 0:nums[0];
        }
        vector<int> dp = {nums[0],max(nums[0],nums[1])};
        for(int i = 2;i < nums.size(); i++)
        {
           dp.push_back(max(dp[i-1],dp[i-2] + nums[i]));       /*递推公式,因为不能取相邻的，就只有取前一个的*/
        }
        return dp.back();                                   
        
    }
};