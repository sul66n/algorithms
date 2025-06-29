#include <iostream>
#include <algorithm>

struct Node {
  int key;
  int height;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int k) : key(k), height(1) {}
};

class AVL {
private:
  Node* root = nullptr;

  int Height(Node* node) {
    return node ? node->height : 0;
  }

  void UpdateHeight(Node* node) {
    node->height = 1 + std::max(Height(node->left), Height(node->right));
  }

  int BalanceFactor(Node* node) {
    return Height(node->left) - Height(node->right);
  }

  Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    UpdateHeight(y);
    UpdateHeight(x);

    return x;
  }

  Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    UpdateHeight(x);
    UpdateHeight(y);

    return y;
  }

  Node* Balance(Node* node) {
    UpdateHeight(node);
    int bf = BalanceFactor(node);

    if (bf > 1) {
      if (BalanceFactor(node->left) < 0) {
        node->left = RotateLeft(node->left);
      }
      return RotateRight(node);
    }
    if (bf < -1) {
      if (BalanceFactor(node->right) > 0) {
        node->right = RotateRight(node->right);
      }
      return RotateLeft(node);
    }
    return node;
  }

  Node* Insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) {
      node->left = Insert(node->left, key);
    } else if (key > node->key) {
      node->right = Insert(node->right, key);
    } else {
      return node;
    }
    return Balance(node);
  }

  Node* Min(Node* node) {
    return node->left ? Min(node->left) : node;
  }

  Node* RemoveMin(Node* node) {
    if (!node->left)
      return node->right;
    node->left = RemoveMin(node->left);
    return Balance(node);
  }

  Node* Erase(Node* node, int key) {
    if (!node) return nullptr;
    if (key < node->key) {
      node->left = Erase(node->left, key);
    } else if (key > node->key) {
      node->right = Erase(node->right, key);
    } else {
      Node* l = node->left;
      Node* r = node->right;
      delete node;
      if (!r) return l;
      Node* min = Min(r);
      min->right = RemoveMin(r);
      min->left = l;
      return Balance(min);
    }
    return Balance(node);
  }

  void Inorder(Node* node) {
    if (node) {
      Inorder(node->left);
      std::cout << node->key << " ";
      Inorder(node->right);
    }
  }

  void Clear(Node* node) {
    if (node) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

public:
  ~AVL() {
    Clear(root);
  }

  void Insert(int key) {
    root = Insert(root, key);
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


int main() {
  AVL avl;

  avl.Insert(10);
  avl.Insert(20);
  avl.Insert(30);
  avl.Insert(25);
  avl.Insert(5);
  avl.Insert(15);

  std::cout << "Inorder traversal: ";
  avl.PrintInorder();

  std::cout << "Tree height: " << avl.Height() << '\n';

  std::cout << "Erase 20...\n";
  avl.Erase(20);

  avl.PrintInorder();
  std::cout << "Tree height: " << avl.Height() << '\n';

  return 0;
}
