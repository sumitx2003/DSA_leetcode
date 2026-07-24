class Solution {
public:
    struct trieNode{
        bool endOfWord;
        trieNode* children[26];
        string storage;
    };
    trieNode* getnode(){
        trieNode* temp=new trieNode();
        temp->endOfWord=false;
        temp->storage="";
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }
    
    void insert(trieNode* root,string &str){
        trieNode* node=root;
        string word=str;

        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(node->children[ch-'a']==NULL){
                node->children[ch-'a']=getnode();
               
            }
             node=node->children[ch-'a'];
        }
        node->endOfWord=true;
        node->storage=word;
    }

    string findsmall(trieNode* root,string &str){
         trieNode* node=root;
         string word=str;
         for(int i=0;i<word.length();i++){
              char ch=word[i];
              if(node->children[ch-'a']!=NULL){
                  if(node->children[ch-'a']->endOfWord==true){
                       return node->children[ch-'a']->storage;
                  }
                  else{
                      node=node->children[ch-'a'];
                  }
              }
              else if(node->children[ch-'a']==NULL){
                break;
              }
         }
         return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        trieNode* root=getnode();

        for(int i=0;i<dictionary.size();i++){
            insert(root,dictionary[i]);
        }
        string str="";
        string ans="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                string s=findsmall(root,str);
                str="";
                ans+=s+' ';
            }
            else{
                str+=sentence[i];
            }
        }
        if(!str.empty()){
            string s=findsmall(root,str);
            ans+=s;
        }
        return ans;
    }
};