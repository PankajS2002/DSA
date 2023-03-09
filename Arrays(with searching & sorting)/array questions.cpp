#include<iostream>
using namespace std;

//1)Peak Element(Given an array arr[] of integers. Find a peak element i.e. an element that is not smaller than its neighbors).Only answer function
int peakElement(int arr[], int n)
{
    int s=0;
    int e=n-1;
    while(s<=e){
       int mid=(s+e)/2;
       if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1]) ){
           return mid;
       }
       else if(arr[mid]<=arr[mid+1]){
           s=mid+1;
       }
       else{
           e=mid-1;
       }
   }
    return -1;
}




//2)Kth smallest element(Given an array and a number K where K is smaller than the size of the array. Find the K’th smallest element in the given array. Given that all array elements are distinct.)
 int kthSmallest(int arr[], int l, int r, int k) {

        priority_queue<int> mh;
        int n=r-l+1;
        for(int i=0;i<k;i++){
            mh.push(arr[i]);
        }
        for(int i=k;i<n;i++){
         if(arr[i]<mh.top()){
             mh.pop();
                mh.push(arr[i]);
            }
        }
    
         return mh.top();
    
    
 }

 //3)Given a vector of N positive integers and an integer X. The task is to find the frequency of X in vector.
 int findFrequency(vector<int> v, int x){
        int count=0;
        for(int i=0;i<v.size();i++){
         if(v[i]==x){
            count++; 
         }
        }
        return count;


   //4)Sort an array of 0s, 1s and 2s. Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order
   
   void sort012(int a[], int n)
    {
          int i = 0 ,  countzero = 0 , countone = 0 ,  counttwo = 0 ;  
    while ( i < n )  
    {  
        if ( a [ i ] == 0 )  
        {  
            countzero = countzero + 1 ;  
        }  
        else if ( a [ i ] == 1 )  
        {  
            countone = countone + 1 ;  
        }  
        else  
        {  
            counttwo = counttwo + 2 ;  
        }  
        i = i + 1 ;  
    }  
    for  ( i = 0 ; i < countzero ; i++ )  
    {  
        a[ i ] = 0 ;  
    }  
    for ( i = countzero ; i < countzero + countone ; i++ )  
    {  
        a[ i ] = 1 ;  
    }  
    for ( i = countzero + countone ; i < n ; i++ )  
    {  
        a[ i ] = 2 ;  
    }  
    }     

//5) Subarray of given sum
 vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int> v;
        // Your code here
        long long sum = arr[0]; int start = 0;
        for(int i=1; i<=n; i++)
        {
            // sum = sum + arr[i];
            // cout<<arr[0];
            // // if(i<n)
            // sum = sum + arr[i];
            while(sum>s && start<i-1)
            {
                sum = sum - arr[start];
                start++;
            }
            if(sum == s)
            {
                v.push_back(start+1);
                v.push_back(i);
                break; //imp
            }
            if(i<n)
            sum = sum + arr[i];
        }
        if(v.size() == 0) v.push_back(-1);
        return v;
    }

//6) Move all negative elements to end
    void segregateElements(int arr[],int n)
    {
        int a[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                a[j]=arr[i];
                j++;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                a[j]=arr[i];
                j++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
    
    }

//7) Union of two arrays
       int doUnion(int a[], int n, int b[], int m)  {
       unordered_map<int, int> map;
       for(int i=0;i<n;i++){
           map[a[i]]++;
       }
       for(int i=0;i<m;i++){
           map[b[i]]++;
     
       }
       
       return map.size();
    }


//8)Count the triplet
int countTriplet(int arr[], int n)
	
	{  
	    sort(arr,arr+n);
	    
        int count=0;
        
        for(int i=n-1;i>=2;i--){
        int s=0;
        int e=i-1;
          while(s<e){    
            if((arr[s]+arr[e])==arr[i]){
                count++;
                s++;
                e--;
                
            }
            else if((arr[s]+arr[e])<arr[i]){
                s++;
            }
            else{
                e--;
            }
              
          }
            
        }
        return count;
	}

//9)cyclically rotate an array by one 
void rotate(int arr[], int n)
{
    for(int i=n-1;i>0;i--){
        
        swap(arr[i],arr[i-1]);

    }
}

//10)Missing number in array
int MissingNumber(int array[], int n) {
    int sum=0;
      for(int i=0;i<n-1;i++){
          sum=sum+array[i];
      }
      int sum2=(n*(n+1))/2;
     int ans=sum2-sum;
     return ans;
}