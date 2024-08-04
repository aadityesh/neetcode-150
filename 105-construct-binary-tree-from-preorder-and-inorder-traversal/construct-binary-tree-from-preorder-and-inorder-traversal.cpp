
class Solution {
public:

    int findPosition(vector<int>& inorder, int elem) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == elem) return i;
        }

        return -1;

    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index,
    int istart, int iend) {

        if(index >= preorder.size() || istart > iend ) return NULL;

        int currentRootData = preorder[index++]; // updation of index
        TreeNode* currentRoot = new TreeNode(currentRootData);
        int currentRootPosition = findPosition(inorder, currentRootData); // helps us in finding L,R

        currentRoot->left = solve(preorder, inorder, index, istart, currentRootPosition-1);
        currentRoot->right = solve(preorder, inorder, index, currentRootPosition+1, iend);
        


    return currentRoot;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int extractRootIndex = 0;
        TreeNode* root = solve(preorder, inorder, extractRootIndex, 0, n-1); // inorder-start, inorder-end

        return root;


    }
};