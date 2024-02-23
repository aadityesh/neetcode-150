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

        // Brute
        /*
        unordered_map<Node*, Node*> umap;
        Node* curr = head;

        while (curr) {
            umap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            umap[curr]->next = umap[curr->next];
            umap[curr]->random = umap[curr->random];
            curr = curr->next;
        }
        return umap[head];
        */

        // Optimal
        /*
        1. Insert Copy nodes in between
        2. Connect random ptr
        3. Connect next ptr using dummy node
        */
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }
        curr = head;
        while (curr) {
            Node* newNode = curr->next;
            if (curr->random)
                newNode->random = curr->random->next;
            curr = curr->next->next;
        }

        Node* dummy = new Node(-1);
        Node* tail = dummy;
        curr = head;

        while (curr) {
            tail->next = curr->next;
            tail = tail->next;

            curr->next = curr->next->next;
            curr = curr->next;
        }

        return dummy->next;

        // Printing

        // curr = head;
        // while(curr) {
        //     cout << curr->val << " ";
        //     curr = curr->next;
        // }

        // return head;
    }
};