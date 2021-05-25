class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        // as given in the problem statement that given RPN expression is always valid so we don't have to check for the side edge cases like empty stack situation
        stack<int>s;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")
            {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                if(tokens[i] == "+")
                {
                    s.push(first + second);
                }
                else if(tokens[i] == "-")
                {
                    s.push(second - first);
                }
                else if(tokens[i] == "*")
                {
                    s.push(first * second);
                }
                else if(tokens[i] == "/")
                {
                    s.push(second / first);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
     return s.top();   
    }
};
// tc o(n)
// sc o(n)
