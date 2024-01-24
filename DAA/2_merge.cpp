#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],M[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }
    for(int i=0;i<n2;i++)
    {
        M[i]=a[q+1+i];
    }

    int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=M[j];
            j++;
        }
       k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=M[j];
        j++;
        k++;
    }
}
void merge_sort(int a[],int s,int l)
{
    if(s<l)
    {
        int m=(s+l)/2;
        merge_sort(a,s,m);
        merge_sort(a,m+1,l);
        merge(a,s,m,l);
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

    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}