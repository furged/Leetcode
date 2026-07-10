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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;
        while (true) {
            // kth node ka loop
            ListNode* kth = prevGroup;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (kth == nullptr)
                    return dummy.next;
            }
            ListNode* first = prevGroup->next;
            ListNode* groupNext = kth->next;
            // reverse loop
            ListNode* prev = groupNext;
            ListNode* curr = first;
            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // previous group ko reversed group se connect
            prevGroup->next = kth;
            // move prevGroup to the tail of reversed group
            prevGroup = first;
        }
        return dummy.next;
    }
};
