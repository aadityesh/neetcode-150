class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        
        for (int num : nums) {

            int n = subs.size(); 
            cout << n << " ";
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};