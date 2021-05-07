class Solution {
public:
    int dp[501][501];
    int lcs(string word1, string word2, int n1, int n2)
    {
        if(n1 == 0 || n2 == 0)
        {
            return 0;
        }
        if(dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }
        if(word1[n1 - 1] == word2[n2 - 1])
        {
             dp[n1][n2] = 1 + lcs(word1, word2, n1 - 1, n2 - 1);
        }
        else
        {
             dp[n1][n2] = max(lcs(word1, word2, n1 - 1, n2), lcs(word1, word2, n1, n2 - 1));
        }
        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.length();
        int n2 = word2.length();
        memset(dp, -1, sizeof(dp));
        int len = lcs(word1, word2, n1, n2);
        return (n1 + n2 - 2 * len);
    }
};


// first attempt which proved to be wrong..
class Solution {
public:
    
    /*
    WRONG IN THIS CASE  
    "sea"
    "ate"
    */
    
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<int>f1(26, 0);
        vector<int>f2(26, 0);
        for(int i = 0; i < n1; i++)
        {
            f1[word1[i] - 'a']++;
        }
        for(int i = 0; i < n2; i++)
        {
            f2[word2[i] - 'a']++;
        }
        int steps = 0;
        for(int i = 0; i < 26; i++)
        {
            if(f1[i] != f2[i])
            {
                steps += abs(f1[i] - f2[i]);
            }
        }
        return steps;
    }
};

