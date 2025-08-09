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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev;
        int i = 0 , count = 0;
        while(temp != NULL) // Count total nodes
        {
            temp = temp -> next;
            count++;
        }
        temp = head;
        k = k % count;
        while(temp != NULL && i < count - k) // Reach at the node from where we want to rotate
        {
            i++;
            prev = temp;
            temp = temp -> next;
        }
        if(temp == NULL)
        {
            return head;
        }
        ListNode* curr = temp; // curr wil hold the start of the list
        prev -> next = NULL; // Previous node of temp i.e. prev will point to NULL
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = head; // Last node will point to start to the original list
       return curr;
    }
    
};

// prb: https://leetcode.com/problems/rotate-list/submissions/
// sol: https://www.youtube.com/watch?v=9VPm6nEbVPA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=39
// sol: https://leetcode.com/problems/rotate-list/discuss/1391679/~95-Time-O(N)-Space-O(1)