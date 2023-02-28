#include<iostream>
using namespace std;

int binarysearch(int key, int arr[], int n){
      int s=0;
      int e=n-1;
     

      while(s<=e){

         int mid=(s+e)/2;
        if(arr[mid]==key){
           return mid;
        }
        else if(arr[mid]>key){ 
            e=mid-1;

        }
        else{
            s=mid+1;
        }
      }
return -1;
}


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
    /*linearsearching
    for(int i=0;i<n;i++){
         if(arr[i]==key){
            cout<<"Key found at:"<<i<<" index";
         }
    }*/
   

      cout<<binarysearch(key,arr,n);


}