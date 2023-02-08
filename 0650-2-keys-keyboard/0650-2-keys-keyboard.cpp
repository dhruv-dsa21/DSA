class Solution {
public:
    int solve(int &n,int steps,int value,int copy){
        if(steps>n||value>n){
            return INT_MAX;
        }
        if(value==n){
            return steps;
        }
      
        return min(solve(n,steps+1,value+copy,copy),solve(n,steps+2,2*value,value));
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        
        
        return solve(n,1,1,1);
        
    }
};