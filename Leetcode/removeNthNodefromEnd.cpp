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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        //ListNode* newHead = head;
        if(head == NULL) return head;
        if(head->next == NULL) return NULL;
        
        ListNode* fast = head; ListNode* slow = head;
        // fast node will be n node ahead of slow node
        // NOTE: BEST PRACTISE TO INITIALIZE BOTH BY NULL(JUST BEFORE HEAD)
        //THEN ADVANCE THE FAST BY N STEPS
        // THAT REDUCE THE NULL CASE I HANDLED HERE
        
        
        
        for(int i=0;i<n;i++) fast = fast->next;
        
        // occurs when n is equals to the length
        // delete the head basically
        if(fast == NULL)
        {
            head = head->next;
            //free(head);
            return head;
        }
        
        for(int i=0;;i++)
        {
            if(fast->next == NULL) break;
            fast = fast->next;
            slow = slow->next;
        }
        
        fast = (slow->next)->next;
        slow->next = fast;
        
        return head;
    }
};

/*
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/