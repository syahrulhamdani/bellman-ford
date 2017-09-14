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

  return 0;
}
