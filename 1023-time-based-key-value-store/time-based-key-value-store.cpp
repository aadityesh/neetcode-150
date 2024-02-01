class TimeMap {

    map<string, vector<pair<string, int>>> omap;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        omap[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {

        if (omap.find(key) == omap.end())
            return "";

        int low = 0;
        int high = omap[key].size() - 1;
        string ans = "";

        while (low <= high) {

            int mid = (low + high) / 2;
            if (omap[key][mid].second <= timestamp) {
                ans = omap[key][mid].first;
                low = mid + 1;
            } else {
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