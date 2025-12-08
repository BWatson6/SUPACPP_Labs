#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>

float magnitude2D(float x, float y){
    // function calculates the distance of a point from the origin 
    return std::sqrt(x*x + y*y);
}


std::vector<float> SplitValues(std::vector<std::vector<float>> vector2d, int index){
    // function takes in a 2D vector and returns a colum of that vector depending on the spesified index 
    std::vector<float> array;

    for (std::vector<float> row : vector2d){
        //std::cout<< "row: "<<row[0]<<std::endl;
        array.push_back(row[index]);
    }
    return array;
}


std::vector<float> magnitude2Darray(std::vector<std::vector<float> > xyArray){
    // takes in a vector of different points and finds the distance from the origin for each one
    // outputs a vector of the magnitudes
    std::vector<float> xArray, yArray, magnitudeArray;
    xArray = SplitValues(xyArray, 0);
    yArray = SplitValues(xyArray, 1);
    for (int i=0 ; i<xArray.size(); i++){
        magnitudeArray.push_back(magnitude2D(xArray[i], yArray[i]));
    }
    return magnitudeArray;
}


void print2DvectorData(std::vector<std::vector<float>> Data){
    //prints out values from a 2d vector to the terminal
    std::cout<<"\n---Data from file---\n";
    for (std::vector<float> &row : Data){ // going through each row in DataArray
        
        for (float &c : row){ // going through each possition in each row
            std::cout << c<< "  ";
        }
        std::cout<< '\n';
        
    }
    std::cout<<"------";
}


std::vector<std::vector<float> > readToVector(std::string fileName, int maxLine){
    // reads a spesified text file into a 2d vector
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
    // finds the fit perameters input a 2d vector of x and y values
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





float chiSqu(std::vector<float> Ovals, std::vector<float> Evals, std::vector<float> SigmaVals){
    // chalculates chi squared takes in vectors of observed values, expected values and expected errors
    float answer = 0.0;
    
    for (float i=0; i<Ovals.size(); i++){
       
        //std::cout<<"ovals: "<<Ovals[i]<<" evals: "<< Evals[i]<<std::endl;
        float topPart = (Ovals[i]-Evals[i])*(Ovals[i]-Evals[i]);
        
        float bottemPart = SigmaVals[i]*SigmaVals[i];
        answer += topPart/bottemPart;    
    }
    return answer;
}


float XtoPowerY(float x, float y){
    //calculates x^y where y is rounded to the closest integer
    
    int y_round = (int)round(y);
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

std::vector<float> XtoPowerYvector(std::vector<std::vector<float>> xyArray){
    // calculates x^y but the input is a 2D vector with the x and y vals
    std::vector<float> xVector, yVector, AnsVector;
    xVector = SplitValues(xyArray, 0);
    yVector = SplitValues(xyArray, 1);
    for (int i=0; i<xVector.size(); i++){
        AnsVector.push_back(XtoPowerY(xVector[i], yVector[i]));
    }
    return AnsVector;
}


void SaveQuestion(std::vector<float> OutFile, std::string filename){
    // the check to save data and also the saveing of the data itself is done in this function
    std::cout<<"would you like to save the resulting data?\n(1) Yes\n(2) No\n";
    int i;
    std::cin>> i;
    switch (i)
    {
    case 1:{
        std::string OutputFileName = filename;
        // create an ofstream object
        std::ofstream outStream;
        // open a file as destination for the output stream
        outStream.open(OutputFileName);

        // check if output file opened correctly
        if (!outStream.is_open()) {
            std::cout<<"error opening file: "<< OutputFileName<< std::endl;
            
        }
        else {
            std::cout<<"output file"<<OutputFileName<<" opened successfully!"<<std::endl;
        }
    
        for (int i=0; i<OutFile.size(); i++){
            outStream<<OutFile[i]<<std::endl;
        }
        outStream.close(); //always close the file aswell


        break;
    }
    case 2:{
        break;
    }
    
    default:{
        std::cout<<"you did not write a valid answer\n";
        break;
    }
    }
    return;
    
}

std::vector<double> DataTo1dArray(std::string filename){
     // reads a spesified text file into a 2d vector
    std::string line;
    std::ifstream infile;
    infile.open(filename); // the text file is opened up?
    std::vector<double>  DataArray; // define the vector that everything is stored in


    if (!infile.is_open()){
        std::cout<<"Error opening file"<<filename<<std::endl;
        
    }

    else{
        std::cout<<"File:"<<filename<<" opend successfully!"<<std::endl;
    }
    while(std::getline(infile, line)){
        DataArray.push_back(std::stod(line));
    }
    return DataArray;
} 