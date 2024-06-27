/*
    Aaron Bevans 4/21/24
    CS 210 R4727 Programming Languages 24EW4
    PROJECT 3: CORNER GROCER

*/

#include <iostream> //standard i/o stream

#include <string> //string library operations

#include <fstream> //file stream operations library

#include <map> //library for map object operations.

// #include <unordered_map>

using namespace std;

//inventory tracking class.
class TrackInventoryItem {

    //private map data member

    private:
    //mapping grcoery item frequency.
    //validate code
        map<string, int> itemFreq;
    

    //public class member functions.
    public:


    //constructor method that tracks grocery items.
        TrackInventoryItem(){
        
            
            //file input stream
            std::ifstream infile("CS210_Project_Three_Input_File.txt");

            //condition checks if file can be open.
            //if flasy, error message is printed.
            if(!infile.is_open()){
                std::cerr << "Error when opening target file!" << std::endl;

            }

            
            std::string groceryItem;

            do{
                itemFreq[groceryItem]++;
            }while(infile >> groceryItem);

            
        }
    

    //method that tracks frequency of the grocery items.
        int groceryItemFrequency(const std::string& groceryItem){
            
            //initialize an item variable that locates a grocery item.
            auto item = itemFreq.find(groceryItem);
            
            /*
                condition that checks if item variable has not reached the end
                of the itemFreq map, it will return the current key.

                else returning successful termination.
            */
            if(item != itemFreq.end()){
                return item->second;
            }else{
                return 0;
            }
        }


    
    /*
    method that returns a list of grocery items and their frequency within text inventory file.
    */
        void getList(){
            for(auto item = itemFreq.begin(); item != itemFreq.end(); item++){
                std::cout << item-> first << " " << item->second << std::endl;
            }
        }



    //method that prints histogram of elements
        void histogramOutput(){

            //item itrerator variable that starts at the beginning of the map.
            auto item = itemFreq.begin();

            /*
                while item has not reached the end of the itemFreq map, print out the current
                element. increment as long as condition is true.
            */

           while(item != itemFreq.end()){
            cout << item->first << " ";

                int i = 0;
                while(i < item->second){
                    cout << "$";
                    i++;
                }
                cout << endl;

                item++;
           }
        }



    //write to backup data file.
        void writeToBackupFile(){
            ofstream outfile("frequency.dat"); 
            //variable that starts at the beginning of the map.
            auto item = itemFreq.begin();
            do{
                //print out map item followed by a empty string/white space.
                cout << item->first<< " ";
                item++;
            }while(item != itemFreq.end());
        
        }

        //function that exits the application.
        void exitApp(int returnStatus){
            std::exit(returnStatus);
        }

        //function that ouput error message.
        void errorMessage(){
            cout << endl << endl;
            std::cerr << "OOps! Something went wrong, please try again." << endl << endl;
        }

};

//main function.
int main(){
    //creating a TrackInventory object.
    TrackInventoryItem itemTracked;

    //do while loop that runs until condition until condition is false.
    do{
        //code that outputs user menu options.
        cout << "Menu Options:" << endl;
        cout << "1. Grocery item frequency" << endl;
        cout << "2. List of grocery item frequencies" << endl;
        cout << "3. History of item frequency" << endl;
        cout << "4. Exit Application" << endl;

        //input variable and input prompt.
        int option;
        cin >> option;
        string grocery;

        //conditions that check each input option.
        if(option == 1){
            
            cout << "Enter item: ";
            cin >> grocery;
            //output grocery item frequency.
            cout << "item frequency - " << grocery << ": " << itemTracked.groceryItemFrequency(grocery) << endl << endl;

        }else if(option == 2){
            itemTracked.getList();
            itemTracked.writeToBackupFile();
        }else if(option == 3){
            itemTracked.histogramOutput();
            itemTracked.writeToBackupFile();
        }else if(option == 4){
            itemTracked.writeToBackupFile();
            itemTracked.exitApp(0);
        }else{
            
            itemTracked.errorMessage();
        }
    
    }while(!false);

    return 0;
}


