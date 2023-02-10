class Solution {
public:
    long long int solve(long long int n){
        if(n<=1){
            return 0;
        }
      
        
        long long int opr = 0;
        
        if((n&1)==0){
            opr = 1 + solve(n>>1);
        }else{
            opr=  min(1 + solve(n+1),1 + solve(n-1));
         
        }
        return opr;
    }
    int integerReplacement(int n) {
        
        return solve(n);
    }
};