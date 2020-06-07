// enumerate circle centers O(n * n), compute count O(n), thus O(n^3)
// O(1)
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int dist = r * r;
        int n = points.size();
        int res = 1;  // minimum is 1
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {  // enumerate different point pair
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
                if (d > 2 * r) continue;  // cannot form a circle
                
                // formula of circle centers(at most 2) of two points wirh radius r
                double Cx0 = (x1 + x2) / 2.0 + (y1 - y2) / 2.0 * sqrt(4 * r * r - d * d) / d;
                double Cy0 = (y1 + y2) / 2.0 + (x2 - x1) / 2.0 * sqrt(4 * r * r - d * d) / d;
                res = max(res, count(points, Cx0, Cy0, r));
                
                double Cx1 = (x1 + x2) / 2.0 + (y2 - y1) / 2.0 * sqrt(4 * r * r - d * d) / d;
                double Cy1 = (y1 + y2) / 2.0 + (x1 - x2) / 2.0 * sqrt(4 * r * r - d * d) / d;
                res = max(res, count(points, Cx1, Cy1, r));
            }
        }
        return res;
    }
    
private:
    int count(vector<vector<int>>& points, double x, double y, int r) {
        int cnt = 0;
        for (auto& point : points) {
            // double dist = sqrt(pow(point[0] - x, 2) + pow(point[1] - y, 2));
            // if (dist <= r + 0.01) ++cnt;
            int dist = pow(point[0] - x, 2) + pow(point[1] - y, 2);
            if (dist <= r * r) ++cnt;
        }
        return cnt;
    }
};