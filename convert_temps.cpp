#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    //fahrenheit temp variable
    int f;

    //celsuis temp variable
    int c;

    //city name var;
    string name_of_city;
    
    //writing to output file using file stream object.
    ofstream outFile("CelsiusTemperature.txt");

    //reading file from file-stream object.
    ifstream inFile("FahrenheitTemperature.txt");

    //verify that input file can be opened.
    if(!inFile){

        //print error if program cannot open file.
        cout << "error: cannot open target file." << endl;
    }

    //iterate through every line within input file.
    do{
        //convert to celsius from fahrenheit.
        c = static_cast<int>(round(((f - 32) * 5.0 /9.0)));

        //writing out name and newly converted celsius temperatures to new file.
        outFile << name_of_city << " " << c << endl;

    }while(inFile >> name_of_city >> f);

    //closing input-file.
    inFile.close();

    //closing output file.
    outFile.close();

    //main() returns no errors.
    return 0;
}