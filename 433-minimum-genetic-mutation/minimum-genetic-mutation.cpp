class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st;
        unordered_set<string>vis;
        for(int i=0;i<bank.size();i++){
             st.insert(bank[i]);
        }
        queue<string>q;
        q.push(startGene);
        vis.insert(startGene);
        vector<char>vec={'A','C','G','T'};

        int level=0;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                string node=q.front();
                q.pop();

                if(node==endGene)return level;

                for(char ch:vec){
                    for(int i=0;i<node.length();i++){
                        string str=node;
                        str[i]=ch;
                        if(st.find(str)!=st.end() && vis.find(str)==vis.end()){
                            q.push(str);
                            vis.insert(str);
                        }

                    }
                }

            }
            level++;
        }
        return -1;
    }
};