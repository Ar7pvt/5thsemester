#include<bits/stdc++.h>
using namespace std;
pair<int,int> maxmin(int a[],int l,int h)
{
    //min,max
    if(l==h)//size==1
    {
        return make_pair(a[l],a[l]);
    }
    else if(h-l==1)//size==2
    {
        if(a[l]<a[h])
        {
            return make_pair(a[l],a[h]);
        }
        else{
            return make_pair(a[h],a[l]);
        }
    }
    else{
        int m=(l+h)/2;
        pair<int,int>left=maxmin(a,l,m);
        pair<int,int>right=maxmin(a,m+1,h);
        int minval=min(left.first,right.first);
        int maxval=max(left.second,right.second);

        return make_pair(minval,maxval);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array ";
    cin>>n;
    
    int a[n];
    cout<<"Enter the element in array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    pair<int,int>res=maxmin(a,0,n-1);

    cout<<"Min element "<<res.first<<endl;
    cout<<"max element "<<res.second;
}