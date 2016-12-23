/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases
*/
就是求小于一个非负数的质数个数

要求时间复杂度小于O(n^2)

class Solution {
public:
    int countPrimes(int n) {
      /*  if(n <= 2)                                 //此方法不行，显示超时，时间复杂度(O(N^2))
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
    
    
      /*现在用（埃拉托斯特尼筛法)来遍历 这个算法的过程如下图所示，我们从2开始遍历到根号n，先找到第一个质数2，然后将其所有的倍数全部标记出来，然后到下一个质数3，标记其所有倍数，一次类推，直到根号n，此时数组中未被标记的数字就是质数。我们需要一个n-1长度的bool型数组来记录每个数字是否被标记，长度为n-1的原因是题目说是小于n的质数个数，并不包括n。 
      然后我们用两个for循环来实现埃拉托斯特尼筛法，难度并不是很大，（记住这个算法，很重要）*/
        int res = 0;
        vector<bool> visit(n,true);  /*从1开始*/
        visit[1] = false;     				//1不是素数，也不是合数
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