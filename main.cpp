#include <iostream>
#include <random> //to generate random number
#include <ctime>
#include <ctype.h>
#include<limits>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"

int main()
{
    cout<<endl;
    cout<<RED<<"Welcome to number guessing game!"<<RESET<<endl;
    cout<<endl;
    cout<<CYAN<< "We have selected a number between 1 to 100. See if you can guess it in 5 turns or less. We will tell if the number is greater or less then the guessed number."<< RESET<<endl;
    // int magic_num = srand(time(0)) ;
    srand(time(0));
    int magic_num = rand() % 100 +1;
    int tries =5;

    do
    {
        int guess;
        cout<<CYAN<<"ENTER THE NUMBER: "<<RESET<<endl;

        while(!(cin >>guess) || guess<0 || guess>100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<RED<<"Invalid input. Please enter a number between 1 and 100: ";
        }

        tries--;

        if(guess == magic_num && tries>0)
        {
            cout<< GREEN <<"You Guessed the correct number!"<<RESET<<endl; 
            break;
        }
        else if(tries==0)
        {
            cout<<RED<<"Sorry You Lost! The number was: "<<magic_num<<RESET <<endl;
            break;
        }
        else if(guess>magic_num){
            cout<<GREEN<<"The magic number is less than "<<guess <<RESET<<endl;
        }
        else if(guess<magic_num)
        {
            cout<<GREEN<<"The magic number is greater than "<<guess<<RESET<<endl;
        }
        else{
            cout<<RED<<"Some errors occured!";
            break;
        }

    }while (tries!=0);

    return 0;
}
