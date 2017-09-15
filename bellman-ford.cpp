#include <iostream>
#include <fstream>

using namespace std;

// declare max number of matrix constant
const int vertice = 10;

// Global varibale declaration
float matrix[vertice][vertice];

// Declare function used
void build_matrix(int size, int data);
float bellman_ford(int size);
void print_path(int par[], int child);

void build_matrix(int size, int data) {

  // Local variable declaration
  ifstream graph;
  int i, j;

  // Open the txt data in the same directory
  // Make sure that you write the correct file name
  if (data == 1) {
    graph.open("graf1.txt");
    if (!graph) {
      cout << "Warning! graf1.txt doesn't exist";
    }
  } else if (data == 2) {
    graph.open("graf2.txt");
    if (!graph) {
      cout << "Warning! graf2.txt doesn't exist";
    }
  }

  // Input the data in the file into the matrix distance
  for (i = 0; i <size; i++) {
    for (j = 0; j < size; j++) {
      graph >> matrix[i][j];
    }
    cout << endl;
  }

}

float bellman_ford (int size) {

  // Local varible declaration
  int i, j, iteration, p[size];
  float d[size];

  for (i = 0; i < size; i++) {
    d[i] = 99;    // Assign all distance array from 0 equals 99
    p[i] = 1;    // Assign all parent equals 0
  }

  // set distance to source vertice to 0
  d[0] = 0;

  // Relax graph repeatedly V-1 times
  for (iteration = 0; iteration < (size - 1); iteration++) {  // Do iteration V-1 times
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        if (matrix[i][j] != 99) {    // check for all possible edges
          if (d[i] + matrix[i][j] < d[j]) {    // check the minimum of targeted vertice
            d[j] = d[i] + matrix[i][j];
            p[j] = i;
          }
        }
      }
    }
  }

  // Check for negative-weight cycles
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (matrix[i][j] != 99) {  // check for all possible edges
        if (d[i] + matrix[i][j] < d[j]) {    // check the minimum of targeted vertice
          d[j] = d[i] + matrix[i][j];
          p[j] = i;
        }
      }
    }
  }

  cout << "Minimum distance to node [" << size-1 << "] : ";
  cout << d[size-1] << endl;

  // Call print_path procedure to print the path
  // The second parameter of the procedure depends on the final target
  print_path(p, size-1);

}

void print_path (int par[], int child) {

  // Local variable declaration
  int i, j, parent[vertice], max_parent;

  // Main program
  i = child;
  cout << "The shortest path to vertice [" << vertice - 1 << "] : ";
  cout << "end <- " << child << " <- ";
  while (i != 0) {
    cout << par[i] << " <- ";
    i = par[i];
    if (i == 0) {
      cout << "begin";
    }
  }

}

int main(){

  // Varible declaration
  int option;

  // Main program
  cout << "-----------------------------------------------------------" << endl;
  cout << "PROGRAM OF BELLMAN-FORD ALGORITHM FOR SHORTEST PATH PROBLEM" << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << endl;
  cout << "List of data for input: " << endl;
  cout << "1. Simple 10 vertices graph" << endl;
  cout << "2. Improved 10 vertices graph with negative weight" << endl;
  do {
    cout << "Your option : ";
    cin >> option;
  } while(option < 1 or option > 2);

  // Call build_matrix function
  build_matrix(vertice, option);
  // Call bellman-ford function
  bellman_ford(vertice);

  return 0;
}
