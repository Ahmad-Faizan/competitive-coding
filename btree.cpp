#include <bits/stdc++.h>

struct Node{
    int node_data;
    Node* left_child;
    Node* right_child;

    Node(int data){
        node_data = data;
        left_child = right_child = nullptr;
    }
};

class BinaryTree {
    public:
        Node* insert(Node* root, int data){
            if(root == nullptr)
                return new Node(data);
            else{
                Node *temp;
                if(data <= root->node_data){
                    temp = insert(root->left_child, data);
                    root->left_child = temp;
                }
                else{
                    temp = insert(root->right_child,data);
                    root->right_child = temp;
                }
            }
            return root;
        }

        int height(Node* root){
            if(root == nullptr)
                return -1;
            else
                return 1 + std::max(height(root->left_child), height(root->right_child));
        }
};

int main(){
    Node* root = nullptr;
    BinaryTree btree;

    int V,n,data;
    std::cin >> V;
    n = V;
    
    while(n--){
        std::cin >> data;
        root = btree.insert(root, data);
    }
    int height = btree.height(root);
    std::cout << height;

    return 0;
}