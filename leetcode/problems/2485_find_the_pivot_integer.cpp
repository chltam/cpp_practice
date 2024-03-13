#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
      for (int i = 1; i <= n; i++) {
        int psum = (1 + i) * i / 2;
        int ssum = (n + i) * (n - i + 1) / 2;
        if (psum == ssum)
          return (i);
      }
      return -1;
    }
};
