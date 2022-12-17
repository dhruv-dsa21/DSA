class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="/"||tokens[i]=="*"||tokens[i]=="-"){
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                if(tokens[i]=="+"){
                    long long x = a + b;
                    st.push(x);
                }
                else if(tokens[i]=="-"){
                    long long x = a-b;
                    st.push(x);
                        
                }
                else if(tokens[i]=="*"){
                    long long x = a*b;
                    st.push(x);
                }
                else if(tokens[i]=="/"){
                    long long x = a/b;
                    st.push(x);
                }
            }else{
                long long num;
                num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};