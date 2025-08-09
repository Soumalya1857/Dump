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
        vector<int>store;
        while(head != NULL)
        {
            store.push_back(head->val);
            head = head->next;
        }
        
        int size = store.size();
        if(size == 0) return false;
        
        for(int i=0; i<=(size/2)-1; i++)
        {
            if(store[i] != store[size-1-i]) return false;
        }
        
        return true;
    }
};

/*question: https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/*/