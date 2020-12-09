
//
//  main.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 11.11.2020.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void input_m(float*, int, int, int, int);
void max_n_min(float[], int);
float array_sum(float[], float);
void array_change(float*, int, int, float);
void array_output(float*, int, int);
int num1=0,num2=0;
int main(){
    float sum=0;
    int begin, end;
    int eps;
    int a;
    do{
        cout<<"Розмір: ";
        cin>>a;
    }
    while (a<=0);
    float m[a];
    do{
        cout<<"Інтервал цілих значень чисел масиву: ";
        cin>>begin;
        cin>>end;
    }
    while (begin>end);
    do{
        cout<<"Розмір дробної частини дійсних чисел масиву: ";
        cin>>eps;
    }
    while (eps<0);
    cout<<endl;
    input_m(m, a, begin, end, eps);
    array_output(m, a, eps);
    max_n_min(m,a);
    array_sum(m, sum);
    sum=array_sum(m, sum);
    cout<<"Значення суми між ["<<num1<<"]\nта ["<<num2<<"] елементами "<<"дорівнює: "<<fixed<<setprecision(eps)<<sum<<endl<<endl;
    array_change(m, a, eps, sum);
    array_output(m, a, eps);
}
void max_n_min(float array[], int a){
    float max=array[0];
    float min=array[0];
    int numb_max=0;
    int numb_min=0;
    
        for(int j=0; j<a; j++){
            if(array[j]>max){
                max=array[j];
                numb_max=j;
            }
        }
        
        for(int j=0; j<a; j++){
            if(array[j]<min){
                min=array[j];
                numb_min=j;
            }
        }

    numb_max>numb_min? (num1=numb_min):(num1=numb_max);
    numb_max>numb_min? (num2=numb_max):(num2=numb_min);
    cout<<"\nМаксимум = "<<max<<". Порядковий номер: "<<numb_max<<endl;
    cout<<"Мінімум = "<<min<<". Порядковий номер: "<<numb_min<<endl<<endl;
}
void input_m(float *p, int a, int begin, int end, int eps){
    srand(time(NULL));
    for (int i=0; i<a; i++){
        *p=begin + rand()%(end-begin) + (float)( rand()%((int)(pow(10,eps)))/(pow(10,eps)));
        p++;
    }
}
float array_sum(float array[], float sum){
    for(int i=num1; i<=num2; i++){
        sum+=array[i];
    }

    return sum;
}
void array_change(float *p, int a, int eps, float sum){
    for(int i=0; i<a; i++){
        if(*p<0){
            *p=*p+sum;
        }
        p++;
    }
}

void array_output(float *p, int a, int eps){
    cout<<"Отриманий масив: \n";
    for(int i=0; i<a; i++){
        cout<<i<<"-й елемент масиву: "<<fixed<<setprecision(eps)<<*p<<endl;
        p++;
    }
}


