#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* right; Node* left;

    Node(int v){
        val=v;
        right=left=nullptr;
    }
};
//preorder traversal
vector<int> preorder(Node* head){  //+LR-- iterative
  stack<Node*>st; vector<int>v;
  st.push(head);
  while(!st.empty()){
    auto top=st.top(); st.pop();
    v.push_back(top->val);
    if(top->right!=nullptr) st.push(top->right);
    if(top->left != nullptr) st.push(top->left);
          
  }
return v;
}

//iterative inorder
vector<int> inorder(Node* head){  //+LR-- iterative
  stack<Node*>st; vector<int>v;
  st.push(head);
  while(!st.empty()){
    auto top=st.top(); st.pop();
    v.push_back(top->val);
    if(top->right!=nullptr) st.push(top->right);
    if(top->left != nullptr) st.push(top->left);
          
  }
return v;
}

vector<int> inorderTraversal(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* current = root;

    while (current!= nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        result.push_back(current->val);

        current = current->right;
    }

    return result;
}

vector<int> postOrder(Node* root) {
    vector<int> postorder;
    
    if(root == NULL){
        return postorder;
    }
    
    stack<Node*> st1, st2;
    st1.push(root);

    
    while(!st1.empty()){
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if(root->left != NULL){
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if(root->right != NULL){
            st1.push(root->right);
        }
    }
    
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    
    return postorder;
}

//postorder- 1 stack

int main(){
   // int root; cin>>root;
    Node* head=new Node(25);
    head->right= new Node(10);
    head->left= new Node(63);
    head->right->right= new Node(58);
    head->right->left= new Node(12);
    head->left->right= new Node(56);
    head->left->left= new Node(89);

    preorder(head);
    return 0;
}