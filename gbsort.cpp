#include<iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int n=r-l+1;
    int* tmp=new int[n];
    int i=0;
    int left=l;
    int right=m+1;
    while(left<=m && right<=r)
    tmp[i++] = arr[left]<= arr[right]?arr[left++]:arr[right++];
    while(left<=m)   
    tmp[i++]=arr[left++];
    while(right<=r)    
    tmp[i++]=arr[right++];
    for(int j=0;j<n;++j)    
    arr[l+j]=tmp[j];
    delete [] tmp;
    return;
}

void sort(int arr[], int l, int r)
{
    if(l==r)return; 
    int m = (l + r)/2;
    sort(arr, l, m);
    sort(arr, m + 1, r);
    merge(arr, l, m, r);
    return;
}

int main()
{
    int k=14;
    int a[k] = {2,5,1,3,4,5,8,7,8,6,10,9,6,3};
    sort(a,0,k);
    for(int i=0;i<k;i++)
        cout<<a[i]<<" ";
    return 0;
}