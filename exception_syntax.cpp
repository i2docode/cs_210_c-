#include <iostream>
using namespace std;

int GetWeight() {
   int weightParam;     // User defined weight
   
   // Get user data
   cout << "Enter weight (in pounds): ";
   cin >> weightParam;
   
   // Error checking, non-negative weight
   if (weightParam < 0) {
      throw runtime_error("Invalid weight.");
   }
   return weightParam;
}

int GetHeight() {
   int heightParam;     // User defined height
   
   // Get user data
   cout << "Enter height (in inches): ";
   cin >> heightParam;
   
   // Error checking, non-negative height
   if (heightParam < 0) {
      throw runtime_error("Invalid height.");
   }
   return heightParam;
}


int main(){
    // cout << "test" << endl;
    // return 0;

    /*
       Error-checking code is code a programmer writes to detect and handle errors 
       that occur during program execution. 

       An exception is a circumstance that a program was not designed to handle, 
       such as if the user enters a negative number.

       The following program, given a person's weight and height, outputs 
       a person's body-mass index (BMI), which is used to determine normal weight 
       for a given height. The program has no error checking.


    
    */

   /*
    int weightVal;       // User defined weight (lbs)
   int heightVal;       // User defined height (in)
   float bmiCalc;       // Resulting BMI
   char quitCmd;        // Indicates quit/continue

   quitCmd = 'a';
   
   while (quitCmd != 'q') {
      
      // Get user data
      cout << "Enter weight (in pounds): ";
      cin >> weightVal;
      
      cout << "Enter height (in inches): ";
      cin >> heightVal;
      
      // Calculate BMI value
      bmiCalc = (static_cast<float>(weightVal) / static_cast<float>(heightVal * heightVal)) * 703.0;
      
      // Print user health info
      // Source: http://www.cdc.gov/
      cout << "BMI: " << bmiCalc << endl;
      cout << "(CDC: 18.6-24.9 normal)" << endl;
      
      // Prompt user to continue/quit
      cout << endl << "Enter any key ('q' to quit): ";
      cin >> quitCmd;
   }
   */


   /*
        special constructs, try, throw, and catch, 
        known as exception-handling constructs, to keep error-checking 
        code separate and to reduce redundant checks.


        // ... means normal code
        ...
        try {
        ...   
        // If error detected
            throw objectOfExceptionType;
        ...
        }
        catch (exceptionType excptObj) {
        // Handle exception, e.g., print message
        }
        ...


        1. A try block surrounds normal code. A throw statement appears within a try block; 
        if reached, execution jumps immediately to the end of the try block.

        2. A catch clause immediately follows a try block; 
        if the catch was reached due to an exception thrown of the catch clause's parameter type, 
        the clause executes.

        A try block surrounds normal code, which is exited immediately if a throw statement executes.

        A throw statement appears within a try block; if reached, execution jumps immediately to the end of the try block. The code is written so only error situations lead to reaching a throw. 
        The throw statement provides an object of a particular type, such as an object of type "runtime_error", which is a class defined in the stdexcept library. The statement is said to throw an exception of the particular type. A throw statement's syntax is similar to a return statement.

        A catch clause immediately follows a try block; if the catch was reached due to an exception thrown of the catch clause's parameter type, the clause executes. The clause is said to catch the thrown exception. A catch block is called a handler because it handles an exception.     


   */

   string password;
   bool validPassword = false;

   while (!validPassword) {
      try {
         cin >> password;

         if (password.length() < 8) {
            throw runtime_error("Invalid");
         }

         validPassword = true;
         cout << "Accepted" << endl;
      }
      catch (runtime_error& excpt) {
         cout << "Error: " << excpt.what() << endl;
      }
   }

   /*
    exceptions with functions

    If an exception is thrown within a function and not caught within that function, 
    then the function is immediately exited and the calling function is checked for a handler, 
    and so on up the function call hierarchy.



   
   */


     int weightVal;        // User defined weight (lbs)
   int heightVal;        // User defined height (in)
   float bmiCalc;        // Resulting BMI
   char quitCmd;         // Indicates quit/continue
   
   quitCmd = 'a';

    while (quitCmd != 'q') {
        try {
            // Get user data
            weightVal = GetWeight();
            heightVal = GetHeight();
            
            // Calculate BMI and print user health info if no input error
            // Source: http://www.cdc.gov/
            bmiCalc = (static_cast<float>(weightVal) /
                        static_cast<float>(heightVal * heightVal)) * 703.0;
            
            cout << "BMI: " << bmiCalc << endl;
            cout << "(CDC: 18.6-24.9 normal)" << endl;
        }
        catch (runtime_error &excpt) {
            // Prints the error message passed by throw statement
            cout << excpt.what() << endl;
            cout << "Cannot compute health info." << endl;
        }
        
        // Prompt user to continue/quit
        cout << endl << "Enter any key ('q' to quit): ";
        cin >> quitCmd;
    }




   return 0;


}   
