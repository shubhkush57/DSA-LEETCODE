//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */
int minVal(int x, int y) { return (x < y)? x: y; } 
int constructStUtil(int arr[],int *st,int as,int ae,int st_node){
    if(as == ae){
        st[st_node] = arr[as];
        return st[st_node];
    }
    int mid = as+(ae-as)/2;
    return st[st_node] = minVal(constructStUtil(arr,st,as,mid,2*st_node+1),constructStUtil(arr,st,mid+1,ae,2*st_node+2));
}
int *constructST(int arr[],int n)
{
  //Your code here
  int h = ceil(log2(n));
  int siz = pow(2,h+1)-1;
  int *st = new int[siz];
  constructStUtil(arr,st,0,n-1,0);
  return st;
}


/* The functions returns the
 min element in the range
 from a and b */
int getMinUtil(int *st,int as,int ae,int st_node,int l,int r){
    if(l <= as && r >= ae){
        return st[st_node];
    }
    if(r < as || l > ae){
        return INT_MAX;
    }
    int mid = as+(ae-as)/2;
    return minVal(getMinUtil(st,as,mid,2*st_node+1,l,r),getMinUtil(st,mid+1,ae,2*st_node+2,l,r));
}
int getMin(int *st,int n,int l,int r){
    if(l > r || l<0 || r>= n){
        return -1;
    }
    return getMinUtil(st,0,n-1,0,l,r);
    
}
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return getMin(st,n,a,b);
}