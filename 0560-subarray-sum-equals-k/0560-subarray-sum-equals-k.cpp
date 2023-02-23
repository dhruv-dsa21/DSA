class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n==1){
            if(k!=nums[0]){
                return 0;
            }
        }
        unordered_map<int,int> mp;
        int prefixsum = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            
            if(prefixsum==k){
                cout<<"hi"<<endl;
                count++;
            }
            if(mp.find(prefixsum-k)!=mp.end()){
                cout<<"hello"<<endl;
                count+=mp[prefixsum-k];
            }
              mp[prefixsum]++;  
            }
        
        return count;
        
        
    }
};