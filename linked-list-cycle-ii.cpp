class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* curr = head;

        while (curr) {
            if (visited.count(curr))
                return curr;

            visited.insert(curr);
            curr = curr->next;
        }

        return nullptr;
    }
};
