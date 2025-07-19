
 #include <iostream>
 #include <cmath>
 using namespace std;
 int main() {
     double a,b;
     cout << "Enter the first number: ";
     cin >>a;
     cout << "Enter the second number: ";
     cin >> b;
     cout << "Enter the operation (+, -, *, /): ";
     char operation;
     cin >> operation;

     switch (operation) {
         case '+':
             cout << "The sum is: " << a + b<<endl;
             break;
        
         case '-':
             cout << "The difference is: " << a - b<<endl;
             break;
         case '*':
             cout << "The product is: " << a * b<<endl;
             break;
         case '/':
             if (b != 0) {
                 cout << "The quotient is: " << a / b<<endl;
             } else {
                 cout << "Error: Division by zero is not allowed."<<endl;
             }
             break;
         default:
             cout << "Invalid operation. Please enter +, -, *, or /.";
             break;
     }

     return 0;
 }