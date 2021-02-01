
#include "foldtraverse.hpp"
#include <iostream>

int main()
{
  // init binary tree structure:
  Node* root = new Node{0};
  root->subLeft = new Node{1};
  root->subLeft->subRight = new Node{2};
  //...
  // traverse binary tree:
  Node* node = Node::traverse(root, Node::left, Node::right);
  std::cout << node->getValue() << '\n';
  node = root ->* Node::left ->* Node::right;
  std::cout << node->getValue() << '\n';
  node = root -> subLeft -> subRight;
  std::cout << node->getValue() << '\n';
}

