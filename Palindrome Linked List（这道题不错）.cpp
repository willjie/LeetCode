/*
Given a singly linked list, determine if it is a palindrome.
*/
�������Ǽ��������ǲ��ǻ�������
//�ص������е㣨������е㣬�ÿ���ָ�룩
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
        
        //����������ҵ�������е�
        //���е�����ÿ���ָ����ʵ��
        ListNode *slow,*fast;
        slow = fast = head;
        
        while(fast->next != NULL && fast->next->next !=NULL)   //��ָ������������ָ����һ��������ָ������ʱ����ָ������е㴦
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //��ΪҪ��ռ临�Ӷ�Ϊ��1�������Բ�����ջ���洢Ԫ�أ����Խ�����İ벿�ֽ��з�ת��Ȼ����жԱ�
        ListNode *t = slow->next;
        while(t->next != NULL)   //��ת����
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