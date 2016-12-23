/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/
/*这个题目就是合并两个有序的连边，合并之后也是有序的*/
/*具体思想就是新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中，由于两个输入链表的长度可能不同，
所以最终会有一个链表先完成插入所有元素，则直接另一个未完成的链表直接链入新链表的末尾
*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode *l3 = new ListNode(0);                                   /*建立一个新的链表*/
			ListNode *p = l1;
			ListNode *q = l2;
			ListNode *res = l3;
			while (p != NULL && q != NULL)
			{
				if (p->val < q->val)
				{
					res->next = p;
					p = p->next;
				}
				else
				{
					res->next = q;
					q = q->next;
				}
			
				res = res->next;
			}
			if (p == NULL)                                                    /*l1和l2的长度有可能不一样，可能是l1要短一点*/
			{
				res->next = q;
			}
			if (q == NULL)                                                     /*l1和l2的长度有可能不一样，可能是l2要短一点*/
			{
				res->next = p;
			}
			return l3->next;
	}