class Solution {
public:
    int minOperations(int n) {
        int count = 0;
        while(n>0){
            int low = floor(log2(n));
            int high = ceil(log2(n));
            
            int tlow = n - pow(2,low);
            int thigh = pow(2,high)-n;
            
            if(tlow<thigh){
                n = tlow;
            }else{
                n = thigh;
            }
            count++;
        }
        
        return count;
//  if (n == 0) return 0;
//         int low = floor(log2(n));
//         int high = ceil(log2(n));
        
//         int tlow = n - pow(2,low);
//         int thigh = pow(2,high) - n;
        
//         if(tlow > thigh) return 1+minOperations(thigh);
//         return 1+minOperations(tlow);
    }
};