#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int a = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // if(find(nums.begin(), nums.end(), target) == nums.end()){
        //     a = -1;
        // }
        // return a;
        int mid, l = 0, r = nums.size() - 1;
        while(l < r)
        {
            mid = (l + r) / 2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};