/*
Reverse a singly linked list
*/

这道题就是链表反置

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        while(cur != NULL && cur->next != NULL)
        {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = dummy->next;
            dummy->next = t;
           
        }
        
        return dummy->next;
    }
};