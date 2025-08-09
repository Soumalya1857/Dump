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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* tortoise = head, *rabbit=head;
        while(tortoise != NULL && rabbit != NULL)
        {
            tortoise = tortoise->next;
            if(rabbit->next != NULL) rabbit = rabbit->next->next;
            else
            {
                return NULL;
            }
            
            if(rabbit == tortoise)
            {
                ListNode* temp = head;
                while(rabbit != temp)
                {
                    rabbit = rabbit->next;
                    temp = temp->next;
                }
                return rabbit;
            }
        }
        
        return NULL;
    }
};

// prob: https://leetcode.com/problems/linked-list-cycle-ii/submissions/
// cool intuition: https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=37