class Solution {
public:
    bool isIsomorphic(string a, string b) {
        int n = a.size();
        int m = b.size();

        if (n != m)
            return false;

        map<char, char> mpp1;
        map<char, char> mpp2;

        for (int i = 0; i < n; i++) {

            char c1 = a[i];
            char c2 = b[i];

            if (mpp1.find(c1) != mpp1.end() && mpp1[c1] != c2)
                return false;
            if (mpp2.find(c2) != mpp2.end() && mpp2[c2] != c1)
                return false;

            mpp1[c1] = c2;
            mpp2[c2] = c1;
        }

        return true;
    }
};