/*
Given an integer, write a function to determine if it is a power of two.
*/

//�ж�һ�����Ƿ���2����

class Solution {
public:            //���Ƿ����ĳ���2
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