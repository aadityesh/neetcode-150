class Solution {
public:
    int square(int x) { return x * x; }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, vector<vector<int>>> umap;

        for (vector<int>& i : points) {
            int x = i[0];
            int y = i[1];
            int distance = square(x) + square(y);
            umap[distance].push_back({x, y});
            pq.push(distance);
        }

        while (res.size() != k) {
            int distance = pq.top();
            for (vector<int>& point : umap[distance]) {
                res.push_back(point); 
                if (res.size() == k)
                    break; 
            }
            pq.pop();
        }

        return res;
    }
};