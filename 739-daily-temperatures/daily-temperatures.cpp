class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {

        /*
        vector<int> res;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    ans = j-i;
                    break;
                }
            }
            res.push_back(ans);
        }

        return res;
        */

        int n = arr.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[i] >= st.top().first) {
                st.pop();
            }

            if (!st.empty()) {
                res[i] = st.top().second - i;
            }

            st.push({arr[i], i});
        }

        return res;
    }
};