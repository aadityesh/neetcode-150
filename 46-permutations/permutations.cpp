class Solution {
public:
    void dfs(vector<int>& input, vector<vector<int>>& result,
             vector<int>& current, vector<bool>& hashSet) {

        if (current.size() == input.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < input.size(); i++) {
            if (hashSet[i] == false) {
                current.push_back(input[i]);
                hashSet[i] = true;
                dfs(input, result, current, hashSet);
                current.pop_back();
                hashSet[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& input) {

        vector<vector<int>> result;
        vector<int> current;
        vector<bool> hashSet(input.size(), false);

        dfs(input, result, current, hashSet);

        return result;
    }
};