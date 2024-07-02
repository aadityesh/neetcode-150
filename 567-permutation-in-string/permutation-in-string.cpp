class Solution {
public:
    // vector<string> generatePermutations(string s1) {

    // }

    void hashing(string& s1, unordered_map<char, int>& umap) {
        for (char i : s1) {
            umap[i]++;
        }
    }

    bool hashIsEmpty(vector<int>& arr) {
        for (int i : arr) {
            if (i > 0)
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        // 1. Frequency would be same of chars in s1
        // 2. Window size == s1.length()

        int len1 = s1.length();
        int len2 = s2.length();
        // cout << "length - " << len1 << " " << len2 << endl;
        unordered_map<char, int> umap;
        hashing(s1, umap);

        // for (auto it : umap) {
        //     cout << it.first << " " << it.second << endl;
        // }

        for (int i = 0; i < len2; i++) {

            // windowSize is maintained
            int flag = 1;
            unordered_map<char, int> hash;
            for (int j = i; j <= ((i + len1) - 1); j++) {
                if (umap.find(s2[j]) == umap.end()) {
                    flag = 0;
                    break;
                }
                hash[s2[j]]++;
            }
            cout << endl;
            if (flag && hash == umap)
                return true;
        }

        return false;
    }
};