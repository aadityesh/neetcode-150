class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int res = 0;
        int start = 0;

        unordered_set<char> uset;
        for (int end = 0; end < n; end++) {

            while (uset.find(s[end]) != uset.end()) {
                uset.erase(s[start]);
                start++;
            }

            uset.insert(s[end]);
            res = max(res, end - start + 1);
        }

        return res;
    }
};