class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m; 
        for(int i=0;i<s.size();i++){
            m[s[i]]+=1;
        }
        int even=0,odd=0;
        for(auto i:m){
            if(i.second % 2 ==0){
                even+=i.second;
            }
            else{
                    if(odd!=0){
                        odd--;
                    }
                odd+=i.second;
            }
        }
        int total=even+odd;
    return total;

        
    }
};
