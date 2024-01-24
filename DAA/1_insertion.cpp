#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(key<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

    }
}
int main()
{
    int n;
    cout<<"Enter the size of array ";
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}