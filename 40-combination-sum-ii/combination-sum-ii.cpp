
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& input, int _target) {
        this->target = _target;
        sort(input.begin(), input.end());
        generate(input, {}, 0, 0);
        for (auto i : st)
            res.push_back(i);
        return res;
    }

    void generate(vector<int>& input, vector<int> temp, int sum, int i) {

        if (sum == target) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        if (i == input.size() || sum > target) {
            return;
        }

        sum += input[i];
        temp.push_back(input[i]);
        generate(input, temp, sum, i + 1);

        sum -= input[i];
        temp.pop_back();
        while (i + 1 < input.size() && input[i] == input[i + 1])
            i++;
        generate(input, temp, sum, i + 1);
    }

private:
    vector<vector<int>> res;
    set<vector<int>> st;
    int target;
};