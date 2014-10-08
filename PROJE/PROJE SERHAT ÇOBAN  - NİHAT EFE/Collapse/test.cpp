#include <graphics.h>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
//mavi-1
//yeþil-2
//kýrmýzý-4
//mor-5
//sarý-14

using namespace std;
int sayac,bitti;
int toplampuan=0,fark,puan;
int i,j,quit,x,y,renk,renku,renka,renksag,renksol,kx,ky,bxy,byy,sayici=0,onsayici=0,sayan;
int dizixbit[15][15],dizixbas[15][15],diziybit[15][15],diziybas[15][15];
int renkler[5]={1,2,4,5,14};
int dokulme(int dx,int dy);
void puanhesapla();
void kaydirma();
int bitirme();
void baryap();
class YON{
      public:
      int xbul(int xbulx);
      int ybul(int ybuly);
      
      }yon;
      
class UST:public YON{
      public:
      int ustkontrol(int ux,int uy);
      }ust;
class SAG:public YON{
      public:
      int sagkontrol(int sagx,int sagy);
      }sag;     
class SOL:public YON{
      public:
      int solkontrol(int solx,int soly);
      }sol;      
class ALT:public YON{
      public:
      int altkontrol(int ax,int ay);
      }alt;     
      
int main()
{ 

srand(time(NULL));
quit=0;
initwindow(464,464);
for (j=0;j<=14;j++){
    for (i=0;i<=14;i++){  
    setfillstyle(1,renkler[rand()%5]);
    bar(i*30+i,j*30+j,i*31+30,j*31+30);
    dizixbit[j][i]=i*31+30;
    dizixbas[j][i]=i*30+i;
    diziybit[j][i]=j*31+30;
    diziybas[j][i]=j*30+j;
    }
}
while(quit!=1)
{
x = mousex();
y = mousey();
if(ismouseclick(WM_LBUTTONDOWN))//mousenin sol tuþu týklandýðýnda...
        {
            clearmouseclick(WM_LBUTTONDOWN);
            renk=getpixel(x,y);
            renku=getpixel(x,y-31);
            renka=getpixel(x,y+31);
            renksag=getpixel(x+31,y);
            renksol=getpixel(x-31,y);
           //cout<<x<<"-"<<y<<"-"<<renk<<endl;
          if(((renk==renku) || (renk==renka)||(renk==renksag) || (renk==renksol)) && (renk!=0)){
           if(renk==renku){
                           //cout<<"uste girdim"<<endl;
                           ust.ustkontrol(x,y);
                           }
                           else if(renk==renksag)
                           {
                           //cout<<"saga girdim"<<endl;     
                           sag.sagkontrol(x,y);
                           }
                           else if(renk==renksol)
                           {
                           //cout<<"sola girdim"<<endl;
                           sol.solkontrol(x,y);
                           }
                           else if(renk==renka)
                           {
                           //cout<<"alta girdim"<<endl;     
                           alt.altkontrol(x,y);
                           }
                           }
                           
                   puanhesapla();        
                           
                
                bitti=bitirme(); 
                if(bitti==196) quit=1;}}//while     
getch();
closegraph();
return 0;
}
int UST::ustkontrol(int ux,int uy){
  while(renk==getpixel(ux,uy)){
                                            
                                            if (renk==getpixel(ux,uy-31))
                                            {
                                            uy=uy-31;
                                            }
                                            else
                                            {
                                             
                                             xbul(ux);
                                            ybul(uy);
                                             baryap(); 
                                             dokulme(ux,uy);   
                                            if (renk==getpixel(ux+31,uy))
                                            sag.sagkontrol(ux+31,uy);
                                            if (renk==getpixel(ux-31,uy))
                                            sol.solkontrol(ux-31,uy);
                                            if (renk==getpixel(ux,uy+31))
                                            alt.altkontrol(ux,uy+31);
                                            }                           
                                            }//while   
}
int SAG::sagkontrol(int sagx,int sagy){
  while(renk==getpixel(sagx,sagy)){
                                                                                        
                                            if (renk==getpixel(sagx+31,sagy))
                                            {
                                            sagx=sagx+31;
                                            }
                                            else
                                            {
                                            
                                            xbul(sagx);
                                            ybul(sagy);
                                            baryap();
                                            dokulme(sagx,sagy);
                                            if (renk==getpixel(sagx-31,sagy))
                                            sol.solkontrol(sagx-31,sagy);
                                            if (renk==getpixel(sagx,sagy+31))
                                            alt.altkontrol(sagx,sagy+31);
                                            }                          
                                            }//while   
}

int SOL::solkontrol(int solx,int soly){
  while(renk==getpixel(solx,soly)){
                                            
                                           if (renk==getpixel(solx-31,soly))
                                            {
                                            solx=solx-31;
                                            }
                                            else
                                            {
                                            
                                            xbul(solx);
                                            ybul(soly);
                                            baryap();
                                            dokulme(solx,soly);
                                            if (renk==getpixel(solx+31,soly))
                                            sag.sagkontrol(solx+31,soly);
                                            if (renk==getpixel(solx,soly+31))
                                            alt.altkontrol(solx,soly+31);                           
                                            }
                                            }//while   
}
int ALT::altkontrol(int ax,int ay){
  while(renk==getpixel(ax,ay)){
                               
                               xbul(ax);
                               ybul(ay);
                               baryap();
                               dokulme(ax,ay);   
                               if (renk==getpixel(ax+31,ay))
                               sag.sagkontrol(ax+31,ay);
                               if (renk==getpixel(ax-31,ay))
                               sol.solkontrol(ax-31,ay);
                               if (renk==getpixel(ax,ay-31))
                               ust.ustkontrol(ax,ay-31);
                               ay=ay+31;                          
                               }//while   
                               
}                           
int dokulme(int dx,int dy){
    while(dy>=0){
                               yon.xbul(dx);
                               yon.ybul(dy);
                               setfillstyle(1,getpixel(dx,dy-31));
                               bar(dizixbas[byy-1][bxy-1],diziybas[byy-1][bxy-1],dizixbit[byy-1][bxy-1],diziybit[byy-1][bxy-1]);
                               yon.xbul(dx);
                               yon.ybul(dy-31);
                               baryap();
                               dy=dy-31;
                              
                               }
kaydirma();
} 
                               
                               
                               
int YON::xbul(int xbulx){
                               bxy=xbulx/31; kx=xbulx%31;
                               if(kx!=0)
                               bxy=bxy+1;
                               }
int YON::ybul(int ybuly){
                               byy=ybuly/31; ky=ybuly%31;
                               if(ky!=0)
                               byy=byy+1;
                               }
void baryap(){
                               setfillstyle(1,0);
                               bar(dizixbas[byy-1][bxy-1],diziybas[byy-1][bxy-1],dizixbit[byy-1][bxy-1],diziybit[byy-1][bxy-1]);
                               }
void kaydirma(){
     
     
      for(int jj=0;jj<=14;jj++){
                   
               
              if(0==getpixel(15+(jj*31),450))
              {
              
                          for(int d=0;d<jj;d++){
                                  
                              for(int k=0;k<=14;k++){
                                       
                          yon.xbul(15+jj*31-(d*31));
                          yon.ybul(450-(k*31));
                          setfillstyle(1,getpixel((15+jj*31-(d*31))-31,450-(k*31)));
                          bar(dizixbas[byy-1][bxy-1],diziybas[byy-1][bxy-1],dizixbit[byy-1][bxy-1],diziybit[byy-1][bxy-1]);
                            yon.xbul(15+jj*31-(d*31)-31);
                          
                          
                          baryap();
                          }
                          }
                          
                          }
     
     
     
     
     }
}
int bitirme()
{
for(int i=0;i<14;i++)
        for(int j=0;j<14;j++)
{
{


if(/*SOL*/getpixel(450-(j*31),450-(i*31))!=getpixel(450-(j*31)-31,450-(i*31))) 
{

if(/*ÜST*/getpixel(450-(i*31),450-(j*31))!=getpixel(450-(i*31),450-(j*31)-31))
{

sayac++;

}    else if(getpixel(450-(i*31),450-(j*31))==0 && getpixel(450-(i*31),450-(j*31)-31)==0) sayac++;

} else if(getpixel(450-(j*31),450-(i*31))==0 && getpixel(450-(j*31)-31,450-(i*31))==0) sayac++;   

}    
}  



if(sayac==196){

cout<<"                              OYUN BiTTi.."<<endl;
return sayac;

}
sayac=0;
}

void puanhesapla(){
     
     onsayici=sayici;
                           sayici=0;  
                           for(int i=0;i<15;i++){
                                   for(int j=0;j<15;j++){
if(getpixel(5+(j*31),5+(i*31))==0) 
{sayici++;}
}
}
                 
                fark=sayici-onsayici;
                puan=fark*fark*5;      
                toplampuan=toplampuan+puan;
                system("CLS");
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
                cout<<"                            PUAN : "<<toplampuan<<endl;
     
     }
