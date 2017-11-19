#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  int num_asteroids = atoi(argv[1]);
  int num_iterations = atoi(argv[2]);
  int num_planets = atoi(argv[3]);
  double pos_ray = atoi(argv[4]);
  int seed = atoi(argv[5]);

  if(num_asteroids<0){
    cerr << "Number of asteroids is lower than zero!" << endl;
    return -1;
  }

  if(num_iterations<0){
    cerr << "Number of iterations is lower than zero!" << endl;
    return -1;
  }

  if(num_planets<0){
    cerr << "Number of planets is lower than zero!" << endl;
    return -1;
  }

  if(seed == 0 || seed <0){
    cerr << "Seed is equal or lower than zero!" << endl;
    return -1;
  }

  ofstream myFile ("init_conf.txt");
  if(myFile.is_open()){
    myFile << num_asteroids << " ";
    myFile << num_iterations << " ";
    myFile << num_planets << " ";
    myFile << pos_ray << " ";
    myFile << seed << endl;
  }

  else{
    cerr << "Error creating the file!" << endl;
  }

  return 0;
}
