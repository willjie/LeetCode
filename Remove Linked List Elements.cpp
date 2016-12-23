/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

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
    ListNode* removeElements(ListNode* head, int val) {
    
        if(head == NULL)
        {
            return NULL;
        }
        if(head->val == val)
        {
           ListNode *temp = head;
           while(head != NULL && head->val == val)     /*判断是不是一直都是这个数*/
           {
               temp = temp->next;
               delete head;
               head = temp;
           }
           if(head == NULL)
           {
               return NULL;
           }
        }
        ListNode *pre,*cur;
        cur = pre = head;
        while(cur != NULL)
        {
            if(cur->val == val && pre != cur)
            {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
                if(pre == cur)
                {
                    cur = cur->next;
                    delete pre;
                    pre = cur;
                }
                
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        
        return head;
    
        
    }
};