class DataStream {
public:
    deque<int> q;
    unordered_map<int,int> mp;
    int val,temp;
    DataStream(int value, int k) {
      val = value;
       temp = k;
    }
    
    bool consec(int num) {
        
        q.push_back(num);
        mp[num]++;
        if(q.size()==temp){
            if(mp[val]==temp){
                  mp[q.front()]--;
            if(mp[q.front()]==0){
                mp.erase(q.front());
            }
             q.pop_front();
                return true;
            }
             mp[q.front()]--;
            if(mp[q.front()]==0){
                mp.erase(q.front());
            }
             q.pop_front();
          
        }
       
       
      
            return false;
        
        
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */