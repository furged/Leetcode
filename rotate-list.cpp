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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int length = 0;
        ListNode* curr = head;

        while (curr) {
            length++;
            curr = curr->next;
        }
        for (int i = 0; i < k%length; i++) {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            curr->next = head;
            prev->next = nullptr;
            head = curr;
            prev = nullptr;
        }
        return head;
        
    }
};
