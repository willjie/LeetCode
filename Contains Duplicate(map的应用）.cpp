/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value 
appears at least twice in the array, and it should return false if every element is distinct.
*/
��������Ѱ���������Ƿ����������ͬ����
//��Ҫ�ǿ���ʱ�临�Ӷ�

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //���ù�ϣ��
        map<int,int> m;
        for(int i = 0; i < nums.size();i++)
        {
            if(m.find(nums[i]) != m.end()) return true;     //�ҵ���
            else
            ++m[nums[i]];                                  //�����ϣ����Ҫ��
        }
        
        return false;
    
    }
};