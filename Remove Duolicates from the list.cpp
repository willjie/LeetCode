/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*方法跟数组一样*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
       
        ListNode *p,*pre;
        pre = head;
        p = head->next;
        while(p != NULL)
        {
            if(pre->val != p->val)
            {
                pre->next = p;
                pre = pre->next;
            }
            p = p->next;
        }
        pre->next = NULL;
        return head;
    }
};