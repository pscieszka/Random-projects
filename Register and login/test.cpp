#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <random>
#include <string>
#include <algorithm>


using namespace std;


void Transition(int dotsNum,int delayTime,int linesNum)
{
    for(int k=0; k<linesNum;k++)
    {

    for(int i=0; i<=dotsNum;i++)
    {
        cout<<"."<<"";
        Sleep(delayTime);
        cout<<"\33[2K";
    }
    cout<<endl;
    }
}

void slowCout(string str, int delay_time)
{
    for (int i = 0; i<=str.size(); i++)
    {
        cout<<str[i];
        Sleep(delay_time);
    }
    Sleep(200);
}

string randomPassword(int charNum)
{
    string characters("0123456789abcdefghijklmnopqrstuvmxyz");
    random_device rd;
    mt19937 generator(rd());

    shuffle(characters.begin(), characters.end(), generator);

    return characters.substr(0,charNum);

}
int main()
{

 int passChar;
    cout<<endl;

                        
    slowCout("Enter the number of characters (6-32):",30);
    cin>>passChar;
    slowCout("You random password:",30);
     slowCout(randomPassword(passChar),30);
     cout<<endl;
     Sleep(3000);
     Transition(30,15,2);
    return 0;
}