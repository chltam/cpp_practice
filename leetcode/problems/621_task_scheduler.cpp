#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> map;

    for (char c : tasks)
      map[c]++;
    
  }
};