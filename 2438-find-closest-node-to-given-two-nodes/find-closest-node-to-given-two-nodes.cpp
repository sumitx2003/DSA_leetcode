class Solution {
public:
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    unordered_map<int, vector<int>> mp; 
    
    for(int i = 0; i < edges.size(); i++){ 
        int u = i; 
        int v = edges[i]; 
        
        if(v != -1){ 
            mp[u].push_back(v); 
        } 
    } 

    unordered_map<int, int> dist1;
    
    int count = 0; 
    queue<int> q; 
    
    q.push(node1); 
    
    while(!q.empty()){ 
        int node = q.front(); 
        q.pop(); 
        
        // If already visited, cycle exists
        if(dist1.find(node) != dist1.end()) 
            continue;
        
        dist1[node] = count; 
        
        for(int j = 0; j < mp[node].size(); j++){ 
            int neigh = mp[node][j]; 
            
            if(dist1.find(neigh) == dist1.end()){
                q.push(neigh); 
            }
        } 
        
        count++; 
    } 


    // Store distance of nodes reachable from node2
    unordered_map<int, int> dist2;
    
    count = 0; 
    
    q.push(node2); 
    
    while(!q.empty()){ 
        int node = q.front(); 
        q.pop(); 
        
        // If already visited, cycle exists
        if(dist2.find(node) != dist2.end()) 
            continue;
        
        dist2[node] = count; 
        
        for(int j = 0; j < mp[node].size(); j++){ 
            int neigh = mp[node][j]; 
            
            if(dist2.find(neigh) == dist2.end()){
                q.push(neigh); 
            }
        } 
        
        count++; 
    } 


    // Find common node with minimum maximum distance
    int ans = -1; 
    int minDist = INT_MAX; 
    
    for(auto it : dist1){ 
        
        int node = it.first; 
        
        if(dist2.find(node) != dist2.end()){ 
            
            int maximumDistance = max(dist1[node], dist2[node]); 
            
            if(maximumDistance < minDist){ 
                minDist = maximumDistance; 
                ans = node; 
            }
            else if(maximumDistance == minDist && node < ans){ 
                ans = node; 
            }
        }
    } 
    
    return ans; 
} 

};
