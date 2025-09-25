class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        for(auto it:s){
           if(it == '(')
           {
             if(count>0){
               ans+=it;
            }
             count++;
           }

         else if(it==')'){
            count--;
            if(count>0){
                ans+=it;
            }
            
           }

        }
        return ans;
    }
};
