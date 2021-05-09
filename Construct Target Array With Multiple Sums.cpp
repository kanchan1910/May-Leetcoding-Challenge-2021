class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        long long n = target.size();
        priority_queue<int>pq;
        long long total_sum = 0;
        for(long long i = 0; i < n; i++)
        {
            pq.push(target[i]);
            total_sum += target[i];
        }
        while(!pq.empty())
        {
            long long max_ele = pq.top();
            pq.pop();
            if(max_ele == 1)
            {
                return true;
            }
            long long rem_sum = total_sum - max_ele;
            if(rem_sum >= max_ele)
            {
                return false;
            }
            if(rem_sum == 1)
            {
                return true;
            }
            if(rem_sum == 0)
            {
                return false;
            }
             //int biggest_after = biggest_before - remain_sum; //this will take too long if biggest is large
            //example : [2, 1000] -> [2, 998]  -> [2, 996] ....
            //So, it's better to find the last value
            long long max_now = max_ele % rem_sum;
            if(max_now < 1)
            {
                return false;
            }
            pq.push(max_now);
            total_sum -= max_ele;
            total_sum += max_now;
        }
        return true;
    }
};
