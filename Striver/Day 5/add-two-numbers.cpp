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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        
        int sum=0,carry=0;
        
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            sum = 0;
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};

// problem = https://leetcode.com/problems/add-two-numbers/submissions/
// sol: https://www.youtube.com/watch?v=LBVsXSMOIk4&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=32