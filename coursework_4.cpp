// Найти минимум среди сумм модулей элементов диагоналей,
// параллельных побочной диагонали матрицы.
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
// function which calculate all diagonals and fill them 'array1d' 
void calculate(int array2d[][5],int array1d[],int quantity){
    // declare varibles 'sum', 'calculation'
    // 'sum' for calculation of each one sum of diagonals
    int sum = 0;
    // 'calculation' for caltulate quantity of repeat cycle ..(1)..
    int calculation = 0;
    //first calculation of first side 
    //cycle for choose which diagonal to calculate
    for(int num = 0; num<4; num++){
        // calculate optimal constant to caltulate diagonals
        calculation = num - 3;
        // cancellation 'sum'
        sum = 0;
        //..(1).. --> cycle for caltulate diagonals 
        for(int i = 0;i<5-abs(calculation);i++){
            sum += abs(array2d[i][5-1-i+calculation]);
        }
    // record sum to 'array1d' 
    array1d[num] = sum;
    }
    //second calculation of second side
    //cycle for choose which diagonal to calculate
    for(int num = 0; num<3; num++){
        // calculate optimal constant to caltulate diagonals
        calculation = num - 3; // 0 - (-3); ?? 1 - (-2)
        // cancellation 'sum'
        sum = 0;
        //cycle for caltulate diagonals 
        for(int i = 4;i>=0+abs(calculation);i--){
            sum += abs(array2d[i][abs(5-1-i-calculation)]);
        }
    // record sum to 'array1d' 
    array1d[6-num] = sum;
    }
    // output 'array1d'
    for(int i = 0; i < 7; i++) {
        cout << "[" << array1d[i] << "]";
    }
}
// return max element of 'array1d'
int return_max_element(int array1d[]){
    // declare for loop of find max element
    int max = array1d[0];
    for(int i=0; i<7;i++){
        if(array1d[i] < max){
            max = array1d[i];
        }
    }
    return max;    
}
// return index of max element of 'array1d'
int return_index_max_element(int array1d[]){

    int index = 0;
	while (index < 7)
	{
		if (array1d[index] == return_max_element(array1d)) {
			break;
		}
		index++;
	}
	return index;
}


int main()
{
    // declare quantity for 'array2d' and 'array2d', 'array1d'
    const int quantity = 5;
    int array2d[quantity][quantity];
    int array1d[7];
    // call function for fill randomly 'array2d'
    fill_randomly_array2d(array2d);
    // call function for print whole 'array2d'
    print_array2d(array2d);
    // call function for calculate all collateral diagonals which parallel each one 
    // and fill 'array1d' of sum of all diagonals
    calculate(array2d,array1d,quantity);
    
    //output max value and index of max value of 'array1d'
	cout << "\nValue of max element\t" << return_max_element(array1d) << endl;
    
	cout << "Index of max element\t" << return_index_max_element(array1d) << endl;
    
    
    return 0;
}

//  0 :     -41     65      -21     67      57      ;                                                                                              
//  1 :     25      17      95      -61     -98     ;                                                                                              
//  2 :     65      98      -77     30      -69     ;                                                                                              
//  3 :     -87     97      -13     92      -68     ;                                                                                              
//  4 :     -78     27      11      4       -91     ;                                                                                              
//  [90][103][347][370][168][172][72]                                                                                                              
//  Value of max element    72                                                                                                                     
//  Index of max element    6
