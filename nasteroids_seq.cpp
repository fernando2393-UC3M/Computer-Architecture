#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>
#include <math.h>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

using clk = high_resolution_clock;

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
                //Now check for repeated position -> Remove and recalculate
                for(int j = 0; j < i; j++) {
                        if(ast[j].x == ast[i].x && ast[j].y == ast[i].y) {
                                ast.erase(ast.begin()+i);
                                i--;
                        }
                }
        }

        for (int i = 0; i < num_planets; i++) {
                //Planets position
                int rem = i%4;
                int aux = i;
                int aux1 = i;
                switch (rem) {
                //This generates planets in the borders and checks if the position is repeated, then iteration is done again
                case 0:
                        pl.push_back(planets());
                        pl[i].x = 0;
                        pl[i].y = ydist(re);
                        pl[i].mass = 10 * mdist(re);
                        for (int j = 0; j < aux; j++) {
                                if (pl[j].x == pl[aux1].x && pl[j].y == pl[aux1].y) {
                                        pl.erase(pl.begin()+i);
                                        i--;
                                }
                        }
                        break;
                case 1:
                        pl.push_back(planets());
                        pl[i].x = xdist(re);
                        pl[i].y = HEIGHT;
                        pl[i].mass = 10 * mdist(re);
                        for (int j = 0; j < aux; j++) {
                                if (pl[j].x == pl[aux1].x && pl[j].y == pl[aux1].y) {
                                        pl.erase(pl.begin()+i);
                                        i--;
                                }
                        }
                        break;
                case 2:
                        pl.push_back(planets());
                        pl[i].x = WIDTH;
                        pl[i].y = xdist(re);
                        pl[i].mass = 10 * mdist(re);
                        for (int j = 0; j < aux; j++) {
                                if (pl[j].x == pl[aux1].x && pl[j].y == pl[aux1].y) {
                                        pl.erase(pl.begin()+i);
                                        i--;
                                }
                        }
                        break;
                case 3:
                        pl.push_back(planets());
                        pl[i].x = xdist(re);
                        pl[i].y = 0;
                        pl[i].mass = 10 * mdist(re);
                        for (int j = 0; j < aux; j++) {
                                if (pl[j].x == pl[aux1].x && pl[j].y == pl[aux1].y) {
                                        pl.erase(pl.begin()+i);
                                        i--;
                                }
                        }
                        break;
                default:
                        cout << "Invalid position" << endl;
                }
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
        f=f/pow(dist, 2);
        f=f*sin(ang);

        if(f>MAXFORCE) {
                f=200; //Truncate to 200 if maxforce is surpassed
        }
        return f;
}

double computeAcc(int length, std::vector<double> vforces, double mass){
        double acc = 0;

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

void releaseGalactus(double target, std::vector<asteroids> &ast, int num_asteroids){
        unsigned long aux = num_asteroids; //Aux var number of ast to not to be modified
        for(unsigned long i=0; i<aux; i++) {
                if(ast[i].y >= (target - (RAY_WIDTH/2)) && ast[i].y <= (target + (RAY_WIDTH/2))) { //If asteroid is inside the range
                        aux--; //Reduce aux -> number of alive asteroids
                        ast.erase(ast.begin()+i); //Erase asteroid from vector
                        i--; //As number reduced, next asteroids go one position back, so iterate over the same position
                }
        }
}

int main(int argc, char const *argv[]) {
        auto t1 = clk::now();

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
                        myFile << pl[i].y << " ";
                        myFile << pl[i].mass << endl;
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

        int col=num_asteroids+num_planets;
        std::vector<std::vector<double> >distMatrix(num_asteroids, vector<double>(col));
        std::vector<std::vector<double> >angleMatrix(num_asteroids, vector<double>(col));
        std::vector<std::vector<double> >forcesMatrixX(num_asteroids, vector<double>(col));
        std::vector<std::vector<double> >forcesMatrixY(num_asteroids, vector<double>(col));

        //SIMULATION
        for(int t=0; t<num_iterations; t++) {
                accx=0;
                accy=0;
                for(int i=0; i< num_asteroids; i++) {
                        for(int j=0; j<(num_asteroids+num_planets); j++) {
                                if(i!=j) { //Avoid evaluate i with itself
                                        if(j<num_asteroids) { //ASTEROID
                                                //Dist
                                                distMatrix[i][j]=computeDistance(ast[i].x, ast[i].y, ast[j].x, ast[j].y);
                                                if(distMatrix[i][j]>DMIN) {
                                                        //Angle
                                                        angleMatrix[i][j]=computeAngle(ast[i].x, ast[i].y, ast[j].x, ast[j].y);
                                                        //Force
                                                        if(forcesMatrixX[i][j]==0 && forcesMatrixY[i][j]==0) { //Check if it has not been previously set
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

                                                if(distMatrix[i][j]>DMIN) {
                                                        //Angle
                                                        angleMatrix[i][j]=computeAngle(ast[i].x, ast[i].y, pl[j-num_asteroids].x, pl[j-num_asteroids].y);

                                                        //Force
                                                        forcesMatrixX[i][j]=computeForceX(ast[i].mass, pl[j-num_asteroids].mass, distMatrix[i][j], angleMatrix[i][j]);

                                                        forcesMatrixY[i][j]=computeForceY(ast[i].mass, pl[j-num_asteroids].mass, distMatrix[i][j], angleMatrix[i][j]);

                                                }
                                        }
                                }
                        }
                        //Results should be updated once the rows are filled so all the forces acting on an asteroid are computed
                        //acc
                        accx=computeAcc(num_planets+num_asteroids, forcesMatrixX[i], ast[i].mass);
                        accy=computeAcc(num_planets+num_asteroids, forcesMatrixY[i], ast[i].mass);
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
                releaseGalactus(pos_ray, ast, num_asteroids);
        }

        //After computing the movement due to the forces, the laser ray must be
        //activated, locating all the asteroids that are inside its range of influence.

        //All asteroids whose vertical coordinate is at a distance less or equal
        //than RAY_WIDTH/2 from the position of the ray (in the y axis) will be destroyed.

        //The destruction of these asteroids imply the removal of these asteroids from the program


        //OUTPUT DATA
        ofstream myFile2 ("out.txt");
        myFile2.setf(ios::fixed,ios::floatfield);
        myFile2.precision(3);
        if(myFile2.is_open()) {
                for(int i = 0; i < num_asteroids; i++) {
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

        auto t2 = clk::now();
        auto diff = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);

        cout << diff.count() << endl;

        return 0;
}
