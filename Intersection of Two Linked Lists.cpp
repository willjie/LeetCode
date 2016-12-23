/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*最开始没有理解题意，以为相交之后还会分开*/
 
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*此题的要求一旦相交之后就不分开了，找寻第一个相交的点*/
        /*
        ListNode *l1,*l2;
        l1 = headA;
        l2 = headB;
         while(l1 != NULL)
         {
             l2 = headB;
             while(l2 != NULL)
             {
                 if(l2 == l1)
                 {
                     return l2;
                 }
                 l2 = l2->next;
             }
             l1 = l1->next;
         }
        
        return  NULL;
        */                      /*暴力破解*,时间复杂度太高O(N*M)*/
        
        /*双指针法*/
        
        int lengthA,lengthB;
        lengthA = lengthB = 0;
        ListNode *l1,*l2;
        l1 = headA;
        l2 = headB;
        while(l1 != NULL)
        {
            lengthA++;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            lengthB++;
            l2 = l2->next;
        }
        
        if(lengthA > lengthB)
        {
            for(int i = 0; i < lengthA - lengthB; i++)
            {
                headA = headA->next;
            }
        }
        else if(lengthA < lengthB)
        {
            for(int i = 0; i < lengthB -lengthA; i++)
            {
                headB = headB->next;
            }
        }
        
        while(headA != NULL && headB != NULL)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
        
        
    }
};