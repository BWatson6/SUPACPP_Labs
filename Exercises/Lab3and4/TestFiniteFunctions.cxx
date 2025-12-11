#include <iostream>
#include <string>
#include <vector>
#include "FiniteFunctions.h"
#include <filesystem> //To check extensions in a nice way
#include "CustomFunctions.h"
#include <cmath>
#include "ExtraFunctions.h"
#include <random>
#include <time.h>


double GausTemp(double x){ //use while im writing the random sampling
    double sigma = 1;
    double mean = 0;
    double gaus = 1/(sigma*std::sqrt(2*M_PI))*std::exp(-0.5*((x-mean)/sigma)*((x-mean)/sigma));
    return gaus;
}

int main(){

    FiniteFunction myfunction(-10.0, 10.0, "DefaultFunction");
    //FiniteFunction myfunction();
    
    //double test = myfunction.FiniteFunction::rangeMin();
    //std::cout << test << std::endl;
    
    //attempt to plot data
    myfunction.FiniteFunction::plotFunction();

    // loading in data
    //std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData22020.txt");
    std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData03342.txt");
    //std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData15345.txt");

    std::vector<double>* myPointer = &misteryData;
    myfunction.FiniteFunction::plotData(*myPointer, 1000);
    //myfunction.FiniteFunction::printInfo();
    //std::cout<<"exp test"<<M_PI<<std::endl;
    //Gaus function time
    std::cout<<"gaus function stuff starts"<<std::endl;

    GausFunction myGausfunction(-10.0, 10.0, 1, 2.5, "GausFunction");
    std::cout<<"just after subclass is called"<<std::endl;
    myGausfunction.FiniteFunction::plotFunction();
    myGausfunction.FiniteFunction::plotData(*myPointer, 1000);
    myGausfunction.FiniteFunction::plotRandSamples(10000, 100);
    //std::cout<<"range max is:"<<myGausfunction.rangeMax()<<" it should be 10"<<std::endl;
    myGausfunction.plotFunction();
    myGausfunction.plotData(*myPointer, 1000);
    std::cout<<"mean value is "<<myGausfunction.meanVal()<<" and sigma is "<<myGausfunction.sigmaVal()<<std::endl;


    // next thing I want to do is over write something in the plotting to make it use a different function

    // for CL distribution
    CauchyLorentzFunction myCLfunc(-10, 10, 1, 2.5, "CLdistribution");
    myCLfunc.FiniteFunction::plotData(*myPointer, 1000);
    myCLfunc.FiniteFunction::plotFunction();
    myCLfunc.FiniteFunction::plotRandSamples(10000, 100);

    // for when I was trying to fing the right perameters
    /**/ 
    double input_xbar, input_sigma, input_alpha, input_n;
    std::string user_input1, user_input2, user_input3, user_input4;

    std::cout<<"\nvalue for xbar: ";
    std::cin >> user_input1;
    std::cout<<"\nvalue for sigma: ";
    std::cin >> user_input2;
    std::cout<<"\nvalue for alpha: ";
    std::cin >> user_input3;
    std::cout<<"\nvalue for n: ";
    std::cin >> user_input4;

    input_xbar = std::stod(user_input1);
    input_sigma = std::stod(user_input2);
    input_alpha = std::stod(user_input3);
    input_n = std::stod(user_input4);
    
    CrystalBall myCrystal(-10.0, 10.0, input_xbar, input_sigma, input_alpha, input_n, "crystalBall");

    // for the crystalball distribution
    
    //CrystalBall myCrystal(-10.0, 10.0, -3, 1.5, 2, 2, "crystalBall");
    myCrystal.FiniteFunction::plotData(*myPointer, 1000);
    myCrystal.FiniteFunction::plotFunction();
    myCrystal.FiniteFunction::plotRandSamples(10000, 100);
    //
    // I think the function used to sample from for each data set is random aswell
    // after some playing around  
    //

    // still need to do a print information function for each part and also tiedy up some of my code!
    // step 1 is to generate a random number:
    int n_random = 10; // number of random numbers
    // these will be the range of the function
    double r_min = -10; // min value
    double r_max = 10; // max value

    //uniform distribution of random numbers
    //auto seed = time(NULL); // returns a pointer to time_t type (a long int)
    std::random_device rd;
    std::mt19937 mtEngine{rd()}; // initalised seed based on current time
    std::uniform_real_distribution dicePDF{r_min, r_max}; // this is ok the spesific function comes later
    //not going to loop to begin with
    //for (int i=0; i< n_random; i++){
    double rand_x = dicePDF(mtEngine);
    std::cout << rand_x<<std::endl;
    //}

    // how do i do the crystal ball random distribution?? but maybe worry about that later?
    //next random number y from normal centered on rand_x
    std::normal_distribution Normal{rand_x, 1.0};
    double rand_y = Normal(mtEngine);
    std::cout<<"y value "<<rand_y<<std::endl;

    double funcRatio = GausTemp(rand_y)/GausTemp(rand_x);
    std::cout<<"gaus ratio is "<<funcRatio<<std::endl;
    if (funcRatio>1){
        funcRatio = 1.0;
    }
    std::cout<<"gaus ratio is "<<funcRatio<<std::endl;
    std::uniform_real_distribution TRandom{0.0, 1.0};
    double T = TRandom(mtEngine);
    std::cout<<"value for T is "<< T << std::endl; 
    std::vector<double> RandSample; // this will need to be outside the loop
    if (T<funcRatio){
        RandSample.push_back(rand_y);
    }
    else {
        RandSample.push_back(rand_x);
    }

    return 0;
}