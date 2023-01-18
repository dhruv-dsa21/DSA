class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n,vector<int>(n+1,0));
        for(int i=0;i<queries.size();i++){
            vector<int> data = queries[i];
            int r1 = data[0];
            int c1 = data[1];
            int r2 = data[2];
            int c2 = data[3];
            
         for(int i = r1;i<=r2;i++){
             matrix[i][c1]+=1;
             matrix[i][c2+1]-=1;
         }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] = matrix[i][j] + matrix[i][j-1];
            }
        }
        for(int i=0;i<n;i++){
            matrix[i].pop_back();
        }
        return matrix;
    }
};