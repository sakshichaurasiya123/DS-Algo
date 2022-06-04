#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* createBinaryTree(Node* root){
    cout<<"  Enter the data = ";
    int data;
    cin>>data;
    cout<<" "<<data<<endl;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter left child of  "<<data;
    root->left=createBinaryTree(root->left);
    cout<<"Enter right child of  "<<data ;
    root->right=createBinaryTree(root->right);
    return root;
    
}

//For Level Order Traversal
void levelOrderTraversal(Node* root){
    cout<<"Level Order Traversal ===== "<<endl;
    queue<Node*>que;
    que.push(root);
    que.push(NULL);
    while(!que.empty()){
        Node* temp=que.front();
        que.pop();
        //For identifying that older level has been completed
        if(temp==NULL){
            cout<<endl;
            if(!que.empty()){
            //Queue still has some child nodes
                que.push(NULL);
                }
        }
        else{
        cout<<" "<<temp->data << " ";
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
       // cout<<"\n";
       }
    }
    cout<<"\n";
}
/*InOrder LNR (Left, Node Right) */
/*PreOrder NLR (Node, Left,Right) */
/*postOrder RLN (Right, Left, Node )*/


//InOrder
void Inorder(Node* root){
    if(root==NULL)
        return;
    Inorder(root->left);
    cout<<" "<<root->data<<" ";
    Inorder(root->right);
}


//PreOrder
void PreOrder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

//Post Order
void postOrder(Node* root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<" "<<root->data<<" ";
}

//BuildTree Using levelOrderTraversal

void buildTreeUsingLevel(Node* root){
    queue<Node*> q;
    cout<<"Enter root Node = ";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    cout<<root->data<<" \n";
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter child for left  of "<<temp->data<<" \n";
        int leftChild;
        cin>>leftChild;
        
         cout<<"left child = "<<leftChild<<endl;
        if(leftChild!=-1){
            temp->left=new Node(leftChild);
         
            q.push(temp->left);
        }
        
        cout<<"Enter child for right  of "<<temp->data<<" \n";
        int rightChild;
        cin>>rightChild;
        
         cout<<"Right child =  "<<rightChild<<endl;
        if(rightChild!=-1){
            temp->right=new Node(rightChild);
           
            q.push(temp->right);
        }
    }
}




int main() {
	Node* root=NULL;
/*	root=createBinaryTree(root);

	//Level Order Traversal
	levelOrderTraversal(root);
    cout<<endl;
    //PreOrder
    cout<<" PreOrder of Tree =  ";
    PreOrder(root);
    cout<<endl;
    
    //PostOrder
    cout<<"Post Order of Tree = ";
    postOrder(root);
    cout<<"\n";
    
    //Inorder
    cout<<"Inorder of tree = ";
    Inorder(root);
    */
    
    //buildTreeUsingLevel
    buildTreeUsingLevel(root);
	
	return 0;
}
