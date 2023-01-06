class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        long long sum = 0;
        sum = accumulate(costs.begin(),costs.end(),sum);
        if(sum<=coins){
            return costs.size();
        }
        sort(costs.begin(),costs.end());
        // if(coins<costs[0]){
        //     return 0;
        // }
        long long ans=  0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]>coins){
                break;
            }else{
                coins-=costs[i];
                ans++;
            }
            
        }
        return ans;
    }
};