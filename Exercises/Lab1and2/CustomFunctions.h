#pragma once

float magnitude2D(float, float);
void print2DvectorData(std::vector<std::vector<float>>);
std::vector<std::vector<float> > readToVector(std::string, int);
std::vector<float> pqValues(std::vector<std::vector<float>>);
std::vector<float> SplitValues(std::vector<std::vector<float>>, int );