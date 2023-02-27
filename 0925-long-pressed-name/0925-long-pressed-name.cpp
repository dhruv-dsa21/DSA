class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        int i=0,j=0;
        
        while(i<m&&j<n){
            if(name[i]==typed[j]){
                i++;
                j++;
            }else if(name[i]!=typed[j]){
                if(i!=0&&name[i-1]==typed[j]){
                    j++;
                }else{
                    return false;
                }
            }
            
        }
        while(j<n){
            if(typed[j]!=typed[j-1]){
                return false;
            }
            j++;
        }
       
        return i==m;
        
    }
};