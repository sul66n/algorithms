#include <iostream>
#include <cstdlib>

struct Node {
  int key;
  int priority;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int k) : key(k), priority(rand()) {}
};

class Treap {
private:
  Node* root = nullptr;

  void Split(Node* node, int key, Node*& left, Node*& right) {
    if (node == nullptr) {
      left = right = nullptr;
    } else if (key < node->key) {
      Split(node->left, key, left, node->left);
      right = node;
    } else {
      Split(node->right, key, node->right, right);
      left = node;
    }
  }

  Node* Merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    if (l->priority > r->priority) {
      l->right = Merge(l->right, r);
      return l;
    } else {
      r->left = Merge(l, r->left);
      return r;
    }
  }

  Node* Insert(Node* node, Node* it) {
    if (!node) return it;
    if (it->priority > node->priority) {
      Split(node, it->key, it->left, it->right);
      return it;
    } else if (it->key < node->key) {
      node->left = Insert(node->left, it);
    } else {
      node->right = Insert(node->right, it);
    }
    return node;
  }

  Node* Erase(Node* node, int key) {
    if (!node) return nullptr;
    if (node->key == key) {
      Node* res = Merge(node->left, node->right);
      delete node;
      return res;
    } else if (key < node->key) {
      node->left = Erase(node->left, key);
    } else {
      node->right = Erase(node->right, key);
    }
    return node;
  }

  void Inorder(Node* node) {
    if (node) {
      Inorder(node->left);
      std::cout << node->key << " ";
      Inorder(node->right);
    }
  }

  int Height(Node* node) {
    if (!node) return 0;
    return 1 + std::max(Height(node->left), Height(node->right));
  }

  void Clear(Node* node) {
    if (node) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

public:
  ~Treap() {
    Clear(root);
  }

  void Insert(int key) {
    Node* it = new Node(key);
    root = Insert(root, it);
  }

  void Erase(int key) {
    root = Erase(root, key);
  }

  int Height() {
    return Height(root);
  }

  void PrintInorder() {
    Inorder(root);
    std::cout << '\n';
  }
};
