/*
There are n trees in a forest. The heights of the trees is stored in array tree[], where tree[i] denotes the height of the ith tree in the forest. If the ith tree is cut at a height H, then the wood collected is tree[i] - H, provided tree[i] > H. If the total woods that needs to be collected is exactly equal to k, find the height H at which every tree should be cut (all trees have to be cut at the same height). If it is not possible then return -1 else return H.

Example 1:

Input:
n = 5, k = 4
nums[] = {2, 3, 6, 2, 4}
Output: 3
Explanation: Wood collected by cutting trees
at height 3 = 0 + 0 + (6-3) + 0 + (4-3) = 4
hence 3 is to be subtracted from all numbers.
Since 2 is lesser than 3, nothing gets
subtracted from it.
Example 2:

Input:
n = 6, k = 8
nums[] = {1, 7, 6, 3, 4, 7}
Output: 4
Explanation: Wood collected by cutting trees
at height 4 = 0+(7-4)+(6-4)+0+0+(7-4) = 8
Your Task:
Your task is to complete the function find_height(). This function takes the array tree[ ], and the integers n and k as input parameters and returns the height at which trees have to be cut. If no positive integer value of height is possible, return -1.


Expected Time Complexity: O(n log h)
Expected Auxiliary Space: O(1)


Constraints: 
1 <= n <= 104
1 <= tree[i] <= 103
1 <= k <= 107
*/
   int correct(int tree[], int n, int k, int h)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(tree[i] > h)
            {
                sum += (tree[i] - h);
            }
        }
        if(sum < k)
        {
            return 1;
        }
        else if(sum == k)
        {
            return 2;
        }
        return 3;
    }
    int find_height(int tree[], int n, int k)
    {
        int l = 0, r = *max_element(tree, tree + n);
        int ans = -1;
        while(l <= r)
        {
            int mid = l +(r - l) / 2;
            if(correct(tree, n, k, mid) == 2)
            {
                ans = mid;
                break;
            }
            else if(correct(tree, n, k, mid) == 1)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(ans == -1)
        {
            return -1;
        }
        int final_sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(tree[i] >= ans)
            {
                final_sum += (tree[i] - ans);
            }
        }
        return final_sum == k ? ans : -1;
    }
    
    
    // or
    
    
     bool correct(int tree[], int n, int k, int h)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(tree[i] > h)
            {
                sum += (tree[i] - h);
            }
        }
        if(sum >= k)
        {
            return true;
        }
        return false;
    }
    int find_height(int tree[], int n, int k)
    {
        int l = 0, r = *max_element(tree, tree + n);
        int ans = -1;
        while(l <= r)
        {
            int mid = l +(r - l) / 2;
            if(correct(tree, n, k, mid) == true)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(ans == -1)
        {
            return -1;
        }
        int final_sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(tree[i] >= ans)
            {
                final_sum += (tree[i] - ans);
            }
        }
        return final_sum == k ? ans : -1;
    }
