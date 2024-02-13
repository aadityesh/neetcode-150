class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int res = 0;
        int left = 0;
        int right = 0;
        // [ l ... r ] -> hold substr w/o repeating characs
        unordered_set<char> uset;
        while (right < n) {
            while (uset.find(s[right]) != uset.end()) {
                uset.erase(s[left]);
                left++;
            }

            res = max(res, right - left + 1);
            uset.insert(s[right++]);
        }

        return res;
    }
}
;