/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.*/
/*�����Ŀ���Ǻϲ�������������ߣ��ϲ�֮��Ҳ�������*/
/*����˼������½�һ������Ȼ��Ƚ����������е�Ԫ��ֵ���ѽ�С���Ǹ������������У�����������������ĳ��ȿ��ܲ�ͬ��
�������ջ���һ����������ɲ�������Ԫ�أ���ֱ����һ��δ��ɵ�����ֱ�������������ĩβ
*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode *l3 = new ListNode(0);                                   /*����һ���µ�����*/
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
			if (p == NULL)                                                    /*l1��l2�ĳ����п��ܲ�һ����������l1Ҫ��һ��*/
			{
				res->next = q;
			}
			if (q == NULL)                                                     /*l1��l2�ĳ����п��ܲ�һ����������l2Ҫ��һ��*/
			{
				res->next = p;
			}
			return l3->next;
	}