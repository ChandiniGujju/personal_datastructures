
//merge sort ---->time complexity = O(nlogn)

#include<iostream>
using namespace std;



void Merge(int arr[],int l,int mid,int r){

    int n1=mid-l+1;
    int n2=r-mid;

    //temporary arrays
    int a[n1];
    int b[n2];


    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }


    int i=0;
    int j=0;
    int k=l;

    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    //if i ponter doesn't reaches end then we have to ensure the last elements to print and same with j also
    while(i<n1){
        arr[k]=a[i];
            k++;
            i++;
    }
    while(j<n2){
        arr[k]=b[j];
            k++;
            j++;
    }
}



void merge_sort(int arr[],int l,int r){
    if(l<r){
    int mid=(l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);

    Merge(arr,l,mid,r);
    }
}




int main(){
    int arr[]={8,6,9,3,5};
    merge_sort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



