class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto it:word1){
            mp1[it]++;
        }
        for(auto it:word2){
            mp2[it]++;
        }
        //TC:-O(26*26);
        //Characters 26 hi h toh hm iss trah se loop krenge
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                char c1 = i + 'a';
                char c2 = j+'a';
                // ab agr dono chr maps me mill gye toh chle
                if(mp1.count(c1)&&mp2.count(c2)){
                    // sbse pehle count km kre dono ka agr mp[c]==0 toh erase                        kre taaki size shi nikle
                    mp1[c1]--;
                    mp2[c2]--;
                    if(mp1[c1]==0){
                        mp1.erase(c1);
                      }
                    if(mp2[c2]==0){
                        mp2.erase(c2);
                      }
                    //dono maps me apas ke chars add kre
                    mp1[c2]++;
                    mp2[c1]++;
                    //agr size same aye toh true return kre
                    if(mp1.size()==mp2.size()){
                        return true;
                    }
                    // nhi aata h toh wapas se reverse kre process
                    if(--mp1[c2]==0){
                        mp1.erase(c2);
                    }
                    if(--mp2[c1]==0){
                        mp2.erase(c1);
                    }
                    mp1[c1]++;
                    mp2[c2]++;
                }
            }
        }
        return false;
    }
};