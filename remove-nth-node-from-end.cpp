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
        ListNode* curr = head;
        int count = 0;
        while (curr->next != nullptr) {
            count++;
            curr = curr->next;
        }
        curr = head;
        ListNode dummy;
        dummy.next = head;
        ListNode * prev = &dummy;
        int toDelete = count - n + 1;
        count = 0;
        while (count != toDelete) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        return dummy.next;
    }
};
