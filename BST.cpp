//odd0004
//Omil Dudhat

#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>

using namespace std;

// class Node function to assist all nodes of tree
class Node {

  public:
    int data;

  Node * left;   //left node of tree
  Node * right;  // right node of tree
  int ndepth;    // depth of the tree
  Node(int val, int depth = 0) {

    this -> data = val;

    this -> left = NULL;

    this -> right = NULL;

    this -> ndepth = depth;

  }
};

// creating binary search tree
class BinarySearchTree{

  public:

  int nodes;    // nodes in total
  Node * root;
  int tree_depth;
  
    BinarySearchTree() {     //construtor of BinarySearchTree
    this -> root = NULL;
    this -> nodes = 0;
    this -> tree_depth = 0;
    }

  int size() {
    return this -> nodes;
  }

  int depth() {
    return this -> tree_depth;
  }

  bool insert(double val) {
    if (!this -> root) {
        this -> nodes++;
        this -> root = new Node(val);
        return true;
    }

    Node * temp = this -> root;    //This will find the pointer and insert into the tree

    while (temp) {
      if (temp -> data > val) {    // If left exits
        if (temp -> left)
          temp = temp -> left;
        else {                      //then insert else insert
          temp -> left = new Node(val, temp -> ndepth + 1);
          this -> tree_depth = max(this -> tree_depth, temp -> left -> ndepth);
          this -> nodes++;
          return true;
        }

      } else if (temp -> data == val) {

        return false;

      } else {

        if (temp -> right)

          temp = temp -> right;

        else
        {

        temp -> right = new Node(val, temp -> ndepth + 1);
        this -> tree_depth = max(this -> tree_depth, temp -> right -> ndepth);
        this -> nodes++;
        return true;

        }

      }

    }

    return false;

  }
    
  Node * searach(double val) {
    
    if (!this -> root)
      return NULL;
    Node * temp = this -> root;

    while (temp) {

    if (temp -> data == val) {
        return temp;
    } else if (temp -> data > val) {
        temp = temp -> left;
    } else {
        temp = temp -> right;
    }
    }
    return NULL;

  }

};

void test(int n, bool sorting = false) {

    srand(time(NULL));
    int duplicates = 0;
    BinarySearchTree b = BinarySearchTree();
    double arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    if (sorting)
        sort(arr, arr + n);

  clock_t tStart = clock();

    for (int i = 0; i < n; i++) {

        if (!b.insert(arr[i])) {

            duplicates++;
        }
    }

  clock_t tEnd = clock();

  cout << "-Insertion Time: ";
  double runTime = (double)(tEnd - tStart) / CLOCKS_PER_SEC;
  runTime = runTime * 1000.0;
  printf("Time taken: %.5fs\n", runTime);

  cout << "Duplcate{insert failed}: " << duplicates << endl;

  cout << "" << endl;

  clock_t tStart1 = clock();

  int found = 0;

  for (int i = 0; i < n; i++) {

    if (b.searach(arr[i])) {

      found++;

    }

  }

  clock_t tEnd1 = clock();


  cout << "Searching Time: ";
  double runTime1 = (double)(tEnd1 - tStart1) / CLOCKS_PER_SEC;
  runTime1 = runTime1 * 1000.0;
  printf("Time taken: %.5fs\n", runTime1);

  cout << found << " elements out of " << n << " elements\n";

  cout << "" << endl;

  clock_t tStart2 = clock();

  cout << "-Size: " << b.size() << endl;

  clock_t tEnd2 = clock();


  cout << "*Size Time: ";
  double runTime2 = (double)(tEnd2 - tStart2) / CLOCKS_PER_SEC;
  runTime2 = runTime2 * 1000.0;
  printf("        Time taken: %.5fs\n", runTime2);

  cout << "" << endl;

  clock_t tStart3 = clock();

  cout << "-Depth: " << b.depth() << endl;

  clock_t tEnd3 = clock();

  cout << "*Depth Time: ";
  double runTime3 = (double)(tEnd3 - tStart3) / CLOCKS_PER_SEC;
  runTime3 = runTime3 * 1000.0;
  printf("        Time taken: %.5fs\n", runTime3);

  cout << "" << endl;

}

int main() {

    cout << "*Experiment 1" << endl;
    cout << "*Unsorted" << endl;
    cout << "----------------------------------" << endl;
    test(100);
    test(1000);
    test(10000);

    cout << "*Experiment 2" << endl;
    cout << "*Sorted" << endl;
    cout << "----------------------" << endl;
    test(100, true);
    test(1000, true);
    test(10000, true);

  return 0;

}
