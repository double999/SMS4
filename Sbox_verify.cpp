#include <iostream>
using namespace std;

int change(int x){
      int A1=0xA7;
      int flag;
      int result=0;
      int tem;
      int flag2;
      for(int i=0;i<8;i++){
          flag=(A1 & 0x80)>>7;
          tem=x & A1;
          flag2=0;
          for(int j=0;j<8;j++){
              flag2^=(tem & 1);
              tem>>=1;
          }
          result=result | (flag2<<i);
          A1=(A1<<1) | flag;
      }
      result^=0xd3;
      return result;
  }
  
int multiplication(int a,int b){ 
      int tem=0;
      int i=0;
      while(b){
          if(b&1){
              tem^=a<<i;
          }
          i++;
          b>>=1;
      }   
      return tem;
  }
  
int length(int x){
      int i=0;
      int comp=1;
      while(1){
          if(comp>=x){
              return i;
          }
          comp=(comp<<1)+1;
          i++;
      }
}
void division(int a,int b,int* round,int* left){
      *round=0;
      *left=0;
      int distance;
      while(1){
          distance=length(a)-length(b);
          if(distance>=0 && a){ 
              a=a ^ (b<<distance);
              *round=(*round) | (1<<distance);
          }else{
              *left=a;
              break;
          }
      }   
  }
int inverse(int a,int b){
      int x2=1;
      int x1=0;
      int y2=0;
      int y1=1;
      int temX1,temY1;
      int q,r,x,y;
      int i;
      while(b){
          division(a,b,&q,&r);
          //x=x2^multiplication(q,x1);
          y=y2^multiplication(q,y1);
          a=b;
          b=r;
          //x2=x1;
          //x1=x;
          y2=y1;
          y1=y;
      }
      return y2;
  }
int main()
  {
     /*cout<<"please enter a 8bit_width hex num:"<<" ";
     int x;
     cin>>hex>>x;
	 cout<<hex<<x<<"对应的S盒输出为"<<hex<<change(inverse(0x1f5,change(x)))<<endl;
	 //正确版本
	 */ 
	 int x;
	 cin>>x;
	 cout<<x<<"逆为"<<inverse(0x1f5,238)<<endl; 
	 
     return 0;
  }


















 
