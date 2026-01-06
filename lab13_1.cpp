#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    
    double sum = 0 , mean =0;
    for(int i = 0 ; i < N ; i++){
        sum+=A[i];
    }
    mean = sum/N ;
    B[0] = mean;

    double sixma = 0;
    for(int j = 0 ; j<N ; j++){
        sixma += pow((A[j] - B[0]),2.0); 
    }
    B[1] = pow(((1.0/N)*sixma),0.5);
    
    double GM = 1.0;
    for(int k = 0 ; k<N ; k++){
        GM *= A[k];
    }
    B[2] = pow(GM,1.0/N);

    double HM = 0;
    for(int l = 0 ; l<N ; l++){
        HM += 1.0/A[l]; 
    }
    B[3] = N/HM;

    double Max = A[0];
    for(int m = 0 ; m<N ; m++){
        if(A[m] > Max) Max = A[m];
    }
    B[4] = Max;

    double Min = A[0];
    for(int n = 0 ; n<N ; n++){
        if(A[n] < Min) Min = A[n];
    }
    B[5] = Min;
}
