class Solution {
public:
    string frequency_counter(string s){
        vector<pair<char,int> >conter; 
        int cnt=1;
        for(int i=0;i<s.size();i++){
              int cnt=1;
              
            while(s[i]==s[i+1]){
                cnt++; 
                i++;
            }
           
            conter.push_back({s[i],cnt});
        }
        string ans="";
        for(auto it : conter){
          ans += to_string(it.second);
          ans += it.first;
        }
        return ans;
    }
    string countAndSay(int n) {
        string s="1"; 
        for(int i=1;i<n;i++){
        string ans=frequency_counter(s);
        s=ans;
       }
        return s;
    }
};
