class RandomizedSet {
public:
    unordered_set<int> st;
//     template<typename S>;
//     auto select_random(const S &st, size_t n) 
//     {
//         auto it = begin(st);
  
//         advance(it,n);
//         return it;
//     }
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            st.insert(val);
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(st.find(val)!=st.end()){
            st.erase(val);
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
       int a = rand() % st.size();
        auto it = st.begin();
        
        while(a--)
            it++;
        
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */