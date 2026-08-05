#include<bits/stdc++.h>

void maxHeapify(vector<int>& arr,int i,int n){
  int left=2*i+1;
  int right=2*i+2;

  int largest=i;
  if(left<n && arr[left]>arr[largest]){
    largest=left;
  }

  if(right<n && arr[right]>arr[largest]){
    largest=right;
  }

  if(largest!=i){
    swap(arr[i],arr[largest]);
    maxHeapify(arr,largest,n);
  }
}

void Min2Max(vector<int>& arr,int index,int n){
  for(int i=(n-2)/2;i>=0;--i){
    maxHeapify(arr,i,n);
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cout<<"arr"<<i<<":";
    cin>>arr[i];
  }
  Min2Max(arr,0,n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  
  return 0;
}
