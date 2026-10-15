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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        int size =0;
        while(temp != null)
        {
            size = size+1;
            temp = temp.next;
        }
        int p = size-n;
        if(p==0)
        {
            return head.next;
        }
        temp = head;
        while(p>1)
        {
            temp = temp.next;
            p--;
        }
        temp.next = temp.next.next;
        return head;
    }
}