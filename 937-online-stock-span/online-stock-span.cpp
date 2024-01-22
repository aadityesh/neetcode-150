class StockSpanner {

    // stack<int> s1;
    stack < pair<int, int>> st; // Optimal

public:
    StockSpanner() {}

    int next(int price) {

        /*
        // Brute
        int cnt = 1;
        stack<int> s2 = s1;

        while (!s2.empty() && s2.top() <= price) {
            s2.pop();
            cnt++;
        }
        s1.push(price);

        return cnt;
        */

        // Optimal
        int cnt = 1;

        if (st.empty() || st.top().first > price) {
            st.push({price, cnt});
        }

        else {

            while (!st.empty() && st.top().first <= price) {
                cnt += st.top().second;
                st.pop();
            }
            st.push({price, cnt});
        }

        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */