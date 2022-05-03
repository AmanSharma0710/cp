#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int timesteps = 30;
    int volatility = 2;  //2 %
    int max_simulations = 5000;
    float starting_price = 600;
    float path[max_simulations][timesteps+1];
    // Timesteps + 1 is for the starting price at Day 0 to be at the start of every array 
    /*Your Code Here*/
    
    /*You need to sample different paths using simulations and store them in a 2D array of Float type*/
    ofstream outputfile;
    outputfile.open("paths.txt");

    for(int i = 0; i<max_simulations; i++)
    {
        for(int j = 0; j<(timesteps+1); j++)
        {
            outputfile<<path[i][j]<<" ";
        }
        outputfile<<endl;
    }
    outputfile.close();


}