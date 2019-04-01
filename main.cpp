#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int find_code(const char* file_name);

int log(double a, double b);

int main(){
    find_code("input1.dat");
    find_code("input2.dat");
    find_code("input3.dat");
    find_code("input4.dat");
    find_code("input5.dat");
    find_code("input6.dat");
    find_code("input7.dat");
    find_code("input8.dat");
    find_code("input9.dat");
    find_code("input10.dat");
}

int find_code(const char* file_name)
{
    int found;
     
     //чтение файла
    ifstream input(file_name);
    if(!input.is_open()){
        cout << "file not opened" << endl;
        return 1;
    }
    double *array;
    int MAX_LENGTH = 100;
    
    input>>MAX_LENGTH;
//    cout << MAX_LENGTH;
    array = new double [MAX_LENGTH];
    for(int i = 0; i < MAX_LENGTH; i++){
        input >> array[i];
//        cout << array[i] << endl;
    }
    

    //поиск смещения 
    int shift;
    for(int i = 0; i < MAX_LENGTH; i++){
        if(array[i] != 0){
            shift = i;
            break;
        }
    }

    for(int i = shift + 1; i < MAX_LENGTH; i++){
        if(array[shift] == array[i]){
            found = i;
            break;
        }
    }
    
    found += 1 + shift; //+1 потому что индексируется с 0, +shitf смещение при '0'

    //поиск k
    int k;
    for(k = 0; k < 10; k++){
//        cout << k << "  >= log2(" <<  k << " + " << found << " + 1)" << endl;
//        cout << k << "  >= " << log(2,k+found+1) << endl;
        if(k >= log(2,k+found+1))
            break;
    }
    
    cout << "(" << found << ", " << found - k << ")"; 
    
    input.close();
    delete [] array;
    
    cout << endl;
}

int log(double a, double b){
    return log(b) / log(a) + 0.5;
}