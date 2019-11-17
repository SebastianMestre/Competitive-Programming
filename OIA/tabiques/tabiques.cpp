#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
//#define FE cin
//#define FS cout
using namespace std;
typedef struct
{
    bool Sup=true,Inf=true,Izq=true, Der=true;
} Lugar;
int a,b,tab,ii,iz,ji,jf;
//vector < vector<Lugar> > MAT(4000, vector <Lugar> (4000));
Lugar MAT[4000][4000];
//vector < vector <int> > ADJ(16000000);
void Horizontal(int i, int j1,int j2)
{
    if(j1>j2)
    {
        /*int aux=j1;
        j1=j2;
        j2=aux;*/
        swap(j1,j2);
    }
    while(j1<j2)
    {
        MAT[i][j1].Inf=false;
        MAT[i-1][j1].Sup=false;
        j1++;
    }
}
void Vertical(int j,int i1,int i2)
{
    if(i1>i2)
    {
        /*int aux=i1;
        i1=i2;
        i2=aux;*/
        swap(i1,i2);
    }
    while(i1<i2)
    {
        MAT[i1][j].Der=false;
        MAT[i1][j+1].Izq=false;
      //  cout<<i1<<"  "<<j<<" no puede cruzar a la derecha "<<endl;
     //   cout<<i1<<"  "<<j+1<<" no puede cruzar a la izquierda "<<endl;
        i1++;
    }
}
int BFS()
{
    //queue <unsigned int> cola;
    //vector <int> d(a*b,-1);
    int d[a][b];
    memset(d,0,sizeof(d));
    d[0][0]=1;
    //cola.push(0);
    unsigned int cola[a*b];
    int pi = 1, pe = 0;
    cola[0] = 0;
    int n=0;
    /*while(cola.size())
    {
        n=cola.front();
        cola.pop();
        //  cout<<endl<<n;
        for(unsigned int z=0; z<ADJ[n].size(); z++)
        {
            //  cout<<"   "<<ADJ[n][z];
            if(d[n]+1 < d[ADJ[n][z]]||d[ADJ[n][z]]==-1)
            {
                d[ADJ[n][z]]= d[n]+1,
                cola.push(ADJ[n][z]);
            }
        }
    }*/
    while(d[a-1][b-1] == 0 && pi > pe)
    {
        unsigned int P = cola[pe];
        pe++;
        int i = P/10000, j = P%10000, c = d[i][j]+1;
       // cout<<i<<"  "<<j<<" tiene costo "<<c<<endl;
       // cola.pop();

        if(MAT[i][j].Sup && i<a-1)
        {
            if(d[i+1][j] == 0)
            {
                d[i+1][j] = c;
                cola[pi++]=((i+1)*10000+j);
            }
        }
        if(MAT[i][j].Inf && i>0)
        {
            if(d[i-1][j] == 0)
            {
                d[i-1][j] = c;
                cola[pi++]=((i-1)*10000+j);
            }
        }
        if(MAT[i][j].Der && j<b-1)
        {
            if(d[i][j+1] == 0)
            {
                d[i][j+1] = c;
                cola[pi++]=(i*10000+j+1);
            }
        }
        if(MAT[i][j].Izq && j>0)
        {
            if(d[i][j-1] == 0)
            {
                d[i][j-1] = c;
                cola[pi++]=(i*10000+j-1);
            }
        }
    }
//int fs=0;
//for(int i=0;i<a;i++)
//{//cout<<endl<<endl;
//for(int j=0;j<b;j++)
    // cout<<"  "<<d[fs]<<"  ",fs++;
//}
    return max(d[a-1][b-1]-1,0);
}







int main()
{
 ifstream FE ("tabiques.in");
    FE>>a>>b>>tab;
//cout<<a<<" X "<<b<<endl;
    for(int k=0; k<tab; k++)
    {
        FE>>ji>>ii>>jf>>iz;
        if(ji==jf)Vertical(ji-1,ii,iz);
        else Horizontal(ii,ji,jf);
//cout<<k<<endl;
    }
  FE.close();
//cout<<"H"<<endl;
    int lug=0;
//cout<<"H"<<endl;
    /*for(int h=0; h<a; h++)
    {
        //cout<<endl;
        for(int w=0; w<b; w++)
        {
            //cout<<lug<<"  ";
            if(h==0)MAT[h][w].Inf=false;
            if(h==a-1)MAT[h][w].Sup=false;
            if(w==0)MAT[h][w].Izq=false;
            if(w==b-1)MAT[h][w].Der=false;
            //    pair <int,bool> push;
            //   push.second=true;
            if(MAT[h][w].Sup)ADJ[lug].push_back(lug+a);
            if(MAT[h][w].Inf)ADJ[lug].push_back(lug-a);
            if(MAT[h][w].Izq)ADJ[lug].push_back(lug-1);
            if(MAT[h][w].Der)ADJ[lug].push_back(lug+1);
            lug++;
            //   cout<<"H"<<endl;
        }

    }*/
    int ret;
    ret=BFS();
    ofstream FS ("tabiques.out");
    if(ret > 0)
        FS<<ret;
    else
        FS<<"imposible"<<endl;
    FS.close();
    return 0;
}
/*int Acercar(int q, int p);
int Acercar(int q, int p)
{if(q>p)
    {return q-1;}
 if(q<p)
    {return q+1;}
 return q;
}
typedef struct
{int h;
 int man;
 int t;
 int auy;
 int aux;
 int py;
 int px;
 int ver;
 int cost;
} lugar;
vector <vector<lugar> > laberinto;
int i;
int j;
int a;
int b;
int tab;
int ax;
int ay;
int zx;
int zy;

int auxi;
vector<lugar>abiertos;
bool LMB(lugar j1, lugar j2)
{return j1.man>j2.man;}
void LMCiclica(lugar *luga);
void LMCiclica(lugar *luga)
{int izq;
 int der;
 int cen;
    if((*luga).ver==0||(*luga).cost<100000)
        {
 (*luga).man=a-((*luga).aux)+(b-(*luga).auy);
 if((*luga).px> 1&&(*luga).py> 1)
    {(*luga).h=laberinto[(*luga).px][(*luga).py].h+(*luga).cost;}
 else
    {(*luga).h=0;}
(*luga).t=(*luga).man+(*luga).h;
(*luga).ver=1;
cout<<"r"<<endl;
abiertos.push_back(laberinto[(*luga).aux+1][(*luga).auy]);
laberinto[(*luga).aux+1][(*luga).auy].ver=0;
laberinto[(*luga).aux+1][(*luga).auy].px=(*luga).aux;
laberinto[(*luga).aux+1][(*luga).auy].py=(*luga).auy;

abiertos.push_back(laberinto[(*luga).aux][(*luga).auy+1]);
laberinto[(*luga).aux][(*luga).auy+1].ver=0;
laberinto[(*luga).aux][(*luga).auy+1].px=(*luga).aux;
laberinto[(*luga).aux][(*luga).auy+1].py=(*luga).auy;



if((*luga).aux>0)
    {abiertos.push_back(laberinto[(*luga).aux-1][(*luga).auy]);
laberinto[(*luga).aux-1][(*luga).auy].ver=0;
laberinto[(*luga).aux-1][(*luga).auy].px=(*luga).aux;
laberinto[(*luga).aux-1][(*luga).auy].py=(*luga).auy;

 }

 if((*luga).auy>0)
    {abiertos.push_back(laberinto[(*luga).aux][(*luga).auy-1]);
laberinto[(*luga).aux][(*luga).auy-1].ver=0;
laberinto[(*luga).aux][(*luga).auy-1].px=(*luga).aux;
laberinto[(*luga).aux][(*luga).auy-1].py=(*luga).auy;
    }
(*luga).ver=1;
        }
}
lugar mini2;
int mini;
int main()
{
 ifstream FE ("tabiques.in");
 FE>>a;
 FE>>b;
 laberinto.resize(a*2);
 for(i=1;i<a*2;i++)
   {laberinto[i].resize(b*2);
    for(j=1;j<b*2;j++)
     {if(j%2==0||i%2==0)
         {laberinto[i][j].cost=0;}
      else
         {laberinto[i][j].cost=1;}
    if(j%2==0&&i%2==0)
         {laberinto[i][j].cost=1000000;}
     }

   }
   FE>>tab;
   for(i=0;i<tab;i++)
    {FE>>ax;

    if(ax==0)
    {ax=1;}
    else
    {ax=ax*2;}
    FE>>ay;

    if(ay==0)
    {ay=1;}
    else
    {ay=ay*2;}
    FE>>zx;

    if(zx==0)
    {zx=1;}
    else
    {zx=zx*2;}
    FE>>zy;

    if(zy==0)
    {zy=1;}
    else
    {zy=zy*2;}

    if(ax==zx)
      {for(;ay!=zy;ay=Acercar(ay,zy))
        {laberinto[ax][ay].cost=10000000;
      laberinto[ax][ay].auy=ay;
       laberinto[ax][ay].aux=ax;
       laberinto[ax][ay].py=-1;
       laberinto[ax][ay].px=-1;
        }

      }
    else
    {{for(;ax!=zx;ax=Acercar(ax,zx))
        {laberinto[ax][ay].cost=10000000;
       laberinto[ax][ay].auy=ay;
       laberinto[ax][ay].aux=ax;
       laberinto[ax][ay].py=-1;
       laberinto[ax][ay].px=-1;
        }
      }
    }
    }
   cout<<"Primer paso hecho"<<endl;
 //  for(i=1;i<a*2;i++)
 //  {
 //   for(j=1;j<b*2;j++)
 //    {cout<<" "<<laberinto[i][j].cost;
  //   }
     cout<<endl;

   LMCiclica(&laberinto[0][0]);
    cout<<"t"<<endl;
    mini2=abiertos[0];
    cout<<"t"<<endl;
   for(;mini2.aux!=laberinto[a*2-1][b*2-1].aux&&mini2.auy!=laberinto[a*2-1][b*2-1].auy;)
   {LMCiclica(&abiertos[mini]);
    for(i=0;i<abiertos.size();i++)
      {if(abiertos[i].man<mini2.man&&abiertos[i].ver==0)
       {mini=i;
        mini2=abiertos[i];}}
        cout<<mini<<endl;

   }
cout<<mini2.t<<endl;
}*/


