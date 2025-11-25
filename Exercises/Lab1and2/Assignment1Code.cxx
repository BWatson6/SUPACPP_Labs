#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include "CustomFunctions.h"



int main()
{
    int k;
    bool go = true;

    // to read in a spesific number of data points:
    std::cout<<"\nhow many lines do you want to print? \n";
    int maxValue;
    std::string user_input;
    std::cin >> user_input;

    maxValue = std::stoi(user_input); // converts string to integer
    
   // trying to load in data
    std::vector<std::vector<float>> DataArray = readToVector("input2D_float.txt", maxValue);
    // print out the data from the file
    print2DvectorData(DataArray);


    while(go){
        std::cout<<"\n\nWhat function would you like to use on the data?\n(1)Find distance from origin  \n(2)Find fitline perameters  \n(3)x^y \n(4)exit code"<<std::endl;
        std::cin >> k;

        switch (k)
        {
        case 1:{
            // calculating the magnitude of vectors
            std::vector<float> vectorMagnitude = magnitude2Darray(DataArray);
            std::cout<<"\n---points distance from origin---\n";
            for(int i=0; i<DataArray.size(); i++){ //printing out results
                std::cout<< vectorMagnitude[i] <<std::endl;
            }
            std::cout<<"------\n";
            SaveQuestion(vectorMagnitude, "outputVectorMag.txt");

            break;
        }
        case 2: {
            // calculating peramters of fitline
            std::vector<std::vector<float>> ErrorVector = readToVector("error2D_float.txt", maxValue);
            std::vector<float> pqArray = pqValues(DataArray);
            std::cout<<"\n---Line fit perameters---\n";
            std::cout<<"\np value is: "<< pqArray[0]<<"\nq value is: "<<pqArray[1] <<std::endl;
            
            //calculating expected y values useing the fit perameters 
            std::vector<float> xValue, yValue_calculated, yValue_original;
            xValue = SplitValues(DataArray, 0);
            yValue_original = SplitValues(DataArray, 1);
            //calculating the new y values
            for(float x:xValue){
                yValue_calculated.push_back(x*pqArray[0] + pqArray[1]);
            }
            // commented out code used to print out the new y values calculated with the fit perameters
            /*
            std::cout<<"my array contains:\n";
            for (int j=0; j < yValue_calculated.size(); j++){
                std::cout<<xValue[j];
                std::cout<<" "<<yValue_calculated[j]<<std::endl;
            }
            */

            std::vector<float> y_error = SplitValues(ErrorVector, 1); // uncertainty in the y values
            //calculating and printing chi squared
            float chiSquare = chiSqu(yValue_original, yValue_calculated, y_error);
            std::cout<<"chi squared term is: "<<chiSquare<<"\n------\n";

            pqArray.push_back(chiSquare);
            SaveQuestion(pqArray, "outputLinefitperam_andChi2.txt");
            break;

        }

        case 3: {
            // x^y
            std::cout<<"\n---x^y---\n";
            std::vector<float> xtoyVector = XtoPowerYvector(DataArray);

            for (int i=0; i<DataArray.size(); i++){
                std::cout<<xtoyVector[i]<<std::endl;
            }
            std::cout<<"------\n";
            SaveQuestion(xtoyVector, "outputXtoTheY.txt"); //checking if the given data should be saved
            break;

        }

        case 4: {
            std::cout<<"\n\n---STOPING CODE---\n\n";
            go = false;
            break;
        }
        
        
        default:{
            std::cout<<"you did not pick a number between 1 and 4"<<std::endl;
            break;
        } //defalt
        } // switch
    } // while
    return 0;
}