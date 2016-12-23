/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
 /*ע�⣬�Ǵ����һ����ǰ��*/
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
        int length = 0;                        /*��������ĳ���*/
        if(head->next == NULL && n == 1)      /*Ҫ��Լ�������������������*/
        {
            return NULL;                      /*��һ���������һ����㣬ֱ�ӷ���NULL*/
        }
        while (p != NULL)
        {
            length++;
            p = p->next;
        }
        if(n == length)                      /*�ڶ��������ɾ������ͷ��㣬�Ҳ���ɾ������ǰһ�����*/
        {
            head = head->next;
            return head;
        }
        while (temp != length - n - 1)       /*��Ϊ�Ǵ�0��ʼ������Ҫ��1,������N����㣬��������length-N+1�����*/
        {
            q = q->next;                     /*qָ��ı�ɾ����ǰһ�����*/
            temp++;
        }

         p = q->next;
         q->next = p->next;
     
         return head;
        
        
    }
};