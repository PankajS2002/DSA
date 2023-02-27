#include<iostream>
using namespace std;


int main(){
//Linear
     //Accepting array from user
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
    cout<<endl;


    //accepting key to find 
    int key;
    cout<<"enter key to find from array"<<endl;
    cin>>key;
    //searching
    for(int i=0;i<n;i++){
         if(arr[i]==key){
            cout<<"Key found at:"<<i<<" index";
         }
    }
}