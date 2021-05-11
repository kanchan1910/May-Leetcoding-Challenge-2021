class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        // sliding window
        int n = cardPoints.size();
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += cardPoints[i];
        }
        int window = 0;
        int left = 0, right = n - k;
        int ans;
        for(int i = left; i < right; i++)
        {
            window += cardPoints[i];
        }
        ans = total - window;
        for(int i = 0; i < k; i++)
        {
            window -= cardPoints[left];
            window += cardPoints[right];
            left++;
            right++;
            ans = max(ans, total - window);
        }
        return ans;
    }
};
