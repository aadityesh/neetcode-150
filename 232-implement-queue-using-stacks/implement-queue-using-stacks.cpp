class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    /*
    // Brute
    class MyQueue {
        stack<int> st1;
        stack<int> st2;

    public:
        MyQueue() {}

        void push(int x) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            st2.push(x);
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }

        int pop() {
            int elem = st1.top();
            st1.pop();
            return elem;
        }

        int peek() { return st1.top(); }

        bool empty() { return st1.size() == 0; }
    };

    */
    MyQueue() {}

    void push(int x) { input.push(x); }

    int pop() {
        if (!output.empty()) {
            int elem = output.top();
            output.pop();
            return elem;
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int elem = output.top();
            output.pop();
            return elem;
        }
    }

    int peek() {
        if (!output.empty()) {
            int elem = output.top();
            // output.pop();
            return elem;
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int elem = output.top();
            // output.pop();
            return elem;
        }
    }

    bool empty(){return (input.empty() && output.empty());};
};
