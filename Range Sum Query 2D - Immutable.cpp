class NumMatrix {
public:
    int mat[202][202];
    int n, m;
    NumMatrix(vector<vector<int>>& matrix)
    {
        n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                mat[i][j] = matrix[i][j];
            }
        }
        for(int i = 1; i < n; i++)
        {
            mat[i][0] += mat[i - 1][0];
        }
        for(int j = 1; j < m; j++)
        {
            mat[0][j] += mat[0][j - 1];
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                mat[i][j] += mat[i - 1][j];
                mat[i][j] += mat[i][j - 1];
                mat[i][j] -= mat[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int ans = mat[row2][col2];
        if(row1 != 0 && col1 != 0)
        {
            ans -= mat[row1 - 1][col2];
            ans -= mat[row2][col1 - 1];
            ans += mat[row1 - 1][col1 - 1];
        }
        else if(row1 == 0 && col1 != 0)
        {
            ans -= mat[row2][col1 - 1];
        }
        else if(row1 != 0 && col1 == 0)
        {
            ans -= mat[row1 - 1][col2];
        }
        return ans;
    }
};

