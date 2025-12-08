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
    myfunction.FiniteFunction::printInfo();
    //std::cout<<"exp test"<<M_PI<<std::endl;
    //Gaus function time
    GausFunction myGausfunction(-10.0, 10.0, -4, 1, "GausFunction");
    //myGausfunction.FiniteFunction::plotFunction();
    //myGausfunction.FiniteFunction::plotData(*myPointer, 1000);
    std::cout<<"range max is:"<<myGausfunction.rangeMax()<<std::endl;
    
    std::cout<<"range max for first is:"<<myfunction.rangeMax()<<std::endl;
    return 0;
}