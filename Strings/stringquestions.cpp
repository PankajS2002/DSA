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

        //8)longest palindrome string
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

    //9)longest common subsequence
    int lcs(int x, int y, string s1, string s2)
    {
     
		  int dp[x+1][y+1];
		  
		  for(int i=0;i<=x;i++){
		      for(int j=0;j<=y;j++){
		          if(i==0 or j==0){
		              dp[i][j]=0;
		          }
		      }
		  }
		  
		  for(int i=1;i<=x;i++){
		      for(int j=1;j<=y;j++){
		          if(s1[i-1]==s2[j-1]){
		              dp[i][j]=1+dp[i-1][j-1];
		          }
		          else{
		              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		          }
		      }
		  }
		  
		  return dp[x][y];
    }

    //10)longest repeating subsequence
    int LongestRepeatingSubsequence(string str){
		  int n=str.length();
		  int dp[n+1][n+1];
		  
		  for(int i=0;i<=n;i++){
		      for(int j=0;j<=n;j++){
		          if(i==0 or j==0){
		              dp[i][j]=0;
		          }
		      }
		  }
		  
		  for(int i=1;i<=n;i++){
		      for(int j=1;j<=n;j++){
		          if(str[i-1]==str[j-1] && i!=j){
		              dp[i][j]=1+dp[i-1][j-1];
		          }
		          else{
		              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		          }
		      }
		  }
		  
		  return dp[n][n];
		
		    
		}

        //11)string subsequence game
         void subseq(string s,string temp,unordered_set<string> &st){
        if(s.empty()){
            st.insert(temp);
            return;
        }
        subseq(s.substr(1),temp+s[0],st);
        subseq(s.substr(1),temp,st);
    }
    set<string> allPossibleSubsequences(string S) {
        unordered_set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        unordered_set<string> st;
        subseq(S,"",st);
        set<string> res;
        for(auto subs:st){
            // cout<<subs<<" ";
            if(s.find(subs[0])!=s.end() and s.find(subs.back())==s.end()) res.insert(subs);
        }
        return res;
    }

//12)print all subsequences of given string

	   void solve(string S,vector<string>& ans,int index){
	       if(index>=S.size()){
	           ans.push_back(S);
	           return;
	       }
	       
	       for(int j=index;j<S.size();j++){
	           swap(S[index],S[j]);
	           solve(S,ans,index+1);
	           swap(S[index],S[j]);
	       }
	       
	   }
		vector<string> find_permutation(string S)
		{
		    vector<string> ans;
		   
		    
		    solve(S,ans,0);
		      sort(ans.begin(),ans.end());
		    ans.erase(unique(ans.begin(),ans.end()),ans.end());
		    return ans;
		}

        //13)split binary string into substrings with equal number of 0s and 1s
        int maxSubStr(string str){
                  int n=str.size();
   
               int count0 = 0, count1 = 0;
            
               int cnt = 0;
               for (int i = 0; i < n; i++) {
                   if (str[i] == '0') {
                       count0++;
                   }
                   else {
                       count1++;
                   }
                   if (count0 == count1) {
                       cnt++;
                   }
               }
               if (count0!=count1) {
                   return -1;
               }
            
               return cnt;
               }

        //14)word wrap problem
            int solve(int idx, vector<int> arr, int k, vector<int> &t) {
        if(t[idx]!=-1) return t[idx];
        int minRes = INT_MAX;
        int sum = 0;
        for(int i=idx; i<arr.size(); i++) {
            sum += arr[i];
            if(k-sum>=0 && i==arr.size()-1) return 0;
            if(k-sum>=0) {
                minRes = min(minRes, (k-sum)*(k-sum) + solve(i+1, arr, k, t));
            }
            sum++;
        }
        return t[idx] = minRes;
    }
    int solveWordWrap(vector<int>nums, int k) 
    {
        vector<int> t(nums.size(), -1);
        return solve(0, nums, k, t);
    }

    //15)edit distance

    int editDistance(string s, string t) {
       
       int n=s.length();
       int m=t.length();
       
       int dp[n+1][m+1];
       
       for(int i=0;i<=n;i++){
         dp[i][0]=i;
       }
       for(int j=0;j<=m;j++){
           dp[0][j]=j;
       }
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s[i-1]==t[j-1]){
                   dp[i][j]=dp[i-1][j-1];
               }
               else{
                   dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
               }
           }
       }
       
       return dp[n][m];
       
    }

    //16)find next greater number with same set of digits
      int findNext (int N) 
    {
             int leftidx=-1;
        
      string s=to_string(N);

//finding adjascent smaller right to left
      for(int i=s.length()-1; i>=1; i--){
          if(s[i] > s[i-1] ){
               leftidx=i-1;//leftidx=2
             
              
              break;
          }
      }
      //adjascent smaller right to left if not find reutrn -1;
      if(leftidx == -1){
          return -1;
      }
      //finding minimum in range of leftidx to s.length()-1
      int mini=INT_MAX;
     int miniidx=leftidx+1;
     for(int i=leftidx+1; i<s.length(); i++){
        if (s[i] > s[leftidx] && s[i] < mini){
             mini=s[i];
              miniidx=i;   //5;
         }
     }
     
      swap(s[leftidx],s[miniidx]);//536974
      
      sort(s.begin()+leftidx+1,s.end());//536479
      
      int res=stoi(s);//converting string into integer
      if(res <=N){
          return -1;
      }
     return res;
      
    } 

    //17)parenthesis checker
     bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.size();i++){
            if(x[i]=='[' || x[i]=='(' || x[i]=='{' ){
                s.push(x[i]);
            }
            else{
                if(s.empty()){
                    return false;
                }
                if(x[i]==')' && s.top()!='('){
                    return false;
                }
                if(x[i]==']' && s.top()!='['){
                    return false;
                }
                if(x[i]=='}' && s.top()!='{'){
                    return false;
                }
             s.pop();    
            }
            
        }

      return s.empty();

    }

    //18)word break
    int wordBreak(string A, vector<string> &B) {
        int n = A.size();
        vector<bool> dp(n + 1, 0);
        dp[n] = true;
        
        for(int i = n - 1; i >= 0; i--) {
            for(auto word: B) {
                if(i + word.size() <= n and A.substr(i, word.size()) == word and dp[i + word.size()])
                    dp[i] = true;
            }
        }
        
        return dp[0];
    }  

    //19)rabin karp
    vector <int> search(string pat, string txt)
        {
            int q=101;
               int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text
    int h = 1;

    // h is the hash value of the first character in the pattern
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // calculate the hash value of the pattern and the first window of the text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // slide the pattern over the text and check for matches
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            // check if the pattern matches the substring in the text
            for (j = 0; j < m; j++) {
                if (text[i+j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                // pattern found at index i
                cout << "Pattern found at index " << i+1 << endl;
            }
        }
        // calculate the hash value of the next window in the text
        if (i < n-m) {
            t = (d*(t - text[i]*h) + text[i+m])%q;
            if (t < 0) {
                t = (t + q);
            }
        }
    }
        }


//20)Convert a sentence into its equivalent mobile numeric keypad sequence
string printSequence(string S)
{
    //code here.
    string str[]={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    
    string output="";
    for(int i=0;i<S.size();i++){
        if(S[i] ==''){
            output=output+"0";
        }
        else{
            int p=S[i]-'A';
            output=output+S[p];
        }
    }
    return output;
}

//21)Count the Reversals
int countRev (string s)
{
 
  int len=s.size();
  int k=0;
  int in_bra=0,out_bra=0;
  
  if(s[0]=='}'){
      s[0]='{';
      k++;
  }
  
  if(len%2!=0)return -1;
  
  for(int i=0;i<len;i++){
      if(s[i]=='{')in_bra++;
      
      else{
          if(in_bra!=0)in_bra--;
          else{
              s[i]='{';
              in_bra++;
              k++;
          }
      }
  }
    return k+ in_bra/2;

}

//22)Count Palindromic Subsequences
public:
   #define MOD 1000000007

   long long int dp[1005][1005];
   string S;
   long long int countPS(string str)
   {
      const int n = str.length();
      
      memset(dp, -1, sizeof(dp));
      
      S = str;
      
      long long int ans = solve(0, n-1);
      return ans<0?ans+MOD:ans;
   }
   
   private:
   long long int solve(int i, int j){
       if(i > j) return 0;
       
       if(dp[i][j] != -1) return dp[i][j]%MOD;
       
       if(i == j) return dp[i][j] = 1;
       
       if(S[i] == S[j]){
           return dp[i][j] = (solve(i+1, j)%MOD + solve(i, j-1)%MOD + 1)%MOD;
       }
       else{
           return dp[i][j] = (solve(i+1, j)%MOD + solve(i, j-1)%MOD - solve(i+1, j-1)%MOD)%MOD;
       }
   }
   

   //23)Count occurrences of a given word in a 2-d array
   int findOccurrence(vector<vector<char> > &mat, string target){
        
        int res=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                res += helper(mat,i,j,target,0);
            }
        }
        return res;
    }
    int helper(vector<vector<char> >&mat , int i ,int j ,string target ,int idx){
        int found =0;
        if(i<mat.size() && i>=0 && j<mat[0].size() && j>=0 
         && (target[idx]==mat[i][j])){
             mat[i][j]='#';
             if(idx==target.size()-1)
                found = 1;
             else{
                found += helper(mat,i,j-1,target,idx+1);
                found += helper(mat,i+1,j,target,idx+1);
                found += helper(mat,i-1,j,target,idx+1);
                found += helper(mat,i,j+1,target,idx+1);
             }
             mat[i][j]=target[idx];
         }
        return found;
    }
    //24)Find the string in grid
    	    void dfs(bool &flag,int k, int len, int i, int j, int n, int m, vector<vector<int>>&vis,vector<vector<char>>grid,string word, string dir)
    {
        //cout<<i<<" "<<j<<" "<<k<<endl;
         if(k==len){
            flag = true;
            return;
        }
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || grid[i][j]!=word[k] || flag) return;
        vis[i][j] = 1;
        k++;
        if(dir=="ul")
        dfs(flag,k,len,i-1,j-1,n,m,vis,grid,word,dir);
        if(dir=="dr")
        dfs(flag,k,len,i+1,j+1,n,m,vis,grid,word,dir);
        if(dir=="ur")
        dfs(flag,k,len,i-1,j+1,n,m,vis,grid,word,dir);
        if(dir=="dl")
        dfs(flag,k,len,i+1,j-1,n,m,vis,grid,word,dir);
        if(dir=="l")
        dfs(flag,k,len,i,j-1,n,m,vis,grid,word,dir);
        if(dir=="r")
        dfs(flag,k,len,i,j+1,n,m,vis,grid,word,dir);
        if(dir=="t")
        dfs(flag,k,len,i-1,j,n,m,vis,grid,word,dir);
        if(dir=="d")
        dfs(flag,k,len,i+1,j,n,m,vis,grid,word,dir);
        k--;
        
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<string> direction = {"l","r","t","d","ul","dl","ur","dr"};
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	                bool flag = false;
	                
	                for(auto dir : direction)
	                {   vector<vector<int>> v = vis;
	                    dfs(flag,0,word.size(), i,j,n,m,v,grid,word,dir);
	                      if(flag)
	                      {
	                    //cout<<i<<" "<<j<<endl;
	                          vector<int> temp(2,-1);
	                          temp[0] = i;
	                          temp[1] = j;
	                          ans.push_back(temp);
	                          break;
	                       }
	                }
	                
	              
	                
	            }
	        }
	    }
	    return ans;
	}

    //25)Pattern Searching
    bool searchPattern(string str, string pat)
{
  int n=pat.length();
    for(int i=0;i<=str.length()-n;i++)
    {
        string w=str.substr(i,n);
        if(w.compare(pat)==0)
        return true;
    }
    return false;
}

//26)roman number to integer
int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans=0;
        for(int i=0; i < str.length();i++){
            if(mp[str[i]] < mp[str[i+1]]){
                ans-=mp[str[i]];
            }
            else{
                ans+=mp[str[i]];
            }
        }
        return ans;
    }

    //27)longest common prefix
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
         string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
    }
    }

    //28)number of flips to make binary string alternate

int minFlips (string S)
{
    // your code here
    int n = S.size();
    int count =0;
    for( int i=0; i<S.size(); i++ )
    {
        // even positions par consider kar rahe hai ki zero hoga
        if( i%2 == 0 )
        {
            // agar zero nahi hai toh flip karna padega
            if( S[i] == '1' )
                count++;
        }
        else {
            // agar odd position par zero hoga toh bhi flip karna hoga because humne consider kiya hai zero even positions par hoga
            if( S[i] == '0' )
                count++;
        }
    }
    
    int counter = 0;
    
    for( int i=0; i<S.size(); i++ )
    {
        // even positions par consider kar rahe hai ki one hoga
        if( i%2 == 0 )
        {  
            if( S[i] == '0' )
                counter++;
        }
        else {
            // agar odd position par one hoga toh bhi flip karna hoga because humne consider kiya hai ones even positions par honge
            if( S[i] == '1' )
                counter++;
        }
    }
    
    return min(counter, count);
}

//29)Second most repeated string in a sequence
string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> map;
        int max = 0;
        int max2 = -1;
        for (int i = 0; i < n; i++) {
            map[arr[i]]++;
            if (map[arr[i]] >= map[arr[max]]) {
                max = i;
            }
        }
        map.erase(arr[max]);
        for (int i = 0; i < n; i++) {
            if (arr[i] != arr[max]) {
                map[arr[i]]++;
                if (max2 == -1 || map[arr[i]] >= map[arr[max2]]) {
                    max2 = i;
                }
            }
        }
        return arr[max2];
    }

    //30)Minimum Swaps for Bracket Balancing
    int minimumNumberOfSwaps(string S){
          int open=0;
        int close=0;
        int swap=0;
        int imbalance=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='[')
            {
                open++;
                if(imbalance>0)
                {
                    swap+=imbalance;
                    imbalance--;
                }
            }
            else
            {
                close++;
                imbalance=close-open;
            }
        }
        return swap;
    }

    //31)program to generate all possible valid IP addresses from given string
    bool check(string s){
       
      if(s.size()<=0 || s.size()>3){return false;}
      if(stoi(s)<0 || stoi(s)>255){return false;}
      if(s[0]=='0' && s.size()>1){return false;}
      return true;
       
   }
   
  
   string generate(string &s,int i,int j,int k,int n){
       string s1,s2,s3,s4;
       
       s1=s.substr(0,i+1);
       s2=s.substr(i+1,j-i);
       s3=s.substr(j+1,k-j);
       s4=s.substr(k+1,n-1-k);
       
       if(check(s1) && check(s2) && check(s3) && check(s4))
       {
           return s1+"."+s2+"."+s3+"."+s4;
         
       }
       else
       {
           return "";
       }
   }
  
    vector<string> genIp(string &s) {
       
       vector<string>ans;
       int n=s.size();
       string str="";
       
       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               for(int k=j+1;k<n;k++)
               {
                   str=generate( s,i,j,k,n);
                   if(str.size()>0){ans.push_back(str);}
               }
           }
       }
       
       return ans;
    }

    //32)Smallest distinct window
        int findSubString(string str)
    {
     unordered_map<char,int>mp;
        for(int i =0;i<str.size();i++){
            mp[str[i]]++;
        }
        int k = mp.size();
        int n = str.size();
        int i =0;
        int j =0;
        int ans = n+1;
        unordered_map<char,int>mp1;
        while(j<n)
        {
            mp1[str[j]]++;
            if(mp1.size()<k)
            {
                j++;
            }
            else if(mp1.size()==k)
            {
             
            //   ans = min(ans,j-i+1);
               while(k>=mp1.size())
               {
                   mp1[str[i]]--;
                   if(mp1[str[i]]==0)
                   {
                       mp1[str[i]]++;
                       break;
                    }
                   i++;
               }
               ans = min(ans,j-i+1);
              j++;
             
            }
            
            
                    
          
            
        }
        return ans;

    }


