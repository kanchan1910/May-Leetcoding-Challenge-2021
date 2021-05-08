class Solution {
public:
    bool is_palindrome(string s)
    {
        int n = s.length();
        for(long long i = 0; i < n / 2; i++)
        {
            if(s[i] != s[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int superpalindromesInRange(string left, string right)
    {
        long long ans = 0;
        long long l = stoll(left);
        long long r = stoll(right);
        vector<long long>store;
        for(long long i = 1; i <= 9; i++)
        {
            store.push_back(i);
        }
        
        for(long long i = 1; i <= 9999; i++)
        {
            string str1 = to_string(i);
            string str2 = str1;
            reverse(str2.begin(), str2.end());
            store.push_back(stoll(str1 + str2));
            for(int j = 0; j <= 9; j++)
            {
                string tmp = str1;
                tmp += j + '0';
                tmp += str2;
                store.push_back(stoll(tmp));
            }
        }
        for(auto x: store)
        {
            long long num = x * x;
            if(num >= l && num <= r && is_palindrome(to_string(num)) == true)
            {
                ans++;
            }
        }
        return ans;
    }
};
