#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>

using namespace std;

const double gravity = 6.674e-5;
const double interval = 0.1;
const double dmin = 2.0;
const double width = 200;
const double height = 200;
const double ray_width = 4;
const double mass = 1000;
const double sdm = 50;


struct asteroids{
  double x, y, mass;
};

struct planets{
  double x, y;
};

void random(const int seed, int num_asteroids, int num_planets, struct asteroids ast[], struct planets pl[], double ray_x, double ray_y){
  std::default_random_engine re{seed};
  std::uniform_real_distribution<double> xdist{0.0, std::nextafter(width, std::numeric_limits<double>::max())};
  std::uniform_real_distribution<double> ydist{0.0, std::nextafter(height, std::numeric_limits<double>::max())};
  std::normal_distribution<double> mdist{mass, sdm};

  for (int i = 0; i < num_asteroids; i++) {
    ast[i].x = xdist(re);
    ast[i].y = ydist(re);
    ast[i].mass = mdist(re);
  }

  for (int i = 0; i < num_planets; i++) {
    pl[i].x = xdist(re);
    pl[i].y = ydist(re);
  }

  ray_x = xdist(re);
  ray_y = ydist(re);

}

int main(int argc, char const *argv[]) {
  int num_asteroids = atoi(argv[1]);
  int num_iterations = atoi(argv[2]);
  int num_planets = atoi(argv[3]);
  double pos_ray = atoi(argv[4]);
  const int seed = atoi(argv[5]);

  if(num_asteroids<0){
    cerr << "nasteroids-seq: Wrong arguments." << endl;
    cerr << "Correct use:" << endl;
    cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
    return -1;
  }

  if(num_iterations<0){
    cerr << "nasteroids-seq: Wrong arguments." << endl;
    cerr << "Correct use:" << endl;
    cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
    return -1;
  }

  if(num_planets<0){
    cerr << "nasteroids-seq: Wrong arguments." << endl;
    cerr << "Correct use:" << endl;
    cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
    return -1;
  }

  if(seed == 0 || seed <0){
    cerr << "nasteroids-seq: Wrong arguments." << endl;
    cerr << "Correct use:" << endl;
    cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
    return -1;
  }

  asteroids ast[num_asteroids];
  planets pl[num_planets];

  double ray_x;
  double ray_y;

  random(seed, num_asteroids, num_planets, ast, pl, ray_x, ray_y);

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
