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

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Store the start of the next pair
            first->next = second->next;

            // Reverse the current pair
            second->next = first;

            // Connect the previous part
            prev->next = second;

            // Move prev to the tail of the swapped pair
            prev = first;
        }

        return dummy.next;
    }
};