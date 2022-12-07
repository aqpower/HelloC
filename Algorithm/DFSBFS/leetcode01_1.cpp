#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        pair<int, int> p[nums.size() + 3];
        for (int i = 0; i < nums.size(); i++)
        {
            p[i] = {nums[i], i};
        }
        sort(p, p + nums.size());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (p[i].first + p[j].first < target)
            {
                i++;
            }
            if (p[i].first + p[j].first > target)
            {
                j--;
            }
            if (p[i].first + p[j].first == target)
            {
                break;
            }
        }
        v.push_back(p[i].second);
        v.push_back(p[j].second);
        return v;
    }
};