class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
            string test=strs[0]; 
            string ans="";
            for(int i =1;i<strs.size();i++){

                int n = min(test.size(),strs[i].size());
                cout<<n<<endl;
                for(int j=0;j<n;j++){

                    if(strs[i][j] == test[j] ){
                        ans+=test[j];
                    }
                    else{
                        break;
                    }
                      
                }
                test = ans ;
                 ans="";
            }
            return test;
    }
};
