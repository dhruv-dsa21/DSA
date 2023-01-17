class Solution {
public:
    int func(int idx,string&s,char ch,vector<vector<int>>&dp){
        int n=s.size();
		//If our index idx is more than n then we will return 0 as no operation can be done
        if(idx>=n){
            return 0;
        }
		//If we have already visited the index and char we would simply return its value
        if(dp[idx][ch-'0']!=-1){
            return dp[idx][ch-'0'];
        }
		//If we have our prev char as '0' then we have 2 choices to toggle it or to move to next idx
        int res1=1e9,res2=1e9;
        if(ch=='0'){
            if(s[idx]=='0'){
                res1=func(idx+1,s,s[idx],dp);
                res2=func(idx+1,s,'1',dp)+1;
            }
            else{
                res1=func(idx+1,s,s[idx],dp);
                res2=func(idx+1,s,'0',dp)+1;
            }
        }
		
		//If we have our prev char as '1' then we will simply 
		//toggling every '0' char and adding one operation to it
        else{
            if(s[idx]=='0'){
                res1=func(idx+1,s,'1',dp)+1;
            }
            else{
                res1=func(idx+1,s,s[idx],dp);
            }
        }
        return dp[idx][ch-'0']=min(res1,res2);
    }
    
    int minFlipsMonoIncr(string s) {
	//First we will create a 2d vector of size of string.size()*2
        vector<vector<int>>dp(s.size(),vector<int>(2,-1));
		//Now we will call our recursive function 
        int ans=func(0,s,'0',dp);
        return ans;
        
    }
};