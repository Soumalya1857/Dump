/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // need to create a new list
        // this is with extra space
//         ListNode* result = &ListNode();
//         ListNode* newHead = result;
//         if(l1 == NULL) return l2;
//         if(l2 == NULL) return l1;
        
//         while(l1 != NULL && l2 != NULL)
//         {
//             result = &ListNode();
//             if(l1->val <= l2->val) {
//                 // add l1->val to list
//                 result->val = l1->val;
//             }
//             else
//             {
//                 result->val = l2->val;
//             }
            
//             result = result->next;
            
//         }
        
//        while(l1 != NULL)
//        {
           
//            result->val = l1->val;
//        } 
        
        
        
        
        // inplace addtion
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val > l2->val)
        {
            // swap as l2 will always point to larger array
            // l1 to smaller array
            
            ListNode* temp = l1;
            l1 = l2;
            l2 = l1;
        }
        ListNode* result = l1;
        
        while(l1 != NULL && l2 != NULL)
        {
            ListNode* temp = NULL;
            // increase l1 untill it crosses value of l2
            // but also remember the value just before of the crossing
            while( l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            
            temp->next = l2;
            
            // swap l1 and l2
            ListNode* temp1 = l1;
            l1 = l2;
            l2 = temp1;
        }
            
        return result;  
    }
};
// probn: https://leetcode.com/problems/merge-two-sorted-lists
// solution by stinver: https://www.youtube.com/watch?v=Lhu3MsXZy-Q&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=29