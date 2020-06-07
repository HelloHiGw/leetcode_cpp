class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int cnt = 0;
      for (int i = 0; i < flowerbed.size() && cnt < n; ++i) {
        if (flowerbed[i] == 0) {
          int pre = (i == 0 ? 0 : flowerbed[i - 1]);
          int next = (i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1]);
          if (pre == 0 && next == 0) {
            ++cnt;
            flowerbed[i] = 1;
          }
        }
      }
      return cnt >= n;
    }
};