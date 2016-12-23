/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int pos = 0;
        bool flag = false;
        int n = 0;
        if(nums.size() % 2 !=0)
        {
            n = nums.size()/2 + 1;
        }
        else
        {
           n = nums.size()/2;
        }
        /*这个方法算法复杂度太高（显示Time limit）*/
      /*  for(int i = 0; i < nums.size();i++)  
        {
            count = 1;
            if(flag == true)
            {
                break;
            }
            for(int j = i + 1; j < nums.size();j++)
            {
                if(nums[i] == nums[j])
                {
                    count++;
                    if(count >= n)
                    {
                        pos = i;
                        flag = true;
                        break;
                    }
                }
            }
        }
        return nums[pos];*/
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        sort(nums.begin(),nums.end());    						/*进行排序*/
        for(int i = 0;i < nums.size();i++)
        {
            count = 1;
            if(nums[i] == nums[i+1])
            {
                count++;
                i++;
                int temp = nums[i];
                while(count < n && i < nums.size())
                {
                    if(nums[i] == temp)
                    {
                        count++;
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(count >= n && i < nums.size())
                {
                    pos = i;
                    break;
                }
            }
        }
        return nums[pos];
        
    }
};