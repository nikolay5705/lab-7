#include <iostream>
#include<Windows.h>
#include<math.h>

using namespace std;

void first_task( int *ptr_of_mass_C, int size_of_C) {
    for (int i = 0;i < size_of_C;i++) {
        for (int j = 0;j < size_of_C;j++) {
            if (ptr_of_mass_C[i] > ptr_of_mass_C[j]) {
                swap(ptr_of_mass_C[i], ptr_of_mass_C[j]);

            }
             
        } 
       
    }
    cout << "Відсортоаний массив С:";

}
void second_task_A(int* ptr_of_mass_A, int size_of_A ) {
    for (int i = 0;i < size_of_A;i++) {
        if (*(ptr_of_mass_A + i) % 2 != 0) {
            *(ptr_of_mass_A + i) = pow(*(ptr_of_mass_A + i), 2);
        }
    }
    cout << "Массив А iз заміненими непарними  елементами" << endl;
    cout << "Елементи: ";
    
}
void second_task_B(int* ptr_of_mass_B, int size_of_B){
    for (int i = 0;i < size_of_B;i++) {
        if (*(ptr_of_mass_B + i) % 2 == 0) {
            *(ptr_of_mass_B + i) = pow(*(ptr_of_mass_B + i), 2);
        }
    }
    cout << endl << "Массив B iз заміненими парними елементами" << endl;
    cout << "Елементи: ";
    
}
void third_task(int *ptr_mass,int size_of_mass) {
     
    for (int i = 0;i < size_of_mass;i++) {
        
        for (int j = 0;j < size_of_mass;j++) {
            if (*(ptr_mass + i) < 0) {
                *(ptr_mass + i) = -*(ptr_mass + i);
            }
            if (*(ptr_mass + i) > *(ptr_mass + j)) {
                swap(*(ptr_mass + i), *(ptr_mass + j));
            }
        }
    }


}
void Entering_mass(int *mass,int size_of_mass) {
    for (int i = 0, j = 1;i < size_of_mass;i++, j++) {
        cout << "Ведіть " << j << " елемент масиву :";
        cin >> mass[i];
    }

}
void Checking_mass(int *mass,int size_of_mass, int &size_of_C) {
    for (int i = 0;i < size_of_mass;i++) {
        if (mass[i] % 7 == 0) {
            size_of_C++;
        }
    }


}
void Checking_mass_C(int* mass , int size_of_mass, int* C, int& size_of_C, int& size_of_C_for_foo) {
    for (int i = 0;i < size_of_mass;i++) {
        if (mass[i] % 7 == 0 ) {
            C[size_of_C_for_foo] = mass[i];
            size_of_C_for_foo++;
        }
    }
}
void Output_mass(int* mass, int size_of_mass) {
    for (int i = 0;i < size_of_mass;i++) {
        cout <<  *(mass + i) << " ";
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\t\tЛабораторна робота №7\n";
    int size_of_A, size_of_B;
    int size_of_C = 0, size_of_C_for_foo = 0;
    cout << "Введіть кількість елементів масиву А: ";
    cin >> size_of_A;
    cout << "Введіть кількість елементів масиву B: ";
    cin >> size_of_B;
   
                   
     int* A = new int[size_of_A];
     int* B = new int[size_of_B];
     
                   
     cout << endl << "\t\tВведення масиву A" << endl;
     Entering_mass(A, size_of_A);
     Checking_mass(A, size_of_A, size_of_C);

     cout << endl << "\t\tВведення масиву В" << endl;
     Entering_mass(B, size_of_B);
     Checking_mass(B, size_of_B, size_of_C);
     if (size_of_C != 0) {
         int* C = new int[size_of_C];

         Checking_mass_C(A, size_of_A, C, size_of_C, size_of_C_for_foo);
         Checking_mass_C(B, size_of_B, C, size_of_C, size_of_C_for_foo);
         cout << endl << "\t\tЗавдання №1\n";
         cout << "Масив А: ";
         Output_mass(A, size_of_A);
         cout << "Масив В: ";
         Output_mass(B, size_of_B);
         cout << "Масив С: ";
         Output_mass(C, size_of_C);

         int* ptr_of_mass_C = C;

         first_task(ptr_of_mass_C, size_of_C);
         Output_mass(ptr_of_mass_C, size_of_C);
         cout << endl;
         delete[] C;
     }
     else {
         cout << endl << "\t\tЗавдання №1\n";
         cout << "У масиві С немає елементів кратних 7\n";
     }
    
     int* ptr_of_mass_A = A;
     int* ptr_of_mass_B = B;

          
     

            
     cout << "\t\tЗавдання №2" << endl;            
     second_task_A(ptr_of_mass_A, size_of_A);
     Output_mass(ptr_of_mass_A, size_of_A);
     second_task_B(ptr_of_mass_B, size_of_B);
     Output_mass(ptr_of_mass_B, size_of_B);
     cout << endl << "\n\t\tЗавдання №3\n";           
     cout << "Упорядкований массив елементів двох масивів " << endl;

     cout << "Відсортований масив A: ";           
     third_task(ptr_of_mass_A, size_of_A);
   
     Output_mass(ptr_of_mass_A, size_of_A);
           
     cout << "Відсортований масив B: ";            
     third_task(ptr_of_mass_B, size_of_B);
     Output_mass(ptr_of_mass_B, size_of_B);

            
     delete[] A;            
     delete[] B;            
     
             
             
         
    system("pause"); 
    return 0;
}

