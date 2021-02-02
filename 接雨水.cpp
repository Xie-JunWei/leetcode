class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
        {
            return 0;
        }
        int left_max[height.size()];
        int right_max[height.size()];
        int ans = 0;
        left_max[0] = height[0];
        right_max[height.size() - 1] = height[height.size() - 1];
        for (int i = 1; i < height.size(); i++)
        {
            left_max[i] = left_max[i - 1] > height[i] ? left_max[i - 1] : height[i];
            right_max[height.size() - i - 1] = right_max[height.size() - i] > height[height.size() - i - 1] ? right_max[height.size() - i] :
                height[height.size() - i - 1];
        }
        for (int j = 0; j < height.size(); j++)
        {
            ans += min(left_max[j], right_max[j]) - height[j];
        }
        return ans;
    }
};