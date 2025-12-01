// COMSC210 | Lab 36 | Tanmayee Chalamalasetti
// IDE Used: VS Code
#include <fstream>
#include <iostream>
#include <string>

#include "IntBinaryTree.h"
using namespace std;

int main() {
  IntBinaryTree tree;
  ifstream infile("codes.txt");

  if (!infile) {
    cout << "Error! Could not open codes.txt.\n";
    return 1;
  }

  string code;

  while (infile >> code) {
    tree.insertNode(code);
  }
  infile.close();

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