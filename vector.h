#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
private:
    double* elem; // elem points to an array of sz doubles
    int sz;
public:
    Vector(int s) :elem{new double[s]}, sz{s} // constructor: acquire resources
    {
        for (int i=0; i!=s; ++i) elem[i]=0; // initialize elements
    }

    ~Vector() { delete[] elem; } // destructor: release resources

    double& operator[](int i);
    int size() const;
};

void vector(int n){
    Vector v(n);
    //v[0]=2;
    //cout <<"the square of " << v[0] << " is " << sqrt(v[0]) <<"\n";
    cout <<"Option not available\n";
    for(int i=0; i!=sz; i++)
    {
        cout<< "the value x: " << v[i] <<endl;
        //cout<< "Enter value: "<<endl;
        //cin>>v.elem[i];
        i++;
    }
}


#endif // VECTOR_H

