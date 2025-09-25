

class Solution {
  public:
    bool nonRepetitive(string S) {
        // code here.
         set<char>st; 
         char start=S[0];
         st.insert(start);
         int curr=st.size();
        for(int i=1;i<S.size();i++){
           if(start!=S[i]){
               st.insert(S[i]); 
               if(st.size()<curr+1){
                   return 0;
               }
               curr+=1; 
               start=S[i];
           }
        }
        return 1;
    }
};
