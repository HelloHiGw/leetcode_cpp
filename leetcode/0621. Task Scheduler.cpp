class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        int maxCount = -1, num = 0;  // there are num char with maxCount
        for (char ch : tasks) {
            int cnt = ++count[ch - 'A'];
            if (cnt == maxCount) {
                ++num;
            } else if (cnt > maxCount) {
                maxCount = cnt;
                num = 1;
            }
        }
        
        int partCount = maxCount - 1;
        int partLength = n - (num - 1);
        int emptyPositions = partCount * partLength;
        int availableTasks = tasks.size() - maxCount * num;
        int idles = max(0, emptyPositions - availableTasks);
        
        return idles + tasks.size();
    }
};