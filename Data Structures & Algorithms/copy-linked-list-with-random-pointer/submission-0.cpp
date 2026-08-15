/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy { 0 };
        Node* last = &dummy;

        std::unordered_map<Node*, Node*> m {};

        Node* current { head };
        while (current != nullptr) {
            Node* node { new Node{ current->val } };
            last->next = node;

            m[current] = node;

            last = last->next;
            current = current->next;
        }

        current = head;
        while (current != nullptr) {
            Node* node = m[current];
            node->random = m[current->random];

            current = current->next;
        }

        return dummy.next;
    }
};
