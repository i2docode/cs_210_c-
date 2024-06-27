

/*
    gcc script.c -o script - command used to compile script into an executable file.
    also renames the script.c file to script.

    ./script - executes script.c.

    VAREIABLES in c

        - reference used to store information for future use.

            - declaration - basic structure of variable creation.

            - main data types in c; int, float, double, char.

            - type var_name can be called later in your code to assign, chage, compare, etc.

            - create multiple variables at the same time.
                - type (int, float, double, char) var_0, var_1, var_2


    DATA TYPES

        - int - whole numbers.

        - float - a number with possible decimals.

        - doubles - a number with possible decimals.

        - stores a single character/letter or number.

    printf() 

        - allows for text output to the terminal.

        - 
*/



// header needed for code block standard output.
#include <stdio.h>

// main function.
int main(){


    /*
        declaring empty variables
            int number;
            int test_value;
            char example_1;
            float integer;
    */

    //declaring/listing the same integer type variable in a row.
    int num_var;

    char example_char0;
    
    char example_char1;

    //declaring float integer.
    float float_var;

    num_var = 1;

    example_char0 = 'a';

    // example_char1 = 'b';
    //updating variables
    example_char1 = example_char0;

    float_var = 100.0;

    

    // code within the curly braces runs first.
    //addding new line character.
    printf("hello world!\n");

    //printf("output text", [optional parameters]);
    //[optional paranters] - allows adding of values dynamically into the string.
    /*
        symbol & type: %d -> int, %i -> int, %f -> double, %f -> float, %c -> char
    */
    printf("linux kernel development: %.2f\n", float_var);

    
    printf("first char: %c\n", example_char0);


    printf("second char: %c\n", example_char1);

    char example_char2 = 'b';

    printf("thirs char: %c\n", example_char2);
    
    /*
        constants
            - variables whose values do not change.
            - prevent any changes during execution once value is set at declaration.
            - const type variable_name.
            - best to use upper_case letters.
                - const type VARIABLE_NAME = value;
            -  




    */







    

    
}




