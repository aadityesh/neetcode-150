class Solution {
public:
    Node* copyRandomList(Node* head) {

        /* unordered_map<Node*, Node*> umap;
         Node* curr = head;

         while(curr) {
             umap[curr] = new Node(curr->val);
             curr = curr->next;
         }
         curr = head;
         while(curr) {

             Node* cpyNode = umap[curr];
             cpyNode->next = umap[curr->next];
             cpyNode->random = umap[curr->random];

             curr = curr->next;
         }

         return umap[head];
     */

        Node* curr = head;

        // Insert in between
        while (curr) {

            Node *newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;

            curr = curr->next->next;

        }
        // Connect Random ptr
        curr = head;
        while (curr) {

            Node* cpy = curr->next;
            if (curr->random)
                cpy->random = curr->random->next;
            else
                cpy->random = NULL;

            curr = curr->next->next;

        }

        // Connect next ptr
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
    }
};