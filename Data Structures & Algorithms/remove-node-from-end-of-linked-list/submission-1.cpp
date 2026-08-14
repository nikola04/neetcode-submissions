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
        ListNode* ptr{head};
        while (n-- > 0) {
            ptr = ptr->next;
        }

        ListNode dummy {};
        dummy.next = head;

        ListNode* current = &dummy;

        while (ptr != nullptr) {
            ptr = ptr->next;
            current = current->next;
        }

        current->next = current->next->next;

        return dummy.next;
    }
};
