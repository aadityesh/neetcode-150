class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> hash(26, 0);
        priority_queue<int> pq;
        int res = 0;

        for (char& ch : tasks) {
            hash[ch - 'A']++;
        }

        /*
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0)
                pq.push(hash[i]);
        }

        while (!pq.empty()) {

            int t = n + 1;
            vector<int> temp;
            while (t--) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int i : temp) {
                if (i > 0)
                    pq.push(i);
            }

            if (pq.empty())
                res += temp.size();
            else
                res += (n + 1);
        }

        return res;
        */
        sort(rbegin(hash), rend(hash));

        int holes = hash[0] - 1;
        int idleSpots = holes * n;

        for (int i = 1; i < 26; i++) {
            idleSpots = idleSpots - min(hash[i], holes);
            // cout << hash[i] << " ";
        }

        if (idleSpots > 0)
            return tasks.size() + idleSpots;
            
        return tasks.size();
    }
};