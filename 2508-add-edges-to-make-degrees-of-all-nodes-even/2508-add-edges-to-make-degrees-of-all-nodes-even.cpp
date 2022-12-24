class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
       
     vector<unordered_set<int>> adj(n+1);
        for(auto it:edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
       //mast Quesn.
       //Yha pe sbse pehle odd degree wale nodes 
       //nikalke store krwao vector me 
        vector<int> odds;
       for(int i=1;i<=n;i++){
           if(adj[i].size()%2!=0){
               odds.push_back(i);
           }
       }
        //agr odd degree edges ka count>4 h 
        //toh koi use nhi h hme 2 se zyada edges 
        //lgegi isliye return false
        //3 odd edges rhegi toh bhi hm saare nodes
        //ko even degree nhi krr payenge
        if(odds.size()>4||odds.size()%2!=0){
            return false;
        }
        //now 2 case rh gye jb hmari edges 4 aur 2 h
        else if(odds.size()==4){
            //for 4
            int a,b,c,d;
            a = odds[0];
            b = odds[1];
            c = odds[2];
            d = odds[3];
            //agr a---b se connect ho jaye
            //aur c---d se toh sb even degree ho jayega
            //same baaki cases explore kre
            if(adj[a].find(b)==adj[a].end()&&adj[c].find(d)==adj[c].end()){
                return true;
            }
            if(adj[a].find(c)==adj[a].end()&&adj[b].find(d)==adj[b].end()){
                return true;
            }
            if(adj[a].find(d)==adj[a].end()&&adj[b].find(c)==adj[b].end()){
                return true;
            }
            return false;
        }
        else if(odds.size()==2){
            // if 2 odd degree nodes h
            // toh iska matlab ya toh voh dono
            //apas me connected h ya nhi h
            
            int a,b;
            a = odds[0];
            b = odds[1];
            //if apas me nhi connected h
            //toh connect krr do :-)
            if(adj[a].find(b)==adj[a].end()){
                return true;
            }else{
                //nhi toh phir baaki nodes explore kro
                //aur ek aisa node dekho jo dono se
                //connected nhi h mil jaye toh connect krr do
               
                // refer this:- https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/discuss/2923490/Easy-idea-with-picture-oror-adjacency-list-with-hashset-oror-c%2B%2B
                
                for(int i=1;i<=n;i++){
                    if(adj[a].find(i)==adj[a].end()&&adj[b].find(i)==adj[b].end()){
                        return true;
                    }
                }
                return false;
            }
        }
        return true;
    }
};