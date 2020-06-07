class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int total = 0, curr = 0;
        for (int i = 0; i < distance.size(); ++i) {
            if (i >= start && i < destination) curr += distance[i];
            total += distance[i];
        }
        return min(curr, total - curr);
    }
};