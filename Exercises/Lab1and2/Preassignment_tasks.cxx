#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>

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

    std::string line;
    std::string inputfile = "input2D_float.txt";
    std::ifstream infile;
    infile.open(inputfile); // the text file is opened up?
    std::vector<std::vector<float> > DataArray; // define the vector that everything is stored in

    // a check
    if (!infile.is_open()){
        std::cout<<"Error opening file"<<inputfile<<std::endl;
        return -1;
    }
    else{
        std::cout<<"File:"<<inputfile<<" opend successfully!"<<std::endl;
    }
    

    // reading data into variables
    int counter = 0;
    while (std::getline(infile, line)){ // this goes through each line of the infile?
        std::vector<float> row; // defining each row
        if (counter>0){ // this counter is to avoid reading the header line
            
            //std::cout<<"line is: "<< line<<"\n"; // cheack to see if we are reading the right thing
            std::stringstream ss(line); // magic string stream??
            float j; // use j to be hold each number
            while (ss>>j){ // goes through the string stream
                row.push_back(j); // first float
                if (ss.peek()==','){
                    ss.ignore();
                }
                //row.push_back(std::stof(line));
            }
                
            
        
            DataArray.push_back(row);
        }
        counter++;

    }

    for (std::vector<float> &row : DataArray){ // going through each row in DataArray
        for (float &c : row){ // going through each possition in each row
            std::cout << c<< "  "; // here we are getting the same number twice?
        }
        std::cout<< '\n';
    }


    infile.close();
    return 0;
}