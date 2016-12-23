/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
/*����������ӣ����ұ�����string�У�Ҫע�������ν�string��int֮�以��ת����
����ÿλ���ʱ�����н�λ�Ŀ��ܣ���Ӱ��֮����ӵĽ����
������������string�ĳ���Ҳ���ܻ᲻ͬ��
��ʱ������Ҫ�½�һ��string�����ĳ�������������string�еĽϴ���Ǹ���
���Ұѽ϶̵��Ǹ�����stringͨ���ڿ�ͷ���ַ���0�������Ľϴ���Ǹ����ȡ�
��ʱ���������������string��ĩβ��ʼȡ���ַ���Ȼ��תΪ���֣�
��ӣ�������ڵ���2�����ǽ�λ��־carry�����Ҹ���string����һ���ַ���0����
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        string c = "";
        bool flag = false;     /*��λ��־*/
        
        int temp = 0;
        int length_a = a.size();
        int length_b = b.size();
        
        if (length_a > length_b)
        {
            for(int i = 0; i < length_a-length_b;i++)
            {
                b.insert(b.begin(),'0');               /*����������λ������*/
            }
        }
        else if(length_a < length_b)
        {
            for(int i = 0; i < length_b-length_a; i++)
            {
                a.insert(a.begin(),'0');
            }
        }
        for(int i = a.size()-1; i >= 0; i--)
        {
            if(flag)            /*�ж��Ƿ��н�λ*/
            {
                 temp = a[i] -'0' + (b[i] - '0') + 1;
            }
            else
            {
                 temp = a[i] -'0' + (b[i] - '0');
            }
            switch (temp)
            {
                case 0: c.insert(c.begin(),'0'); flag = false; break;        /*ͨ����ǰ�������ó����*/
                case 1: c.insert(c.begin(),'1'); flag = false; break;
                case 2: c.insert(c.begin(),'0'); flag = true; break;
                case 3:  c.insert(c.begin(),'1'); flag = true; break;
            }
        }
        if(flag)
        {
            c.insert(c.begin(),'1');
        }
        
        return c;
    }
};