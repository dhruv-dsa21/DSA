class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> st;
        int num = 1;
        for(auto it:nums){
            st.insert(it);
        }
        for(auto it:st){
            if(st.find(num)!=st.end()){
                num = num*2;
            }
        }
        return num;
    }
};