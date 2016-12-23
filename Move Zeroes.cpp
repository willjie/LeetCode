/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int i = 0;
		int count = 0;
		for (i = 0; i< nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				count++;
				for (int j = i + 1; j < nums.size(); j++)      //整体往前移一个元素
				{
					nums[j - 1] = nums[j];
				}
				nums.erase(--nums.end());                    //删除最后一个元素
				i--;
			}
		}

		for (int i = 0; i < count; i++)
		{
			nums.push_back(0);
		}
    }
};