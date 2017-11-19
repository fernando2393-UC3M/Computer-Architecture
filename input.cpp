#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>

using namespace std;

struct asteroids{
  double x, y, mass;
};

struct planets{
  double x, y;
};

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

  asteroids ast[num_asteroids];
  planets pl[num_planets];


  // Random distributions
  default_random_engine re{seed};
  uniform_real_distribution<double> xdist{0.0, std::nextafter(width,
    std :: numeric_limits<double>::max())};
  uniform_real_distribution<double> ydist{0.0, std::nextafter(height,
    std :: numeric_limits<double>::max())};
  normal_distribution<double> mdist{mass, sdm};

  for (int i = 0; i < num_asteroids; i++) {
    ast[i].x = xdist(re);
    ast[i].y = ydist(re);
    ast[i].mass = mdist(re);
  }

  for (int i = 0; i < num_planets; i++) {
    pl[i].x = xdist(re);
    pl[i].y = ydist(re);
  }

  double ray_x = xdist(re);
  double ray_y = ydist(re);

  ofstream myFile ("init_conf.txt");
  if(myFile.is_open()){
    myFile << num_asteroids << " ";
    myFile << num_iterations << " ";
    myFile << num_planets << " ";
    myFile << pos_ray << " ";
    myFile << seed << endl;

    for(int i = 0; i < num_asteroids; i++){
      myFile << ast[i].x << " ";
      myFile << ast[i].y << " ";
      myFile << ast[i].mass << endl;
    }

    for(int i = 0; i < num_planets; i++){
      myFile << pl[i].x << " ";
      myFile << pl[i].y << endl;
    }

    myFile << ray_x << " ";
    myFile << ray_y << endl;

  }

  else{
    cerr << "Error creating the file!" << endl;
  }

  return 0;
}
