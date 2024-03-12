#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int n = 0;

        while (i < nums1.size() && n < nums2.size()) {
            if (nums1[i] == nums2[n])
                return nums1[i];
            if (nums1[i] < nums2[n])
                i++;
            else
                n++;
        }
        return -1;
    }
};