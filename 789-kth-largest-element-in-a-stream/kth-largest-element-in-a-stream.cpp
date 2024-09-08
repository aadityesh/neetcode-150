class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int val, vector<int>& nums) {
        k = val;
        for (int i : nums) {
            pq.push(i);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        while(pq.size() > k) 
            pq.pop();
        
        return pq.top();
    }
};
