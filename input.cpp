#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>
#include <math.h>

using namespace std;

// const double GRAVITY = 6.674e-5;
// const double INTERVAL = 0.1;
// const double DMIN = 2.0;
const double WIDTH = 200;
const double HEIGHT = 200;
// const double RAY_WIDTH = 4;
const double MASS = 1000;
const double SDM = 50;


struct asteroids {
        double x, y, mass;
};

struct planets {
        double x, y;
};

void random(const unsigned int seed, int num_asteroids, int num_planets, std::vector<asteroids> &ast, std::vector<planets> &pl){
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
                cout.setf(ios::fixed,ios::floatfield);
                cout.precision(3);

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

                myFile << "0.000" << " ";
                myFile << pos_ray << endl;

        }



        else{
                cerr << "Error creating the file!" << endl;
        }
/*
   //-------------------------HERE STARTS THE COMPUTATION OF FORCES//-------------------------//

   //Here we need to create an array attraction of size num_asteroids+num_planets-1

   for(int i = 0; i < num_asteroids; i++){
    for(int j = 0; j < (num_asteroids+num_planets-1); j++){
      if(j!=i){
        if(j<num_asteroids){
          ast[i].attraction[j] = sqrt(pow(ast[i].x-ast[j].x,2)+pow(ast[i].y-ast[j].y,2));
        }
        else{
          ast[i].attraction[j] = sqrt(pow(ast[i].x-pl[j-(num_asteroids-1)].x,2)+pow(ast[i].y-pl[j-(num_asteroids-1)].y,2));
        }
      }
    }
   }

 */

        return 0;
}
