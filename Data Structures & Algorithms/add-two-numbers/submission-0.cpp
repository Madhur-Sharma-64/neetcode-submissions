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

    // ListNode* rev(ListNode* li) {
    //     ListNode* curr = li;
    //     ListNode* prev nullptr;
    //     ListNode* tmp = nullptr;

    //     while ( li != nullptr ) {
    //         tmp = curr->next;
    //         curr->next = prev;

    //         prev = curr;
    //         curr = tmp;
    //     }

    //     return prev;
    //}


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = rev(l1);
        // l2 = rev(l2);

        ListNode* lst = new ListNode(0);
        ListNode* ptr = lst;

        int carry = 0;

        while ( l1 != nullptr || l2 != nullptr || carry ) {
            int add = carry;

            if ( l1 != nullptr ) add += l1->val;
            if ( l2 != nullptr ) add += l2->val;

            ptr->val = add%10;
            carry = add/10;

            if ( l1 != nullptr ) l1 = l1->next;
            if ( l2 != nullptr ) l2 = l2->next;

            if ( l1 != nullptr || l2 != nullptr || carry){
                ptr->next = new ListNode (0);
                ptr = ptr->next;
            }

        }

        return lst;
    }
};
