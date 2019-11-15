//Вычислить значение максимального 
//элемента главной диагонали матрицы.

#include <iostream>

using namespace std;
// function which fill randomly array2d 
void fill_randomly_array2d(int array2d[][5]){
    srand ( time(0) );
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            array2d[i][j] = rand() % 100 + 1; 
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
    // assignment main diagonal to 'array1d'
    for(int i=0,j=0; i<5 , j<5; i++,j++){
        array1d[i] = array2d[i][j];
    }
    // output main diagonal of 'array1d'
    for(int i=0; i<5;i++){
        cout << "[" << array1d[i]<< "]";
    }
    // declare for loop of find max element
    int max = 0;
    // find max element
    for(int i=0; i<5;i++){
        if(array1d[i] > max){
            max = array1d[i];
        }
    }
    //find index of max element
    int index = 0;
	while (index < 5)
	{
		if (array1d[index] == max) {
			break;
		}
		index++;
	}
	//output max value and index of max value of 'array1d'
	cout << "\nValue of max element\t" << max << endl;
    
	cout << "Index of max element\t" << index << endl;
    
    
    return 0;
}
//0 : 46 93 26 40 58 ;                                                                     
//1 : 80 52 77 68 73 ;                                                                     
//2 : 61 13 80 91 16 ;                                                                     
//3 : 43 34 8 77 40 ;                                                                      
//4 : 82 43 61 99 64 ;                                                                     
//[46][52][80][77][64]                                                                     
//Value of max element    80                                                               
//Index of max element    2 
