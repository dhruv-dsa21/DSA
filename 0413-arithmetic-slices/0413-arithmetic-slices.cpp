class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=  0;
        int start = 0,end = 1;
        int k = 0;
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            int diff = nums[end]-nums[start];
            while(i+1<n&&nums[i+1]-nums[i]==diff){
                end++;
                i++;
            }
             k = end-start+1;
            if(k>=3){
                
                count+= (k-2)*(k-2+1)/2;
                cout<<"hi"<<endl;
             
            }
               start = end;
                end++;
               
        }
        return count;
    
    }
};