/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
 /*注意，是从最后一个往前算*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        int temp = 0;
        int length = 0;                        /*计算链表的长度*/
        if(head->next == NULL && n == 1)      /*要针对集中特殊的情况单独讨论*/
        {
            return NULL;                      /*第一种情况，就一个结点，直接返回NULL*/
        }
        while (p != NULL)
        {
            length++;
            p = p->next;
        }
        if(n == length)                      /*第二种情况，删除的是头结点，找不到删除结点的前一个结点*/
        {
            head = head->next;
            return head;
        }
        while (temp != length - n - 1)       /*因为是从0开始，所以要减1,倒数第N个结点，就是正数length-N+1个结点*/
        {
            q = q->next;                     /*q指向的被删结点的前一个结点*/
            temp++;
        }

         p = q->next;
         q->next = p->next;
     
         return head;
        
        
    }
};