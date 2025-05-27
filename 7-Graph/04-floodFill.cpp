class Solution {
public:
    bool is_safe(vector<vector<int>>& image,int oldcolor,int n,int m,int sr,int sc){
        return (sr>=0 && sc>=0 && sr<n && sc<m && image[sr][sc]==oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

       
        int n=image.size(); 
        int m=image[0].size();
        int oldcolor=image[sr][sc]; 


           if (oldcolor == color) return image;
        queue<pair<int,int>>q; 
        
        q.push({sr,sc}); 
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        image[sr][sc] = color;//
        while(!q.empty()){
            pair<int,int> p=q.front(); 
            q.pop(); 
            int k=p.first; 
            int l=p.second;
            for(int i=0;i<4;i++){
                if(is_safe(image,oldcolor,n,m,k+dx[i] , l+dy[i])){
                   q.push({k+dx[i],l+dy[i]}); 
                   image[k+dx[i]][l+dy[i]]=color;
                }
            }
        }
        
        return image;
    }
};
