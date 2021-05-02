class Solution {
public:
    static bool com(vector<int>&a, vector<int>& b)
    {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses)
    {
        int n = courses.size();
        sort(courses.begin(), courses.end(), com);
        if(n == 1)
        {
            if(courses[0][0] > courses[0][1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        int cur_time = 0;
        priority_queue<int>pq;
        for(int i = 0; i < n; i++)
        {
            if(cur_time + courses[i][0] <= courses[i][1])
            {
                pq.push(courses[i][0]);
                cur_time += courses[i][0];
            }
            else
            {
                if(!pq.empty() && pq.top() > courses[i][0])
                {
                    int top = pq.top();
                    pq.pop();
                    cur_time -= top;
                    cur_time += courses[i][0];
                    pq.push(courses[i][0]);
                }
            }
        }
       return pq.size(); 
    }
};
