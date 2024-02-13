class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // set<vector<int>> ss;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;

        // for (int i = 0; i < n; i++)
        // {
        //     set<int> hashset;
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         int diff = -(nums[i] + nums[j]);

        //         if (hashset.find(diff) != hashset.end())
        //         {
        //             vector<int> tmp = {nums[i], nums[j], diff};
        //             sort(tmp.begin(), tmp.end());

        //             ss.insert(tmp);
        //         }

        //         hashset.insert(nums[j]);
        //     }
        // }

        // vector<vector<int>> ans(ss.begin(), ss.end());
        // return ans;
    }
};