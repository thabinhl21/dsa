#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    delete root;
}

void BSTree::insert(const string &newString) {
    Node* newNode = new Node(newString);
    Node* curr = root;

    if (root == nullptr) {
        root = newNode;
        root->count += 1;
    }

    else if (searchTree(root, newString)) {
        Node* sameNode = searchForNode(root, newString);
        sameNode->count += 1;
        return;
    }

    else {
        while (curr != nullptr) {
            if (newNode->data < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    curr->left->count += 1;
                    curr = nullptr;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    curr->right->count += 1;
                    curr = nullptr;
                }
                else {
                    curr = curr->right;
                }
            }
        }
    }  
}

void BSTree::remove(const string &key) {
    return;
}

bool BSTree::search(const string &key) const {
    // Node* curr = root;
    // bool found = false;

    // while (curr != nullptr) {
    //     if (key == curr->data) {
    //         found = true;
    //     }
    //     else if (key < curr->data) {
    //         curr = curr->left;
    //     }
    //     else {
    //         curr = curr->right;
    //     }
    // }

    // return found;
    Node* curr = root;
    return searchTree(curr, key);
}

bool BSTree::searchTree(Node* curr, const string &key) const {

    if (curr == nullptr) {
        return false;
    }
    
    else if (key == curr->data) {
        return true;
    }
    
    else if (key < curr->data) {
        return searchTree(curr->left, key);
    }
    
    else {
        return searchTree(curr->right, key);
    }
}

Node* BSTree::searchForNode(Node* curr, const string &key) const {
    if (curr == nullptr) {
        return nullptr;
    }
    
    else if (key == curr->data) {
        return curr;
    }
    
    else if (key < curr->data) {
        return searchForNode(curr->left, key);
    }
    
    else {
        return searchForNode(curr->right, key);
    }
}

string BSTree::largest() const {
    return "";
}

string BSTree::smallest() const {
    return "";
}

int BSTree::height(const string&) const {
    return -1;
}

void BSTree::preOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << "(" << node->count << "), ";
    preOrder(node->left);
    preOrder(node->right);

}

void BSTree::postOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << "(" << node->count << "), ";
}

void BSTree::inOrder(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    inOrder(node->left);
    cout << node->data << "(" << node->count << "), ";
    inOrder(node->right);
}

void BSTree::preOrder() const {
    preOrder(root);
}

void BSTree::postOrder() const {
    postOrder(root);
}

void BSTree::inOrder() const {
    postOrder(root);
}



