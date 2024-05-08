#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      unordered_map<int,string> map;
      vector<int> copy(score);
      vector<string> ans;
      
      sort(copy.begin(), copy.end(), [](int lhs, int rhs){return lhs>rhs;});
      
      for (int i = 0; i < copy.size(); i++) {
        if (i == 0)
            map[copy[i]] = "Gold Medal";
        if (i == 1)
            map[copy[i]] = "Silver Medal";
        if (i == 2)
            map[copy[i]] = "Bronze Medal";
        if (i > 2)
            map[copy[i]] = to_string(i + 1);
      }
      for (int i : score) {
        ans.push_back(map[i]);
      }
      return ans;
    }
};