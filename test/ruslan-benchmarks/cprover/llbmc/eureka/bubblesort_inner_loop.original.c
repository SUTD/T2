#include <llbmc.h>

int j;
int a[5];

void swap(int x,int y){
  int tmp;
  tmp=a[x];
  a[x]=a[y];
  a[y]=tmp;
}


int main(){
  a[0]=0;
  a[1]=1;
  a[2]=2;
  a[3]=3;
  a[4]=4;
  j=0;
  while(j<4){
    if(a[j]>a[j+1]){
      swap(j,j+1);
      ;
    } else {
      ;
    }
    j=j+1;
  }
  if(a[0]==0){
    __llbmc_assert(0);
  }
  return 0;
}
