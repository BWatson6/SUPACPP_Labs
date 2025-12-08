#include "FiniteFunctions.h"
#pragma once


class GausFunction : public FiniteFunction
{
public:
    GausFunction(); // empty constructor
    GausFunction(double range_min, double range_max, double mean, double sigma, std::string outfile); // variable constructor



private:
    double GausEquation(double x); //
    double m_mean;
    double m_sigma;

};


