class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };

    trieNode* getNode(){
        trieNode* temp=new trieNode();
        temp->left=NULL;
        temp->right=NULL;

        return temp;
    }
    void insert(trieNode* root,int &num){
        trieNode* node=root;
        for(int i=31;i>=0;i--){
            int ithbit=(num>>i)&1;

            if(ithbit==0 && node->left==NULL){
                node->left=getNode();
               // node->left=0;
                node=node->left;
            }
            else if(ithbit==1 && node->right==NULL){
                node->right=getNode();
               // node->right=1;
                node=node->right;
            }
            else if(ithbit==0 && node->left!=NULL){
                node=node->left;
            }
            else if(ithbit==1 && node->right!=NULL){
                 node=node->right;
            }     

        }
    }
    int findmax(trieNode* root,int &num){
        int x=0;
        trieNode* node=root;
        for(int i=31;i>=0;i--){
            int ithbit=(num>>i)&1;
            if(ithbit==0 && node->right!=NULL){
                x+=(1 << i);
                node=node->right;
            }
            else if(ithbit==1 && node->left!=NULL){
               x+=(1 << i);
                node=node->left;
            }
            else if((ithbit==0 && node->right==NULL)&& node->left!=NULL){
                node=node->left;
            }
            else if((ithbit==1 && node->left==NULL) && node->right!=NULL){
                node=node->right;
            }
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root=getNode();

        for(int i=0;i<nums.size();i++){
            insert(root,nums[i]);
        }
        int result=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int x=findmax(root,nums[i]);

            result=max(result,x);
        }
        return result;
    }
};