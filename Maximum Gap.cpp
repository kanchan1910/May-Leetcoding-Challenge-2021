class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        if(n < 2)
        {
            return 0;
        }
        for(int i = 0; i < n - 1; i++)
        {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};
// tc o(nlogn)
// sc o(1)

// using bucket sort(peignhole principal)

class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        int n = nums.size();
        int ans = INT_MIN;
        if(n < 2)
        {
            return 0;
        }
         int minvalue = nums[0], maxvalue = nums[0];
        for(auto x : nums)
        {
            minvalue = min(minvalue, x);
            maxvalue = max(maxvalue, x);
        }
        int minarr[n - 1], maxarr[n - 1];
        for(int i = 0; i < n - 1; i++)
        {
            minarr[i] = INT_MAX;
            maxarr[i] = INT_MIN;
        }
        int max_gap = ceil((maxvalue - minvalue) * 1.0/ (n - 1) * 1.0);
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == maxvalue || nums[i] == minvalue)
            {
                continue;
            }
            int index = (nums[i] - minvalue)/ max_gap;
            minarr[index] = min(minarr[index], nums[i]);
            maxarr[index] = max(maxarr[index], nums[i]);
        }
        int prev_val = minvalue;
        for(int i = 0; i < n - 1; i++)
        {
            if(minarr[i] == INT_MAX)
            {
                continue;
            }
            ans = max(ans, minarr[i] - prev_val);
            prev_val = maxarr[i];
        }
        ans = max(ans, maxvalue - prev_val);
        return ans;
    }
};
// tc o(n)
// sc o(n)
