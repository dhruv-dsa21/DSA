class Solution {
public:
    vector<int> dfs(vector<vector<int>> &graph,string &labels,vector<int> &ans,int node,int prev){
        //hm hrr node ke liye ek vector tyyar krenge
        vector<int> curr_node(26,0);
        //uss nod ke liye jo uska label h usko 1 
        //krr denge bcoz 1 toh hoga na
        //trick:- jb hme graph quesn. me tree de 
        //rkha ho toh visited array maintain krne 
        //ki bajay hm prev variable maintain krr skte h
        curr_node[labels[node]-'a'] = 1;
        for(auto it:graph[node]){
            if(it==prev){
                continue;
            }
            vector<int> temp(26,0);
            //hrr child ek vector dega labels ka apne
            //papa ko bss hme use add krna h parent me 
                temp = dfs(graph,labels,ans,it,node);
            for(int i=0;i<26;i++){
                curr_node[i]+=temp[i];
            }
        }
        // answer vector me daal do values jo nikli hr 
        // node ke liye
        ans[node] = curr_node[labels[node]-'a'];
        return curr_node;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)  {
           vector<vector<int>> a(n);
        for(auto x:edges){
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
        //hmara answer vector 
        vector<int> ans(n,0);
         dfs(a,labels,ans,0,-1);
        return ans;
   }
};