#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> s;
      for (int n : nums1) {
        if (std::find_if(nums2.begin(), nums2.end(), [n](int i){return n == i; }) != nums2.end())
          s.emplace(n);
      }
      vector<int> v;
      for (int n : s)
        v.push_back(n);

      return v;
    }
};