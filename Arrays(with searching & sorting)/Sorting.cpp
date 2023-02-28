#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"enter number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array"<<endl;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
//Selection Sort
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){

            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

        }
    }
    cout<<"sorted array"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}