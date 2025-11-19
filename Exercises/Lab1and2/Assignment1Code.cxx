# include <iostream>
#include <cmath>
#include <fstream>
#include <vector>


float Magnitude(float x, float y){
    return std::sqrt(x*x + y*y);
}

int main()
{
    // start by loading in some data
    std::string inputfile = "input2D_float.txt"; // loads the data as a string
    std::ifstream data_file; //
    data_file.open(inputfile);



    // a check
    if (!data_file.is_open()){
        std::cout<<"Error opening file"<<inputfile<<std::endl;
        return -1;
    }
    else{
        std::cout<<"File:"<<inputfile<<" opend successfully!"<<std::endl;
    }
    
    // reading data into variables
    std::vector<double> data;

    // to read in a spesific number of data points:
    std::cout<<"how many lines do you want to print? ";
    int maxValue;
    std::string user_input;
    std::cin >> user_input;

    maxValue = std::stoi(user_input); // converts string to integer

    for (int i=0; i<maxValue; i++){
        double dataValue;
        data_file >> dataValue;
        data.push_back(dataValue);
    }
    std::cout << "the data in the file is: "<< std::endl;
    for (auto dataVal : data){
        std:: cout << dataVal << std::endl;
    }

    data_file.close();
}