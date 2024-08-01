

class Solution {
private:
    void minimumValueBST(TreeNode* root, int& mini) {
        if (root == NULL)
            return;

        mini = min(mini, root->val);

        if (root->left)
            minimumValueBST(root->left, mini);

        else
            minimumValueBST(root->right, mini);
    }

public:
    vector<TreeNode*> searchBST(TreeNode* root, int target) {

        // if (root == NULL)
        //     return NULL;

        // if (root->val == target)
        //     return root;

        // if (root->data > target)
        //     return searchBST(root->left, target);

        // return searchBST(root->right, target);

        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr) {
            if (curr->val == target) {
                return {prev, curr};
            } else if (curr->val > target) {
                prev = curr;
                curr = curr->left;
            } else {
                prev = curr;
                curr = curr->right;
            }
        }
        return {nullptr, nullptr};
    }

    TreeNode* deleteNode(TreeNode* root, int target) {
        /*
         vector<TreeNode*> toDelete = searchBST(root, key);

         TreeNode* prev = toDelete[0];
         TreeNode* curr = toDelete[1];
         if (prev && curr)
             cout << prev->val << " " << curr->val << endl;

         // elem not found
         if (curr == nullptr)
             return root;

         TreeNode* temp = curr;

         // No children
         if (curr->left == NULL && curr->right == NULL) {
             prev->left = NULL;
         }

         // left children exists
         else if (curr->left && curr->right == NULL) {
             prev->left = curr->left;
             curr->left = nullptr;
         }

         // right children exists
         else if (curr->left == NULL && curr->right) {
             prev->left = curr->right;
             curr->right = nullptr;
         }

         // both children
         else {
             prev->left = curr->right;
             curr->right->left = curr->left;
             curr->left = nullptr;
             curr->right = nullptr;
         }

         delete temp;

         return root;
         */

        if (root == NULL)
            return nullptr;

        if (root->val == target) {

            // #1 : 0 Children
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                cout << "o" << endl;
                return nullptr;
            }
            // #2 : 2 Children
            else if (root->left && root->right) {

                int mini = INT_MAX;
                minimumValueBST(root->right, mini);
                cout << mini << endl;
                root->val = mini;
                root->right = deleteNode(root->right, mini);

                return root;

            }
            // #3 : 1 Children
            else {
                TreeNode* child = root->left ? root->left : root->right;
                cout << "o777" << endl;
                delete root;
                return child;
            }
        }

        if (root->val > target) {
            root->left = deleteNode(root->left, target);
            return root;
        }

        else {
            root->right = deleteNode(root->right, target);
            return root;
        }
    }
};