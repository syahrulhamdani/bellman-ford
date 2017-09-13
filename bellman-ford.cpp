#include <iostream>
#include <fstream>

using namespace std;

// declare max number of matrix constant
const int vertice = 10;

// Global varibale declaration
float matrix[vertice][vertice];

// Declare function used
void build_matrix(int size);
float bellman_ford(int size);
void print_path(int par[], int child);

int main(){

  // Varible declaration


  // Main program
  cout << "-----------------------------------------------------------" << endl;
  cout << "PROGRAM OF BELLMAN-FORD ALGORITHM FOR SHORTEST PATH PROBLEM" << endl;
  cout << "-----------------------------------------------------------" << endl;

  return 0;
}
