// failed attemp includes inplace replacements of the nodes


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

// this includes creating to separate list and then merge them
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftNode = new ListNode(), *rightNode = new ListNode();
        ListNode* leftHead = leftNode, *rightHead = rightNode;
        ListNode *curr = head;

        while(curr != NULL){
            if(curr->val < x){
                // append to left
                ListNode* now = curr;
                curr = curr->next;
                leftNode->next = now;
                now->next = NULL;
                leftNode = now;
            } else{
                // append to right
                ListNode* now = curr;
                curr = curr->next;
                rightNode -> next = now;
                now->next = NULL;
                rightNode = now;
            }
        }

        leftNode ->next = rightHead->next;
        rightHead->next = NULL;


        return leftHead->next;
    }
};

// https://leetcode.com/problems/partition-list/submissions/1421631522/
// https://leetcode.com/problems/partition-list/solutions/2315494/java-c-detailed-explanation/