class Solution {
public:
    int beauty(vector<int>& arr) {

        int mf = -1;
        int lf = INT_MAX;

        for (int i = 0; i < 26; i++) {
            mf = max(mf, arr[i]);
            if (arr[i] >= 1) {
                lf = min(lf, arr[i]);
            }
        }
        return mf - lf;
    }
    int beautySum(string s) {

        int n = s.length();
        int res = 0;

        //   unordered_map<char, int> umap;
        //   for (int i = 0; i < n; i++)
        //     umap[s[i]]++;

        //   if (umap.size() <= 1)
        //     return 0;

        // vector<string> allStrings;

        for (int i = 0; i < n; i++) {
            vector<int> arr(26, 0);
            for (int j = i; j < n; j++) {
                // allStrings.push_back(s.substr(i, j - i + 1));
                arr[s[j] - 'a']++;
                res += beauty(arr);
            }
        }

        // for (int i = 0; i < allStrings.size(); i++) {

        //     unordered_map<char, int> m;
        //     string a = allStrings[i];

        //     for (int j = 0; j < a.length(); j++) {
        //         m[a[j]]++;
        //     }

        //     if (m.size() == 1)
        //         continue;

        //     int minFreq = INT_MAX;
        //     int maxFreq = INT_MIN;
        //     // char e1, e2;
        //     for (auto i : m) {
        //         if (minFreq > i.second) {
        //             minFreq = i.second;
        //         }
        //         if (maxFreq < i.second) {
        //             maxFreq = i.second;
        //         }
        //     }

        //     res += (maxFreq - minFreq);
        // }

        //   for (string i : allStrings) {
        //     cout << i << endl;
        //   }

        return res;
    }
};