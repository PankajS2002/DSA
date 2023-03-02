// It is collection of variables of similar data type
//An array is a contiguous memory location which holds data.
//Indexing starts from 0 in most of the programming languages

#include<iostream>
using namespace std;

int main(){

    /*int array[5]={10,20,30,40,50};

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
*/


    //2d array
      int n,m;
      cout<<"enter number of rows"<<endl;
      cin>>n;
      cout<<endl;
      cout<<"enter number of columns"<<endl;
      cin>>m;
      cout<<endl;
      int arr[n][m];
      cout<<"enter elements"<<endl;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
      }


      cout<<"2d array is"<<endl;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }

        cout<<endl;
      }







}