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

    ListNode* merge (ListNode* l1, ListNode* l2 ) {
        ListNode* node = new ListNode(0);
        ListNode* curr = node;

        while ( l1 && l2 ) {
            if ( l1->val > l2->val ) {
                curr->next = l2;
                l2 = l2->next;
            }
            else {
                curr->next = l1;
                l1 = l1->next;
            }

            curr = curr->next;
        }

        if ( l1 != nullptr ) curr->next = l1;
        if ( l2 != nullptr ) curr->next = l2; 

        return node->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        for ( int i = 0 ; i < lists.size() - 1; i++ ) {
            ListNode* l1 = lists[i];
            ListNode* l2 = lists[i+1];

            lists[i+1] = merge(l1, l2);
        }

        return lists.empty() ? nullptr : lists.back();
    }
};
