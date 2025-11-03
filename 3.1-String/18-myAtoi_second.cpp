class Solution {
public:
    int myAtoi(string s) {
        int flag=0;
        long long ans=0; 
        int countsub=0;
        string symoble="";
        bool sy=false;
        for(int i=0;i<s.size();i++){

            if((s[i]=='+' || s[i]=='-' )){
                if(sy==true){
                    break;
                }
                symoble=s[i];
                sy=true;
            }
            if(isalpha(s[i]) || s[i]=='.' || (sy && s[i]==' ')){
                break;
            }
            
             if(ans> (INT_MAX-curr)/10 ){
                if(symoble[0]=='-') return INT_MIN;
                return INT_MAX;
             }
             ans=ans*10+curr;
             i++;
             }


             if(flag==1){
                break;
             }
             
        }
        

         if(symoble[0]=='-') return ans*-1;
        return (int)ans;
    }
};
