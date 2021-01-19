#include"iostream"
#include"algorithm"
#include"vector"
#include <numeric>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int main()
{
    Solution test;
    vector<int> a = { -2,1,-3,4,-1,2,1,-5,4};
    cout << test.maxSubArray(a);
}

int Solution::maxSubArray(vector<int>& nums) {
    vector<int> row_sum_base;
    vector<int> row_sum;
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        max = max > nums[i] ? max : nums[i];
    }
    if (max <= 0)
    {
        return max;
    }
    vector<int> positive_number;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            continue;
        }
        else
        {
            positive_number.push_back(i);
        }
    }
    if (positive_number.size() == 1)
    {
        return nums[positive_number[0]];
    }
    for (int i = 0; i < positive_number.size()-1; i++)
    {
        row_sum_base.push_back(accumulate(nums.begin() + positive_number[i], nums.begin() + positive_number[i + 1]+1 , 0));
    }
    row_sum.push_back(row_sum_base[0]);
    for (int i = 1; i < row_sum_base.size(); i++)
    {
        if (row_sum[i-1] - nums[positive_number[i]] < 0)
        {
            row_sum.push_back( row_sum_base[i]);
        }
        else
        {
            {
                row_sum.push_back(row_sum_base[i] + row_sum[i-1]-nums[positive_number[i]]);
            }
        }
    }
    for (int i = 0; i < row_sum.size(); i++)
    {
        max = max > row_sum[i] ? max : row_sum[i];
    }
    return max;
}
