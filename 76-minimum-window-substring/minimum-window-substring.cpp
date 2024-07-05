
class Solution {
public:
    bool check(string& curr, string& t, unordered_map<char, int>& tmap) {

        unordered_map<char, int> umap;
        for (char i : curr) {
            umap[i]++;
        }

        for (char i : t) {
            if (curr.find(i) == string::npos)
                return false;
            if (tmap[i] > umap[i])
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {

        if (s == t)
            return s;

        int len1 = s.length();
        int len2 = t.length();

        int minLength = 0;

        if (len2 > len1)
            return "";

        unordered_map<char, int> tmap;
        for (char& i : t) {
            tmap[i]++;
        }

        /*
        string res = "";
        
         for (int i = 0; i < len1; i++) {

             for (int j = i; j < len1; j++) {

                 if ((j - i + 1) < len2)
                     continue;

                 string curr = s.substr(i, (j - i) + 1);
                 // cout << curr;

                 if (check(curr, t, tmap)) {

                     if (minLength == 0) {
                         res = curr;
                         minLength = curr.length();
                     }

                     if (minLength > curr.length()) {
                         res = curr;
                         minLength = curr.length();
                     }
                 }

                 // cout << " " << res << endl;
             }
         }
         */

        int startIndex = -1;
        int windowSize = INT_MAX;
        int requiredCount = t.length();
        int i = 0, j = 0;

        while (j < len1) {

            char ch = s[j];
            if (tmap[ch] > 0)
                requiredCount--;
            tmap[ch]--;

            while (requiredCount == 0) {

                int currWindowSize = j - i + 1;
                if (windowSize > currWindowSize) {
                    windowSize = currWindowSize;
                    startIndex = i;
                }

                tmap[s[i]]++;

                if (tmap[s[i]] > 0)
                    requiredCount++;

                i++;
            }

            j++;
        }

        string res = (windowSize == INT_MAX)
                         ? ""
                         : s.substr(startIndex, windowSize);
        return res;
    }
};