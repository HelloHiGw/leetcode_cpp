class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        if (it == mp[key].begin()) return "";
        return prev(it)->second;
    }
    
private:
    unordered_map<string, map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // if you use {timestamp, ""} reports error
        // if no const, reports error
        // auto it = upper_bound(mp[key].begin(), mp[key].end(), pair<int, string>(timestamp, ""), [&](const pair<int, string>& p1, const pair<int, string>& p2) {
        //     return p1.first < p2.first;
        // });
        // return it == mp[key].begin() ? "" : prev(it)->second;
        
        int left = 0, right = mp[key].size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mp[key][mid].first > timestamp) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == 0) return "";
        return mp[key][--left].second;
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> mp;
};