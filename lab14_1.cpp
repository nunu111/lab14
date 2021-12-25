#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double hide[],int A_size,double show[]){

    double X=0,Y=1,Z=0,deviation=0;

    //หาค่าเฉลี่ยเลขคณิต
    for (int i=0;i<A_size;i++){
        X += hide[i];
    }
    show[0]= X/A_size;

    //หาส่วนเบี่ยงเบนมาตรฐาน
    for(int i=0;i<A_size;i++){
        deviation += pow(hide[i]-show[0],2);
    }
    deviation = deviation/A_size;
    deviation = sqrt(deviation);
    show[1] = deviation;

    //หาค่าเฉลี่ยเรขาคณิต
    for(int i=0;i<A_size;i++){
        Y *= hide[i];
    }
    show[2] = pow(Y,(1.0/A_size));

    //หาค่าเฉลี่ยฮาร์โมนิก
    for(int i=0;i<A_size;i++){
        Z += (1.0/hide[i]);
    }
    show[3] =  A_size/Z;

    //หาค่าสูงสุดและค่าต่ำสุด
    for(int i=0;i<A_size;i++){
        if (i==0) {
            show[4]=hide[i];
            show[5]=hide[i];
        }
        else if (hide[i]>show[4]) show[4]=hide[i];
        else if (hide[i]<show[5]) show[5]=hide[i];
       
    }
}