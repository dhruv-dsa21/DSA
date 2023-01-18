class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        //concept:-prefix sum
        //Refer this editorial in case of doubt:-
        //https://leetcode.com/problems/increment-submatrices-by-one/discuss/3053405/Easy-to-                     Understand-oror-Prefix-Sum-oror-With-Explanation-oror-Not-brute-force-oror-C%2B%2B-Solution
        vector<vector<int>> matrix(n,vector<int>(n+1,0));
        for(int i=0;i<queries.size();i++){
            vector<int> data = queries[i];
            int r1 = data[0];
            int c1 = data[1];
            int r2 = data[2];
            int c2 = data[3];
            //We will increment every value by 1 in column c1 from r1 to r2.
            //after that we will decrement value by 1 in column next to c2 from r1 to r2 
            //so that values afte the query will not be affected by prefix sum which
            //we will implement next.
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