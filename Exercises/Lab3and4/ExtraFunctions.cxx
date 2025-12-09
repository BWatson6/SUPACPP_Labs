#include "FiniteFunctions.h"
#include "ExtraFunctions.h"
#include <cmath>
#include <string>

// empty constructor

GausFunction::GausFunction(){
    std::cout<<"I AM IN THE WRONG PLACE (guas function)"<<std::endl;
    //calls perant class constructor
    FiniteFunction();
    m_mean = 0;
    m_sigma = 1;
}


// initalised constructor
GausFunction::GausFunction(double range_min, double range_max, double mean, double sigma, std::string outfile){
    std::cout<<"I am in the right place (gaus function)"<<std::endl;
    //calls perant
    std::cout<<"range min is:"<<range_min<<std::endl;
    // seems like there is already an instance of the finite function perhaps use setters instead?? 
    // FiniteFunction(range_min, range_max, outfile);
    FiniteFunction::setRangeMin(range_min);
    FiniteFunction::setRangeMax(range_max);
    FiniteFunction::setOutfile(outfile);
    m_mean = mean;
    m_sigma = sigma;
}

double GausFunction::GausEquation(double x){
    double gaus = 1/(m_sigma*std::sqrt(2*M_PI))*std::exp(-0.5*((x-m_mean)/m_sigma)*((x-m_mean)/m_sigma));
    return gaus;
}

//Getters
double GausFunction::meanVal(){return m_mean;};
double GausFunction::sigmaVal(){return m_sigma;};


//something else
double GausFunction::callFunction(double x){
    return this->GausEquation(x);
}

//##################################
// NEW CLASS FUNCTIONS  Cauchy Lorentz

CauchyLorentzFunction::CauchyLorentzFunction(){
    //empty constructor
    FiniteFunction();
    m_x0 = 0;
    m_lambda = 1;
}

CauchyLorentzFunction::CauchyLorentzFunction(double range_min, double range_max, double x0, double lambda, std::string outfile){
    // not so empty constructor
    FiniteFunction::setRangeMin(range_min);
    FiniteFunction::setRangeMax(range_max);
    FiniteFunction::setOutfile(outfile);
    m_x0 = x0;
    m_lambda = lambda;
}

double CauchyLorentzFunction::CLequation(double x){
    double bottemLine = M_PI*m_lambda*(1+((x-m_x0)/m_lambda)*((x-m_x0)/m_lambda));
    return 1/bottemLine;
}

double CauchyLorentzFunction::callFunction(double x){
    return this->CLequation(x);
}


//##############################
// new class crystalball

CrystalBall::CrystalBall(){
    // the empty one
    m_xbar = 0;
    m_sigma = 1;
    m_alpha = 1; // must be greater than 0
    m_n = 2; // must be greater than 1
}

CrystalBall::CrystalBall(double range_min, double range_max, double xbar, double sigma, double alpha, double n, std::string outfile){
    // will be the full one
        m_xbar = xbar;
        m_sigma = sigma;
        m_alpha = alpha; // must be greater than 0
        m_n = n; // must be greater than 1
        FiniteFunction::setRangeMin(range_min);
        FiniteFunction::setRangeMax(range_max);
        FiniteFunction::setOutfile(outfile);
}

double CrystalBall::CrystalEquation(double x){
    double xbar, sigma, alpha, n, A, B, C, D, N, solution;
    xbar = m_xbar;
    sigma = m_sigma;
    alpha = m_alpha;
    n = m_n;
    A = pow((n/pow(abs(alpha), 2)),n)*exp(-pow(abs(alpha), 2)/2);
    B = n/abs(alpha) - abs(alpha);
    C = n/abs(alpha)*1/(n-1)*exp(-pow(abs(alpha), 2)/2);
    D = sqrt(M_PI/2)*(1+std::erf(abs(alpha)/sqrt(2)));
    N = 1/(sigma*(C+D));

    double check = (x-xbar)/sigma;
    if (check> -alpha){
        solution = N*exp(-(x-xbar)/(2*sigma*sigma));
    }

    else{
        solution = N*A*pow((B-(x-xbar)/sigma),-n);
    }
    return solution;
}

double CrystalBall::callFunction(double x){
    return this->CrystalEquation(x);
}