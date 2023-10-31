#include<iostream>
using namespace std;
void heapify(int arr[],int size,int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<size && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<size && arr[smallest]>arr[right]){
        smallest=left;
    }

    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,size,smallest);
    }
}
int main(){
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
