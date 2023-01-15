// class Solution {
// public:
//     bool dfs(int node,int start,vector<int> &vis,vector<int>& vals,vector<vector<int>> &graph){
//         bool ans = true;
//         vis[node] = true;
//         for(auto it:graph[node]){
//             if(vis[it]==0){
//                 if(start<vals[it]){
//                     return false;
//                 }
                
//                 ans = ans||dfs(it,start,vis,vals,graph);
//             }
//         }
//         return ans;
//     }
//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//         int n = vals.size();
//         vector<vector<int>> graph(n);
//         for(auto it:edges){
//             graph[it[0]].push_back(it[1]);
//             graph[it[1]].push_back(it[0]);
//         }
//         int count = 0;
//         for(int i=0;i<n;i++){
//             vector<int> vis(n,0);
//             int start = vals[i];
//             if(dfs(i,start,vis,vals,graph)){
//                 count++;
//             }
//         }
//         count = count/2;
//         return n+count;
//     }
// };

class Solution {
public:
	int find(vector<int>& y,int i) {
		if(i==y[i]) return i;
		y[i]=find(y,y[i]);
		return y[i];
	}
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(),m=edges.size(),ans=0;
		vector<vector<int>> x(n);
		vector<int> y(n);
		for(int i=0;i<n;i++){
			y[i]=i;
			x[i]={vals[i],1};
		}
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		});
		for(int i=0;i<m;i++){
			int a=find(y,edges[i][0]);
			int b=find(y,edges[i][1]);
			if(x[a][0]!=x[b][0]){
				if(x[a][0]>x[b][0]) y[b]=a;
				else y[a]=b;
			}
			else{
				y[a]=b;
				ans+=x[a][1]*x[b][1];
				x[b][1]+=x[a][1];
			}
		}
		return ans+n;
	}
};