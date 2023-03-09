class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:t){
            mp[it]++;
        }
        int count = mp.size();
        int i=0,j=0;
        int n = s.size();
        string ans = "";
        int mini = 0;
        int len = INT_MAX;
        while(j<n){
           if(mp.find(s[j])!=mp.end()){
               mp[s[j]]--;
               if(mp[s[j]]==0){
                   count--;
               }
           }
            if(count==0){
                while(count==0&&i<=j){
                    char st = s[i];
                    if(j-i+1<len){
                        mini = i;
                        len = j-i+1;
                    }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                        }
                        i++;
                    }else{
                        i++;
                    }
                }
            }
            j++;
            
        }
        if(len==INT_MAX){
            return "";
        }
        ans = s.substr(mini,len);
        
           return ans; 
        
        
    }
};

//  if(mp.find(s[j])!=mp.end()){
//                 mp[s[j]]--;
//                 if(mp[s[j]]==0){
//                     count--;
//                 }else if(mp[s[j]]<0){
//                     while(mp[s[j]]<0){
//                         if(s[i]==s[j]){
//                             mp[s[j]]++;
//                         }
//                         i++;
//                     }
//                 }
//             }
//                 if(count<0){
//                     j++;
//                 }else if(count==0){
//                     int temp = j-i+1;
//                     cout<<temp<<endl;
//                     if(temp<mini){
//                         ans = s.substr(i,temp);
//                         mini = temp;
//                     }
//                     if(mp.find(s[i])==mp.end()){
//                         while(mp.find(s[i])==mp.end()){
//                             i++;
//                             mini--;
//                             ans = s.substr(i,mini);
//                         }
//                         j++;
//                     }else{
//                         mp[s[i]]++;
//                         if(mp[s[i]]==1){
//                             count++;
//                         }
//                         i++;
//                         j++;
//                     }
//                 }