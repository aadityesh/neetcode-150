class MinStack
{
    private:
        stack<int> st1;
        stack<int> st2;
    public:
        MinStack() {}

    void push(int val)
    {
        st1.push(val);
        if(st2.empty() || val <= st2.top()) st2.push(val);
    }

    void pop()
    {
        if(st1.top() == st2.top()) st2.pop();
        st1.pop();
    }

    int top()
    {
        return st1.top();
    }

    int getMin()
    {

        // Brute Approach
        // ALT: HashMap
        
        /*stack<int> cpy = st;
        vector<int> a;

        while (!cpy.empty())
        {
            a.push_back(cpy.top());
            cpy.pop();

        }

        int mini = INT_MAX;
        for (auto i: a)
        {
            if (i < mini)
                mini = i;
        }
        return mini;*/

        return st2.top();
    }
};

/**
 *Your MinStack object will be instantiated and called as such:
 *MinStack* obj = new MinStack();
 *obj->push(val);
 *obj->pop();
 *int param_3 = obj->top();
 *int param_4 = obj->getMin();
 */