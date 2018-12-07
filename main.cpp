#include <iostream>
//#include <vector.h>
#include "class.h"
#include<string.h>


using namespace std;
//Basics
struct TheVector{
    int sz;
    double* elem;
};

double square(double x)
{
    return x*x;
}


void print_square(double x)
{
    cout << "the square of " << x << " is " << square(x) <<"\n";
}
void print()
{
    int v1[]={0,1,2,3,4,5,6,7,8};
    for(auto x : v1)
        cout<<x<<"\n";
}
void increment()
{
    int v1[]={0,1,2,3,4,5,6,7,8};
    for(auto& x : v1)
    {
        ++x;
        cout<<x<<"\n";
    }
}
void vector_init(TheVector& v, int s)
{
    v.elem = new double[s]; //operator "new" allocates memory from an area called the free store (dynamic memory and heap)
    v.sz = s;
}

double read_and_sum(int s)
{
    TheVector v;
    vector_init(v,s);
    for(int i=0; i!=s; i++)
    {
        cout<< "Double Sum enter values "<<endl;
        cout<< "Enter value: "<<endl;
        cin>>v.elem[i];
    }
    double sum = 0;
    for(int i=0; i!=s; ++i)
        sum+=v.elem[i];
    return sum;
}

void basics(){
    int answer;
    double sum = read_and_sum(5);
    char array[8]={'a','b','c','d','e','f'};

    cout << "Hello World!\n Enter a number" << endl;
    cin>>answer;

    print_square(answer);
    char* p=&array[answer];
    char x = *p;
    char** y = &p;
    cout<< " The sum is: " << sum << endl;
    cout << "the value x: " << x << "\n" << "the value p: " << p << "\n" << "the value y: " << y << "\n";
    //increment();
}
// CLASSES

void test(){
    int i = 13, j = 60;
    cout<<i<<" "<<j<<"\n";
    i^=j;
    cout<<i<<" "<<j<<"\n";
    j^=i;
    cout<<i<<" "<<j<<"\n";
    i^=j;
    cout<<i<<" "<<j<<"\n";
    union abc {
            int x;
            char ch;
        } var;

       var.ch = 'A';
       cout<<var.x<<"\n";
       char s[] = "Hello\0Hi";

          cout<<strlen(s)<<" "<<sizeof(s);

          class student {
             public : int rno = 10;
          } v;

          cout<<v.rno;
}
int main()
{
    int answer;

    cout << "Hello C++!\n\nSelect your example:\n" << endl; // "<<" operator put to
    cout << "1 - Basics" << endl;
    cout << "2 - Classes" << endl;
    cout << "3 - Constructor/Destructor" << endl;
    cout << "4 - Copy Constructor" << endl;
    cout << "5 - Friend Function" << endl;
    cout << "6 - Inline Function" << endl;
    cout << "7 - This Pointer" << endl;
    cout << "8 - Pointer in Classes" << endl;
    cout << "9 - Static Functions" << endl;
    cin>>answer;

    switch(answer)
    {
    case 1:
        basics();
        break;
    case 2:
        print_class();
        break;
    case 3:
        constructor();
        break;
    case 4:
        copy_construct();
        break;
    case 5:
        print_friend();
        break;
    case 6:
        ex_inline();
        break;
    case 7:
        this_pointer();
        break;
    case 8:
        ex_pointer();
        break;
    case 9:
        ex_static();
        break;

    default:
        test();
        cout <<"Option not available\n";
    }

    return 0;
}
