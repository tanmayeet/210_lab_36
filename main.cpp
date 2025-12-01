// COMSC210 | Lab 36 | Tanmayee Chalamalasetti
// IDE Used: VS Code
#include <iostream>

#include "IntBinaryTree.h"
using namespace std;

int main() {
  IntBinaryTree tree;

  tree.insertNode("uANq6eH7");
  tree.insertNode("gwlXSBJv");
  tree.insertNode("i6QN2GdS");

  cout << "In Order\n";
  tree.displayInOrder();

  cout << "Pre Order\n";
  tree.displayPreOrder();

  cout << "Post Order\n";
  tree.displayPostOrder();

  if (tree.searchNode("gwlXSBJv")) {
    cout << "Found gwlXSBJv\n";
  } else {
    cout << "gwlXSBJv not found.\n";
  }

  cout << "Remove\n";
  tree.remove("gwlXSBJv");

  tree.displayInOrder();

  return 0;
}