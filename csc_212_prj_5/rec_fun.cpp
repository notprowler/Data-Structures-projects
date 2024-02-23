#include "rec_fun.h" //rec_fun header file
#include <bits/stdc++.h>
using namespace std;


//power function
double pow(double x, int n)
{
    if (n!= 1) //base case
        return (x*pow(x, x-1));// x^n=x*pow(x,n-1)
    else
        return 1;// return 1
}
//print traingular pattern
void triangle(ostream& outs, unsigned int m, unsigned int n)
{
    if (m>n) return;      //base case
    else{
        for (int q = 1; q <=m; q++)
        {outs << "*";} //print *
        outs<< endl; //new line
        //recursively call for m+1 stars line
        triangle(outs,m +1, n);
        //for bottom part of triangle
        //print stars
        for (int q = 1; q <= m; q++)
        {outs << "*";}


        outs << endl;
    }

}
//similar to printing *s but instead of stars
//print the text
void indented_sentences(size_t m, size_t n)
{
    if (m>n) return; //base case
    else{
        for (int q = 1; q <m; q++)
            cout <<" ";//print spaces
        cout<<"This was written by calling number "<<m<< endl;
        //recursively call for m+1  line
        //for bottom part
        indented_sentences(m +1, n);
        for (int q = 1; q <m; q++) //to print spaces
            cout <<" ";
        cout<<"This was ALSO written by calling number"<<m<<endl;

    }
}
//print in binary format
void binary_print(ostream& outs, unsigned int n)
{
    if(n<=1) //base case
    {
        outs<<n;
        return;
    }
    //recursively call by dividing by 2
    binary_print(outs,n>>1);
    outs<<n%2;//print n%2
}