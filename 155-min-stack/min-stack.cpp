class MinStack {

    /*stack<int> st1;
    stack<int> st2;
    */

    vector<pair<int, int>> vec;

public:
    MinStack() {}

    void push(int x) {

        /*
        st1.push(x);
        if (st2.empty() || st2.top() >= x)
            st2.push(x);
        */

        if (vec.empty()) {
            vec.push_back({x, x});
            return;
        };

        int lastMin = vec.back().second;
        lastMin = lastMin > x ? x : lastMin;
        vec.push_back({x, lastMin});
    }

    void pop() {

        // if (st1.top() == st2.top())
        //     st2.pop();
        // st1.pop();
        return vec.pop_back();
    }

    int top() { return vec.back().first; }

    int getMin() { return vec.back().second; }
};
