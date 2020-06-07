const int MAXN = 1e5 + 10;
int heap[MAXN];

class KthLargest {
public:
    // min heap of size k, then top is the kth largest
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num : nums) {
            insert(num);
        }
    }
    
    int add(int val) {
        insert(val);
        return heap[1];  // if n < kth, we return the min of n
    }
    
private:
    int n = 0;
    int kth = 0;
    
    void downAdjust(int low, int high) {
        int i = low, j = 2 * i;
        while (j <= high) {
            if (j + 1 <= high && heap[j + 1] < heap[j]) ++j;
            if (heap[j] < heap[i]) {
                swap(heap[j], heap[i]);
                i = j;
                j = i * 2;
            } else {
                break;
            }
        }
    }
    
    void deleteTop() {
        heap[1] = heap[n--];
        downAdjust(1, n);
    }
    
    void upAdjust(int low, int high) {
        int i = high, j = i / 2;
        while (j >= low) {
            // min heap
            if (heap[i] < heap[j]) {
                swap(heap[i], heap[j]);
                i = j;
                j = i / 2;
            } else {
                break;
            }
        }
    }
    
    void insert(int val) {
        if (n == kth && val < heap[1]) return;  // prune in stable condition(n == kth)
        
        heap[++n] = val;
        upAdjust(1, n);
        
        if (n > kth) deleteTop();  // maintain size of kth
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (pq.size() < kth) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.push(val);
            pq.pop();
        }
        
        return pq.top();
    }
    
private:
    int kth = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
};
