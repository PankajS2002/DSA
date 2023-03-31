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

//12)Minimize the Heights
 int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        
        int diff=arr[n-1]-arr[0];
        int mini,maxi;
        
        for(int i=1;i<n;i++){
            if(arr[i]-k<0){
                continue;
            }
            
            maxi=max(arr[i-1]+k,arr[n-1]-k);
            mini=min(arr[0]+k,arr[i]-k);
            
            diff=min(diff,maxi-mini);
        }
        return diff;
    }

//13)Maximum Triplet product
long long maxTripletProduct(long long arr[], int n)
    {
          sort(arr,arr+n);
      
        return max(arr[n-1]*arr[n-2]*arr[n-3],arr[0]*arr[1]*arr[n-1]);
    }

//14)Find duplicate number in N+1 array
int findDuplicate(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while (slow != fast);
        
        fast = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;

    }

//15)Minimum number of jumps
int minJumps(int arr[], int n){
        if (n <= 1)
         return 0;
 
        if (arr[0] == 0)
            return -1;
     
        int maxReach = arr[0];
        int step = arr[0];
        int jump = 1;
     
        
        for (int i = 1; i < n; i++) {
            
            if (i == n - 1)
                return jump;
    
            maxReach = max(maxReach, i + arr[i]);
            step--;
            if (step == 0) {
                jump++;
                if (i >= maxReach)
                    return -1;
                step = maxReach - i;
            }
        }
     
        return -1;
    }
//16)Kadane's algorithm
long long maxSubarraySum(int arr[], int n){
        
      int maxi=INT_MIN;
      int curr=0;
      
      for(int i=0;i<n;i++){
          curr=curr+arr[i];
          curr=max(curr,arr[i]);
          maxi=max(curr,maxi);
      }
      return maxi;
    }
};

//17)Merge without extra space

  int nextGap(int gap){
             if (gap <= 1){
              return 0;
              }
             return (gap / 2) + (gap % 2);
           }
           
           
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
             int temp;
             int gap =  ((n+m) / 2) + ((n+m) % 2); /*value of gap */
             
             while (gap > 0) {
               int ptr1 = 0, ptr2 = gap;
               while (ptr2 < (n+m)) {
               /* comparing elements in first array - if arr1[ptr2]<arr1[ptr1] swap their values */
               if (ptr2 < n && arr1[ptr1] > arr1[ptr2]) {
                swap(arr1[ptr1] , arr1[ptr2]);
               }
              /* comparing elements in both arrays */
              else if (ptr2 >= n && ptr1 < n && arr1[ptr1] > arr2[ptr2 - n]) {
                swap(arr1[ptr1] , arr2[ptr2 -n]);
               }
              /* comparing elements in the second array */
               else if (ptr2 >= n && ptr1 >= n && arr2[ptr1 - n] > arr2[ptr2 - n]) {
                  swap(arr2[ptr1 - n] , arr2[ptr2 - n]);
              }
              ptr2++;
              ptr1++;
                   }
             gap = nextGap(gap);
            }
        
        } 

//18) Merge intervals
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0) {
            return mergedIntervals; 
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0]; 
        
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]); 
            } else {
                mergedIntervals.push_back(tempInterval); 
                tempInterval = it; 
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals; 
    }

//19) subarray with 0 sum
bool subArrayExists(int arr[], int n)
    { 
        unordered_map<int,int> m;
        int sum=0;
       
        
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum==0 || arr[i]==0 || m[sum]){
                return 1;
            }
            else{
                m[sum]=1;
            }
        }
        return 0;
        
    }


//20)count inversion
long long int total_inversion(long long arr[],long long l,long long m,long long r)

    {

        long long n1=m-l+1,n2=r-m;

        long long left[n1],right[n2];

        

        for(long long int i=0;i<n1;i++)

        {

            left[i]=arr[l+i];

        }

        

        for(long long int j=0;j<n2;j++)

        {

            right[j]=arr[m+1+j];

        }

        

        long long int i=0,j=0,k=l,res=0;

        while(i<n1 and j<n2)

        {

            if(left[i]<=right[j])

            {

                arr[k]=left[i];

                i++;

            }

            else

            {

                arr[k]=right[j];

                j++;

                res+=(n1-i);

            }

            k++;

        }

        

        while(i<n1)

        {

            arr[k]=left[i];

            i++,k++;

        }

        

        while(j<n2)

        {

            arr[k]=right[j];

            j++,k++;

        }

        

        return res;

    }

    

    long long int cnt_inversion(long long arr[],long long l,long long r)

    {

        long long int res=0;

        if(r>l)

        {

            long long m=l+(r-l)/2;

            res+=cnt_inversion(arr,l,m);

            res+=cnt_inversion(arr,m+1,r);

            

            res+=total_inversion(arr,l,m,r);

            

        }

        

        return res;

    }
   
    long long int inversionCount(long long arr[], long long N)
    {   
        return cnt_inversion(arr,0,N-1);
       
    }

    //21)best time to buy and sell stock
    int maxProfit(vector<int>& prices) {
         if(prices.size()==0){
            return 0;
        }
        
        int profit=0;
        int mini=prices[0];
        int maxi=0;
        
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            profit=prices[i]-mini;
            maxi=max(maxi,profit);
        }
        return maxi;
    }
    //22)count pairs with given sum
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> m;
        int ans=0;
        
        for(int i=0;i<n;i++){
            int value=k-arr[i];
            if(m[value]){
                ans+=m[value];
            }
            m[arr[i]]++;
        }
        return ans;
    }

    //23)common elements in 3 sorted array
     vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,k=0,j=0;
            vector<int> ans;
            
            int prev1, prev2, prev3;
            prev1 =prev2 =prev3 =INT_MIN;
            while(i<n1 && j<n2 && k<n3){
                while(A[i]==prev1 && i<n1)
                 i++;
                while(B[j]==prev2 && j<n2)
                 j++;
                while(C[k]==prev3 && k<n3)
                 k++;
            
             if(A[i]==B[j] && B[j]==C[k]){
                 ans.push_back(A[i]);
                 prev1=A[i];
                 prev2=B[j];
                 prev3=C[k];
                 i++;
                 j++;
                 k++;
             }
             else if(A[i]<B[j]){
                 prev1=A[i];
                 i++;
             }
             else if(B[j]<C[k]){
                 prev2=B[j];
                 j++;
             }
             else{
                 prev3=C[k];
                 k++;
             }
            }
            return ans;
            }

            
24)Rearrange positive and negative numbers
            	void rearrange(int arr[], int n) {
	    int newarr[n];
	    int j=0;
	    int k=0;
	    int l=0;
	    int m=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
	            newarr[j]=arr[i];
	            j++;
	            k++;
	            m++;
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            newarr[j]=arr[i];
	            j++;
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	       if(l<m && k<n){ 
	        if(i%2==0){
	            arr[i]=newarr[l];
	            l++;
	        }
	        else{
	            arr[i]=newarr[k];
	            k++;
	        }
	       }
	       else{
	           while(l<m){
	               arr[i]=newarr[l];
	               l++;
	           }
	           while(k<n){
	               arr[i]=newarr[k];
	               k++;
	           }
	       }
	    }
	    
	    
	    
	    
	}

25)subarray with 0 sum
 bool subArrayExists(int arr[], int n)
    { 
        unordered_map<int,int> m;
        int sum=0;
       
        
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            if(sum==0 || arr[i]==0 || m[sum]){
                return 1;
            }
            else{
                m[sum]=1;
            }
        }
        return 0;
        
    }

    26)maximum product subarray
    	long long maxProduct(vector<int> arr, int n) {
	 long long int maxi=INT_MIN, prod=1;
	 for(int i=0;i<n;i++){
	     prod*=arr[i];
	     maxi=max(maxi,prod);
	     if(prod==0){
	         prod=1;
	     }
	 }
	 
	 prod=1;
	 for(int i=n-1;i>=0;i--){
	     prod*=arr[i];
	     maxi=max(maxi,prod);
	     if(prod==0){
	         prod=1;
	     }
	 }
	 return maxi;
	}

    27)longest consequtive subsequence
    int findLongestConseqSubseq(int arr[], int N)
    {
       unordered_set<int> s;
        for(int i=0;i<N;i++){
            s.insert(arr[i]);
        }
        
        int ans=0;
        for(int i=0;i<N;i++){
            if(s.find(arr[i]-1)!=s.end()){
                continue;
            
            }else{
                int count=0;
                int current=arr[i];
                while(s.find(current)!=s.end()){
                    count++;
                    current++;
                }
                
                ans=max(ans,count);
            } 
        }
        return ans;
    }

    28)count more than n/k occurences
     int countOccurence(int arr[], int n, int k) {
          unordered_map<int, int> mp;
      int count = 0;
      for(int i = 0; i<n;i++){
          mp[arr[i]]++;
      }
      
      for(auto it: mp){
          if(it.second > (n/k)){
              count++;
          }
      }
      return count;
    }

    29)buy and sell a share more than twice

int maxProfit(vector<int>&price){
    int n=price.size();
   int profit[n];
   
	for (int i = 0; i < n; i++){
		profit[i] = 0;
	}

	int max_price = price[n - 1];
	
	for (int i = n - 2; i >= 0; i--) {
		if (price[i] > max_price){
			max_price = price[i];
		}

		profit[i]
			= max(profit[i + 1], max_price - price[i]);
	}

	int min_price = price[0];
	
	for (int i = 1; i < n; i++) {
		if (price[i] < min_price){
			min_price = price[i];
		}

		profit[i] = max(profit[i - 1],
						profit[i] + (price[i] - min_price));
	}
	int result = profit[n - 1];

	return result;
   
}

30)array subset of another array

string isSubset(int a1[], int a2[], int n, int m) {
 
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++){
        map[a1[i]]++;
    }
    
    for(int j = 0; j < m; j++){
        if(map[a2[j]] < 1 ){
            return "No";
        }
        else{
            map[a2[j]]--;
        }
        
        
    }
    
    return "Yes";
    
}
31)find triplet that sum to given value
bool find3Numbers(int A[], int n, int X)
    {
         sort(A,A+n);
         for(int i=0;i<n-2;i++){
             int next=i+1;
             int end=n-1;
             while(next<end){
                 if(A[i]+A[next]+A[end]==X){
                     return 1;
                 }
                 else if(A[i]+A[next]+A[end]>X){
                     end--;
                 }
                 else{
                     next++;
                 }
             }
             
         }
         
         return 0;
    }

32)trapping rain water
 long long trappingWater(int arr[], int n){
       int left[n];
       int right[n];
       int max1=arr[0];
       int max2=arr[n-1];
      
      
       for(int i=0;i<n;i++){
           max1=max(max1,arr[i]);
           left[i]=max1;
       }
       
       
       for(int j=n-1;j>=0;j--){
           max2=max(max2,arr[j]);
           right[j]=max2;
       }
       
       
       long long sum=0;
       
       for(int i=0;i<n;i++){
           sum=sum+ (min(left[i],right[i]))
       }
    }

    33)chocolate distribution problem
    long long findMinDiff(vector<long long> a, long long n, long long m){
      sort(a.begin(),a.end());
      
      long long mini=INT_MAX;
      
      for(int i=0;i<=(n-m);i++){
          mini=min(mini, a[m-1+i]-a[i]);
      }
      return mini;
      
    
    } 

    34)smallest subarray with sum greater than x

    int smallestSubWithSum(int arr[], int n, int x)
    {
       int start=0;
       int end=0;
       int min_len=INT_MAX;
       int sum=0;
       while(end<n){
           
           while(sum<=x && end<n){
               sum+=arr[end++];
                
           }
           
           while(sum>x && start<n){
               min_len=min(min_len,end-start);
               sum-=arr[start];
              start++;
               
           }
           
       }
       
       if(min_len==INT_MAX){
           return 0;
       }
       return min_len;
    }

    35)three way partitioning
     void threeWayPartition(vector<int>& array,int a, int b)
    {
         int n=array.size();
         int low = 0;
         int high = n-1;
         int i = 0;
        
        while(i <= high){
            if(array[i] < a){
                swap(array[i],array[low]);
                low++;
                i++;
            }
            else if(array[i] > b){
                swap(array[i] , array[high]);
                high--;
            }
            else i++;
        }

        
    }

    36)minimum swaps and k together
    int minSwap(int arr[], int n, int k) {
       

   
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;
     
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;
     
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {
         
        if (arr[i] > k)
            --bad;
         
        if (arr[j] > k)
            ++bad;
         
        ans = min(ans, bad);
    }
    return ans;

       
    }

    37)palindromic array

	bool isPalindrome(int num) {
    int temp = num, rev = 0;
    while (temp > 0) {
        rev = (rev * 10) + (temp % 10);
        temp /= 10;
    }
    return (num == rev);
}
    int PalinArray(int a[], int n)
    {
    


    for (int i = 0; i < n; i++) {
        if (!isPalindrome(a[i])) {
            return 0;
        }
    }
    return 1;

    }

38)find median
    int find_median(vector<int> v)
		{
		   if(v.size()%2==1){
		       sort(v.begin(),v.end());
		       int mid=(v.size()-1)/2;
		       return v[mid];
		   }
		   else{
		       int mid=ceil((v.size())/2);
		       return (v[mid]+v[mid-1])/2;
		   }
		}


39)Median of 2 sorted arrays of different size
double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
         int n = array1.size(), m = array2.size();
    int i = 0, j = 0, count;
    double m1 = -1, m2 = -1;

    // Check for empty vectors
    if ((n + m) % 2 == 1) {
        for (count = 0; count <= (n + m) / 2; count++) {
            if (i != n && j != m) {
                m1 = (array1[i] > array2[j]) ? array2[j++] : array1[i++];
            } else if (i < n) {
                m1 = array1[i++];
            } else {
                m1 = array2[j++];
            }
        }
        return m1;
    } else {
        for (count = 0; count <= (n + m) / 2; count++) {
            m2 = m1;
            if (i != n && j != m) {
                m1 = (array1[i] > array2[j]) ? array2[j++] : array1[i++];
            } else if (i < n) {
                m1 = array1[i++];
            } else {
                m1 = array2[j++];
            }
        }
        return (m1 + m2) / 2;
    }
        
        
    
    }