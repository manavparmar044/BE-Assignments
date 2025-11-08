#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr,int st,int end){
    int idx = st - 1;
    int pivot = arr[end];

    for(int j = st;j<end;j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);

    return idx;
}

int randomPartition(vector<int> &arr,int st,int end){
    int randomIdx = st + rand()%(end - st + 1);
    swap(arr[randomIdx],arr[end]);

    int idx = st - 1;
    int pivot = arr[end];

    for(int j = st;j<end;j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);

    return idx;
}

void quickSort(vector<int> &arr,int st,int end){
    if(st < end){
        int pivot = randomPartition(arr,st,end);

        quickSort(arr,st,pivot - 1);
        quickSort(arr,pivot + 1,end);
    }
}

int main(){
    vector<int> arr = {4,3,2,1,0};
    quickSort(arr,0,arr.size() - 1);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}