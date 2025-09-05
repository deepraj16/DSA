class Solution {
public:
    int characterReplacement(string s, int k) {


        //want to find the logest string with given  
        int r=0,l=0,max_len=0 ; 
        int n=s.size();
        int ans=0;
        vector<int>hash(26,0);
        while(r<n){
            hash[s[r]-'A']++ ;
            max_len = max(max_len ,hash[s[r]-'A']); 
            if((r-l+1) - max_len > k ){
                hash[s[l]-'A'] -- ; 
                l++;
               
            }
            ans=max(ans,r-l+1);

            r++;
        }
        return ans;
    }
};
