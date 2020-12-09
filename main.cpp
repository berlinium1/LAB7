
//
//  main.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 11.11.2020.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int a=10;
int num1,num2;
float sum=0;
float m[a];
void input_m(float*, int, int, int);
void max_n_min(float[], int);
void array_sum(float[]);
void array_change(float*, int);

int main(){
    int begin, end;
    int eps;
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
    input_m(m, begin, end, eps);
    max_n_min(m,a);
    array_sum(m);
    array_change(m, eps);
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
    cout<<"Максимум = "<<max<<". Порядковий номер: "<<numb_max<<endl;
    cout<<"Мінімум = "<<min<<". Порядковий номер: "<<numb_min<<endl<<endl;
}
void input_m(float *p, int begin, int end, int eps){
    srand(time(NULL));
    for (int i=0; i<a; i++){
        *p=begin + rand()%(end-begin) + (float)( rand()%((int)(pow(10,eps)))/(pow(10,eps)));
        p++;
        cout<<i<<"-й) елемент массиву "<<fixed<<setprecision(eps)<<m[i]<<endl;
    }
    cout<<endl;
}
void array_sum(float array[]){
    for(int i=num1; i<=num2; i++){
        cout<<"["<<i<<"] "<<array[i]<<endl;
        sum+=array[i];
    }
    cout<<endl;
    cout<<"Сума = "<<sum<<endl;
    cout<<endl;
}
void array_change(float *p, int eps){
    cout<<"Змінений масив: \n";
    for(int i=0; i<a; i++){
        if(*p<0){
            *p=*p+sum;
        }
        cout<<i<<")-й елемент: "<<fixed<<setprecision(eps)<<*p<<endl;
        p++;
    }
}






/*
#include <iostream>
#include <iomanip>
using namespace std;
void array_check(float[], int);
int main(){
    int begin, end;
    float eps;
    int p;
    int a;
    do{
        cout<<"Введіть бажану величину масиву: ";
        cin>>a;
    }
    while (a<0);
    cout<<endl;
    do{
        cout<<"Введіть інтервал цілих значень чисел масиву: ";
        cin>>begin;
        cin>>end;
    }
    while (begin>end);
    do{
        cout<<"Введіть розмір дробної частини дійсних чисел масива: ";
        cin>>eps;
    }
    while (eps<0);
    float m[a];
    srand(time(NULL));
    for (int i=0; i<a; i++){
        m[i]=begin + rand()%(end-begin) + (float)( rand()%((int)(pow(10,eps)))/(pow(10,eps)));
        cout<<i<<"-й) елемент массиву "<<fixed<<setprecision(eps)<<m[i]<<endl;
    }
    array_check(m,a);
}
void array_check(float array[], int a){
    float max=array[0];
    float min=array[0];
    int numb_max;
    int numb_min;
    int num1, num2;
    float sum=0;
    for(int i=0; i<a; i++){
        cout<<"For element "<<"["<<i<<"] "<<array[i]<<": "<<endl;
        
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
    }
    numb_max>numb_min? (num1=numb_min):(num1=numb_max);
    numb_max>numb_min? (num2=numb_max):(num2=numb_min);
    for(int i=num1; i<=num2; i++){
        cout<<"["<<i<<"] "<<array[i]<<": "<<endl;
        sum+=array[i];
    }
    cout<<"max = "<<max<<" - "<<numb_max<<endl;
    cout<<"min = "<<min<<" - "<<numb_min<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<"Sum = "<<sum;
    
}
*/
/*
void array3_formation(char[], char[]);
char maximum(char[]);
char minimum(char[]);

int main()
{
    char array1[a];
    char array2[a];
    for (int i=0; i<a; i++){
        array1[i]=2*i+23;
        printf("Елемент[%d] 1-го массиву: '%c' - код ASCII: %d\n", i, array1[i], int(array1[i]));
    }
    cout<<endl;
    for (int i=0; i<a; i++){
        array2[i]=49-2*i;
        printf("Елемент[%d] 2-го массиву: '%c' - код ASCII: %d\n", i, array2[i], int(array2[i]));
    }
    cout<<endl;
    
    array3_formation(array1, array2);
    cout<<endl<<endl;
    for (int i=0; i<n; i++){
        printf("Елемент[%d] 3-го массиву: '%c' - код ASCII: %d\n", i, array3[i], int(array3[i]));
    }
    cout<<endl;
    cout<<"Код максимального: "<<int(maximum(array3))<<endl;
    cout<<"Код мінімального: "<<int(minimum(array3))<<endl;
    int result = maximum(array3)-minimum(array3);
    printf("Різниця макс. і мін. елементів: %d(символ - %c)\n", result, result);
    return 0;
}

void array3_formation(char* numbers1, char* numbers2)
{
    for (int i=0; i<a; i++){
        for (int j=0; j<a;j++){
        if (int(numbers1[j])==int(numbers2[i])){
            array3[n]=numbers1[j];
            cout<<n<<" - "<<int(array3[n])<<endl;
            n++;
        }
        }
    }
}
char maximum(char* symbs){
   char max=symbs[0];
   for (int i=0; i<n; i++){
       if (symbs[i]>max){
           max=symbs[i];
       }
   }
    return max;
}

char minimum(char* array){
   char min=array[0];
   for (int i=0; i<n; i++){
       if (array[i]<min){
           min=array[i];
       }
   }
    return min;
}
*/
