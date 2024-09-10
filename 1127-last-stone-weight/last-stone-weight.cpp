class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        if (stones.size() == 1)
            return stones[0];

        priority_queue<int> pq(stones.begin(), stones.end());

        while (!pq.empty()) {

            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (y - x > 0)
                pq.push(y - x);

            /* else
               if x == y then we move on
            */

            if (pq.size() == 1)
                return pq.top();
        }

        return 0;
    }
};