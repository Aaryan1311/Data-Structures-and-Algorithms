class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i : nums) {
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }

    int add(int val) {
        int currk = INT_MIN;
        if(pq.size() == size) {
            currk = pq.top();
        }
        if(val <= currk) return currk;
        else{
            pq.push(val);
            if(pq.size() > size) pq.pop();
            int ans = pq.top();
            return ans;
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */