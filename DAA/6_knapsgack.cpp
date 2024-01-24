#include<bits/stdc++.h>
using namespace std;

int knpshackrec(int p[],int wt[],int W,int index,int **dp)
{
    if(index<0)
    {
        return 0;
    }
    if(dp[index][W]!=-1)
    {
        return dp[index][W];
    }
    if(wt[index]>W)
    {
        dp[index][W]=knpshackrec(p,wt,W,index-1,dp);
        return dp[index][W];
    }
    else{
        dp[index][W]=max(p[index]+knpshackrec(p,wt,W-wt[index],index-1,dp),knpshackrec(p,wt,W,index-1,dp));
        return dp[index][W];
    }
}
int knpshack(int p[],int wt[],int W,int n)
{
    int **dp;
    dp=new int*[n];

    for(int i=0;i<n;i++)
    {
        dp[i]=new int[W+1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            dp[i][j]=-1;
        }
    }

    return knpshackrec(p,wt,W,n-1,dp);
}
int main()
{
    int profit[]={60,100,120};
    int weight[]={10,20,30};
    int W=50;
    int n=sizeof(profit)/sizeof(profit[0]);
    int ans=knpshack(profit,weight,W,n);
    cout<<ans;
    return 0;
}