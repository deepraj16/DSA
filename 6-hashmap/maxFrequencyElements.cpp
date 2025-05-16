class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m ; 
        int n=nums.size();
        int maxocc=0;
        for(int i=0;i<n;i++){
           m[nums[i]]++;
           maxocc=max(maxocc,m[nums[i]]);
           cout<<m[nums[i]]<<" ";
        }
        cout<<maxocc;
        int maxi=0; 
       for(auto &i: m){
        if(i.second  == maxocc){
            maxi+=maxocc;
        }
       }
        return maxi;
    }
};
