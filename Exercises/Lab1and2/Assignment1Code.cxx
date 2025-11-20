# include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>

float Magnitude(float x, float y){
    return std::sqrt(x*x + y*y);
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
                
            }

            DataArray.push_back(row);
        }
        counter++;

    }
    int NumbLines = 0;
    for (std::vector<float> &row : DataArray){ // going through each row in DataArray
        if (NumbLines<maxValue){
            NumbLines++;
            for (float &c : row){ // going through each possition in each row
                std::cout << c<< "  "; // here we are getting the same number twice?
            }
            std::cout<< '\n';
        }
    }

    // calculating the magnitude of vectors

    for(int i=0; i<maxValue; i++){
        float x = DataArray[i][0];
        float y = DataArray[i][1];
        float magnitude = Magnitude(x, y);
        std::cout<<"the magnitude of vector "<<i<<" is: "<< magnitude<<std::endl;

    }

    infile.close();
}