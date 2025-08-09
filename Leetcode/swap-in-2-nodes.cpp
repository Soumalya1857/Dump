class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *ptr1, *ptr2, *ptr;
        ptr1 = head; ptr2 = head->next;
        
        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        
        head = ptr2;
        
        ptr = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr1!=NULL? ptr1->next : NULL;
        
        while(ptr1!=NULL && ptr2!=NULL){
            ptr->next = ptr2;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            
            ptr = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr1!=NULL? ptr1->next : NULL;
        }
        
        return head;
    }
};

// accepted solution

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
    ListNode* swapPairs(ListNode* head) {
        
//         ListNode* first = head;
//         if(first == NULL) return head;
        
//         ListNode* second = first->next;
//         if(second == NULL) return head;
        
//         // swap them and restore head
        
//         ListNode* temp = second->next;
//         first->next = temp;
//         second->next = first;
//         head = first;
        
//         // restore first and second
//         first = temp;
//         if(first == NULL) return head;
        
//         second = first->next;
//         if(second == NULL) return head;
        
        
//         while(first != NULL && second != NULL)
//         {
//             ListNode* temp = second->next;
//             first->next = temp;
//             second->next = first;

//             // restore first and second
//             first = temp;
//             if(first == NULL) return head;

//             second = first->next;
//             if(second == NULL) return head;

//         }
//         return head;
        
        
        ListNode* curr=head, *next=NULL; 
        if(curr) next=curr->next;
        else    return head;
        
        while(curr && next)
        {
            swap(curr->val, next->val);
            next=next->next;
            if(next)    
            {
                curr=next;
                next=curr->next;
            }
            else
                return head;
        }
        return head;
    }
};


/*
Problem: https://leetcode.com/problems/swap-nodes-in-pairs/submissions/
*/