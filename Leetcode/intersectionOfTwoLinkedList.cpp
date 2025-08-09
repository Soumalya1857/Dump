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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     
        
        ListNode* copyA = headA;
        ListNode* copyB = headB;
        
        int countA = 0, countB = 0;
        while(copyA != NULL)
        {
            countA++;
            copyA = copyA->next;
        }
        
        while(copyB != NULL)
        {
            countB++;
            copyB = copyB->next;
        }
        
        
        copyA = headA;
        copyB = headB;
        if(countA > countB)
        {
            int diff = countA - countB;
            for(int i=0;i<diff;i++)
            {
                copyA = copyA->next;
            }
            
            countA -= diff;
        }
        
        else if(countA < countB)
        {
            int diff = countB - countA;
            for(int i=0;i<diff;i++)
            {
                copyB = copyB->next;
            }
            
            countB -= diff;
        }
        
        ListNode* node = new ListNode();
        //node->val = 121;
        bool flag = false;
        
        while(copyA != NULL && copyB != NULL)
        {
            if(copyA == copyB)
            {
                node->val = copyA->val;
                flag = true;
                break;
            }
            
            copyA = copyA->next;
            copyB = copyB->next;
        }
        
        if(flag) return node;
        else return NULL;
        
    }
};

/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/