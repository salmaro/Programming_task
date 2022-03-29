#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isInteger(string strInput);
unsigned long optimalArea (double a, double b);
void maxFenceLength (double &a, double &b, unsigned long lengthFence);

int main(){

    string inputAction{}, inputMeter{};
    bool flagStart{false};
    unsigned long lengthFence{};
    double a{}, b{};

// Program ask if the user want to start calculating area
    do {
        cout << "Enter 'RUN' to start calculating farm area or  'EXIT' to and the program" << endl;
        cin >> inputAction;

        if (inputAction == "RUN") 
            flagStart = true;
        else if (inputAction == "EXIT") // stop program
            break;
        else
            cout << "Invalid word, please try again..." << endl; // validation correct input

    } while (inputAction != "RUN");

// Calucalting Area and Validation Input, when the user chose RUN
    while (flagStart){
        cout << "How many meters of fence have you got? (Enter a positive integer number)" << endl;
        cin >> inputMeter;
            // is inputMeter a integer number?
        if (!isInteger(inputMeter))
            cout << "This is not a positive integer number, please try again..." << endl;
        else {
            lengthFence = stoll(inputMeter); // convert input data to integer 
            if (lengthFence < 3){
                cout << "You don't have enough fence segments to build fence.\nYou should have more than 2 meters."<< endl;
                break;
                }
            else {

                maxFenceLength (a, b, lengthFence); // calculating max length of each farm  side

                cout << "The lenght of fence segment should be a = " 
                << round(a) << "[m] and b = " << b << "[m]"<<endl;

                cout << "The optimal farm area is: " << optimalArea(a, b) << "[m^2]. \n"
                "Good luck with farming!"<<endl; 

                flagStart = false; // ended loop iteration

            }
            
        }

    }

    return 0;
}

bool isInteger(string strInput){
    // fuction validates input data
    // input : value  write by user
    // output : it is or it isn't a integer number
    for (int i{0}; i < strInput.length(); i++){
        if (isdigit(strInput[i]) == false)
            return false;
    }
    return true;
}

void maxFenceLength (double &a, double &b, unsigned long lengthFence){
    // input : references to value with length of fence segments, how many meters of fence is available
    a = lengthFence / static_cast<double>(4); // calculate max length
    b = lengthFence - 2*round(a); 
}

unsigned long optimalArea (double a, double b){
    //  input : two length of 2 fence segments
    //  output : optimal area of farm
    return round(a) * round(b);
}