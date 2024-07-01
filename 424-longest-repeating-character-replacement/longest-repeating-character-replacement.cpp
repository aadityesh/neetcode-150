class Solution {
public:
    int helper(unordered_map<char, int>& umap) {
        int length = 0;
        for (auto it : umap) {
            length = max(length, it.second);
        }

        return length;
    }
    int characterReplacement(string s, int k) {

        unordered_map<char, int> umap;

        int n = s.length();
        int L = 0;
        int R = 0;

        int length = 0;
        int maxf = 0;

        while (R < n) {

            umap[s[R]]++;
            
            maxf = helper(umap);

            while ((R - L + 1) - maxf > k) {
                umap[s[L]]--;
                L++;
            }

            length = max(length, R - L + 1);
            R++;
        }

        return length;
    }
};