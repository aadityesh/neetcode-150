
class Solution {
public:
    // Brute
    /*
    int findPosition(vector<int>& inorder, int elem) {
        for(int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == elem) return i;
        }

        return -1;

    }
    */

    int findPosition(unordered_map<int, int>& umap, int elem) {
        if (umap.find(elem) == umap.end())
            return -1;

        return umap[elem];
    }

    // TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,
    //                 int istart, int iend) {

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,
                    int istart, int iend, unordered_map<int, int>& umap) {

        if (index >= preorder.size() || istart > iend)
            return NULL;

        // EXTRACTION OF ROOT
        int currentRootData = preorder[index++]; // updation of index
        TreeNode* currentRoot = new TreeNode(currentRootData);

        // EXTRACTION OF L, R
        int currentRootPosition =
            findPosition(umap, currentRootData); // helps us in finding L,R
        currentRoot->left =
            solve(preorder, inorder, index, istart, currentRootPosition - 1, umap);
        currentRoot->right =
            solve(preorder, inorder, index, currentRootPosition + 1, iend, umap);

        return currentRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        int extractRootIndex = 0;

        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++) {
            umap[inorder[i]] = i;
        }

        // TreeNode* root = solve(preorder, inorder, extractRootIndex, 0,
        //                        n - 1); // inorder-start, inorder-end

        TreeNode* root = solve(preorder, inorder, extractRootIndex, 0,
                               n - 1, umap); // inorder-start, inorder-end

        return root;
    }
};