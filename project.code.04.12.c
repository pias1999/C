#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
long long get_ans(int x,int mask,int N,long long**mem1,int*block,int*size,int*mem2,int*cut_mask,int M,int**good);
int next_mask(int mask,int*mem2,int*cut_mask,int M);

int main()
{
  int i,j,k,l,T,N,M,block_mask,flag;
  char**board=(char**)malloc(50*sizeof(char*));
  for(i=0;i<50;i++)
    board[i]=(char*)malloc(6*sizeof(char));
  int*block,*size,**good,*cut_mask,*mem2;
  long long**mem1;
  block=(int*)malloc(50*sizeof(int));
  size=(int*)malloc(50*sizeof(int));
  good=(int**)malloc(50*sizeof(int*));
  for(i=0;i<50;i++)
    good[i]=(int*)malloc(32*sizeof(int));
  cut_mask=(int*)malloc(5*sizeof(int));
  mem1=(long long**)malloc(50*sizeof(long long*));
  for(i=0;i<50;i++)
    mem1[i]=(long long*)malloc(32768*sizeof(long long));
  mem2=(int*)malloc(32768*sizeof(int));
  for(i=0;i<5;i++){
    cut_mask[i]=0x80000000;
    cut_mask[i]=~(cut_mask[i]>>(28-3*i));
  }
  for(i=0;i<32768;i++)
    mem2[i]=-1;
  scanf("%d",&T);
  for(i=0;i<T;i++){
    scanf("%d%d",&N,&M);
    for(j=0;j<N;j++)
      scanf("%s",board[j]);
    for(j=0;j<N;j++){
      block[j]=block_mask=size[j]=0;
      for(k=0;k<M;k++)
        if(board[j][k]=='#'){
          block_mask|=1<<k;
          block[j]|=7<<3*k;
        }
      for(k=0;k<1<<M;k++){
        flag=0;
        if(k&block_mask)
          continue;
        for(l=0;l<M;l++){
          if(k&(1<<l)&&!flag)
            flag=1;
          else if(k&(1<<l)&&flag){
            flag=2;
            break;
          }
          else if(board[j][l]=='#')
            flag=0;
        }
        if(flag!=2){
          good[j][size[j]]=0;
          for(l=0;l<M;l++)
            if(k&(1<<l))
              good[j][size[j]]|=7<<3*l;
          size[j]++;
        }
      }
    }
    for(j=0;j<N;j++)
      for(k=0;k<1<<3*M;k++)
        mem1[j][k]=-1;
    printf("%lld\n",(get_ans(0,0,N,mem1,block,size,mem2,cut_mask,M,good)-1+MOD)%MOD);
  }
  return 0;
}
long long get_ans(int x,int mask,int N,long long**mem1,int*block,int*size,int*mem2,int*cut_mask,int M,int**good)
{
  int i;
  if(x==N)
    return 1;
  mask&=~block[x];
  if(mem1[x][mask]!=-1)
    return mem1[x][mask];
  mem1[x][mask]=0;
  for(i=0;i<size[x];i++)
    if(!(good[x][i]&mask)){
      mem1[x][mask]+=get_ans(x+1,next_mask(good[x][i]|mask,mem2,cut_mask,M),N,mem1,block,size,mem2,cut_mask,M,good);
      mem1[x][mask]%=MOD;
    }
  return mem1[x][mask];
}
int next_mask(int mask,int*mem2,int*cut_mask,int M)
{
  int i;
  if(mem2[mask]!=-1)
    return mem2[mask]&cut_mask[M-1];
  mem2[mask]=0;
  for(i=0;i<M;i++){
    if((1<<3*i)&mask&&i)
      mem2[mask]|=1<<3*(i-1);
    if((2<<3*i)&mask)
      mem2[mask]|=2<<3*i;
    if((4<<3*i)&mask)
      mem2[mask]|=4<<3*(i+1);
  }
  return mem2[mask]&cut_mask[M-1];
}
