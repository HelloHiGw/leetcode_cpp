/*
the key is find upperBound(b) in sorted A
*/

/*
Set is BST internally, and it's algorithm designed/optimized for that. Generic binary search 
just works with ranges, which is slow for BST.

if you set auto it = upper_bound(st.begin(), st.end(), B[i])
it will TLE

you can not use sorted vector and for (int i = 0; i < B.size(); ++i) here
cause when B[i] find a upperBound in sorted A, you should erase it in sorted A
so next element in B will never select it again
but erase in vector is O(n)

st.erase(position) is amortized constant.

time O(nlogn)
space O(n)
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset st(A.begin(), A.end());
        vector<int> res(A.size());
        for (int i = 0; i < B.size(); ++i) {
            auto it = st.upper_bound(B[i]);
            if (it == st.end()) it = st.begin();
            res[i] = *it;
            st.erase(it);
        }
        return res;
    }
};

/*
time O(nlogn)
space O(n)
*/
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        priority_queue<pair<int, int>> pq;  // max heap
        for (int i = 0; i < B.size(); ++i) {
            pq.push({B[i], i});
        }
        
        vector<int> res(A.size());
        int low = 0, high = A.size();
        while (!pq.empty()) {
            // first tackleing with bigger element in B
            // then we only need erase begin() or end(), that is ++low, --high
            // we do not simplely sort B, because we want the index of val in B
            int val = pq.top().first, index = pq.top().second;
            pq.pop();
            int ub = upperBound(A, low, high, val);
            if (ub == high) {
                res[index] = A[low++];
            } else {
                res[index] = A[--high];
            }
            
        }
        
        return res;
    }
    
private:
    int upperBound(vector<int>& A, int low, int high, int target) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] > target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};