// COMSC210 | Lab 36 | Tanmayee Chalamalasetti
// IDE Used: VS Code
#include <fstream>
#include <iostream>
#include <string>

#include "IntBinaryTree.h"
using namespace std;

void menu() {
  cout << "Menu Options\n";
  cout << "1. Display InOrder\n";
  cout << "2. Display PreOrder\n";
  cout << "3. Display PostOrder\n";
  cout << "4. Search Code\n";
  cout << "5. Insert Code\n";
  cout << "6. Delete Code\n";
  cout << "7. Modify Code\n";
  cout << "8. Exit\n";
  cout << "Enter choice: ";
}

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

  int choice;
  do {
    menu();
    cin >> choice;

    string input, newCode;

    switch (choice) {
      case 1:
        tree.displayInOrder();
        break;
      case 2:
        tree.displayPreOrder();
        break;
      case 3:
        tree.displayPostOrder();
        break;
      case 4:
        cout << "Enter code to search: ";
        cin >> input;
        if (tree.searchNode(input)) {
          cout << "Found " << input << endl;
        } else {
          cout << input << " not found.\n";
        }
        break;
    }
  }

  cout << "In Order\n";
  tree.displayInOrder();

  cout << "Pre Order\n";
  tree.displayPreOrder();

  cout << "Post Order\n";
  tree.displayPostOrder();

  return 0;
}