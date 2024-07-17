#include <bits/stdc++.h>
const int N=1e6;
struct MonoQueue {
    int l=1,r=0;int tl=1,tr=0;int type;
    struct ele{int v,pos;} data[N];
    MonoQueue(int t){data[0]={t==1?INT_MAX:INT_MIN};type=t;} // type==1 递减，维护最大值; type==-1 递增，维护最小值
    void push(int v) {ele tmp={v, ++tr};while (type==1?data[r].v<=v:data[r].v>=v) r--;data[++r]=tmp;}
    void rmf() {if (tl==data[l].pos)data[l].v=type==1?INT_MAX:INT_MIN,l++;tl++;}
    int query() {return data[l].v;}
    void clear() {l=1,r=0,tl=1,tr=0;}
};