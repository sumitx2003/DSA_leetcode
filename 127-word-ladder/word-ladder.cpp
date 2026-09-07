class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        unordered_set<string>vis;
        queue<string>q;
        int level=1;

        q.push(beginWord);
        vis.insert(beginWord);

        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        while(!q.empty()){
            int N=q.size();
            while(N--){
                string node=q.front();
                q.pop();

                if(node==endWord)return level;

                for(char ch='a';ch<='z';ch++){
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
        return 0;
    }
};