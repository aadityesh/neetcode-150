class Solution {
public:
    vector<int> previousElem(vector<int>& a) {

        int n = a.size();
        vector<int> b(n, 0);
        stack<int> st;

        int idx = 0;
        for (int i = 0; i < n; i++) {

            if (st.empty()) {
                b[idx++] = -1;
            }

            else {

                while (!st.empty() && a[st.top()] >= a[i]) {
                    st.pop();
                }
                if (!st.empty() && a[st.top()] < a[i]) {
                    b[idx++] = st.top();
                }
                if (st.empty()) {
                    b[idx++] = -1;
                }
            }

            st.push(i);
        }

        return b;
    }

    vector<int> nextElem(vector<int>& a) {

        int n = a.size();
        vector<int> b(n, 0);
        stack<int> st;

        int idx = n - 1;
        for (int i = n - 1; i >= 0; i--) {

            if (st.empty()) {
                b[idx--] = n;
            }

            else {

                while (!st.empty() && a[st.top()] >= a[i]) {
                    st.pop();
                }
                if (!st.empty() && a[st.top()] < a[i]) {
                    b[idx--] = st.top();
                }
                if (st.empty()) {
                    b[idx--] = n;
                }
            }
            st.push(i);
        }

        return b;
    }

    int largestRectangleArea(vector<int>& a) {

        int n = a.size();
        int ans = 0;

        /*
        // Brute
        for (int i = 0; i < n; i++) {

            int curr = a[i];

            for (int j = i - 1; i != 0 && j >= 0; j--) {
                if (a[j] >= a[i])
                    curr += a[i];
                else
                    break;
            }

            for (int j = i + 1; j < n; j++) {
                if (a[j] >= a[i])
                    curr += a[i];
                else
                    break;
            }

            ans = max(ans, curr);
        }
        */

        // Optimal

        vector<int> ps = previousElem(a);
        vector<int> ns = nextElem(a);

        for (int i = 0; i < n; i++) {
            int height = a[i];
            int currArea = (ns[i] - ps[i] - 1) * height;
            ans = max(ans, currArea);
        }

        return ans;
    }
};