class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for (int i = 0; i < rects.size(); ++i) {
            int area = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            sum.push_back(area + (sum.empty() ? 0 : sum.back()));
        }
    }
    
    vector<int> pick() {
        int n = sum.back();
        int rnd = rand() / (1.0 * RAND_MAX + 1) * n;
        int i = upperBound(rnd);
        int x1 = rects[i][0], x2 = rects[i][2];
        int y1 = rects[i][1], y2 = rects[i][3];
        //cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        return {random(x1, x2), random(y1, y2)};
    }
    
private:
    vector<int> sum;
    vector<vector<int>> rects;
    
    int upperBound(int target) {
        int left = 0, right = sum.size(), mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (sum[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    int random(int min, int max) {
        // correct
        // return rand() % (max - min + 1) + min;

        // still cannot pass, algorithm note
        // return round(rand() / (1.0 * RAND_MAX) * (max - min) + min);
        
        int res = rand() / (1.0 * RAND_MAX / (max - min + 1) + 1);
        // cout << min << " " << max << " " << res << endl;
        // i do not know why the following is incorrect, you have to int() then add
        // int res = min + rand() / (1.0 * RAND_MAX / (max - min + 1) + 1);
        return res + min;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */