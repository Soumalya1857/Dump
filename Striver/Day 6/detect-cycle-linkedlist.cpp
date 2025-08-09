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
    bool hasCycle(ListNode *head) {
        // first approach should be memorization technique
        
        // then the rabbit and tortoise approach
        
        ListNode* tortoise = head, *rabbit = head;
        // rabbit will move twice as fast as tortoise
        
        while(tortoise != NULL && rabbit != NULL)
        {
            tortoise = tortoise->next;
            if(rabbit->next != NULL) rabbit = rabbit->next->next;
            else{
                return false;
            }
            
            if(tortoise == rabbit) return true;
        }
        
        return false;
    }
};

// prb: https://leetcode.com/problems/linked-list-cycle/submissions/
// soln: https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=34