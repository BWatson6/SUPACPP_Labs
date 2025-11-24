# include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include "CustomFunctions.h"

float XtoPowerY(float x, float y){
    int y_round = (int)y;
    //std::cout<<y_round;
    if (y_round==0){
        return 1;
    }
    else{
        y_round--;
        y = (float)y_round;
        return x * XtoPowerY(x, y);
    }
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

    for(int i=0; i<DataArray.size(); i++){
        float x = DataArray[i][0];
        float y = DataArray[i][1];
        float magnitude = magnitude2D(x, y);
        std::cout<<"the magnitude of vector "<<i<<" is: "<< magnitude<<std::endl;
    }


    // testing my fit function
    
    std::vector<float> pqArray = pqValues(DataArray);
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
    for (int j=0; j < yValue_calculated.size(); j++){
        std::cout<<xValue[j];
        std::cout<<" "<<yValue_calculated[j]<<std::endl;
    }

    //need to load in othe stuff as well
    std::vector<std::vector<float>> ErrorVector = readToVector("error2D_float.txt", maxValue);

    std::vector<float> y_error = SplitValues(ErrorVector, 1);
    float chiSquare = chiSqu(yValue_original, yValue_calculated, y_error);
    std::cout<<"the chi squared term is: "<<chiSquare<<"\n";

    std::cout<<"\n----------\n\nx^y is:\n\n";
    //std::cout<<"data size is:"<<DataArray.size()<<std::endl;

    float a = 7.9;
    int b = (int)a;
    float c = (float)b;
    // ok so this thing above works
    float test = XtoPowerY(3.0 ,3.4);
    //std::cout<<" is: "<<test<<"\n";
    
    for (int i=0; i<DataArray.size(); i++){
        float x_val = DataArray[i][0];
        float y_val = DataArray[i][1];
        std::cout<<x_val<<" "<<y_val<<"\n";
        float result = XtoPowerY(x_val, y_val);
        std::cout<<result<<std::endl;

    }
    std::string OutputFileName = "Assignment1OutputFile.txt";
    // create an ofstream object
    std::ofstream outStream;
    // open a file as destination for the output stream
    outStream.open(OutputFileName);

    // check if output file opened correctly
    if (!outStream.is_open()) {
        std::cout<<"error opening file: "<< OutputFileName<< std::endl;
        return -1;
    }
    else {
        std::cout<<"output file"<<OutputFileName<<" opened successfully!"<<std::endl;
    }
    
    for (int i=0; i<pqArray.size(); i++){
        outStream<<pqArray[i]<<std::endl;
    }
    outStream.close(); //always close the file aswell

    return 0;
}