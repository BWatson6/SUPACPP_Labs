#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>

float magnitude2D(float x, float y){
    return std::sqrt(x*x + y*y);
}

void print2DvectorData(std::vector<std::vector<float>> Data){
    
    for (std::vector<float> &row : Data){ // going through each row in DataArray
        std::cout<<"row: ";
        for (float &c : row){ // going through each possition in each row
            std::cout << c<< "  ";
        }
        std::cout<< '\n';
        
    }
}


std::vector<std::vector<float> > readToVector(std::string fileName, int maxLine){
    std::string line;
    std::ifstream infile;
    infile.open(fileName); // the text file is opened up?
    std::vector<std::vector<float> > DataArray; // define the vector that everything is stored in


    if (!infile.is_open()){
        std::cout<<"Error opening file"<<fileName<<std::endl;
        
    }

    else{
        std::cout<<"File:"<<fileName<<" opend successfully!"<<std::endl;
    }

    int counter = 0;
    int i = 0;
    while (std::getline(infile, line)){ // this goes through each line of the infile?
        
        if (i<=maxLine){
            i++;
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

    }
    infile.close();
    return DataArray;

}

std::vector<float> pqValues(std::vector<std::vector<float>> xyData){
    //some thing is wrong with my p and q
    float xy_sum, xx_sum, y_sum, x_sum;
    xy_sum = 0.0;
    xx_sum = 0.0;
    x_sum = 0.0;
    y_sum = 0.0;

    int arrayLength = xyData.size();
    
    for (int i=0; i< xyData.size(); i++){
        xy_sum += xyData[i][0]*xyData[i][1];
        xx_sum += xyData[i][0]*xyData[i][0];
        x_sum += xyData[i][0];
        y_sum += xyData[i][1];
    }
    float p, q;
    p = (arrayLength*xy_sum-x_sum*y_sum)/(arrayLength*xx_sum-x_sum*x_sum);
    q = (xx_sum*y_sum-xy_sum*x_sum)/(arrayLength*xx_sum-x_sum*x_sum);
    std::vector<float> pqVals;
    pqVals.push_back(p);
    pqVals.push_back(q);
    return pqVals;  
}


std::vector<float> SplitValues(std::vector<std::vector<float>> vector2d, int index){
    std::vector<float> array;

    for (std::vector<float> row : vector2d){
        //std::cout<< "row: "<<row[0]<<std::endl;
        array.push_back(row[index]);
    }
    return array;
}


float chiSqu(std::vector<float> Ovals, std::vector<float> Evals, std::vector<float> SigmaVals){
    float answer = 0.0;
    for (float i=0; i<Ovals.size(); i++){
        float topPart = (Ovals[i]-Evals[i])*(Ovals[i]-Evals[i]);
        float bottemPart = SigmaVals[i]*SigmaVals[i];
        answer += topPart/bottemPart;    
    }
    return answer;
}
