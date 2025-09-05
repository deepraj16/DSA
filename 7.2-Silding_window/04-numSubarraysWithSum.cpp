class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int n=nums.size();
        int sum=0;
        for(int start=0 ; start<n; ++start ){
             sum=0;
          
            for(int end=start ; end<n; ++end){
                sum+=nums[end]; 
                
                if(sum == goal) 
                {
                    ans++;
                }
                else if(sum > goal){
                    break;
                }
            }
         
           
        }
        return ans;
    }
};
