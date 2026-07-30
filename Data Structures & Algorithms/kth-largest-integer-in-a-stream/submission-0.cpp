class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> minHeap;
int n;

    KthLargest(int k, vector<int>& nums) {
        n = k;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            minHeap.push(nums[i]);

            if ( minHeap.size() > n ) minHeap.pop();
        }        
    }
    
    int add(int val) {
        if ( minHeap.size() < n ) minHeap.push(val);

        else if ( minHeap.top() < val ) {
            minHeap.push(val);
            minHeap.pop();
        }

        return minHeap.top();
    }
};
