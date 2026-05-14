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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp && count<k)
        {
            temp = temp->next;
            count++;
        }
        if(count<k)
        {
            return head;
        }
        count = 0 ;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* newNode = nullptr;
        while(curr && count<k)
        {
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
            count++;
        }
        if(newNode != nullptr)
        {
            head->next = reverseKGroup(newNode,k);
        }
        return prev;
    }
};