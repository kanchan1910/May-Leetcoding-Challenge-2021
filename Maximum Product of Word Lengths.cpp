class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int ans = 0;
        int n = words.size();
        vector<vector<bool>>vis(n, vector<bool>(26, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < words[i].length(); j++)
            {
                vis[i][words[i][j] - 'a'] = true;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int n1 = words[i].length();
            for(int j = i + 1; j < n; j++)
            {
                int f = 0;
                int n2 = words[j].length();
                for(int k = 0; k < 26; k++)
                {
                    if(vis[i][k] ==  true && vis[j][k] == true)
                    {
                        f = 1;
                        break;
                    }
                }
                if(f == 0)
                {
                     ans = max(ans, n1 * n2);
                }
            }
        }
        return ans;
    }
};
// tc o(n * n * 26)
// sc o(n * 26)

// brute force solution
// tc o(n * n * n * n)
// sc o(1)
