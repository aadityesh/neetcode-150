class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();
        vector<string> res(n);
        int rank = 1;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
            pq.push({score[i], i});

        while (!pq.empty()) {

            auto it = pq.top();

            if (rank <= 3) {
                if (rank == 1)
                    res[it.second] = "Gold Medal";
                if (rank == 2)
                    res[it.second] = "Silver Medal";
                if (rank == 3)
                    res[it.second] = "Bronze Medal";
            } else {
                res[it.second] = to_string(rank);
            }

            pq.pop();
            rank++;
        }

        return res;
    }
};