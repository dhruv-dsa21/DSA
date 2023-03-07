class DataStream {
public:
    
    int val,temp,i=0,j=0,cnt=0;
    vector<int> v;
    DataStream(int value, int k) {
      val = value;
      temp = k;
    }
    
    bool consec(int num) {
        
            bool ans = false;
          v.push_back(num);
           if(num==val){
               cnt++;
           }
        if(j-i+1<temp){
            j++;
        }else if(j-i+1==temp){
            if(cnt==temp){
                cout<<"heihi"<<endl;
                ans = true;
               }
            if(v[i]==val){
                cnt--;
               }
             i++;
            j++;
            
     }
       
       
      
            return ans;
        
        
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */