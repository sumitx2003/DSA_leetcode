class Solution {
public:
   struct trieNode{
       trieNode* children[26];
       int countnumber;
   };
   trieNode* getnode(){
         trieNode* temp=new trieNode();
         temp->countnumber=0;
         for(int i=0;i<26;i++){
            temp->children[i]=NULL;
         }
         return temp;
   }
   void insert(trieNode* root,string &s){
         trieNode* node=root;
         string str=s;
         for(int i=0;i<str.length();i++){
              char ch=str[i];
              if(node->children[ch-'a']==NULL){
                  node->children[ch-'a']=getnode();
                  node->children[ch-'a']->countnumber+=1;
                  node=node->children[ch-'a'];
              }
              else{
                node->children[ch-'a']->countnumber+=1;
                node=node->children[ch-'a'];
                
              }
         }
   }
   int findnumber(trieNode* root,string &str){
         trieNode* node=root;
         string s=str;
         for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(node->children[ch-'a']!=NULL){
                node=node->children[ch-'a'];
            }
         }
         return node->countnumber;
   }
    vector<int> sumPrefixScores(vector<string>& words) {
        trieNode* root=getnode();
        vector<int>ans(words.size(),0);

        for(int i=0;i<words.size();i++){
            string s=words[i];
            insert(root,s);
        }

        for(int i=0;i<words.size();i++){
           trieNode* node = root;

           for(char ch : words[i]){
           node = node->children[ch-'a'];
           ans[i] += node->countnumber;
           }
        }
        return ans;
    }
};