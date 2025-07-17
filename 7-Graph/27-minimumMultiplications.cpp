// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
       // priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>q; 
        vector<int>cost(1e5,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,start});
        //cost[start]=0;
        long long int MOD=100000;
        while(!q.empty()){
            int time_=q.front().first;
            int node=q.front().second; 
            q.pop(); 
            
            if (node == end){
              return time_;   
            } 
            
            for(auto it:arr){
                int new_cost=(node*it)%MOD;
                int new_time=(time_+1)%MOD ;
                if(cost[new_cost]>new_time){
                    cost[new_cost]=new_time;
                    q.push({new_time,new_cost});
                }
        
            }
            
            
        }
        return -1;
    }
};
