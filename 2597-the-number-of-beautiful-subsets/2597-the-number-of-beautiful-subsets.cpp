class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        vector<int> visited(1001, 0);
        int count = 0;
        
        function<int(int)> solve = [&](int i) -> int {
            // if we reach the end
            if(i == nums.size()) {
                if(count > 0) return 1;
                return 0;
            }
            
            int result = 0;
            
            // don't choose the current element
            result += solve(i+1);
            
            // choose the current element
            if(nums[i]-k<1 or nums[i]-k>1000 or (visited[nums[i]-k]==0)) {
                visited[nums[i]]++;
                count++;
                result += solve(i+1);
                visited[nums[i]]--;
                count--;
            }
            
            return result;
        };
        
        return solve(0);
    }
};
// class Solution {
// public:

//     int solve(vector<int> &nums,vector<int> temp,int &n,int idx,int &k){
//         if(idx==n){
//             return 0;
//         }
//         int p = nums[idx];
//         int flag = 0,pick=0,nopick=0;
//         int x = temp.size();
//         for(int i=0;i<temp.size();i++){
//             if(abs(p-temp[i])==k){
//                 flag = 1;
//                 break;
//             }
//         }
//         // if(dp[idx][x]!=-1){
//         //     return dp[idx][x];
//         // }
       
//         if(flag==0){
//             temp.push_back(p);
//            pick= 1 + solve(nums,temp,n,idx+1,k);
//             temp.pop_back();
//         }
//         nopick=solve(nums,temp,n,idx+1,k);
//         return  pick + nopick;
//     }
//     int beautifulSubsets(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         vector<int> temp;
//         return solve(nums,temp,n,0,k);
        
        
        
//     }
// };