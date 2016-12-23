/*Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*���������û�л��г��淽��*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution
 {
 	 bool hasCycle(ListNode *head) {
 	 	/*�����㷨*/
 	 	
 	 	if(head == NULL || head->next == NULL)
 	 	{
 	 		return false;
 	 	}
 	 			
 	 	ListNode *pre,*cur;
 	 	pre = head;
 	 	cur = head->next;
 	 	
 	 	while(cur != NULL)
 	 	{
 	 		if(cur->next == cur)
 	 		{
 	 			return true;
 	 		}
 	 		pre = head;
 	 		
      while(cur->next != pre && cur != pre)
      {
      	 pre = pre->next;
      }
      if(cur->next == pre && pre != cur)
      {
      	  return true;
      }
      cur = cur->next; 
		}
		
		return false;
}

/*�����㷨,ʱ�临�Ӷ�ΪO��n)*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*�����Ĺ�˼̫�����ˣ�ʱ�临�ӶȺܵ�O��n����˼·����һ����ָ��ÿ����������һ����ָ��ÿ����һ��������л������������϶�������*/
        
        ListNode *slow, *fast;
        slow = fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                break;
            }
        }
        if(fast == NULL || fast->next == NULL)
        {
            return false;
        }
        return true;
        
    }
};