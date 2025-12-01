// COMSC210 | Lab 36 | Tanmayee Chalamalasetti
// IDE Used: VS Code
#include <fstream>
#include <iostream>
#include <string>

#include "IntBinaryTree.h"
using namespace std;

void menu() {
  cout << "\nMenu Options\n";
  cout << "1. Display In Order\n";
  cout << "2. Display Pre Order\n";
  cout << "3. Display Post Order\n";
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
        cout << "Display In Order\n";
        tree.displayInOrder();
        break;
      case 2:
        cout << "Display Pre Order\n";
        tree.displayPreOrder();
        break;
      case 3:
        cout << "Display Post Order\n";
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
      case 5:
        cout << "Enter code to insert: ";
        cin >> input;
        tree.insertNode(input);
        break;

      case 6:
        cout << "Enter code to delete: ";
        cin >> input;
        tree.remove(input);
        break;
      case 7:
        cout << "Enter code to modify: ";
        cin >> input;
        if (tree.searchNode(input)) {
          tree.remove(input);
          cout << "Enter new code: ";
          cin >> newCode;
          tree.insertNode(newCode);
        } else {
          cout << "Code not found.\n";
        }
        break;
      case 8:
        cout << "Exiting program.\n";
        break;
      default:
        cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 8);

  return 0;
}