#include <stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}node;
typedef struct queue{
  int a[50];
  int start;
  int end;
}queue;
typedef struct stack{
  int a[50];
  int i;
}stack;
void init_stack(stack *s){
  s->i=0;
}
int is_empty_stack(stack *s){
  if(s->i==0) return 1;
  else return 0;
}
void push_stack(stack *s,int val){
  s->i++;
  s->a[s->i]=val;
}
int pop_stack(stack *s){
  int temp;
  temp=s->a[s->i];
  s->i--;
  return temp;
}
void init(queue *s){
  s->start=0;
  s->end=0;
}
int is_empty(queue *s){
  if(s->start==s->end) return 1;
  else return 0;
}
int is_full(queue *s){

  if(s->end==19) return 1;
  else return 0;
}
void push(queue *s,int i){
  s->end++;
  s->a[s->end]=i;
}
int pop(queue *s){
  int temp;
  s->start++;
  temp=s->a[s->start];
  s->a[s->start]=0;
  return temp;
}
node *create_node(int val){
  node *temp;
  temp=malloc(sizeof(node));
  temp->data=val;
  temp->next=NULL;
  return temp;

}
void create_list(node **l,int a,int b){
  node *temp=NULL;
  if(l[a]==NULL) l[a]=create_node(b);
  else {
    temp=l[a];
    l[a]=create_node(b);
    l[a]->next=temp;
  }
  if(l[b]==NULL)l[b]=create_node(a);
  else{
    temp=l[b];
    l[b]=create_node(a);
    l[b]->next=temp;
    }
}
void print(node **l,int n){
  int i,j;
  node *temp;
  for(i=1;i<=n;i++){
    printf(" %d :::  ",i);
    if(l[i]!=NULL){
      temp=l[i];}
      while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;

      }
      printf("\n");
   }
}
void dfs(node **l,int n,int e,int index){

int i,ret,val;
int *v;
node *temp;
stack *s;
v=malloc(sizeof(int)*(n+1));
s=malloc(sizeof(stack));
init_stack(s);
for(i=0;i<=n;i++){v[i]=0;}
v[index]=1;
push_stack(s,index);
while(!is_empty_stack(s)){
  ret=pop_stack(s);
  printf("\n%d\n",ret);
  temp=l[ret];
  while(temp!=NULL){
    val=temp->data;
    if(v[val]==0){
      v[val]=1;
      push_stack(s,val);
      }

   temp=temp->next;
  }
}



}

void bfs(node **l,int n,int e,int index){
  int i,j,ret,val;
  int *v;
  queue *q;
  node *temp=NULL;
  q=malloc(sizeof(queue));
  init(q);
  v=malloc(sizeof(int )*(n+1));
  for(i=0;i<=n;i++)v[i]=0;
  v[index]=1;
  push(q,index);
  while(!is_empty(q)){
    ret=pop(q);
    printf("\n%d\n",ret);
    temp=l[ret];
    while(temp!=NULL){
      val=temp->data;
      if(v[val]==0){
        v[val]=1;
        push(q,val);
      }
     temp=temp->next;
    }


  }




}
int main()
{
    int n,i,j,e,a,b;
    node **l;
    printf("enter n");
    scanf("%d",&n);
    l=malloc(sizeof(node *)*(n+1));
    l[0]=NULL;
    for(i=1;i<=n;i++)l[i]=NULL;
    printf("enter e");
    scanf("%d",&e);
    for(i=1;i<=e;i++){
      scanf("%d%d",&a,&b);
      create_list(l,a,b);
      }

      print(l,n);
      bfs(l,n,e,1);
      dfs(l,n,e,1);
    return 0;
}
