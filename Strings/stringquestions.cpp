//1)Longest Palindrome in a string

 string longestPalin (string S) {
         string result="";
        int high;
        int low=0;
        int start=0;
        int maxlength=1;
        int n=S.size();
        for(int i=1;i<n;i++){
            low=i-1;
            high=i;
            while(low>=0 && high<n && S[low]==S[high]){
                if(high-low+1>maxlength){
                    start=low;
                    maxlength=high-low+1;
                }
                low--;
                high++;
            }
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && S[low]==S[high]){
                if(high-low+1>maxlength){
                    start=low;
                    maxlength=high-low+1;
                }
                low--;
                high++;
            }
        }
        for(int i=start;i<start+maxlength;i++){
            result=result+S[i];
        }
        return result;
    }

 //2)Reverse a string
void reverseString(vector<char>& s) {
        int ss=0;
        int e=s.size()-1;

        while(ss<e){
            swap(s[ss],s[e]);
            ss++;
            e--;
        }
    }

 //3)Check whether a string is palindrome

	int isPalindrome(string S)
	{
	    int i=0;
	    int j=S.size()-1;
	    
	    while(i<j){
	        if(S[i]!=S[j]){
	            return 0;
	        }
	        i++;
	        j--;
	    }
	    
	    return 1;
	}

 //4)count and say problem
string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";

        string s="11";
        int count=1;
        for(int i=3;i<=n;i++){
           string t="";
           s=s+"&";
           for(int j=1;j<s.size();j++){
               if(s[j]!=s[j-1]){
                   t=t+to_string(count);
                   t=t+s[j-1];
                   count=1;
               }
               else{
                   count++;
               }
           }
           s=t;
        }
        return s;
    }

 //5)Write a Program to check whether a string is a valid shuffle of two strings or not   
bool isInterleave(string A, string B, string C) 
    {
        int n=A.length(),m=B.length();
        if((n+m)!=C.length())
        return false;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        dp[n][m]=1;
        for(int i=n-1;i>=0;i--)
        {
            if(C[i+m]==A[i])
            dp[i][m]=dp[i+1][m];
        }
        
        for(int i=m-1;i>=0;i--)
        {
            if(C[n+i]==B[i])
            dp[n][i]=dp[n][i+1];
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(A[i]==C[i+j]&&B[j]!=C[i+j])
                dp[i][j]=dp[i+1][j];
                
                if(B[j]==C[i+j]&&A[i]!=C[i+j])
                dp[i][j]=dp[i][j+1];
                
                if(A[i]==C[i+j]&&B[j]==C[i+j])
                dp[i][j]=(dp[i+1][j])|(dp[i][j+1]);
            }
        }
        
        return dp[0][0];
       
    }
 //6)Remove all duplicates from a given string
 string removeDuplicates(string str) {
	   
    string res ="";
    
    unordered_map<char,bool> present;
    
    for(auto ch:str){
        if(!present[ch]){
            res+=ch;
        }
        present[ch]=true;
    }
    return res;
	}

    //7)longest repeating subsequence
    	int LongestRepeatingSubsequence(string str){
		   int n = str.length();

	int t[n+1][n+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
		
		if(i==0 or j==0)
		t[i][j]=0;
	}
		
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			
			if (str[i-1] == str[j-1] && i != j)
			t[i][j] = 1 + t[i-1][j-1];		
		
			else
				t[i][j] = max(t[i][j-1], t[i-1][j]);
		}
	}
	return t[n][n];
		}

        //8)longest palindrom string
         string longestPalin (string S) {
        string result="";
        int start=0;
        int high;
        int low=0;
        int maxlen=1;
        int n=S.size();
        for(int i=1;i<n;i++){
            low=i-1;
            high=i;
            while(low>=0 && high<n && S[low]==S[high]){
                if(high-low+1>maxlen){
                    start=low;
                    maxlen=high-low+1;
                }
              low--;
              high++;
            }
            
            low=i-1;
            high=i+1;
            
            while(low>=0 && high<n && S[low]==S[high]){
                if(high-low+1>maxlen){
                    start=low;
                    maxlen=high-low+1;
                }
              low--;
              high++;
            }
           
            
        }
        
        for(int i=start;i<maxlen+start;i++){
            result=result+S[i];
        }
        return result;
    }