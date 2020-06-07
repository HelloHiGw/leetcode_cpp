class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        p = persons;
        t = times;
        int mx = 0, candidate = -1;
        unordered_map<int, int> count;
        for (int i = 0; i < p.size(); ++i) {
            if (++count[p[i]] >= mx) {
                mx = count[p[i]];
                candidate = p[i];
            }
            winner.push_back(candidate);
        }
    }
    
    int q(int time) {
        int left = 0, right = t.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (t[mid] > time) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        --left;
        return winner[left];
    }

private:
    vector<int> p;
    vector<int> t;
    vector<int> winner;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */s