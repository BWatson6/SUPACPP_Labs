#include "FiniteFunctions.h"
#pragma once


class GausFunction : public FiniteFunction
{
public:
    GausFunction(); // empty constructor
    GausFunction(double range_min, double range_max, double mean, double sigma, std::string outfile); // Overloaded constructor
    double meanVal();
    double sigmaVal();
    virtual double callFunction(double x);



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


    private:
        double CrystalEquation(double x);
        double m_xbar;
        double m_sigma;
        double m_alpha;
        double m_n;


};


