# include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include "CustomFunctions.h"

float chiSqu(std::vector<float> Ovals, std::vector<float> Evals, std::vector<float> SigmaVals){
    float answer = 0.0;
    for (float i=0; i<Ovals.size(); i++){
        float topPart = (Ovals[i]-Evals[i])*(Ovals[i]-Evals[i]);
        float bottemPart = SigmaVals[i]*SigmaVals[i];
        answer += topPart/bottemPart;    
    }
    return answer;
}


int main()
{

    // to read in a spesific number of data points:
    std::cout<<"how many lines do you want to print? ";
    int maxValue;
    std::string user_input;
    std::cin >> user_input;

    maxValue = std::stoi(user_input); // converts string to integer
    
   // trying to load in data
    std::vector<std::vector<float>> DataArray = readToVector("input2D_float.txt", maxValue);

    print2DvectorData(DataArray);
    // calculating the magnitude of vectors

    for(int i=0; i<maxValue; i++){
        float x = DataArray[i][0];
        float y = DataArray[i][1];
        float magnitude = magnitude2D(x, y);
        std::cout<<"the magnitude of vector "<<i<<" is: "<< magnitude<<std::endl;
    }


    // testing my fit function
    std::cout<<"this is just before the pq function";
    std::vector<float> pqArray = pqValues(DataArray);
    std::cout<<"and this is just after";
    std::cout<<"p value is: "<< pqArray[0]<<"\nand q value is: "<<pqArray[1] <<std::endl;
    //ok I think this is working-ish ok atm 


    std::vector<float> xValue, yValue_calculated, yValue_original;
    xValue = SplitValues(DataArray, 0);
    yValue_original = SplitValues(DataArray, 1);
    std::cout<<"xValue file type "<< typeid(xValue).name()<<"\nyValue type "<< typeid(yValue_calculated).name()<<std::endl;
    // not allowed to use a for loop:
    

    for(float x:xValue){
        yValue_calculated.push_back(x*pqArray[0] + pqArray[1]);
    }
    
    std::cout<<"my array contains:\n";
    for (int j=0; j < maxValue; j++){
        std::cout<<xValue[j];
        std::cout<<" "<<yValue_calculated[j]<<std::endl;
    }

    //need to load in othe stuff as well
    std::vector<std::vector<float>> ErrorVector = readToVector("error2D_float.txt", maxValue);

    std::vector<float> y_error = SplitValues(ErrorVector, 1);
    float chiSquare = chiSqu(yValue_original, yValue_calculated, y_error);
    std::cout<<"the chi squared term is: "<<chiSquare<<"\n";


    return 0;
}