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
        cout << i << " :\t"; 
        for(int j = 0; j<5; j++){
            cout << array2d[i][j] << "\t";
        }
        cout << ";" << endl;
    }
}

void calculate(int array2d[][5],int array1d[],int quantity){
    int sum = 0;
    int calculation = 0;
    //first calculation of first side 
    for(int num = 0; num<4; num++){
        calculation = num - 3;
        sum = 0;
        for(int i = 0;i<5-abs(calculation);i++){
            sum += abs(array2d[i][5-1-i+calculation]);
        }
    array1d[num] = sum;
    }
    int reverse = 0;
    //second calculation of second side
    for(int num = 0; num<3; num++){
        calculation = num - 3; // 0 - (-3); ?? 1 - (-2)
        
        sum = 0;
        for(int i = 4;i>=0+abs(calculation);i--){
            sum += abs(array2d[i][abs(5-1-i-calculation)]);
        }
    array1d[num+4] = sum;
    int reverse[3]; // second part of diagonals
    }
    for(int i = 0; i < 7; i++) {
        cout << "[" << array1d[i] << "]";
    }
}
int main()
{
    const int quantity = 5;
    int array2d[quantity][quantity];
    int array1d[7];
    
    fill_randomly_array2d(array2d);
    print_array2d(array2d);
    
    // int* array1d_pointer = calculate(array2d,array1d,quantity);
    
    // for(int i = 0;i<9;i++){
    //     cout << "[" << array1d_pointer[i] << "]";
    // }
    calculate(array2d,array1d,quantity);
    
    
    
    
    
    
    return 0;
}
