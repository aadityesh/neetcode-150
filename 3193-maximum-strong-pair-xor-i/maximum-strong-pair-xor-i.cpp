class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {

        // Brute
        
        int n = a.size();
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (abs(a[i] - a[j]) <= min(a[i], a[j])) {
                    st.insert({a[i], a[j]});
                }
            }
        }

        int res = 0;
        for(auto i : st) {
            int curr = i.first ^ i.second;
            res = max(res, curr);
        }

        return res;
    }
};