/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
/*二进制数想加，并且保存在string中，要注意的是如何将string和int之间互相转换，
并且每位相加时，会有进位的可能，会影响之后相加的结果。
而且两个输入string的长度也可能会不同。
这时我们需要新建一个string，它的长度是两条输入string中的较大的那个，
并且把较短的那个输入string通过在开头加字符‘0’来补的较大的那个长度。
这时候我们逐个从两个string的末尾开始取出字符，然后转为数字，
想加，如果大于等于2，则标记进位标志carry，并且给新string加入一个字符‘0’。
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        string c = "";
        bool flag = false;     /*进位标志*/
        
        int temp = 0;
        int length_a = a.size();
        int length_b = b.size();
        
        if (length_a > length_b)
        {
            for(int i = 0; i < length_a-length_b;i++)
            {
                b.insert(b.begin(),'0');               /*是两个加数位数对齐*/
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
            if(flag)            /*判断是否有进位*/
            {
                 temp = a[i] -'0' + (b[i] - '0') + 1;
            }
            else
            {
                 temp = a[i] -'0' + (b[i] - '0');
            }
            switch (temp)
            {
                case 0: c.insert(c.begin(),'0'); flag = false; break;        /*通过向前插入来得出结果*/
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