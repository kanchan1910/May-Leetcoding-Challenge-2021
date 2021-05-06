class Solution {
public:
    TreeNode* fun(vector<int>& arr, int l, int r)
    {
        if(l > r)
        {
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = fun(arr, l, mid - 1);
        node->right = fun(arr, mid + 1, r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int>arr;
        ListNode* cur = head;
        while(cur != NULL)
        {
            arr.push_back(cur->val);
            cur = cur->next;
        }
        int n = arr.size();
        return fun(arr, 0, n - 1);
    }
};
