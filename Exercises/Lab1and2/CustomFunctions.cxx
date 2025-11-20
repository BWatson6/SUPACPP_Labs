#include <iostream>
#include <cmath>
#include <vector>


float magnitude2D(float x, float y){
    return std::sqrt(x*x + y*y);
}

void print2DvectorData(std::vector<std::vector<float>> Data, int N){
    int NumbLines = 0;
    for (std::vector<float> &row : Data){ // going through each row in DataArray
        if (NumbLines<N){
            NumbLines++;
            for (float &c : row){ // going through each possition in each row
                std::cout << c<< "  "; // here we are getting the same number twice?
            }
            std::cout<< '\n';
        }
    }
}
