class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m ;
        int c=(nums.size())/3;
        set<int>st;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]+=1; 
            if(m[nums[i]]>c){
                st.insert(nums[i]);
            }
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
