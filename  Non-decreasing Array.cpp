class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        int need = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i + 1] < nums[i])
            {
                need++;
                if(need > 1)
                {
                    return false;
                }
                if(i == 0)
                {
                    nums[i] = nums[i + 1];
                }
                else if(i == n - 2)
                {
                    nums[i + 1] = nums[i];
                }
                else if(nums[i + 1] <  nums[i - 1])
                {
                    nums[i + 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i + 1];
                }
            }
        }
        return true;
    }
};

/*
[4,2,3]
[4,2,1]
[3,4,2,3]
*/
// tc o(n)
// sc o(1)
