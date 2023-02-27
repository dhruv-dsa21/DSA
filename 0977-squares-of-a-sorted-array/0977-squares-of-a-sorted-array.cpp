class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        if(n==1){
            int x = pow(nums[0],2);
            return {x};
        }
        vector<int> ans;
     
        if(nums[0]>=0){
            while(j<n){
                  
            int y = pow(nums[j],2);
            ans.push_back(y);
             j++;
        
            }
            return ans;
            
        }else{
            while(i<n&&nums[i]<=0){
                i++;
            }
            j = i;
            i--;
            while(i>=0&&j<n){
                int x = pow(nums[i],2);
                int y = pow(nums[j],2);
                if(x<=y){
                    ans.push_back(x);
                    i--;
                }else if(x>y){
                    ans.push_back(y);
                    j++;
                }
            }
        }
        
  
        while(i>=0){
            int x = pow(nums[i],2);
            ans.push_back(x);
            i--;
        }
         while(j<n){
            int y = pow(nums[j],2);
            ans.push_back(y);
             j++;
        }
        return ans;
    }
};