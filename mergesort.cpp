#include<bits/stdc++.h>
using namespace std;
int arr[100],temp[100];
void merging(int startpoint,int midpoint,int endpoint)
{
    int firstarr=startpoint;
    int secarr=midpoint+1;
    int i;
    for(i=firstarr; firstarr<=midpoint&&secarr<=endpoint; i++)
    {
        if(arr[firstarr]<arr[secarr])
            temp[i]=arr[firstarr++];
        else
            temp[i]=arr[secarr++];
    }
    while(firstarr<=midpoint)
        temp[i++]=arr[firstarr++];
    while(secarr<=endpoint)
        temp[i++]=arr[secarr++];
    for(i=startpoint; i<=endpoint; i++)
        arr[i]=temp[i];
}
void mergesort(int startpoint, int endpoint)
{
    if(startpoint==endpoint)
        return;
    int midpoint=(startpoint+endpoint)/2;
    mergesort(startpoint,midpoint);
    mergesort(midpoint+1,endpoint);
    merging(startpoint,midpoint,endpoint);
}
int main()
{
    int i,n;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>arr[i];
    mergesort(0,n-1);
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
