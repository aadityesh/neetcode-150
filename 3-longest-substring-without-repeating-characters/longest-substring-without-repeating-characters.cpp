class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<int> hashSet;

        int n = s.length();
        int L = 0;
        int R = 0;

        int res = 0;

        while (R < n) {

            while (!hashSet.empty() && hashSet.find(s[R]) != hashSet.end()) {
                hashSet.erase(s[L]);
                L++;
            }

            res = max(res, R - L + 1);
            hashSet.insert(s[R]);
            R++;
        }

        return res;
    }
};