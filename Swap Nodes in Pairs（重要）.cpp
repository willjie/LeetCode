/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/*���������������ڽ��Ľ�������������Ҫһ����ʱָ����Ͻ�������ǰһ�����󽻻����ĺ�һ�����*/

/*����ʵ��*/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *res = new ListNode(0);
        ListNode *pre = NULL;
        res->next = head;
        pre = res;
        int flag = 0;
        
        while (pre->next != NULL && pre->next->next != NULL)
        {
            ListNode *t = pre->next;
            pre->next = t->next;
            t->next = pre->next->next;
            pre->next->next = t;
            
            pre = t;
         
        }
        
        return res->next;
        
    }
};

/*�ݹ�ʵ��*/
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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
        		return head;
        }
        ListNode *t = head->next;
        
        head->next = swapPairs(head->next->next);
        t->next = head;
        
        return t;        
    }
};

