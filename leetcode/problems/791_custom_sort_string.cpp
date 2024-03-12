#include <iostream>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
      string  result;

      for (int i = 0; i < order.length(); i++) {
        int pos;
        while ((pos = s.find(order[i])) != s.npos) {
          result.push_back(order[i]);
          s.erase(pos, 1);
        }
      }
      for (char c : s)
        result.push_back(c);
      return result;
        
    }
};

int main()
{
  Solution solution;

  cout << solution.customSortString("cba", "abcd") << endl;
}