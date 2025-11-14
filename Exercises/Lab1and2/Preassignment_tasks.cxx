#include <iostream>
#include <cmath>


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

    return 0;
}