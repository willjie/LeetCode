/*Given an array of integers, every element appears twice except for one. Find that single one.
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*����⴫ͳ�����ܼ򵥣�����ʱ�临�Ӷ�̫�ߣ�*/
/*����Ҫ��ʱ�临�Ӷ�ΪO��n)*/
/*���Կ��������ķ�ʽ����(���Ծ��䣩*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {     
    
       /*���������ڼ�������Զ����ƴ洢�ģ�ÿλ�϶���0��1��������ǰ�������ͬ���������0��0�����0,1��1���Ҳ��0����ô���ǻ�õ�0����������ص㣬���ǰ����������е����ֶ����������
       ��ÿ����ͬ�����ֶ����0��Ȼ�����ʣ���������־����Ǹ�ֻ��1�ε����֡��������ȷʵ���ޣ����Ǹо�һ���˲������������
       */
       /*������㽻����*/
       int res = nums[0];
       
       for(int i = 1; i< nums.size();i++)
       {
           res ^= nums[i];   /*0��1�����1(0���κ����������κ�����*/
       }
       
       return res;
    }
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		/*�����㷨��ʱ�临�Ӷ�ΪO(n^2),��������ĿҪ������Ҫ��ʱ�临�Ӷȱ���ΪO��n��*/
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

