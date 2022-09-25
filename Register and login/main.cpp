#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <random>
#include <algorithm>
#include <string>


using namespace std;

string randomPassword(int charNum)
{
    string characters("0123456789abcdefghijklmnopqrstuvmxyz");
    random_device rd;
    mt19937 generator(rd());

    shuffle(characters.begin(), characters.end(), generator);

    return characters.substr(0,charNum);

}


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

int main(){
    int num;
    string login,password;
    while(true){
    slowCout("1. Create account",30); cout<<endl;
    slowCout("2. Sign in",30); cout<<endl;     //after bad pass, 3 next tries
    slowCout("3. Exit",30); cout<<endl;
    slowCout("Pick a number:",30); 
    num=getch();
    switch(num)
    {
        case '1':
        {
            Transition(30,15,3);
            slowCout("Login:",30);
            cin>>login;
            cout<<endl;
            slowCout("Do you want to generate random password? Press Y/n:",30);
            int randomPass;
            randomPass=getch();
                switch(randomPass)
                {
                    case 'Y':
                    {
                        int passChar;
                        cout<<endl;

                        
                        slowCout("Enter the number of characters (6-32):",30);
                        cin>>passChar;
                        slowCout("Your random password:",30);
                        slowCout(randomPassword(passChar),30);
                        cout<<endl;
                        Sleep(3000);
                        Transition(30,15,2);
                        break;
                        
                        
                    }
                    case 'n':
                    {
                        break;
                    }
                    Default: break;



                }

            slowCout("Password:",30);
            cin>>password;


            fstream file;
            file.open("data.txt",ios::out|ios::app);
            file<<login<<" "<<password;
            file.close();
            break;
        }
        case '2':
        {
            cout<<"2es";
            break;
        }
        case '3':
        {
            exit(0);
        }
        default:
        cout<<endl;
        cout<<"There are only 2 options. 1 or 2."<<endl;
        Sleep(2000);
        break;
    }
        }
    
return 0;}

