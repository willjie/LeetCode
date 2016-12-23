/*
Given a singly linked list, determine if it is a palindrome.
*/
这道题就是检验链表是不是回文链表
//重点是找中点（链表的中点，用快慢指针）
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        
        //这道题首先找到链表的中点
        //找中点可以用快慢指针来实现
        ListNode *slow,*fast;
        slow = fast = head;
        
        while(fast->next != NULL && fast->next->next !=NULL)   //快指针走两步，慢指针走一步，当快指针走完时，慢指针就在中点处
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //因为要求空间复杂度为（1），所以不能用栈来存储元素，所以将后面的半部分进行翻转，然后进行对比
        ListNode *t = slow->next;
        while(t->next != NULL)   //翻转链表
        {
            ListNode *tmp = t->next;
            t->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        
        while(slow->next != NULL)
        {
            if(head->val != slow->next->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
        
    }
};