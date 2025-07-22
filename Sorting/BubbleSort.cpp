#include<iostream>
using namespace std;

int main(){
    int arr[1000];
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    cout<<"Enter elements of array";
    for(int i = 0;i < n; i++){
        cin>>arr[i];
    }

    // for(int i = n-2; i>=0; i--){
    //     bool flag = false;
    //     for(int j = 0; j <= i; j++){
    //         if(arr[j] > arr[j+1]){
    //             swap(arr[j], arr[j+1]);
    //             flag = true;
    //         }
    //     }
    //     if(flag == false) break;
    // }

    for(int i = 0; i < n; i--){
        bool flag = false;
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}