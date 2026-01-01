#include <iostream>

int main() {
    int* p = new int[10]; 
    p[10] = 5;            
    
    std::cout << "Hello" << endl; 
    return 0;
}