class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            string curr = words[i];
            for (int j = 0; j < curr.length(); j++) {
                if (curr[j] == x) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};