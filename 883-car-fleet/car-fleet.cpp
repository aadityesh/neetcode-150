class Solution {
public:
    // int carFleet(int target, vector<int>& pos, vector<int>& speed) {

    //     int n = pos.size();
    //     stack<double> st;
    //     vector<pair<int, int>> input;

    //     for (int i = 0; i < n; i++) {
    //         input.push_back({pos[i], speed[i]});
    //     }

    //     sort(input.begin(), input.end());

    //     for(int i = n - 1; i >= 0 ; i--) {

    //         double time = double(target - input[i].first) /
    //         double(input[i].second);
    //         // if(time <= st.top()) -> required condition
    //         if(st.empty() || time > st.top()) {
    //             st.push(time);
    //         }

    //     }

    //     return int(st.size());

    // }

    int carFleet(int target, vector<int>& pos, vector<int>& speed) {

        int n = pos.size();
        // stack<double> st;

        vector<pair<int, double>> input;

        double time = 0.0;
        for (int i = 0; i < n; i++) {
            time = double(target - pos[i]) / double(speed[i]);
            input.push_back({pos[i], time});
        }

        sort(input.begin(), input.end());

        double maxTime = 0.0;
        int cnt = 0;

        for (int i = n - 1; i >= 0; i--) {

            if(input[i].second > maxTime) {
                maxTime = input[i].second;
                cnt++;
            }
           
        }

        return cnt;
    }
};