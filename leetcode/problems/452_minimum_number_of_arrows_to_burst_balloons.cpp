#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    vector<int> arrows;
    
    while (!points.empty()) {
      unordered_map<int, int> freq;

      for (vector<int>& v : points) {
        int n = v[0];
        while (n <= v[1]) {
          freq[n]++;
          n++;
        }
      }
      
      for (auto& pair : freq) {
        cout << "Key: " << pair.first << " Value: " << pair.second << endl;
      }

      int maxVal = INT32_MIN;
      int maxKey;
      for (auto& pair : freq) {
        if (pair.second > maxVal) {
          maxVal = pair.second;
          maxKey = pair.first;
        }
      }
      cout << "max = " << maxKey << endl;
      arrows.push_back(maxKey);
      for (auto it = points.begin(); it != points.end(); ) {
        if (maxKey >= (*it)[0] && maxKey <= (*it)[1]) {
          points.erase(it);
        } else {
          it++;
        }
      }
      // points.erase(remove_if(points.begin(), points.end(), [maxKey](const vector<int>& v) {return (maxKey >= v[0] && maxKey <= v[1]); }));
      freq.clear();
    }
    

    return arrows.size();  
  }
};

int main() {
  Solution solution;
  vector<vector<int>> p({{10,16}, {2,8}, {1,6}, {7,12}});
  int re = solution.findMinArrowShots(p);
  cout << "a = " << re << endl;
  return (0);
}