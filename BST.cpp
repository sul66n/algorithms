#include <iostream>

struct Node {
  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;

  Node(int val) : value(val) {}
};

class BST {
private:
  Node* root = nullptr;

  void InorderWalk(Node* node) {
    if (node != nullptr) {
      InorderWalk(node->left);
      std::cout << node->value << " ";
      InorderWalk(node->right);
    }
  }

  void PreorderWalk(Node* node) {
    if (node != nullptr) {
      std::cout << node->value << " ";
      PreorderWalk(node->left);
      PreorderWalk(node->right);
    }
  }

  void PostorderWalk(Node* node) {
    if (node != nullptr) {
      PostorderWalk(node->left);
      PostorderWalk(node->right);
      std::cout << node->value << " ";
    }
  }

  Node* Minimum(Node* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  void Transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if (v != nullptr) {
      v->parent = u->parent;
    }
  }

  void Clear(Node* node) {
    if (node != nullptr) {
      Clear(node->left);
      Clear(node->right);
      delete node;
    }
  }

public:
  ~BST() {
    Clear(root);
  }

  void Insert(int val) {
    Node* z = new Node(val);
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
      y = x;
      if (z->value < x->value) {
        x = x->left;
      } else {
        x = x->right;
      }
    }

    z->parent = y;

    if (y == nullptr) {
      root = z;
    } else if (z->value < y->value) {
      y->left = z;
    } else {
      y->right = z;
    }
  }

  Node* Search(int val) {
    Node* current = root;
    while (current != nullptr && current->value != val) {
      if (val < current->value) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return current;
  }

  void Erase(int val) {
    Node* z = Search(val);
    if (z == nullptr) {
      return;
    }

    if (z->left == nullptr) {
      Transplant(z, z->right);
    } else if (z->right == nullptr) {
      Transplant(z, z->left);
    } else {
      Node* y = Minimum(z->right);
      if (y->parent != z) {
        Transplant(y, y->right);
        y->right = z->right;
        if (y->right) {
          y->right->parent = y;
        }
      }
      Transplant(z, y);
      y->left = z->left;
      if (y->left) {
        y->left->parent = y;
      }
    }

    delete z;
  }

  void PrintInorder() {
    InorderWalk(root);
    std::cout << '\n';
  }

  void PrintPreorder() {
    PreorderWalk(root);
    std::cout << '\n';
  }

  void PrintPostorder() {
    PostorderWalk(root);
    std::cout << '\n';
  }
};
