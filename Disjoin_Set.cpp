//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends


/*Complete the functions below*/
int find(int A[],int x)
{
    if(x == A[x]) return x;
    
    return A[x] = find(A, A[x]);
       //add code here
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	int ulp_x = find(A, X);
	int ulp_z = find(A, Z);
	
	if(A[ulp_x] != A[ulp_z]){
	    A[ulp_x] = ulp_z;
	}
}
