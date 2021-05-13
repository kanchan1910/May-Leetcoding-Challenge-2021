class Solution {
public:
    vector<string>fun(string str)
    {
        vector<string>ans;
        int n = str.length();
        if(n == 1)
        {
            return {str};
        }
        // cases like "123"
        if(str[0] != '0')
        {
            ans.push_back(str);
        }
        
        if(str[0] == '0')
        {
            // cases like "0110"
            if(str.back() == '0')
            {
                return {};
            }
            // cases like "011"
            return {"0." + str.substr(1)};
        }
        
        // for cases like 123 -- final vector would be {123, 1.23, 12.3}, but
        // for cases like 120 -- final vector would be {120} and not {120, 1.20, 12.0} as 1.20 and 12.0 are invalid 
        if(str.back() != '0')
        {
                 for(int i = 1; i < n; i++)
                    {
                        string first = str.substr(0, i);
                        string second = str.substr(i);
                        ans.push_back(first + "." + second);
                    }   
        }
        return ans;
    }
    vector<string> ambiguousCoordinates(string s) 
    {
        vector<string>ans;
        // removing parenthesis
        string str = s.substr(1, s.length() - 2);
        int n = str.length();
        
        for(int i = 1; i < n; i++)
        {
            string first = str.substr(0, i);
            string second = str.substr(i);
            
            vector<string>for_first = fun(first);
            vector<string>for_second = fun(second);
            
            for(int i  = 0; i < for_first.size(); i++)
            {
                for(int j = 0; j < for_second.size(); j++)
                {
                    ans.push_back("(" + for_first[i] + ", " + for_second[j] + ")");
                }
            }
        }
        return ans;
    }
};
