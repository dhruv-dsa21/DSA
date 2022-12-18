class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack <pair<int,int>> st;
         for(int i = temperatures.size()-1;i>=0;i--){
                 if(st.size()==0){
                         ans.push_back(0);
                 }
                  else if(st.size()>0&&temperatures[i]<st.top().first){
                         ans.push_back(st.top().second-i);
                 }
                  if(st.size()>0&&temperatures[i]>=st.top().first){
                         while(st.size()>0&&temperatures[i]>=st.top().first){
                                 st.pop();
                         }
                           if(st.size()==0){
                         ans.push_back(0);
                      }else{
                        ans.push_back(st.top().second-i);
                     }
                }
               
                
                 st.push({temperatures[i],i});
                 
         }
           reverse(ans.begin(),ans.end());
        return ans;
    }
};