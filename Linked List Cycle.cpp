/*Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*检查链表有没有环有常规方法*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution
 {
 	 bool hasCycle(ListNode *head) {
 	 	/*常规算法*/
 	 	
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

/*巧妙算法,时间复杂度为O（n)*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*这道题的构思太巧秒了，时间复杂度很低O（n），思路就是一个快指针每次走两步，一个慢指针每次走一步，如果有环，他们两个肯定会相遇*/
        
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