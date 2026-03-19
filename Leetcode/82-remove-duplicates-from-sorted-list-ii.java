/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode newHead = new ListNode();
        newHead.next = head;
        ListNode prev = newHead; // last confirmed unique node
        ListNode curr = head; // current node

        while(curr != null && curr.next != null) {
            // 
            if (curr.val == curr.next.val) {
                // skip all such elements
                while(curr.next != null && curr.val == curr.next.val){
                    curr = curr.next;
                }
                prev.next = curr.next; // remove duplicates totally
            } else {
                prev = prev.next; // move to next unique
            }

            curr = curr.next;
        }

        return newHead.next;
    }
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/6801800/beats-100-easiest-explanation-for-beginn-6noz/