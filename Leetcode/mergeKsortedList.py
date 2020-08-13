# // /**
# //  * Definition for singly-linked list.
# //  * struct ListNode {
# //  *     int val;
# //  *     ListNode *next;
# //  *     ListNode() : val(0), next(nullptr) {}
# //  *     ListNode(int x) : val(x), next(nullptr) {}
# //  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
# //  * };
# //  */

# // typedef pair<int, int> pi; 
  
# // class Solution {
# // public:
    
# // //    struct Compare{  
# // //          bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const
# // //         {
# // //             return lhs.first < rhs.first;
# // //         }
# // //    };
    
# //     bool empty(vector<ListNode*>& lists)
# //     {
# //         int k = lists.size();
# //         for(int i=0;i<k;i++)
# //         {
# //             if(lists[i] != NULL) return false;
# //         }
        
# //         return true;
# //     }
# //     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
# //         int k = lists.size();
# //         //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<int,int> > q; // for holding the least number
        
# //         priority_queue<pi, vector<pi>, greater<pi> > q;
# //         ListNode ans = ListNode(0);
# //         ListNode* head = &ans;
# //         ListNode* newHead = head;
# //         for(int i=0;i<k;i++)
# //         {
# //             q.push(make_pair(lists[i]->val, i));
# //         }
        
# //         while(!empty(lists))
# //         {
# //             pair<int,int> temp = q.top();
# //             q.pop();
            
# //             ListNode curr = ListNode(temp.first);
# //             head->next = &curr;
# //             head = head->next;
            
# //             int index = temp.second;
# //             if(lists[index]!=NULL) lists[index] = lists[index]->next;
# //         }
        
# //         newHead = newHead->next;
# //         return newHead;
# //     }
# // };



# // TIME LIMIT EXCEEDED



# // ORIGINAL solution


# // best approach
# /*

# Intuition & Algorithm

# This approach walks alongside the one above but is improved a lot. We don't need to traverse most nodes many times repeatedly

# Pair up \text{k}k lists and merge each pair.

# After the first pairing, \text{k}k lists are merged into k/2k/2 lists with average 2N/k2N/k length, then k/4k/4, k/8k/8 and so on.

# Repeat this procedure until we get the final sorted linked list.

# Thus, we'll traverse almost NN nodes per pairing and merging, and repeat this procedure about \log_{2}{k}log 
# 2
# ​	
#  k times.
# */


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

from Queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next
        