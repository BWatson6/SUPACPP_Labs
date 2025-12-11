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
    
    //attempt to plot data
    myfunction.FiniteFunction::plotFunction();

    // loading in data
    //std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData22020.txt");
    std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData03342.txt"); // looks Gausian or maybe Crystalball
    //std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData15345.txt");

    std::vector<double>* myPointer = &misteryData;


    myfunction.FiniteFunction::plotData(*myPointer, 1000);
    myfunction.FiniteFunction::printInfo();


    //
    //Gaus function
    //

    GausFunction myGausfunction(-10.0, 10.0, 1, 2.5, "GausFunction");

    myGausfunction.FiniteFunction::plotFunction();
    myGausfunction.FiniteFunction::plotData(*myPointer, 1000);
    myGausfunction.FiniteFunction::plotRandSamples(10000, 100);
    
    //myGausfunction.plotFunction();
    //myGausfunction.plotData(*myPointer, 1000);
    
    myGausfunction.printInfo();

    //
    // for CL distribution
    //
    CauchyLorentzFunction myCLfunc(-10, 10, 1, 2.5, "CLdistribution");
    myCLfunc.FiniteFunction::plotData(*myPointer, 1000);
    myCLfunc.FiniteFunction::plotFunction();
    myCLfunc.FiniteFunction::plotRandSamples(10000, 100);

    myCLfunc.printInfo();

    //
    // Crystalball Function
    //

    // for when I was trying to fing the right perameters
    /* 
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
    */

    
    CrystalBall myCrystal(-10.0, 10.0, 1, 2.5, 2, 2, "crystalBall");
    myCrystal.FiniteFunction::plotData(*myPointer, 1000);
    myCrystal.FiniteFunction::plotFunction();
    myCrystal.FiniteFunction::plotRandSamples(10000, 100);

    myCrystal.printInfo();

    return 0;
}