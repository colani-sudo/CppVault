//
//  main.cpp
//  Strings
//
//  Created by Colani Matsenjwa on 2022/8/3.
//

#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, const char * argv[]) {
    int n,m;
    printf("Read input: ");
    scanf("%d",&n);
    
    m = n/2;
    bool flag = true;
    
    for(int i=2; i<n/2; i++){
        if(n%i == 0){
            flag = false;
            break;
        }
    }
    if(flag){
        printf("%d is a prime number.\n", n);
    }else{
        printf("%d is not a prime number.\n", n);
    }
    
//    read in an character and determine if its a alphabet, digit or other
//    char c;
//    cout << "Read input: ";
//    cin >> c;
//    if(isalpha(c)){
//        cout << c << " is an alphabet." << endl;
//    }else if(isdigit(c)){
//        cout << c << " is a digit." << endl;
//    }else{
//        cout << c << " is a special character." << endl;
//    }
    return 0;
}
        
