class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int word[26]={0}; 
        for(auto i : s){
            word[i-'a']+=1;
        }
        for(auto i:t){
            if(--word[i-'a']<0){
                return false;
            }
        }
        return true;
    }
};
