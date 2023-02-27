// It is collection of variables of similar data type
//An array is a contiguous memory location which holds data.
//Indexing starts from 0 in most of the programming languages

#include<iostream>
using namespace std;

int main(){

    int array[5]={10,20,30,40,50};

    cout<<array[3]<<endl; //output:-40

    //to take array from user 
    int n;
    cout<<"Enter the number of elements in an array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in an array"<<endl;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

     cout<<"Elements of this array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}