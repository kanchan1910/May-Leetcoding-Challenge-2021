class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        vector<vector<string>>ans;
        int i = 0;
        sort(products.begin(), products.end());
        string search = "";
        while(i < searchWord.length())
        {
            search += searchWord[i];
            vector<string>tmp;
            for(int j = 0; j < products.size(); j++)
            {
                string sub = products[j].substr(0, i + 1);
                if(sub == search && tmp.size() != 3)
                {
                    tmp.push_back( products[j]);
                }
            }
            ans.push_back(tmp);
            i++;
        }
        return ans;
    }
};




class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        vector<vector<string>>ans;
        int i = 0;
        int m = products.size();
        sort(products.begin(), products.end());
        string search = "";
        while(i < searchWord.length())
        {
            search += searchWord[i];
            vector<string>tmp;
            int index =lower_bound(products.begin(),products.end(),search)-products.begin();
            for(int j = index ; j < min(index + 3, m); j++)
            {
                if(products[j].substr(0, i + 1) == search)
                {
                    tmp.push_back(products[j]);
                }
                else
                {
                    break;
                }
            }
            ans.push_back(tmp);
            i++;
        }
        return ans;
    }
};
