class Solution {
public:
    string frequencySort(string s) {

        int n = s.length();
        unordered_map<char, int> umap;

        int i = 0;
        while (i < n) {
            umap[s[i]]++;
            i++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto i : umap) {
            pq.push({i.second, i.first});
        }

        string res = "";
        while (!pq.empty()) {
            auto it = pq.top();
            int freq = it.first;
            while(freq--) res += it.second;
            pq.pop();
        }
        return res;
    }
};