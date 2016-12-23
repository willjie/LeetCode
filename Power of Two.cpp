/*
Given an integer, write a function to determine if it is a power of two.
*/

//判断一个数是否是2的幂

class Solution {
public:            //就是反复的除以2
    bool isPowerOfTwo(int n) {
    
      if(n <= 0)
      {
          return false;
      }
        while(n > 1)
        {
            if(n % 2 != 0)
            {
                return false;
            }
            else
            {
                n /= 2;
            }
        }
        
        return true;
    }
};