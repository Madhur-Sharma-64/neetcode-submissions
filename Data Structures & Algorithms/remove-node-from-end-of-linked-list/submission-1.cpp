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

        if ( head == nullptr ) return head;
        if ( head->next == nullptr && n == 1 ) return nullptr;
        ListNode* curr = head;

        int len = 0;

        while ( curr != nullptr ) {
            len++;
            curr = curr->next;
        }

        int remove = len - n + 1 ;

        if ( remove == 1 ) return head->next;
        
        ListNode* prev = head;
        curr = head->next;

        int idx = 2;

        while ( curr != nullptr ) {
            if ( idx == remove ) {
                prev->next = curr->next;
                curr->next = nullptr;
                return head;
            }
            idx++;
            prev = prev->next;
            curr = curr->next;
        }

        

        

        //cout << len;

        return head;
    }
};
