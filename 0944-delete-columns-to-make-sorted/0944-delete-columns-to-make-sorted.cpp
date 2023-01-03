class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        int m = strs.size();
        int count = 0;
        for(int i=0;i<n;i++){
            char s = strs[0][i];
            for(int j=1;j<m;j++){
                if(strs[j][i]>=s){
                    s = strs[j][i];
                }else{
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};