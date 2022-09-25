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

// char *removeSpaces(char *str)
// {
//     int i = 0, j = 0;
//     while (str[i])
//     {
//         if (str[i] != ' ')
//         str[j++] = str[i];
//         i++;
//     }
//     str[j] = '\0';
//     return str;
// }

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
    string login,Password;
    while(true){
        cout<<endl;
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
            slowCout("Remember: spaces not allowed, 5-16 characters!",30);
            cout<<endl;
            slowCout("Login:",30);
            cin>>login;
            cout<<endl;

            while(login.size()<5 || login.size()>16){
            if(login.size()>=5 && login.size()<16)
            {
                break;
            }
            else{
            slowCout("Try again! Invalid login lenght!",30);
            cout<<endl;
            slowCout("Login:",30);
            cin>>login;
                continue;
            }
            }
            cout<<endl;
            slowCout("Do you want to generate random password? Press Y/n:",30);
            int randomPass;
            randomPass=getch();
                switch(randomPass)
                {
                    case 'Y':
                    {
                        int passChar=0;
                        cout<<endl;

                        while(passChar<6 || passChar>32){
                        slowCout("Enter the number of characters (6-32):",30);
                        cin>>passChar;
                        if(passChar>=6 && passChar<=32)
                        {
                            break;
                        }
                        else{
                            slowCout("Try again with a number in range (6-32)",30);
                            Sleep(1500);
                            cout<<"\33[2K";
                            cout<<endl;
                            Transition(30,15,2);
                            continue;
                        }
                        }
                        slowCout("Your random password:",30);
                        Password = randomPassword(passChar);
                        slowCout(Password,30);
                        cout<<endl;
                        int flag=1;
                        while(flag==1){
                            slowCout("Do you want to generate a new one? Press Y/n:",30);
                            cout<<endl;
                            char newOne;
                            newOne=getch();
                            switch(newOne)
                            {
                                case 'Y':
                                {
                                    Password = randomPassword(passChar);
                                    cout<<endl;
                                    slowCout("Password:",30);
                                    slowCout(Password,30);
                                    cout<<endl;
                                    continue;
                                }
                                case 'n':
                                {
                                    flag=2;
                                    break;
                                }
                               
                            }

                        }
                        cout<<endl;
                        slowCout("You have 10 seconds to copy your password",30);
                        cout<<endl;
                        Sleep(2000);
                        cout<<"\33[2K";
                        for(int i=1; i<=10;i++)
                        {        
                            cout<<i<<"..."<<"\r";
                            Sleep(1000);  
                            cout<<"\33[2K";
                        }
                        cout<<endl;
                        cout << "\x1b[2J";

                        break;    
                    }
                    case 'n':
                    {

                        cout<<endl;
                        slowCout("Password:",30);
                        cin>>Password;
                        break;
                    }
                    Default: break;
                }
            slowCout("Please enter test sentence:",30);
            string test;
            cin.ignore();
            getline(cin,test);

            fstream file;
            file.open(login +".txt",ios::out|ios::app);
            file<<login<<endl<<Password;
            file<<endl<<test;
            
            file.close();

            Transition(50,15,2);

            slowCout("Data successfully saved",30); cout<<endl;

            slowCout("Login:",30); 
            cout<<login;
            cout<<endl;

            slowCout("Password:",30); 
            cout<<Password;
            cout<<endl;

            slowCout("Test sentence:",30); 
            cout <<"\"" <<test<<"\"" <<endl;
            cout<<endl;

            Sleep(4500);
            cout<<"\33[2K";
            break;
        }
        case '2':
        {
        Transition(30,15,1);
        slowCout("Sign in.",30);
        cout<<endl;
        string str1,str2,str3;
         
        string login2,password2;
        
        slowCout("Login:",30);
        cin>>login2;
        slowCout("Password:",30);
        cin>>password2;


         fstream file2;
        file2.open(login2 + ".txt");
        getline(file2,str1);
        getline(file2,str2);
        getline(file2,str3);
        file2.close();
       
        if(str1==login2 && str2==password2)
        {
            slowCout("Logged in!",30);
            cout<<endl;
            slowCout("Test message:" + str3,30);
            
        }
        else{
            slowCout("Incorrect login or password.",30);
        }
        
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

