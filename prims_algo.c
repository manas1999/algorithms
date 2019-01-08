#include <stdio.h>
#include<stdlib.h>
typedef struct node{
  int i;
  int j;
  int w;
}node ;
typedef struct heap{
  node a[20];
  int size;
}heap;
void init(heap *h){
  int i;
  h->size=0;
 // for(i=0;i<20;i++)h->a[i]=0;
}
int parent(int i){
  return i/2;
}
int left_child(int i){
  return 2*i;
}
int right_child(int i){
  return 2*i+1;
}
void min_heapify(heap *h){
  int n=h->size;
  int i=n;
  int p,l,r;
  node temp;
  for(i=n;i>=1;i--){
    p=parent(i);
    l=left_child(i);
    r=right_child(i);
    if((h->a[p]).w > h->a[i].w && p >=1 ){
      temp=h->a[p];
      h->a[i]=h->a[p];
      h->a[p]=temp;
      }
    }
}
node extract_min(heap *h){
  int n;
  node min;
  n=h->size;
  min=h->a[1];
  h->a[1]=h->a[n];
  h->size--;
  min_heapify(h);
  return min;
}
void enqueue(heap *h,int i,int j,int w){
  node *temp;
  h->size++;
  (h->a[h->size]).i=i;
  (h->a[h->size]).j=j;
  (h->a[h->size]).w=w;
  min_heapify(h);
}
int is_empty(heap *h){
  if(h->size==0) return 1;
  else return 0;
}
void print_queue(heap *h){
  int n=h->size,i;
  printf("\n queue :: ");
  for(i=1;i<=n;i++){
    printf(" %d ",(h->a[i]).i);
  }

}
void prims_algo(int **l,int n){
  int b=0,i;
  int *k;
  heap *h;
  int v=1;
  node temp;
  int min_weight=500;
  h=malloc(sizeof(heap));
  init(h);
  //for(i=0;i<=n;i++)h[i]=0;
  k = malloc(sizeof(int)*(n));
  for(i=0;i<n;i++) k[i]=0;
  //first push
  k[b++]=1;
  for(i=1;i<=n;i++){
    if(l[1][i]!=0) { enqueue(h,1,i,l[1][i]);}
  }
  print_queue(h);
  // min 7
  temp=extract_min(h);
  k[b++]=temp.j;
  v++;
  while(!is_empty(h) && v<=n ){
    for(i=1;i<=n;i++){
      if(l[v][i]!=0){enqueue(h,v,i,l[v][i]);}
      temp=extract_min(h);
      k[b++]=temp.j;
      v++;
      printf("\n%d\n",v);
    }

  }

  for(i=0;i<=n;i++)printf("\n%d\n",k[i]);


}
int main()
{
    int i,j,n,m,**l;
    printf("enter n");
    scanf("%d",&n);
    l=malloc(sizeof(int *)*(n+1));
    for(i=0;i<=n;i++){
      l[i]=malloc(sizeof(int)*(n+1));
    }
    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
        if(i==0||j==0) l[i][j]=0;
        else scanf("%d",&l[i][j]);
      }
    }

    prims_algo(l,n);


    return 0;
}
