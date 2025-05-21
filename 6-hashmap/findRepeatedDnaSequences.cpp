class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>stor; 
        vector<string>str;
        if(s.size()<10){
            return str;
        }
        for(int i=0;i<=s.size()-10;i++){
            string sub=s.substr(i,10);
            stor[sub]+=1;
        }
        for(auto i:stor){
            if(i.second>1){
                str.push_back(i.first);
            }
        }
        return str;
    }
};
