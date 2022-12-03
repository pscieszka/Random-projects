#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
int main(){
    fstream data;

    string what;
    string pass;

    cout<<"what is the password for?"<<endl;
    cin>>what;

    cout<<"password: "<<endl;
    cin>>pass;


  data.open ("data.txt");
  data << what<<"\n"<<pass;

  data.close();

  return 0;
}