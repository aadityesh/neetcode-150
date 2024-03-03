class Solution {
public:
    int firstUniqChar(string s) {

        int hash[26] = {0};
        int res = -1;
        for (int i = 0; i < s.length(); i++) {
            hash[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (hash[idx] == 1) {
                res = i;
                break;
            }
        }

        return res;
    }
};