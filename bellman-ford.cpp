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

  return 0;
}
