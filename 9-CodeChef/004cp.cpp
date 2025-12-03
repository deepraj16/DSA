class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";

        for(auto it :s){
            if (isalnum(it)) {
               char ch = tolower(it);
                ans+=ch;
            }
        }
        int n=ans.size();
        for(int i=0;i<ans.size()/2;i++){
            if(ans[i] != ans[n-i-1]){
                return false;
            }
        }
        return true;
    }
};
