#include <iostream>
#include <string>
#include <vector>
#include "FiniteFunctions.h"
#include <filesystem> //To check extensions in a nice way
#include "CustomFunctions.h"
#include <cmath>
#include "ExtraFunctions.h"

int main(){

    FiniteFunction myfunction(-10.0, 10.0, "DefaultFunction");
    //FiniteFunction myfunction();
    
    //double test = myfunction.FiniteFunction::rangeMin();
    //std::cout << test << std::endl;
    
    //attempt to plot data
    myfunction.FiniteFunction::plotFunction();

    // loading in data
    std::vector<double> misteryData = DataTo1dArray("Outputs/data/MysteryData10206.txt");
    
    
    std::vector<double>* myPointer = &misteryData;
    myfunction.FiniteFunction::plotData(*myPointer, 1000);
    //myfunction.FiniteFunction::printInfo();
    //std::cout<<"exp test"<<M_PI<<std::endl;
    //Gaus function time
    std::cout<<"gaus function stuff starts"<<std::endl;

    GausFunction myGausfunction(-10.0, 10.0, -3, 1.5, "GausFunction");
    std::cout<<"just after subclass is called"<<std::endl;
    myGausfunction.FiniteFunction::plotFunction();
    myGausfunction.FiniteFunction::plotData(*myPointer, 1000);
    //std::cout<<"range max is:"<<myGausfunction.rangeMax()<<" it should be 10"<<std::endl;
    myGausfunction.plotFunction();
    myGausfunction.plotData(*myPointer, 1000);
    std::cout<<"mean value is "<<myGausfunction.meanVal()<<" and sigma is "<<myGausfunction.sigmaVal()<<std::endl;
    // next thing I want to do is over write something in the plotting to make it use a different function
    // for CL distribution
    CauchyLorentzFunction myCLfunc(-10, 10, -3, 1.5, "CLdistribution");
    myCLfunc.FiniteFunction::plotData(*myPointer, 1000);
    myCLfunc.FiniteFunction::plotFunction();


    // for the crystalball distribution
    CrystalBall myCrystal(-10.0, 10.0, -3, 1, 1, 3, "crystalBall");
    myCrystal.FiniteFunction::plotData(*myPointer, 1000);
    myCrystal.FiniteFunction::plotFunction();

    return 0;
}