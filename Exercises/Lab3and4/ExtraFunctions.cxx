#include "FiniteFunctions.h"
#include "ExtraFunctions.h"
#include <cmath>

// empty constructor
GausFunction::GausFunction(){
    //calls perant class constructor
    FiniteFunction();
}

// initalised constructor
GausFunction::GausFunction(double range_min, double range_max, double mean, double sigma, std::string outfile){
    //calls perant
    std::cout<<"range min is:"<<range_min<<std::endl;
    // see if this helps

    FiniteFunction(range_min1, range_max1, outfile1);
    m_mean = mean;
    m_sigma = sigma;
}

double GausFunction::GausEquation(double x){
    double gaus = 1/(m_sigma*std::sqrt(2*M_PI))*std::exp(-0.5*((x-m_mean)/m_sigma)*((x-m_mean)/m_sigma));
    return gaus;
}


