#include <iostream>
#include <time.h>
#include <windows.h> 

using namespace std;
int number;

void quicksort(int *array, int left, int right)
{
    int v=array[(left+right)/2];
    int i,j,x;
    i=left;
    j=right;
    do
    {
        while(array[i]<v) i++;
        while(array[j]>v) j--;
        if(i<=j)
        {
            x=array[i];
            array[i]=array[j];
            array[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>left) quicksort(array,left, j);
    if(i<right) quicksort(array, i, right);
}



int main(){
    
    cout<<"Array size: ";
    cin>>number;

    int *array;
    array = new int[number];
    srand(time(NULL));
    for(int i=0; i<number; i++)
    {
        array[i] = rand()%100+1;
        cout<<array[i]<<", ";
    }
    quicksort(array, 0, number-1);
    cout<<endl; cout<<endl;
    for(int j=0; j<number; j++)
    {
        cout<<array[j]<<", ";
    }

    delete [] array;
    return 0;
}
