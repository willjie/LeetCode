//Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        //�ж�n�Ƿ���3�Ĵη���
        
        while(n> 0 && n % 3==0)
        {
            n = n / 3;
        }
        if(n == 1)
        {
            return true;
        }
        return false;
    }
};

//����ѭ���ķ���
��Ŀ�е�Follow up�����ǲ���ѭ����
��ô��һ��Ͷ��ȡ�ɵķ���������������int��������Χ��0-231��
�ڴ˷�Χ�����������3�Ĵη���Ϊ319=1162261467����ô����ֻҪ��������ܷ�n�������ɣ��μ��������£�

 

�ⷨ����

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};