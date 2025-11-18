#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

float magnitude2D(float x, float y){
    return std::sqrt(x*x + y*y);
}

int main()
{
    std::cout<<"hello world!"<<std::endl;

    float x, y;
    x = 7.5;
    y = 3.4;

    float magnitude;
    magnitude = std::sqrt(x*x + y*y);

    std::cout<<"vector size: "<<magnitude<<std::endl;

    std::string userinput_x, userinput_y;

    std::cout<<"please insert x component of the vector: ";
    std::cin >> userinput_x;

    std::cout<<"please insert y component of the vector: ";
    std::cin>> userinput_y;
    float x_val, y_val;
    x_val = std::stof(userinput_x);
    y_val = std::stof(userinput_y);

    float user_vector_magnitude = magnitude2D(x_val, y_val);
    std::cout<<"the magnitude of you vector is: "<<user_vector_magnitude<<"\n\n";

    // trying to load in data
    std::string inputfile = "../../Data/MysteryData20000.txt";
    std::ifstream data_file;
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
    std::vector<int> data;

    for (int i=0; i<5; i++){
        double dataValue;
        data_file >> dataValue;
        data.push_back(dataValue);
    }
    std::cout << "the data in the file is: "<< std::endl;
    for (auto dataVal : data){
        std:: cout << dataVal << std::endl;
    }

    data_file.close();
    return 0;
}