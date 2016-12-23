/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
Input:
1->2->3

Output:
1->2->4
 
/*链表的情况
这道题给了我们一个链表，用来模拟一个三位数，
表头是高位，现在让我们进行加1运算，
这道题的难点在于链表无法通过坐标来访问元素，只能通过遍历的方式进行，
而这题刚好让我们从链尾开始操作，从后往前，
遇到进位也要正确的处理，最后还有可能要在开头补上一位。
那么我们反过来想，如果链尾是高位，那么进行加1运算就方便多了，
直接就可以边遍历边进行运算处理，那么我们可以做的就是先把链表翻转一下，
然后现在就是链尾是高位了，我们进行加1处理运算结束后，再把链表翻转回来即可
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {      							/*不是链表的情况(而且每一个元素只能是个位数)*/
        
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
/*链表的情况而且每一个数不一定是个位数*/
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

