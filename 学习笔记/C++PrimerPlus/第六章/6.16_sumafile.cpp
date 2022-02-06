// sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream>
#include <cstdlib>
const int SIZE = 60;
int main(){
    using namespace std;
    char filename[SIZE];
    ifstream inFile;
    cout << "Enter name of datafile:";
    cin.getline(filename,SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open file: " << filename << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }

    double value;
    double sum;
    int count = 0;

    inFile >> value;
    while (inFile.good())
    {
        ++count;
        sum += value;
        inFile >> value;
    }
    
    if (inFile.eof())
    {
        cout << "End of file reached." << endl;
    }
    else if (inFile.fail())
    {
        cout << "Input terminated by data mismatch." << endl;
    }
    else
    {
        cout << "Input terminated by unknown reason." << endl;
    }
    if (count == 0)
    {
        cout << "No data processed!" << endl;
    }
    else
    {
        cout << "Number of values processed: " << count << endl;
        cout << "Sum of values processed: " << sum << endl;
        cout << "Average of values processed: " << (double)sum / count << endl;
    }
    
    inFile.close();
    return 0;
}