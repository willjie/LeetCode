/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
Input:
1->2->3

Output:
1->2->4
 
/*��������
������������һ����������ģ��һ����λ����
��ͷ�Ǹ�λ�����������ǽ��м�1���㣬
�������ѵ����������޷�ͨ������������Ԫ�أ�ֻ��ͨ�������ķ�ʽ���У�
������պ������Ǵ���β��ʼ�������Ӻ���ǰ��
������λҲҪ��ȷ�Ĵ�������п���Ҫ�ڿ�ͷ����һλ��
��ô���Ƿ������룬�����β�Ǹ�λ����ô���м�1����ͷ�����ˣ�
ֱ�ӾͿ��Ա߱����߽������㴦����ô���ǿ������ľ����Ȱ�����תһ�£�
Ȼ�����ھ�����β�Ǹ�λ�ˣ����ǽ��м�1��������������ٰ�����ת��������
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {      							/*������������(����ÿһ��Ԫ��ֻ���Ǹ�λ��)*/
        
       int count = 0;
       for(int i = digits.size() - 1; i >= 0; i--)
       {
           digits[i] += 1;
           if(i==0 && digits[0] > 9 && count == digits.size() - 1)
           {
               digits[0] = 0;
               for(int j =  0;j < digits.size()-1;j++)
               {
                   digits[j + 1] = digits[j];
               }
               digits[0] = 1;
               digits.push_back(0);
           }
           else if(digits[i] > 9)
           {
               digits[i] = 0;
               count++;
           }
           else
           {
               break;
           }
       }
       return digits;
        
       
    }
};
/*������������ÿһ������һ���Ǹ�λ��*/
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        ListNode *rev_head = reverse(head), *cur = rev_head, *pre = cur;
        int carry = 1;
        while (cur) {
            pre = cur;
            int t = cur->val + carry;
            cur->val = t % 10;
            carry = t / 10;
            if (carry == 0) break;
            cur = cur->next;
        }
        if (carry) pre->next = new ListNode(1);
        return reverse(rev_head);
    }
    ListNode* reverse(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        while (cur->next) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;
    }
};

