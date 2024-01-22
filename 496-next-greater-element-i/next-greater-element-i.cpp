class Solution {
public:
    stack<pair<int, int>> st;
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {

        // brute - nested loops

        // optimal
        int n = a.size();
        int m = b.size();

        /*vector<int> ans;
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
        */

        stack<int> st;
        unordered_map<int, int> umap;

        for (int i = m - 1; i >= 0; i--) {

            while (!st.empty() && b[i] >= st.top()) {
                st.pop();
            }

            int res = (st.empty()) ? -1 : st.top();
            umap[b[i]] = res;

            st.push(b[i]);
        }

        vector<int> ans;
        for (auto i : a)
            ans.push_back(umap[i]);

        return ans;
    }
};