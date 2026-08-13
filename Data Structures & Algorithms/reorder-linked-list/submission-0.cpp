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
        ListNode* slow { head };
        ListNode* fast { head };

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if (fast != nullptr)
                slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        second = prev;

        ListNode* current = head;

        while (current != nullptr && second != nullptr) {
            ListNode* next = current->next;
            ListNode* s_next = second->next;

            current->next = second;
            second->next = next;

            current = next;
            second = s_next;
        }
    }
};
