class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>>adj;  // traversal
        unordered_map<int,int>ctp; // child to parent

        for(int i=0;i<n;i++){
            int node=i;
            int leftc=leftChild[i];
            int rightc=rightChild[i];

            if(leftc!=-1){
                adj[node].push_back(leftc);

                if(ctp.find(leftc)!=ctp.end())return false;  // if already has parent
                ctp[leftc]=node;

            }
            if(rightc!=-1){
                adj[node].push_back(rightc);

                if(ctp.find(rightc)!=ctp.end())return false;

                ctp[rightc]=node;
            }
        }
        int  root=-1;
        for(int i=0;i<n;i++){
            if(ctp.find(i)==ctp.end()){
                if(root!=-1)return false;
                
                root=i;
            }
        }
        if(root==-1)return false;
        
        // now apply the bfs 
        queue<int>q;
        int count=0;
        vector<int>vis(n,false);

        q.push(root);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;

            for(int j=0;j<adj[node].size();j++){
                int neigh=adj[node][j];
                if(!vis[neigh]){
                    vis[neigh]=1;
                    q.push(neigh);
                }
            }
        }
        if(count!=n)return false;
        
        return true;

    }
};