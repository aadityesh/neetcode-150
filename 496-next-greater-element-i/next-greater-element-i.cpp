class Solution {
public:
    stack<pair<int, int>> st;
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {

        // brute - nested loops

        // optimal
        int n = a.size();
        int m = b.size();

        vector<int> ans;
        unordered_map<int, int> umap;

        for (int i = 0; i < m; i++) {

            int res = -1;
            for (int j = i + 1; j < m; j++) {
                if (b[i] < b[j]) {
                    res = b[j];
                    break;
                }
            }
            umap[b[i]] = res;
        }

        for (int i = 0; i < n; i++) {
            ans.push_back(umap[a[i]]);
        }
        return ans;
    }
};