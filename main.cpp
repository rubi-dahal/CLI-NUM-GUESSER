#include <iostream>
#include <random> //to generate random number
#include <ctime>
#include <ctype.h>
#include<limits>
using namespace std;

int main()
{
    // int magic_num = srand(time(0)) ;
    srand(time(0));
    int magic_num = rand() % 100 +1;
    int tries =5;

    do
    {
        int guess;
        cout<<"ENTER THE NUMBER: ";

        while(!(cin >>guess) || guess<0 || guess>100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input. Please enter a number between 1 and 100: ";
        }

        tries--;

        if(guess == magic_num && tries>0)
        {
            cout<< "You Guessed the correct number!"<<endl; 
            break;
        }
        else if(tries==0)
        {
            cout<<"Sorry You Lost! The number was: "<<magic_num <<endl;
            break;
        }
        else if(guess>magic_num){
            cout<<"The magic number is less than "<<guess <<endl;
        }
        else if(guess<magic_num)
        {
            cout<<"The magic number is greater than "<<guess<<endl;
        }
        else{
            cout<<"Some errors occured!";
            break;
        }

    }while (tries!=0);

    return 0;
}
