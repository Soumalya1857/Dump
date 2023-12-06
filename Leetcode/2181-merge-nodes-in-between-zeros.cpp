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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode *curr = head, *pHead = head;
        int sum = 0;
        while(curr->next != NULL){
            sum += curr->val;
            if(curr->next->val == 0){
                ListNode *newNode = new ListNode(sum);
                pHead->next = newNode;
                newNode->next = curr->next;

                sum=0;
                pHead = curr->next;
            }

            curr = curr->next;
        }

        // remove all the zeros

        ListNode *newHead = head->next, *runningHead = head->next; 
        curr = head->next;
        while(curr->next != NULL){
            if(curr->next->val != 0){
                runningHead-> next = curr->next;
                runningHead = curr->next;
            }

            curr = curr->next;
        } 

        runningHead->next = NULL;
        return newHead;
    }
};

// https://leetcode.com/problems/merge-nodes-in-between-zeros/


// better elegant solution
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
    ListNode* mergeNodes(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ListNode* curr=head;
        while(curr->next&&curr->next->next){
            if(curr->next->val==0){
              curr=curr->next;}
              else{
                  curr->val+=curr->next->val;
                  curr->next=curr->next->next;
              }
        }
        curr->next=NULL;
        return head;
    }
};