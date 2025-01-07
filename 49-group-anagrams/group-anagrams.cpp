class Solution {
public:
    string customKey(string& inp) {
        vector<int> hash(26, 0);
        for (char& i : inp) {
            hash[i - 'a']++;
        }
        string key = ""; // 5a2b3c....
        for (int i = 0; i < 26; i++) {
            key.push_back(hash[i]);
            key.push_back(char(i + 'a'));
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;

        for (string i : strs) {
            // string key = i;
            // sort(key.begin(), key.end()); // lexicographical
            string key = customKey(i);
            umap[key].push_back(i);
        }

        // T - O(N * mlogm)

        for (auto i : umap) {
            res.push_back(i.second);
        }

        // T - O(N)

        return res;
    }
};