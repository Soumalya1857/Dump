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
    ListNode* middleNode(ListNode* head) {
        
//         ListNode* curr = head;
//         int size = 0;
//         while(curr != NULL)
//         {
//             curr = curr->next;
//             size++;
//         }
        
//         size = size/2 +1;
//         // there should be node no -1 hops
//         curr = head;
//         for(int i=0;i<size-1;i++) curr = curr -> next;
        
//         return curr;
        
        
        
        // slow and fast method
        
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// prob: https://leetcode.com/problems/middle-of-the-linked-list/
// soln: https://www.youtube.com/watch?v=sGdwSH8RK-o&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=28


