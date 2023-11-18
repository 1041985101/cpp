#include<iostream>
using namespace std;

void input(int n,int arr[]){
    int i=0;
    cout << "enter the array";
    for(;i<n;i++){
        cin >> arr[i];
    }
    return;
}

int check(int n,int arr[]){
    int ans=0;
    int i,j;
    for (i =0;i<n;i++){
        for (j=i+1;j<n;j++){
            if(arr[i]>arr[j])
            ans++;
        }
    }
    return ans;
}

int main(){
    int n,ans;
    cout << "enter a number";
    cin >> n;
    int arr[n];
    input(n,arr);
    ans=check(n,arr);
    cout << ans;
    return 0;
}
