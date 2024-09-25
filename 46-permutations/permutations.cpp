class Solution {
public:
    void dfs(vector<int>& input, vector<vector<int>>& result,
             vector<int>& current, unordered_set<int>& hashSet) {

        if (current.size() == input.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < input.size(); i++) {
            if (hashSet.find(input[i]) == hashSet.end()) {
                current.push_back(input[i]);
                hashSet.insert(input[i]);
                dfs(input, result, current, hashSet);
                current.pop_back();
                hashSet.erase(input[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& input) {

        vector<vector<int>> result;
        vector<int> current;
        unordered_set<int> hashSet;

        dfs(input, result, current, hashSet);

        return result;
    }
};