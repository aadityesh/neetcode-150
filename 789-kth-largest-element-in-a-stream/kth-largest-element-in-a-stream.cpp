class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i : nums) {
            if (pq.size() < K)
                pq.push(i);
            else if (pq.top() < i) {
                pq.push(i);
                if (pq.size() > K)
                    pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */