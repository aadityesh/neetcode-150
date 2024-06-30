class TimeMap {

    unordered_map<string, vector<pair<string, int>>> umap;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        umap[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {

        if (umap.find(key) == umap.end())
            return "";

        int low = 0;
        int high = umap[key].size() - 1;

        string ans = "";
        while (low <= high) {

            int mid = (low + high) / 2;
            if (umap[key][mid].second <= timestamp) {
                ans = umap[key][mid].first;
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */