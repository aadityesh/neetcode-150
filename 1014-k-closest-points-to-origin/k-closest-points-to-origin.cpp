class Solution {
public:
    int square(int x) { return x * x; }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>> res;
        priority_queue<vector<int>> pq;
        
        for(vector<int> &v : points) {
            int dist = square(v[0]) + square(v[1]);
            pq.push({dist, v[0], v[1]});
            // maintain size K
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            vector<int> point = pq.top();
            res.push_back({point[1], point[2]});
            pq.pop();
        }

        return res;
    }
};