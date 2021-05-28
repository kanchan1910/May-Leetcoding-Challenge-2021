class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int>m;
        int start = 0;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            while(m.find(nums[i]) != m.end())
            {
                sum -= nums[start];
                m.erase(nums[start]);
                start++;
            }
            sum += nums[i];
            m[nums[i]]++;
            ans = max(ans, sum);
        }
        return ans;
    }
};
