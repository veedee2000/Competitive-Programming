https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>nums,BIT;

void insert(int i,int val){
    while(i <= n){
        BIT[i] += (val % 2);
        i += i&-i;
    }
}

void update(int i,int val){
    while(i <= n){
        BIT[i] += (val % 2) ? 1 : -1;
        i += i&-i;
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum += BIT[i];
        i -= i&-i;
    }
    return sum;
}



int main(){
    cin>>n;
    BIT.resize(n + 1,0);
    nums.resize(n + 1);
    for(int i = 1;i <= n;i++) cin>>nums[i];
    for(int i = 1;i <= n;i++) insert(i,nums[i]);
    int q,t;
    cin>>q;
    while(q--){
        cin>>t;
        if(t == 0){
            int index,val;
            cin>>index>>val;
            if(nums[index] % 2 != val % 2){
                update(index,val);
                nums[index] = val;
            }
        }
        else if(t == 1){
            int l,r;
            cin>>l>>r;
            cout<<r - l + 1 - (query(r) - query(l - 1))<<endl; // Counting even
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(r) - query(l - 1)<<endl; // Counting odd
        }
    }
    return 0;
}
