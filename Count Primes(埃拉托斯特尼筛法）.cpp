/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases
*/
������С��һ���Ǹ�������������

Ҫ��ʱ�临�Ӷ�С��O(n^2)

class Solution {
public:
    int countPrimes(int n) {
      /*  if(n <= 2)                                 //�˷������У���ʾ��ʱ��ʱ�临�Ӷ�(O(N^2))
      {
            return 0;
        }
        
        int count = 0; 
        for(int i = 2;i < n; i++)
        {
            if(Is_Prim(i))
            {
                count++;
            }
        }
        return count;
        
        
        
    }
    bool Is_Prim(int num)
    {
        for(int i = 2; i < num; i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        return true;
    }*/
    
    
      /*�����ã�������˹����ɸ��)������ ����㷨�Ĺ�������ͼ��ʾ�����Ǵ�2��ʼ����������n�����ҵ���һ������2��Ȼ�������еı���ȫ����ǳ�����Ȼ����һ������3����������б�����һ�����ƣ�ֱ������n����ʱ������δ����ǵ����־���������������Ҫһ��n-1���ȵ�bool����������¼ÿ�������Ƿ񱻱�ǣ�����Ϊn-1��ԭ������Ŀ˵��С��n��������������������n�� 
      Ȼ������������forѭ����ʵ�ְ�����˹����ɸ�����ѶȲ����Ǻܴ󣬣���ס����㷨������Ҫ��*/
        int res = 0;
        vector<bool> visit(n,true);  /*��1��ʼ*/
        visit[1] = false;     				//1����������Ҳ���Ǻ���
        for(int i = 2;i < sqrt(n);i++)
        {
            if(visit[i])
            {
                for(int j = i*2;j < n;j+= i)
                {
                    visit[j] = false; 
                }
            }
        }
        for(int i = 2;i < n;i++)
        {
            if(visit[i])
            {
                res++;
            }
        }
            return res;
    }
    
};