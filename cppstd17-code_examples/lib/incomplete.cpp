
#include "incomplete.hpp"
#include <iostream>

int main()
{
  // create node tree:
  Node root{"top"};
  root.add(Node{"elem1"});
  root.add(Node{"elem2"});
  root[0].add(Node{"elem1.1"});

  // print node tree:
  root.print();
}

