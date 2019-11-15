// Вычислить элементы вектора как количества
// положительных элементов строк матрицы.

#include <iostream>

using namespace std;
// function which fill randomly array2d 
void fill_randomly_array2d(int array2d[][5]){
    srand ( time(0) );
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            array2d[i][j] = rand() % 200 + 1 - 100; 
        }
    }
}
// function which print array2d
void print_array2d(int array2d[][5]) {
    for(int i = 0; i<5; i++){
        cout << i << " : "; 
        for(int j = 0; j<5; j++){
            cout << array2d[i][j] << " ";
        }
        cout << ";" << endl;
    }
}

int main()
{
    // declare 'array2d' and 'array1d'
    int array2d[5][5];
    int array1d[5];
    // fill randomly array2d
    fill_randomly_array2d(array2d);
    // print array2d
    print_array2d(array2d);
    
    int quantity = 0;
    for(int i=0; i<5; i++){
        quantity = 0;
        for(int j=0;j<5;j++){
            if(array2d[i][j]>=0){
                quantity++;
            }
        }
        array1d[i] = quantity;
    }
    
    for(int i=0;i<5;i++){
        cout << "[" << array1d[i] << "]";
    }

// 0 : -48 -75 -33 -81 -36 ;                                                               
// 1 : 87 88 75 -68 -80 ;                                                                  
// 2 : -36 33 68 -44 -40 ;                                                                 
// 3 : 38 85 -28 -37 58 ;                                                                  
// 4 : -25 -35 -6 -55 -19 ;                                                                
// [0][3][2][3][0] 
    
    return 0;
}
