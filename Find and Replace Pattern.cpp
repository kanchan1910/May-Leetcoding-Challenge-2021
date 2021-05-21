class Solution {
public:
    bool fun(string a, string b)
    {
        if(a.length() != b.length())
        {
            return false;
        }
        int len = a.length();
        unordered_map<char, char>m1, m2;
        for(int i = 0; i < len; i++)
        {
            if(m1.find(a[i]) == m1.end() && m2.find(b[i]) == m2.end())
            {
                m1[a[i]] = b[i];
                m2[b[i]] = a[i];
            }
            else
            {
                if(m1[a[i]] != b[i] || m2[b[i]] != a[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>ans;
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            if(fun(words[i], pattern) == true)
            {
             ans.push_back(words[i]);   
            }
        }
        return ans;
    }
};
