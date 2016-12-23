/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.
*/
/*����������ַ�����һ�������������������飨����������һ��������Ķ����ԣ����������*/

/*��һ�ַ�����ʱ�临�Ӷ�O��n) �������������飨����*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
       /*ʱ�临�Ӷ�ΪO��n��*/
       int i = 0;
       if(nums.size() == 1) return 1;
       if(nums.size() == 0) return 0;            /*���п��ܴ�СΪ0��ʱ��*/
       for(int j = 1; j < nums.size(); j++)
       {
           if (nums[i] != nums[j])              /*����㷨Ҳ������*//*��Ϊ�������*/
           {
               i++;
               nums[i] = nums[j];
           }
       }
       return (i+1);
    }
};
/*�ڶ��ַ����������������飨������ʱ�临�Ӷ�O��n^2)*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int length = nums.size();

		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (nums[i] == nums[j])
				{
					int k = j;
					if (j == nums.size() - 1)
					{
						nums.erase(nums.end());
						break;
					}
					while (k < length - 1)
					{
						nums[k] = nums[k + 1];
						k++;
					}
					
					length--;
					j--;
				}
			}
		}
		int count = nums.size() - length;
		for (int i = 0; i < count; i++)
		{
			nums.pop_back();
		}

		return length;
	}
};