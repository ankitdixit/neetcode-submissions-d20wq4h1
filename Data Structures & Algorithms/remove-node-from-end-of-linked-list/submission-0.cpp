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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        ListNode* end = head;
        ListNode* nth = dummy;
        dummy->next = head;
        for(int i = 0; i < n; i++) {
            end = end->next;
        }
        while(end != nullptr) {
            end = end->next;
            nth = nth->next;
        }
        ListNode* temp = nth->next;
        nth->next = nth->next->next;
        delete temp;
        return dummy->next;
    }
};
