#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
          int diff = target - nums[i];
          if (map.count(diff))
            return {map[diff], i};
          map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
  Solution solution;

  vector<int> nums = {1, 2, 3, 4};
  int target = 6;

  vector<int> result = solution.twoSum(nums, target);
  cout << result[0] << " " << result[1] << endl;
}