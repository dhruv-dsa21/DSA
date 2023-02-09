class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int x,int y,int z){
        if(x==0&&y==0){
            return true;
        }
        if((x>0&&s1[x-1]==s3[z-1])&&(y>0&&s2[y-1]==s3[z-1])){
            return solve(s1,s2,s3,x-1,y,z-1)||solve(s1,s2,s3,x,y-1,z-1);
        }
       else if(x>0&&s1[x-1]==s3[z-1]){
            return solve(s1,s2,s3,x-1,y,z-1);
        }
        else if(y>0&&s2[y-1]==s3[z-1]){
            return solve(s1,s2,s3,x,y-1,z-1);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.size();
        int y = s2.size();
        int z = s3.size();
        if(z!=x+y){
            return false;
        }
        return solve(s1,s2,s3,x,y,z);
    }
};