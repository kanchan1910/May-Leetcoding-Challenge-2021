class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
    {
        unordered_map<string, vector<string>>m;
        int n = paths.size();
        vector<vector<string>>ans;
        for(string str: paths)
        {
            string dir;
            int i = 0;
            while(i < str.length() && str[i] != ' ')
            {
                dir.push_back(str[i]);
                i++;
            }
            i++;
            while(i < str.length())
            {
                
                string filename, content;
                bool f = false;
                while(i < str.length() && str[i] != ' ')
                {
                    if(str[i] != ')')
                    {
                             if(f == true)
                            {
                                content.push_back(str[i]);
                            }
                            else
                            {
                                if(str[i] == '(')
                                {
                                    f = true;
                                }
                                else
                                {
                                    filename.push_back(str[i]);
                                }
                            }   
                    }
                    i++;
                }
                m[content].push_back(dir + "/" + filename);
                i++;
            }
        }
            for(auto x : m)
            {
                if(x.second.size() > 1)
                {
                    ans.push_back(x.second);
                }
            }
        return ans;
    }
};
