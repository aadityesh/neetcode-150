class Solution {
public:
    bool isAnagram(string s, string t) {

        int len = s.length();
        if (len != t.length())
            return false;
            
        vector<int> hashArray(26, 0);

        for (int i = 0; i < len; i++) {
            hashArray[s[i] - 'a']++;
            hashArray[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (hashArray[i] != 0)
                return false;
        }

        return true;
    }
};