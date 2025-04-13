#include<bits/stdc++.h> 
using namespace std ;

vector<int> samestfromright(vector<int>nums ,int n){
    stack<int>s; 
    s.push(-1); 
    vector<int>ans(n); 
    for(int i=n-1;i>=0;i--){
        int curr_elem=nums[i]; 
        while(curr_elem <= nums[s.top()] ){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int>samestfromleft(vector<int>nums ,int n){
    stack<int>s; 
    s.push(-1); 
    vector<int>ans(n); 
    for(int i=0;i<n;i++){
        int curr_elem=nums[i]; 
        while(curr_elem <= nums[s.top()] ){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
int largest_rectangle(vector<int>nums , int n){
    vector<int>next= samestfromright(nums,n); 
    vector<int>right= samestfromleft(nums,n); 

     int area=INT_MIN; 
     for(int i=0;i<n;i++){
        int height=nums[i]; 
        if(next[i]==-1){
            next[i]=n;
        }

        int base=next[i]-right[i]-1; 
        int newarea=height*base; 
        area = max(area,newarea);
     }
return area;
}
int main(){
    vector<vector<int>>nums={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
// vector<int>test={2,5,6,2,3};
//     cout<<largest_rectangle(test,6);
 int area = largest_rectangle(nums[0],4);
 cout<<area;
 cout<<endl; 
 for(int i=1;i<4;i++){
    for(int j=0;j<4;j++){
        if(nums[i][j]!=0){
            nums[i][j]=nums[i-1][j]+nums[i][j];
        }
        else{
            nums[i][j]=0;
        }
    }
  
    int new_area=largest_rectangle(nums[i],4); 
    area=max(area,new_area);
    cout<<new_area<<endl;
 }
 cout<<endl;
 for(int i=0;i<nums.size();i++){
    for(int j=0;j<nums[i].size();j++){
        cout<<nums[i][j]<<" ";
    }
    cout<<endl;
}
cout<<area<<endl;
}
