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
    bool isPalindrome(ListNode* head) {
        // r4everse the right half of the list
        // and then check
        
        // get to the middle bro
        if(head->next == NULL) return true;
        ListNode* slow=head, *fast=head;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        while(fast->next != NULL) fast = fast->next;
        
        // now slow is on the middle
        // now reverse the after the node from slow
        // so head is basically slow->next
        
        ListNode* curr = slow->next, *prev = NULL, *next=curr->next;
        // list reverse here
        while(next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
            curr->next = prev;
        }
        
        slow->next = fast;
        
        // now we have a working list
        ListNode* secondHead = fast, *firstHead=head;
        
        // check palindrome
        while(secondHead != NULL)
        {
            if(firstHead->val != secondHead->val) return false;
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }
        
        return true;
    }
};
// p[rb: https://leetcode.com/problems/palindrome-linked-list
// soln: https://www.youtube.com/watch?v=-DtNInqFUXs&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=36
