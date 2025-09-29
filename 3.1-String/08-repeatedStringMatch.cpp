class Solution {
public:
    int string_case_1(string a,string b){
          for(int i=0;i<a.size();i++){
            string ch=a.substr(i,b.size()); 
            if(ch==b){
                return 1;
            }
        }
        return -1;      
    }
    int string_case_2(string a,string b){
            string conver_string="";
            int index=0;
            while(conver_string.size() < b.size()*4 ){
            if( conver_string.size() >= b.size() && string_case_1(conver_string,b)!=-1){
                    return index;
                }
                conver_string = conver_string + a ;
                index++;
            }
            return -1;
    }

    int repeatedStringMatch(string a, string b) {
        
            // two case for given input starting 
            // case-1 when a.size() >= b.size()
            // case-2 when a.size() < b.size()
           
        if(a.size()> b.size()){
            int index=string_case_1(a,b);
           if(index!=-1){
            return string_case_1(a,b);
           }
            a=a+a;
           for(int i=0;i<a.size();i++){
            string ch=a.substr(i,b.size()); 
            if(ch==b){
                return 2;
            }
        }
        return -1;  
           
        }
        else{
            return string_case_2(a,b);
        }
        }

    
};
