#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int h){
    int pivot=a[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }

    }
    swap(&a[i+1],&a[h]);
    return i+1;
}
void quick_sort(int a[],int l,int h){
    if(l<h)
    {
        int p=partition(a,l,h);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,h);   
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

    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}