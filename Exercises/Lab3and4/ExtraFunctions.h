#include "FiniteFunctions.h"
#pragma once


class GausFunction : public FiniteFunction
{
public:
    GausFunction(); // empty constructor
    GausFunction(double range_min, double range_max, double mean, double sigma, std::string outfile); // Overloaded constructor
    //getters
    double meanVal();
    double sigmaVal();
    // setters
    void set_meanVal(double Mean);
    void set_sigmaVal(double Sigma);
    //
    virtual double callFunction(double x);
    virtual void printInfo();



private:
    double GausEquation(double x); //
    double m_mean;
    double m_sigma;

    
};

class CauchyLorentzFunction: public FiniteFunction
{
    public:
        CauchyLorentzFunction(); //empty constructor
        CauchyLorentzFunction(double range_min, double range_max, double x0, double lambda, std::string outfile);
        virtual double callFunction(double x);
        virtual void printInfo();
        //getters
        double x0Val();
        double lambdaVal();
        //setters
        void set_x0Val(double X0);
        void set_lambdaVal(double Lambda);


    private:
        double CLequation(double x);
        double m_x0;
        double m_lambda;
};

class CrystalBall: public FiniteFunction
{
    public:
        CrystalBall(); 
        CrystalBall(double range_min, double range_max, double xbar, double sigma, double alpha, double n, std::string outfile);
        virtual double callFunction(double x);
        virtual void printInfo();
        //getters
        double xbarVal();
        double sigmaVal();
        double alphaVal();
        double nVal();
        //setters
        void set_xbarVal(double Xbar);
        void set_sigmaVal(double Sigma);
        void set_alphaVal(double Alpha);
        void set_nVal(double N);


    private:
        double CrystalEquation(double x);
        double m_xbar;
        double m_sigma;
        double m_alpha;
        double m_n;


};


