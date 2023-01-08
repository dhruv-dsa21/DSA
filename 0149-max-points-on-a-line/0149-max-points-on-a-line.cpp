class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2){
            return points.size();
        }
        int n = points.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int count = 2;
                for(int k=0;k<n;k++){
                    
                    int x = points[k][0];
                    int y = points[k][1];
                    if(k==i||k==j){
                        continue;
                    }
                    if((y2-y1)*(x-x1)==(y-y1)*(x2-x1)){
                        count++;
                    }
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};