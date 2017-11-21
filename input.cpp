#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>
#include <math.h>

using namespace std;

const double GRAVITY = 6.674e-5;
const double INTERVAL = 0.1;
const double DMIN = 2.0;
const double WIDTH = 200;
const double HEIGHT = 200;
const double RAY_WIDTH = 4;
const double MASS = 1000;
const double SDM = 50;
const double MAXFORCE = 200;



struct asteroids{
  double x, y, vx,vy, ax, ay, mass;
};

struct planets{
  double x, y, mass;
};


double computeDistance(double xa, double ya, double xb, double yb){
  double distance;

  distance=pow(xa-xb,2)+pow(ya-yb,2);
  distance=sqrt(distance);
printf("DISTANCE: %f \n", distance);
  return distance;
}

double computeAngle(double xa, double ya, double xb, double yb){
  double slope;
  double angle;

  slope=(ya-yb)/(xa-xb);
  //Correction for the slope
  if(slope>1 || slope<-1){
    slope=slope-trunc(slope);
  }
  angle= atan(slope);

  return angle;
}

double computeForceX(double ma, double mb, double dist, double ang){
  double f;

  f=GRAVITY*ma*mb;
  f=f/dist;
  f=f*cos(ang);

  if(f>MAXFORCE){
    f=200; //Truncate to 200 if maxforce is surpassed
  }
  return f;
}

double computeForceY(double ma, double mb, double dist, double ang){
  double f;

  f=GRAVITY*ma*mb;
  f=f/dist;
  f=f*sin(ang);

  if(f>MAXFORCE){
    f=200; //Truncate to 200 if maxforce is surpassed
  }
  return f;
}

int main(int argc, char const *argv[]) {
  int num_asteroids = atoi(argv[1]);
  int num_iterations = atoi(argv[2]);
  int num_planets = atoi(argv[3]);
  double pos_ray = atoi(argv[4]);
  const int seed = atoi(argv[5]);

  //ARGUMENTS CHECK
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
  //random(seed, num_asteroids, num_planets, ast, pl, ray_x, ray_y);

  //JUST SOME TESTS UNTIL RANDOM WORKS
  for (int i = 0; i < num_asteroids; i++) {
    ast[0].x = 1;
    ast[0].y = 0;
    ast[0].mass = 10;
    ast[0].vx = 0;
    ast[0].vy = 0;
    ast[0].ax = 0;
    ast[0].ay = 0;

    ast[1].x = 2;
    ast[1].y = 0;
    ast[1].mass = 20;
    ast[1].vx = 0;
    ast[1].vy = 0;
    ast[1].ax = 0;
    ast[1].ay = 0;

    ast[2].x = 1;
    ast[2].y = 2;
    ast[2].mass = 30;
    ast[2].vx = 0;
    ast[2].vy = 0;
    ast[2].ax = 0;
    ast[2].ay = 0;
  }

  for (int i = 0; i < num_planets; i++) {
    pl[i].x = 0;
    pl[i].y = 100;
  }


  //INITIAL DATA FILE
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
    myFile << pos_ray << endl;
  }
  else{
    cerr << "Error creating the input file!" << endl;
  }

  double distMatrix[num_asteroids][num_asteroids+num_planets]; //Distance of body i with respect to body j
  double angleMatrix[num_asteroids][num_asteroids+num_planets]; //Angle of body i with respect to body j
  double forcesMatrixX[num_asteroids][num_asteroids+num_planets]; //Force X of body i with respect to body j
  double forcesMatrixY[num_asteroids][num_asteroids+num_planets]; //Force X of body i with respect to body j

  //SIMULATION
  for(int t=0; t<num_iterations; t++){
    for(int i=0; i< num_asteroids; i++){
      for(int j=0; j< num_asteroids+num_planets; j++){
        printf("ITERATION: i=%i  j=%i\n", i, j);
        if(i!=j){ //Avoid evaluate i with itself
          if(i<num_asteroids){ //ASTEROID
            //Dist
            distMatrix[i][j]=computeDistance(ast[i].x, ast[i].y, ast[j].x, ast[j].y);
            if(distMatrix[i][j]<DMIN){
              //Angle
              angleMatrix[i][j]=computeAngle(ast[i].x, ast[i].y, ast[j].x, ast[j].y);
              //Force
              if(forcesMatrixX==0 && forcesMatrixY==0){ //Check if it has not been previously set
                forcesMatrixX[i][j]=computeForceX(ast[i].mass, ast[j].mass, distMatrix[i][j], angleMatrix[i][j]);
                forcesMatrixY[i][j]=computeForceY(ast[i].mass, ast[j].mass, distMatrix[i][j], angleMatrix[i][j]);
                //Attraction force for second asteroid
                forcesMatrixX[j][i]=forcesMatrixX[i][j]*(-1);
                forcesMatrixY[j][i]=forcesMatrixX[i][j]*(-1);
              }
            }
          }

          else{ //PLANET
            //Dist
            distMatrix[i][j]=computeDistance(ast[i].x, ast[i].y, pl[j].x, pl[j].y);
            if(distMatrix[i][j]>DMIN){
              //Angle
              angleMatrix[i][j]=computeAngle(ast[i].x, ast[i].y, pl[j].x, pl[j].y);
              //Force
              forcesMatrixX[i][j]=computeForceX(ast[i].mass, pl[j].mass, distMatrix[i][j], angleMatrix[i][j]);
              forcesMatrixY[i][j]=computeForceY(ast[i].mass, pl[j].mass, distMatrix[i][j], angleMatrix[i][j]);
            }
          }
        }
      }
    }

    //Results should be updated once the matrix is filled as if not the i+1 asteroid in t would be taking into account the t+1 position of the i asteroid
    //Rebound(destance check + velocity) should be computed when the asteroid is about to move


  }
  //OUTPUT DATA
  ofstream myFile2 ("out.txt");
  if(myFile2.is_open()){
    for(int i = 0; i < num_asteroids; i++){
      myFile << ast[i].x << " ";
      myFile << ast[i].y << " ";
      myFile << ast[i].vx << " ";
      myFile << ast[i].vy << " ";
      myFile << ast[i].mass << endl;
    }
  }
  else{
    cerr << "Error creating the file!" << endl;
  }


  return 0;
}

/*RANDOM GENERATION
void random(const int seed, int num_asteroids, int num_planets, struct asteroids ast[], struct planets pl[], double ray_x, double ray_y){
  std::default_random_engine re{seed};
  std::uniform_real_distribution<double> xdist{0.0, std::nextafter(WIDTH, std::numeric_limits<double>::max())};
  std::uniform_real_distribution<double> ydist{0.0, std::nextafter(HEIGHT, std::numeric_limits<double>::max())};
  std::normal_distribution<double> mdist{MASS, SDM};

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
*/
