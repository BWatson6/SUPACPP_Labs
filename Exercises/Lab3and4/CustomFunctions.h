#pragma once

float magnitude2D(float, float);

void print2DvectorData(std::vector<std::vector<float>>);

std::vector<std::vector<float> > readToVector(std::string, int);

std::vector<float> pqValues(std::vector<std::vector<float>>);

std::vector<float> SplitValues(std::vector<std::vector<float>>, int );

float chiSqu(std::vector<float>, std::vector<float>, std::vector<float>);

std::vector<float> magnitude2Darray(std::vector<std::vector<float> >);

float XtoPowerY(float, float);

std::vector<float> XtoPowerYvector(std::vector<std::vector<float>>);

void SaveQuestion(std::vector<float>, std::string);

std::vector<double> DataTo1dArray(std::string);
