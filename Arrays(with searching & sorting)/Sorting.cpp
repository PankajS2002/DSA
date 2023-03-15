#include<bits/stdc++.h>
using namespace std;


/*
 int partition (int arr[], int low, int high)
    {
       int i=low;
       int j=high;
       int pivot=arr[low];
       
       while(i<j){
           
           while(arr[i]<=pivot && i<=high-1){
               i++;
           }
           while(arr[j]>pivot && j>=low+1){
               j--;
           }
          if(i<j){ 
           swap(arr[i],arr[j]);
}       }
       swap(arr[low],arr[j]);
       return j;
    }


 void quickSort(int arr[], int low, int high)
    {
      if(low<high){
        int part=partition(arr,low,high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);
      }
    }
    
  
   

void merge(int arr[],int l,int mid,int r){
   int low=l;
   int high=mid+1;
   vector<int> temp;

   while(low<=mid && high<=r){

      if(arr[low]<=arr[high]){
         temp.push_back(arr[low]);
          low++;
         
      }
      else{
        temp.push_back(arr[high]);
        high++;
        
      }

   }

   while(low<=mid){
    temp.push_back(arr[low]);
    low++;

   }

   while(high<=r){
    temp.push_back(arr[high]);
    high++;
   }

   for(int i=l;i<=r;i++){

    arr[i]=temp[i-l];

   }



}

void mS(int arr[],int l,int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    mS(arr,l,mid);
    mS(arr,mid+1,r);
    merge(arr,l,mid,r);

}
*/


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
   /* for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){

            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }

        }
    }
    */
    
    //Bubble Sort
   /* int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        counter++;
    }
    cout<<"sorted array"<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
*/

    //Insertion Sort
 /*for(int i=1;i<n;i++){
    int current = arr[i];
    int j=i-1;
    while (arr[j]>current && j>=0)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=current;
    
  }


      quickSort(arr,0,n-1);
      mS(arr,0,n-1);
       */ 

    


}