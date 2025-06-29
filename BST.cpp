#include <iostream>
#include <algorithm>

struct Node {
  int value;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int v) : value(v) {}
};

class BST {
private:
  Node* root = nullptr;

  Node* Insert(Node* node, int val) {
    if (node == nullptr) {
      return new Node(val);
    }
    if (val < node->value) {
      node->left = Insert(node->left, val);
    } else {
      node->right = Insert(node->right, val);
    }
    return node;
  }

  Node* Search(Node* node, int val) {
    if (node == nullptr || node->value == val) {
      return node;
    }
    if (val < node->value) {
      return Search(node->left, val);
    } else {
      return Search(node->right, val);
    }
  }

  Node* Min(Node* node) {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* Max(Node* node) {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }

  Node* RemoveMin(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->left == nullptr) {
      Node* rightChild = node->right;
      delete node;
      return rightChild;
    }
    node->left = RemoveMin(node->left);
    return node;
  }

  Node* RemoveMax(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->right == nullptr) {
      Node* leftChild = node->left;
      delete node;
      return leftChild;
    }
    node->right = RemoveMax(node->right);
    return node;
  }

  Node* Erase(Node* node, int val) {
    if (node == nullptr) return nullptr;
    if (val < node->value) {
      node->left = Erase(node->left, val);
    } else if (val > node->value) {
      node->right = Erase(node->right, val);
    } else {
      // Найден узел
      if (node->left == nullptr) {
        Node* rightChild = node->right;
        delete node;
        return rightChild;
      } else if (node->right == nullptr) {
        Node* leftChild = node->left;
        delete node;
        return leftChild;
      } else {
        // Есть оба потомка
        Node* minRight = Min(node->right);
        node->value = minRight->value;
        node->right = Erase(node->right, minRight->value);
      }
    }
    return node;
  }

  void Inorder(Node* node) {
    if (node != nullptr) {
      Inorder(node->left);
      std::cout << node->value << " ";
      Inorder(node->right);
    }
  }

  void Preorder(Node* node) {
    if (node != nullptr) {
      std::cout << node->value << " ";
      Preorder(node->left);
      Preorder(node->right);
    }
  }

  void Postorder(Node* node) {
    if (node != nullptr) {
      Postorder(node->left);
      Postorder(node->right);
      std::cout << node->value << " ";
    }
  }

  int Height(Node* node) {
    if (node == nullptr) return 0;
    return 1 + std::max(Height(node->left), Height(node->right));
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
    root = Insert(root, val);
  }

  void Erase(int val) {
    root = Erase(root, val);
  }

  Node* Search(int val) {
    return Search(root, val);
  }

  int Min() {
    Node* m = Min(root);
    return m ? m->value : -1;
  }

  int Max() {
    Node* m = Max(root);
    return m ? m->value : -1;
  }

  void RemoveMin() {
    root = RemoveMin(root);
  }

  void RemoveMax() {
    root = RemoveMax(root);
  }

  int Height() {
    return Height(root);
  }

  void PrintInorder() {
    Inorder(root);
    std::cout << '\n';
  }

  void PrintPreorder() {
    Preorder(root);
    std::cout << '\n';
  }

  void PrintPostorder() {
    Postorder(root);
    std::cout << '\n';
  }
};
