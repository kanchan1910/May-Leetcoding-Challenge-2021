// vairation of the longest inceasing subsequence problem 
class Solution {
public:
    static bool com(string a, string b)
    {
        if(a.length() == b.length())
        {
            return a < b;
        }
        return a.length() < b.length();
    }
    bool fun(string str1, string str2)
    {
        int n1 = str1.length();
        int n2 = str2.length();
        int i = 0, j = 0;
        int count = 0;
        while(i < n1 && j < n2)
        {
            if(str1[i] == str2[j])
            {
                i++;
                j++;
            }
            else
            {
                count++;
                i++;
            }
            if(count > 1)
            {
                return false;
            }
        }
        while(i < n1)
        {
            // Input:
            //         ["xbc","pcxbcf","xb","cxbc","pcxbc"]
            //         Output:
            //         3
            //         Expected:
            //         5
            count++;
            i++;
        }
        return count == 1;
    }
    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(), com);
        int n = words.size();
        int dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if((words[i].length() - words[j].length()) == 1 && (fun(words[i], words[j]) == true))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = INT_MIN;
        for(auto x: dp)
        {
            ans = max(ans, x);
        }
        return ans;
    }
};
