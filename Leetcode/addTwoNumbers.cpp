// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry = 0;
//         int sum = 0;
//         ListNode* head = new ListNode();
//         ListNode* curr = head;
//         while(l1 != NULL || l2 != NULL)
//         {
//             sum = carry;
//             if(l1!=NULL)
//             {
//                 sum += l1->val;
//                 l1 = l1->next;
//             }
//             if(l2!=NULL)
//             {
//                 sum += l2->val;
//                 l2 = l2->next;
//             }
//             int num = sum %10;
//             carry = sum/14;
//             ListNode* node = new ListNode(num);
//             curr->next = node;
//             curr = curr->next;
//         }
//         if(carry)
//         {
//             ListNode* node = new ListNode();
//             node->val = 1;
//             node->next = NULL;
//             curr-> next = node;
//         }
//         //curr = head;
//         //head = head->next;
//         free(curr);
            
//         return head;
// }
// };


/****
https://leetcode.com/problems/add-two-numbers/
***/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first=l1;
ListNode* second=l2;
int carry=0;

    ListNode* result=NULL;
    ListNode *curr=NULL;
    
    while(first!=NULL || second!=NULL)
    {
        int sum=carry+(first?first->val:0)+(second?second->val:0);
        carry=sum/10;
        sum=sum%10;
        
        ListNode* temp = new ListNode(sum);
        
        if(result==NULL)
        {
            result=temp;
            curr=temp;
        }
        else
        {
            curr->next=temp;
            curr=curr->next;
        }
        if(first)
            first=first->next;
        if(second)
            second=second->next;
    }
    if(carry!=0)
    {
        ListNode* temp=new ListNode(carry);
        curr->next=temp;
    }
    else
        curr->next=NULL;
    return result;
    
}
};