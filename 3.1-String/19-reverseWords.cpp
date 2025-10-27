class Solution {
public:
    string reverseWords(string s) {
        int cnt=0;
        string word="";
        bool flag=false;
        stack<string>st;
        for( int i=0;i<s.size();i++){
            while(s[i]!=' '){
                word=word+s[i];
                i++;
                
                if(i>=s.size()){
                     flag=false; 
                    st.push(word);
                    break;
                }
                flag=true;
            }
            if(flag){
                flag=false; 
                st.push(word);
                word="";
            }
        }
        string sent="";
        while(!st.empty()){
            string temp=st.top(); 
            st.pop(); 
            cout<<temp<<" ";
            if(st.empty()){
                sent+=temp;
                break;
            }
            sent+=temp;
            sent+=" ";
        }
        return sent;
    }
};
