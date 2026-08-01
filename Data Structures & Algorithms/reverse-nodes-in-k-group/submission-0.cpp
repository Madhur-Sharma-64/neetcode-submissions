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
    ListNode* rev(ListNode* st, ListNode* end) {
        ListNode* curr = st;
        ListNode* prev = end;

        while (curr != end) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        // Find the node after the kth node
        ListNode* end = head;
        for (int i = 0; i < k; i++) {
            if (!end)
                return head;      // Less than k nodes remain
            end = end->next;
        }

        // Reverse first k nodes
        ListNode* newHead = rev(head, end);

        // head is now the tail of the reversed group
        head->next = reverseKGroup(end, k);

        return newHead;
    }
};