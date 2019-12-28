#include<bits/stdc++.h>
using namespace std;

int parent[1100],size[1100];

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    
    return 0;
}
