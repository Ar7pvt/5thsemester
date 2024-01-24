#include<bits/stdc++.h>
using namespace std;

int matrixchain(int a[],int n)
{
    int m[n][n];
    int i,j,k,l,q;
    for(i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q = m[i][k] + m[k + 1][j]+ a[i - 1] * a[k] * a[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
int main()
{
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=matrixchain(arr,n);
    cout<<"The min no of multiplication is "<<ans;
    return 0;
}

