#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      map<int, int> map;
      
      for (int n : nums) {
        if (!map.count(n))
          map[n] = 1;
        else
          map[n]++;
      }

      int maxf = 0;
      for (auto& pair : map)
        maxf = max(maxf, pair.second);

      int count = 0;
      for (auto& pair : map) {
        if (pair.second == maxf)
          count++;
      }
      return maxf * count;
    }
};