class Solution {
public:
    struct trieNode{
        trieNode* children[10];
    };
    trieNode* getnode(){
        trieNode* temp=new trieNode();
        for(int i=0;i<=9;i++){
            temp->children[i]=NULL;
        }
        return temp;

    }
    void insert(trieNode* root,int &num){
        trieNode* node=root;
        int x=num;
        string str=to_string(x);
        for(int i=0;i<str.length();i++){
            int y=str[i]-'0';
            if(node->children[y]==NULL){
                node->children[y]=getnode();

            }
            node=node->children[y];
        }
    }
    int findlongest(trieNode* root,int &num){
          trieNode* node=root;
          int x=num;
          string str=to_string(x);
          int len=0;
        for(int i=0;i<str.length();i++){
             int y=str[i]-'0';
             if(node->children[y]!=NULL){
                len++;
                node=node->children[y];
             }
             else{
                break;
             }
        }
        return len;

    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root=getnode();

        for(int i=0;i<arr1.size();i++){
            insert(root,arr1[i]);
        }
        int res=INT_MIN;
        for(int i=0;i<arr2.size();i++){
            int x=findlongest(root,arr2[i]);
            res=max(res,x); 
        }
        return res;
    }
};