class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> umap;
        for (int i : nums)
            umap[i]++; // hashing part

        vector<vector<int>> count(n + 1);
        vector<int> res;

        for (auto i : umap) {
            count[i.second].push_back(i.first);
        }

        for (int i = n; i >= 0; i--) {
            for (int elem : count[i]) {
                res.push_back(elem);
                if (res.size() == k)
                    return res;
            }
        }

        return res;
    }
};