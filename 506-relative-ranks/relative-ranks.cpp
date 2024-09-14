class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();
        vector<string> res(n);

        int maxElement = *max_element(score.begin(), score.end());
        vector<int> indexes(maxElement + 1, 0);

        for (int i = 0; i < n; i++) {
            indexes[score[i]] = i + 1;
        }

        int rank = 1;
        for (int i = maxElement; i >= 0; i--) {

            if (indexes[i] > 0) {
                int ind = indexes[i] - 1;
                cout << ind << " " << rank << endl;
                if (rank == 1)
                    res[ind] = "Gold Medal";
                else if (rank == 2)
                    res[ind] = "Silver Medal";
                else if (rank == 3)
                    res[ind] = "Bronze Medal";
                else
                    res[ind] = to_string(rank);
                
                rank++;
            }
        }

        return res;
    }

    /*{
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
    }*/
};