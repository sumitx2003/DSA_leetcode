class Solution {
public:
   vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int need=image[sr][sc];
        image[sr][sc]=color;

        while(!q.empty()){
              int x=q.front().first;
              int y=q.front().second;
              q.pop();

              for(auto &dir:directions){
                   int a=x+dir[0];
                   int b=y+dir[1];

                  if(a<0 || a>=m || b<0 || b>=n || image[a][b]==color || image[a][b]!=need)continue;

                  q.push({a,b});
                  image[a][b]=color;

              }
        }
        return image;
    }
};