class Solution {
public:
    int helper(vector<int>& hash) {
        int length = 0;
        for (int it : hash) {
            length = max(length, it);
        }

        return length;
    }
    int characterReplacement(string s, int k) {

        int n = s.length();

        int length = 0;
        int maxf = 0;

        for (int L = 0; L < n; L++) {

            vector<int> hashA(26, 0);

            for (int R = L; R < n; R++) {

                hashA[s[R] - 'A']++;
                maxf = max(maxf, hashA[s[R] - 'A']);

                if ((R - L + 1) - maxf <= k) {
                    length = max(length, (R - L + 1));
                } else
                    break;
            }
        }

        /*
         vector<int> hashA(26, 0);

        int n = s.length();

        int length = 0;
        int maxf = 0;
        int L = 0;
        int R = 0;

        while (R < n) {

             hashA[s[R] - 'A']++;
             maxf = max(maxf, hashA[s[R]-'A']);

             while ((R - L + 1) - maxf > k) {
                 hashA[s[L] - 'A']--;
                 L++;
             }

             length = max(length, R - L + 1);
             R++;
         }

        */
        return length;
    }
};