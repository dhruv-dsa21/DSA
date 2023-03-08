class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
         int n = nums.size();
        long long sum = 0;
        int i=0;
        deque<pair<long,long>> q;
        int ans = INT_MAX;
        while(i<n){
           sum+=nums[i];
            if(sum>=k){
                ans = min(ans,i+1);
            }
           while(q.size()>0&&sum-q.front().first>=k){
               int x = q.front().second;
               ans = min(ans,i-x);
               q.pop_front();
           }
            while(q.size()>0&&sum<q.back().first){
                q.pop_back();    
            }
            q.push_back({sum,i});
            i++;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};