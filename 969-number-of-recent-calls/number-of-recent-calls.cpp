class RecentCounter {
    int cnt;
    vector<int> requests;

public:
    RecentCounter() { cnt = 0; }

    int ping(int t) {

        int a = t - 3000;
        int b = t;
        int c = 0;

        requests.push_back(t);

        for (auto i : requests) {
            if (i >= a && i <= b) {
                // cout << i << " ";
                c++;
            }
        }

        return c;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */