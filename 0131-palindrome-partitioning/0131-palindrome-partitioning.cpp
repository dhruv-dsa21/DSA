// class Solution {
// public:
//     bool checkPalindrome(string str, int startIndex, int lastIndex){
//         while(startIndex <= lastIndex){
//             if(str[startIndex] != str[lastIndex])
//                 return false;
//             startIndex++;
//             lastIndex--;
//         }
//         return true;
//     }
//     void palindromePartition(int index, vector<string>& ds, vector<vector<string>>& output, string str){
//         if(index == str.length()){
//             output.push_back(ds);
//             return;
//         }
//         for(int i = index; i < str.length(); i++){
//             if(checkPalindrome(str, index, i)){
//                 ds.push_back(str.substr(index, i - index + 1));
//                 palindromePartition(i+1, ds, output, str);
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> output;
//         vector<string> ds;
//         palindromePartition(0, ds, output, s);
//         return output;
//     }
// };
class Solution {
public:
        bool isPalindrome(string str, int startIndex, int lastIndex){
        while(startIndex <= lastIndex){
            if(str[startIndex] != str[lastIndex])
                return false;
            startIndex++;
            lastIndex--;
        }
        return true;
    }
    void solve(int idx,int n,string &s,vector<string> temp,vector<vector<string>> &ans){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,n,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
         solve(0,n,s,temp,ans);
        return ans;
    }
};