#include<iostream>

using namespace std;


int main(){

int n = 10;
char c = 'A';
double d;

int *p = &n;


*p = 25;


cout << n << *p<<"\n";

}

