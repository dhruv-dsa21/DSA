class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int x,int y,int z,vector<vector<int>> &dp){
        if(x==0&&y==0){
            return true;
        }
      
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if((x>0&&s1[x-1]==s3[z-1])&&(y>0&&s2[y-1]==s3[z-1])){
            return dp[x][y] = solve(s1,s2,s3,x-1,y,z-1,dp)||solve(s1,s2,s3,x,y-1,z-1,dp);
        }
       else if(x>0&&s1[x-1]==s3[z-1]){
            return dp[x][y]= solve(s1,s2,s3,x-1,y,z-1,dp);
        }
        else if(y>0&&s2[y-1]==s3[z-1]){
            return dp[x][y] = solve(s1,s2,s3,x,y-1,z-1,dp);
        }
        return dp[x][y]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        if(z!=x+y){
            return false;
        }
        return solve(s1,s2,s3,x,y,z,dp);
    }
};