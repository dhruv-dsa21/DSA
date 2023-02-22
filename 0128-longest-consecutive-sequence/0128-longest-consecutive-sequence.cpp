class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
        set<int> st;
        for(auto it:nums){
            st.insert(it);
        }
       vector<int> temp;
       temp.assign(st.begin(),st.end());
      
        int x = temp[0];
        int count = 1;
        int tempcount = 1;
        for(int i=1;i<temp.size();i++){
            if(temp[i]==x+1){
                tempcount++;
                 }
            else{
                 tempcount = 1;
              }
            count = max(count,tempcount);
            x = temp[i];
        }
        return count;
    }
};