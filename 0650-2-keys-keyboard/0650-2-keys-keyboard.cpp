class Solution {
public:
    int solve(int &n,int value,int copy){
        if(value>n){
            return 1e8;
        }
        if(value==n){
            return 1;
        }
        int fstep = 0;
        int sstep = 0;
        fstep = 1+solve(n,value+copy,copy);
        sstep = 2+solve(n,2*value,value);
       
        return min(fstep,sstep);
    }
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        
        
        return solve(n,1,1);
        
    }
};