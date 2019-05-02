#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

// condiciones iniciales del sistema

const int steps=200;
double T[steps][steps];
double x[steps];
double tiempo[steps];
const double K=200.0;
const double C=900.0;
const double p=2700.0;
const double dx=2.0/steps;
const double dt=(C*p*(dx*dx))/(2*K);
const double L=2.0;
const double n=K*dt/(C*p*(dx*dx));
double  sol(int x,int t){

    if( L<=(dx*x) || (x*dx)<=0){
        if(x<steps && t<steps){
            T[x][t]=200;
        }
        return 200.0;
    }
    if( 0.8<=(dx*x) && (x*dx)<=1.2){ // para estabilidad 
        if(x<steps && t<steps){
            T[x][t]=500;
        }
        return 500.0;
    }
    if (t==0){
        if(x<steps && t<steps){
            T[x][t]=200;
        }
        return 200.0;
    }
    if (T[x][t]!=-1)
        return T[x][t];

    T[x][t]=sol(x,t-1)+n*(sol(x+1,t-1)+sol(x-1,t-1)-2*sol(x,t-1));
    return T[x][t];
}
int main(){

    for(int i=0;i<steps;i++){
        for(int j=0;j<steps;j++){
            T[i][j]=-1;
        }
    }
    for(int i=0;i<steps;i++){
        for(int j=0;j<steps;j++){
            sol(i,j);
        }
    }

    freopen("datos.dat","w",stdout);
    for(int i=0;i<steps;i++){
        x[i]=dx*i;
        tiempo[i]=dt*i;
    }
    for(int i=0;i<steps;i++){
        printf("%f ",x[i]);
    }
    cout<<endl;
    for(int i=0;i<steps;i++){
        cout<<tiempo[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<steps;j++){
        for(int i=0;i<steps;i++){
            printf("%.20lf ",sol(i,j));
        }
        cout<<endl;
    }
	return 0;

}
