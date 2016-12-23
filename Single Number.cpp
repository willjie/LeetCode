/*Given an array of integers, every element appears twice except for one. Find that single one.
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*这道题传统方法很简单（但是时间复杂度太高）*/
/*本题要求时间复杂度为O（n)*/
/*所以考虑用异或的方式来做(绝对经典）*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {     
    
       /*由于数字在计算机是以二进制存储的，每位上都是0或1，如果我们把两个相同的数字异或，0与0异或是0,1与1异或也是0，那么我们会得到0。根据这个特点，我们把数组中所有的数字都异或起来，
       则每对相同的数字都会得0，然后最后剩下来的数字就是那个只有1次的数字。这个方法确实很赞，但是感觉一般人不会忘异或上想
       */
       /*异或满足交换律*/
       int res = nums[0];
       
       for(int i = 1; i< nums.size();i++)
       {
           res ^= nums[i];   /*0和1异或是1(0和任何数异或就是任何数）*/
       }
       
       return res;
    }
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		/*常规算法，时间复杂度为O(n^2),不满足题目要求，体面要求时间复杂度必须为O（n）*/
		int i = 0;
		int pos = -1;
		vector<bool> visit(nums.size(), false);
		if (nums.empty())
		{
			return 0;
		}
		for (i = 0; i < nums.size(); i++)
		{
			bool flag = false;
			if (visit[i] == true)
			{
				continue;
			}
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == nums[j])
				{
					visit[j] = true;
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				break;
			}
		}
		return nums[i];
	}
};

