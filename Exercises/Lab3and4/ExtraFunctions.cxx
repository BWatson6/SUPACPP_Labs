#include "FiniteFunctions.h"
#include "ExtraFunctions.h"
#include <cmath>
#include <string>

// empty constructor

GausFunction::GausFunction(){
    //calls perant class constructor
    FiniteFunction();
    m_mean = 0;
    m_sigma = 1;
}


// initalised constructor
GausFunction::GausFunction(double range_min, double range_max, double mean, double sigma, std::string outfile){
    
    //calls perant
    
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
//Setters
void GausFunction::set_meanVal(double Mean) {m_mean = Mean;};
void GausFunction::set_sigmaVal(double Sigma) {m_sigma = Sigma;};

//something else
double GausFunction::callFunction(double x){
    return this->GausEquation(x);
}

void GausFunction::printInfo(){
    std::cout<<"\nrangeMin: " << m_RMin << std::endl;
    std::cout<<"rangeMax: " << m_RMax << std::endl;
    std::cout<<"intergral: " << m_Integral << std::endl;
    std::cout<<"function: " << m_FunctionName << std::endl;
    std::cout<<"perameters:"<<std::endl;
    std::cout<<"    mean: "<< m_mean<< std::endl;
    std::cout<<"    standard diviation "<< m_sigma<< std::endl;
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


void CauchyLorentzFunction::printInfo(){
    std::cout<<"\nrangeMin: " << m_RMin << std::endl;
    std::cout<<"rangeMax: " << m_RMax << std::endl;
    std::cout<<"intergral: " << m_Integral << std::endl;
    std::cout<<"function: " << m_FunctionName << std::endl;
    std::cout<<"perameters:"<<std::endl;
    std::cout<<"    x0: "<< m_x0<< std::endl;
    std::cout<<"    gamma: "<< m_lambda << std::endl;
}

//Getters
double CauchyLorentzFunction::x0Val(){return m_x0;};
double CauchyLorentzFunction::lambdaVal(){return m_lambda;};
//Setters
void CauchyLorentzFunction::set_x0Val(double X0) {m_x0 = X0;};
void CauchyLorentzFunction::set_lambdaVal(double Lambda) {m_lambda = Lambda;};

//##############################
// new class crystalball
//##############################

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
    A = pow((n/abs(alpha)),n)*exp(-pow(abs(alpha), 2)/2);
    B = n/abs(alpha) - abs(alpha);
    C = n/abs(alpha)*1/(n-1)*exp(-pow(abs(alpha), 2)/2);
    D = sqrt(M_PI/2)*(1+std::erf(abs(alpha)/sqrt(2)));
    N = 1/(sigma*(C+D));

    double check = (x-xbar)/sigma;
    if (check> -alpha){
        solution = N*exp(-pow((x-xbar),2)/(2*sigma*sigma));
    }

    else{
        solution = N*A*pow((B-(x-xbar)/sigma),-n);
    }
    return solution;
}

double CrystalBall::callFunction(double x){
    return this->CrystalEquation(x);
}


void CrystalBall::printInfo(){
    std::cout<<"\nrangeMin: " << m_RMin << std::endl;
    std::cout<<"rangeMax: " << m_RMax << std::endl;
    std::cout<<"intergral: " << m_Integral << std::endl;
    std::cout<<"function: " << m_FunctionName << std::endl;
    std::cout<<"perameters:"<<std::endl;
    std::cout<<"    x_bar: "<< m_xbar<< std::endl;
    std::cout<<"    sigma: "<< m_sigma << std::endl;
    std::cout<<"    alpha: "<< m_alpha << std::endl;
    std::cout<<"    n: "<< m_n << std::endl;
}

//Getters
double CrystalBall::xbarVal(){return m_xbar;};
double CrystalBall::sigmaVal(){return m_sigma;};
double CrystalBall::alphaVal(){return m_alpha;};
double CrystalBall::nVal(){return m_n;};
//Setters
void CrystalBall::set_xbarVal(double Xbar) {m_xbar = Xbar;};
void CrystalBall::set_sigmaVal(double Sigma) {m_sigma = Sigma;};
void CrystalBall::set_alphaVal(double Alpha) {m_alpha = Alpha;};
void CrystalBall::set_nVal(double N) {m_n = N;};