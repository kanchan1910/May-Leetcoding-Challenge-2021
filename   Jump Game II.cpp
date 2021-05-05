//You can assume that you can always reach the last index.

// so no worries to handle for that case
class Solution {
public:
    int fun(vector<int>&nums, vector<int>& dp, int index)
    {
        // base case
        if(index >= nums.size())
        {
            return nums.size();
        }
        if(index == nums.size() - 1)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        int ans = nums.size();
        for(int i = index + 1; i <= index + nums[index]; i++)
        {
            ans = min(ans, fun(nums, dp, i) + 1);
        }
        dp[index] = ans;
        return dp[index];
    }
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>dp(n, -1);
        int index = 0;
        return fun(nums, dp, index);
        
    }
};
