#include<bits/stdc++.h>
using namespace std;
int arr[1000];
int partitn(int s,int e)
{
    int i,t;
    int indx=s;
    for(i=s;i<e;i++)
    {
        if(arr[i]<=arr[e])
        {
            t=arr[i];
            arr[i]=arr[indx];
            arr[indx]=t;
            indx++;
        }
    }
    t=arr[indx];
    arr[indx]=arr[e];
    arr[e]=t;
    return indx;
}
void quicksort(int s, int e)
{
    if(s>=e)
        return;
    int pindex= partitn(s,e);
    quicksort(s,pindex-1);
    quicksort(pindex+1,e);
}
int main()
{
    int i,p,s=0,e,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(s,n-1);
        for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
