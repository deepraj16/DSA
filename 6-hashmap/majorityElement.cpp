class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m ;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]+=1; 
        }
        int n=nums.size();
        int c=n/3;
        vector<int>ans;
        for(auto i:m){
            if(i.second>c){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
