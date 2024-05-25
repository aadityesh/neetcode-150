class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> umap;
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

    }
};