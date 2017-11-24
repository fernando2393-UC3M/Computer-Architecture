#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>
#include <math.h>
#include <vector>
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


struct asteroids {
        double x, y, vx,vy, ax, ay, mass;
};

struct planets {
        double x, y, mass;
};

void random(const unsigned int seed, int num_asteroids, int num_planets, std::vector<asteroids> &ast, std::vector<planets> &pl){
        std::default_random_engine re{seed};
        std::uniform_real_distribution<double> xdist{0.0, std::nextafter(WIDTH, std::numeric_limits<double>::max())};
        std::uniform_real_distribution<double> ydist{0.0, std::nextafter(HEIGHT, std::numeric_limits<double>::max())};
        std::normal_distribution<double> mdist{MASS, SDM};

        for (int i = 0; i < num_asteroids; i++) {
                ast.push_back(asteroids());
                ast[i].x = xdist(re);
                ast[i].y = ydist(re);
                ast[i].mass = mdist(re);
        }

        for (int i = 0; i < num_planets; i++) {
                pl.push_back(planets());
                pl[i].x = xdist(re);
                pl[i].y = ydist(re);
                pl[i].mass = 10 * mdist(re);
        }
}

double computeDistance(double xa, double ya, double xb, double yb){
        double distance;

        distance=pow(xa-xb,2)+pow(ya-yb,2);
        distance=sqrt(distance);

        return distance;
}

double computeAngle(double xa, double ya, double xb, double yb){
        double slope;
        double angle;

        slope=(ya-yb)/(xa-xb);
        //Correction for the slope
        if(slope>1 || slope<-1) {
                slope=slope-trunc(slope);
        }
        angle= atan(slope);

        return angle;
}

double computeForceX(double ma, double mb, double dist, double ang){
        double f;

        f=GRAVITY*ma*mb;
        f=f/pow(dist, 2);
        f=f*cos(ang);

        if(f>MAXFORCE) {
                f=200; //Truncate to 200 if maxforce is surpassed
        }
        return f;
}

double computeForceY(double ma, double mb, double dist, double ang){
        double f;

        f=GRAVITY*ma*mb;
        f=f/dist;
        f=f*sin(ang);

        if(f>MAXFORCE) {
                f=200; //Truncate to 200 if maxforce is surpassed
        }
        return f;
}

double computeAcc(int length, std::vector<double> vforces, double mass){
        double acc;

        for(int i=0; i<length; i++) {
                acc=acc+vforces[i];
        }
        acc=acc/mass;

        return acc;
}

int checkRebound(double x, double y){
        int id;

        if(x<=0) {
                id=1;
                return id;
        }
        if(x>=WIDTH) {
                id=2;
                return id;
        }
        if(y<=0) {
                id=3;
                return id;
        }
        if(y>=HEIGHT) {
                id=4;
                return id;
        }

        return 0;
}

void releaseGalactus(double target, std::vector<asteroids> &ast){
        for(unsigned long i=0; i<ast.size(); i++) {
                if(ast[i].y==target || ast[i].y==target+(RAY_WIDTH/2) || ast[i].y==target-(RAY_WIDTH/2)) {
                    cout << "Asteroid" << i << " was devoured by GALACTUS" << endl;
                        ast.erase(ast.begin()+i);
                }
        }
}

int main(int argc, char const *argv[]) {
        if(argc != 6) {
                cerr << "nasteroids-seq: Wrong arguments." << endl;
                cerr << "Correct use:" << endl;
                cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
                return -1;
        }

        int num_asteroids = atoi(argv[1]);
        int num_iterations = atoi(argv[2]);
        int num_planets = atoi(argv[3]);
        double pos_ray = stod(argv[4]);
        const auto seed = (unsigned int) atoi(argv[5]);

        if(num_asteroids<0) {
                cerr << "nasteroids-seq: Wrong arguments." << endl;
                cerr << "Correct use:" << endl;
                cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
                return -1;
        }

        if(num_iterations<0) {
                cerr << "nasteroids-seq: Wrong arguments." << endl;
                cerr << "Correct use:" << endl;
                cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
                return -1;
        }

        if(num_planets<0) {
                cerr << "nasteroids-seq: Wrong arguments." << endl;
                cerr << "Correct use:" << endl;
                cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
                return -1;
        }

        if(seed == 0) {
                cerr << "nasteroids-seq: Wrong arguments." << endl;
                cerr << "Correct use:" << endl;
                cerr << "nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed" << endl;
                return -1;
        }

        std::vector<asteroids> ast;
        std::vector<planets> pl;

        random(seed, num_asteroids, num_planets, ast, pl);

        ofstream myFile ("init_conf.txt");
        if(myFile.is_open()) {

                //This adjust the precision of the numbers written in the output file
                myFile.setf(ios::fixed,ios::floatfield);
                myFile.precision(3);

                myFile << num_asteroids << " ";
                myFile << num_iterations << " ";
                myFile << num_planets << " ";
                myFile << pos_ray << " ";
                myFile << seed << endl;

                for(int i = 0; i < num_asteroids; i++) {
                        myFile << ast[i].x << " ";
                        myFile << ast[i].y << " ";
                        myFile << ast[i].mass << endl;
                }

                for(int i = 0; i < num_planets; i++) {
                        myFile << pl[i].x << " ";
                        myFile << pl[i].y << endl;
                }

                myFile << 0.000 << " ";
                myFile << pos_ray << endl;

        }



        else{
                cerr << "Error creating the file!" << endl;
        }

        //-------------------------HERE STARTS THE COMPUTATION OF FORCES//-------------------------//
        double accx; //acceleration
        double accy;

        // double **distMatrix;
        // distMatrix= new double *[num_asteroids];
        // for(int i = 0;i<num_asteroids;i++){
        //   distMatrix[i] = new double[num_asteroids+num_planets];
        // }
        //
        // double **forcesMatrixX;
        // forcesMatrixX= new double *[num_asteroids];
        // for(int i = 0;i<num_asteroids;i++){
        //   forcesMatrixX[i] = new double[num_asteroids+num_planets];
        // }
        //
        // double **angleMatrix;
        // angleMatrix= new double *[num_asteroids];
        // for(int i = 0;i<num_asteroids;i++){
        //   angleMatrix[i] = new double[num_asteroids+num_planets];
        // }
        //
        // double **forcesMatrixY;
        // forcesMatrixY= new double *[num_asteroids];
        // for(int i = 0;i<num_asteroids;i++){
        //   forcesMatrixY[i] = new double[num_asteroids+num_planets];
        // }
        int col=num_asteroids+num_planets;
        std::vector<std::vector<double> >distMatrix(num_asteroids, vector<double>(col));
        std::vector<std::vector<double> >angleMatrix(num_asteroids, vector<double>(col));
        std::vector<std::vector<double> >forcesMatrixX(num_asteroids, vector<double>(col));
        std::vector<std::vector<double> >forcesMatrixY(num_asteroids, vector<double>(col));

// for(int i=0; i<num_asteroids; i++){
//   for(int j=0; j<num_asteroids+num_planets;j++){
//     cout << "distance: " << distMatrix[i][j]<<" i: " << i << "j: " <<j<<endl;
//   }
// }

        //SIMULATION
        for(int t=0; t<num_iterations; t++){
          accx=0;
          accy=0;
          for(int i=0; i< num_asteroids; i++){
            cout << i << endl;
            for(int j=0; j<(num_asteroids+num_planets); j++){
              if(i!=j){ //Avoid evaluate i with itself
                if(j<num_asteroids){ //ASTEROID
                  //Dist
                  distMatrix[i][j]=computeDistance(ast[i].x, ast[i].y, ast[j].x, ast[j].y);
                  if(distMatrix[i][j]>DMIN){
                    //Angle
                    angleMatrix[i][j]=computeAngle(ast[i].x, ast[i].y, ast[j].x, ast[j].y);
                    //Force
                    if(forcesMatrixX[i][j]==0 && forcesMatrixY[i][j]==0){ //Check if it has not been previously set
                      forcesMatrixX[i][j]=computeForceX(ast[i].mass, ast[j].mass, distMatrix[i][j], angleMatrix[i][j]);
                      forcesMatrixY[i][j]=computeForceY(ast[i].mass, ast[j].mass, distMatrix[i][j], angleMatrix[i][j]);
                      //Attraction force for second asteroid
                      forcesMatrixX[j][i]=forcesMatrixX[i][j]*(-1);
                      forcesMatrixY[j][i]=forcesMatrixY[i][j]*(-1);
                    }
                  }
                }
                else{ //PLANET
                  //Dist
                  distMatrix[i][j]=computeDistance(ast[i].x, ast[i].y, pl[j-num_asteroids].x, pl[j-num_asteroids].y);

                  if(distMatrix[i][j]>DMIN){
                    //Angle
                    angleMatrix[i][j]=computeAngle(ast[i].x, ast[i].y, pl[j-num_asteroids].x, pl[j-num_asteroids].y);

                    //Force
                    forcesMatrixX[i][j]=computeForceX(ast[i].mass, pl[j-num_asteroids].mass, distMatrix[i][j], angleMatrix[i][j]);

                    forcesMatrixY[i][j]=computeForceY(ast[i].mass, pl[j-num_asteroids].mass, distMatrix[i][j], angleMatrix[i][j]);

                  }
                }
              }
            }
            cout << "BUCLE J HA ACABADO"<< endl;
            //Results should be updated once the rows are filled so all the forces acting on an asteroid are computed
            //acc
            accx=computeAcc(i, forcesMatrixX[i], ast[i].mass);
            accy=computeAcc(i, forcesMatrixY[i], ast[i].mass);
            //vel
            ast[i].vx=ast[i].vx+(accx*INTERVAL);
            ast[i].vy=ast[i].vy+(accy*INTERVAL);
            //pos
            switch(checkRebound(ast[i].x, ast[i].y)) {
                case 1: ast[i].x=2;
                        ast[i].y=ast[i].y+(ast[i].vy*INTERVAL);
                        ast[i].vx=ast[i].vx*(-1);
                        break; //x<=0
                case 2: ast[i].x=WIDTH-2;
                        ast[i].y=ast[i].y+(ast[i].vy*INTERVAL);
                        ast[i].vx=ast[i].vx*(-1);
                        break; //x>=WIDTH
                case 3: ast[i].x=ast[i].x+(ast[i].vx*INTERVAL);
                        ast[i].y=2;
                        ast[i].vy=ast[i].vy*(-1);
                        break; //y<=0
                case 4: ast[i].x=ast[i].x+(ast[i].vx*INTERVAL);
                        ast[i].y=HEIGHT-2;
                        ast[i].vy=ast[i].vy*(-1);
                        break; //y>=HEIGHT
                default:  ast[i].x=ast[i].x+(ast[i].vx*INTERVAL);
                          ast[i].y=ast[i].y+(ast[i].vy*INTERVAL);
            }
          }
          releaseGalactus(pos_ray, ast);
        }

        // for( int i = 0 ; i < num_asteroids ; i++ ){
        //     delete[] distMatrix[i]; // delete array within matrix
        //     delete[] angleMatrix[i];
        //     delete[] forcesMatrixX[i];
        //     delete[] forcesMatrixY[i];
        // }
        //
        // delete[] distMatrix;
        // delete[] forcesMatrixX;
        // delete[] forcesMatrixY;
        // delete[] angleMatrix;


        //After computing the movement due to the forces, the laser ray must be
        //activated, locating all the asteroids that are inside its range of influence.

        //All asteroids whose vertical coordinate is at a distance less or equal
        //than 2 from the position of the ray (in the y axis) will be destroyed.

        //The destruction of these asteroids imply the removal of these asteroids from the program


        //OUTPUT DATA
        ofstream myFile2 ("out.txt");
        myFile2.setf(ios::fixed,ios::floatfield);
        myFile2.precision(3);
        if(myFile2.is_open()){
          for(int i = 0; i < num_asteroids; i++){
            myFile2 << ast[i].x << " ";
            myFile2 << ast[i].y << " ";
            myFile2 << ast[i].vx << " ";
            myFile2 << ast[i].vy << " ";
            myFile2 << ast[i].mass << endl;
          }
        }
        else{
          cerr << "Error creating the file!" << endl;
        }

        return 0;
}
