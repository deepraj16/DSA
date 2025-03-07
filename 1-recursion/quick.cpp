#include<bits/stdc++.h> 
using namespace std ; 


int partation(int *arr,int s,int e){
    
    int current_element=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(current_element>=arr[i]){   // counting the similary elemnt also 
            count++;
        }
    }

    swap(arr[s],arr[s+count]);
    int i=s;
    int j=e;
    while(i<s+count and j>s+count){
           
            while(arr[i]<=current_element){
                i++;
            }while(arr[j]>current_element){
                j--;
            }
            if(i<s+count and j>s+count){
                swap(arr[i],arr[j]);
                i++;
                j--;
        }
    }

    return s+count;
}

void Q_sort(int *arr,int s,int e){
        if(s>=e){
            return ;
        }
      int  p=partation(arr,s,e);
      Q_sort(arr,s,p-1); 
      Q_sort(arr,p+1,e);
}
int main(){
    int arr[10]={9,8,4,5,3,2,66,12,5,1};
    int n=10; 
    Q_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
