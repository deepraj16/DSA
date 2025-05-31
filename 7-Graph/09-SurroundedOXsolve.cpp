class Solution {
public:
    // void DFS()
bool is_safe( int i,int j,vector<vector<char>>& board,  vector<vector<int>>visted,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m && board[i][j]=='O' && visted[i][j]!=0);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size(); 
        vector<vector<int>>visted(n,vector<int>(m,0)); 
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && (j==0 || j==m-1 || i==0 || i==n-1)) {
                    q.push({i,j}); 
                    visted[i][j]=0; 
                }
                else if(board[i][j]=='O'){
                     visted[i][j]=-1;
                }
                
            }
        }
        int dx[4]={0,0,-1,1}; 
        int dy[4]={-1,1,0,0}; 

        while(!q.empty()){
            auto [i , j] =q.front(); 
            q.pop(); 

            for(int k=0;k<4;k++){
                cout<<i<<j;
                if(is_safe(i+dx[k],j+dy[k] , board,visted,n,m)){
                    q.push({i+dx[k],j+dy[k]}); 
                    visted[i+dx[k]][j+dy[k]]=0; 
                }
            }

        }

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visted[i][j]==-1){
                    board[i][j]='X'; 
                }
            }
    }
     

    }
};
