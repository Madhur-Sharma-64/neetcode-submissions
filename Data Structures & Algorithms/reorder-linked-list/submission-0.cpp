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
    void reorderList(ListNode* head) {

        if ( head == nullptr || head->next == nullptr ) return;

        ListNode* slow = head;
        ListNode* fast = head->next ;
       // ListNode* prev = head;

        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;

            // ( fast->next->next == nullptr || fast->next == nullptr ) 
            //prev = slow;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
       // ListNode* prev = nullptr;
        fast = nullptr;

        while ( mid != nullptr ) {
            slow = mid->next;
            mid->next = fast;
            fast = mid;

            // if ( slow == nullptr )
            // break;

            mid = slow;
        }

        //prev->next = mid;

        ListNode* curr = head;
        ListNode* tmp = head;
        ListNode* tmp2 = fast;

        while ( fast != nullptr ) {
            tmp = curr->next;
            tmp2 = fast->next;

            curr->next = fast;
            fast->next = tmp;

            curr = tmp;
            fast = tmp2;
        }

        return;
       
    }
};
