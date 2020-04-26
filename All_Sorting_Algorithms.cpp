#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>a;

void selectionSort(){
    int index;
    for(int i = 0;i < n - 1;i++){
        index = i;
        for(int j = i + 1;j < n;j++){
            if(a[j] < a[index]) index = j;
        }
        swap(a[i],a[index]);
    }
}

void bubbleSort(){
    for(int i = n - 2;i >= 0;i--){
        for(int j = 0;j <= i;j++){
            if(a[j] > a[j + 1]) swap(a[j],a[j + 1]);
        }
    }
}

void insertionSort(){
    for(int i = 1;i < n;i++){
        int value = a[i],hole = i;
        while(hole > 0 and a[hole - 1] > value){
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = value;
    }
}

// Merge Sort Recursive----

void merge(vector<int>& left,vector<int>& right,vector<int>& v){
    int i = 0,j = 0,k = 0;
    while(i < left.size() and j < right.size()){
        if(left[i] < right[j]) v[k++] = left[i++];
        else v[k++] = right[j++];
    }
    while(i < left.size()) v[k++] = left[i++];
    while(j < right.size()) v[k++] = right[j++];
}

void mergeSort(vector<int>& v){
    if(v.size() < 2) return;
    int mid = (v.size() - 1) / 2;
    vector<int>left,right;
    for(int i = 0;i <= mid;i++) left.push_back(v[i]);
    for(int i = mid + 1;i < v.size();i++) right.push_back(v[i]);
    mergeSort(left);
    mergeSort(right);
    merge(left,right,v);
    left.clear();
    right.clear();
}

// ---------------


// Merge Sort Iterative----

void mergeSortIterative(){
    int sz = 1;
    int pass = 0,num;
    while((1 << pass) < a.size()) pass++;
    vector<int>b(a.size());
    num = a.size() / 2 + a.size() % 2;
    while(pass--){
        int start1 = 0,end1 = sz - 1,start2 = sz,end2 = min(2 * sz - 1,(int) a.size() - 1);
        int i = 0;
        for(int k = 0;k < num;k++){
            while(start1 <= end1 and start2 <= end2){
                if(a[start1] < a[start2]) b[i++] = a[start1++];
                else b[i++] = a[start2++];
            }
            while(start1 <= end1) b[i++] = a[start1++];
            while(start2 <= end2) b[i++] = a[start2++];
            start1 += sz,end1 = start1 + sz - 1,start2 += sz,end2 = min(start2 + sz - 1,(int) a.size() - 1);
        }
        a = b;
        for(auto x:b) cout<<x<<" ";
        cout<<endl;
        num = num / 2 + num % 2;
        sz *= 2;
    }
}

// ---------------


int main() {
    
    cin>>n;
    a.resize(n,0);
    for(int i = 0;i < n;i++) cin>>a[i];
    
    // selectionSort();
    // bubbleSort();
    // insertionSort();
    // mergeSort(a);
    mergeSortIterative();
    
    for(auto x:a) cout<<x<<" ";
    
	return 0;
}
