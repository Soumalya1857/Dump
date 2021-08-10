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
        
        int lenA=0,lenB=0;
        ListNode* currA=headA, *currB=headB;
        while(currA != NULL) lenA++, currA = currA->next;
        while(currB != NULL) lenB++, currB = currB->next;
        
        currA = headA; currB = headB;
        
        if(lenA > lenB)
        {
            int gap = lenA-lenB;
            while(gap--)
            {
                currA=currA->next;
            }
        }
        else
        {
            int gap = lenB-lenA;
            while(gap--)
            {
                currB=currB->next;
            }
        }
        
        
        while(currA != NULL && currB != NULL)
        {
            if(currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        
        return NULL;
    }
};

// prob: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
// https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=33