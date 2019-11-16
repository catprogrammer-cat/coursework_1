// Определить: сумму элементов в тех столбцах, 
// которые не содержат отрицательных элементов;

#include <iostream>

using namespace std;
// function which fill randomly array2d 
void fill_randomly_array2d(int array2d[][5]){
    srand ( time(0) );
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            array2d[i][j] = rand() % 200 + 1 - 50; 
        }
    }
}
// function which print array2d
void print_array2d(int array2d[][5]) {
    for(int i = 0; i<5; i++){
        cout << i << " :\t"; 
        for(int j = 0; j<5; j++){
            cout << array2d[i][j] << "\t";
        }
        cout << " " << endl;
    }
}

int main()
{
    // declare 'array2d' and 'array1d'
    int array2d[5][5];
    int array1d[5];
    int array1d_check[5];
    // fill randomly array2d
    fill_randomly_array2d(array2d);
    // print array2d
    print_array2d(array2d);
    
    for(int i=0;i<5;i++){
        array1d_check[i] = 0;
        for(int j=0;j<5;j++){
            
            if(array2d[j][i] < 0){
                array1d_check[i] = 0;
                break;
            }
            else{
                array1d_check[i]+=array2d[j][i];
            }
           
        }
    }
    cout << "\t";
    for(int i=0;i<5;i++){
        
        cout << "[" << array1d_check[i] << "]" << "\t";
    }
    
    
    
    return 0;
}

// 0 :     10      -19     -41     -27     104                                                                                                    
// 1 :     36      24      -39     -6      131                                                                                                    
// 2 :     -39     56      -34     134     9                                                                                                      
// 3 :     32      36      -25     -44     142                                                                                                    
// 4 :     86      -16     6       -2      117                                                                                                    
//         [0]     [0]     [0]     [0]     [503]
