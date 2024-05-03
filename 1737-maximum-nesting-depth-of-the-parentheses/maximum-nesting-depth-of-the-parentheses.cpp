class Solution {
public:
    int maxDepth(string s) {

        stack<char> st;
        int n = s.length();
        int i = 0;
        int cnt = 0;
        int res = 0;

        while (i < n) {

            char c = s[i];

            if (c == '(') {
                st.push(c);
                cnt++;
            } else {
                if (c == ')') {
                    st.pop();
                    res = max(cnt, res);
                    cnt--;
                }
            }

            i++;
        }

        return res;
    }
};