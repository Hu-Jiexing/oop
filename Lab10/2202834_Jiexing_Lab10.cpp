// 2202834_Jiexing_Lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// main.cpp : Defines the entry point for the application.
// 
// Do not change this file - add your code in Set.h.
//

#include "Set.h"

int main()
{
    // Test with integers:
    Set<int> A("A");
    A.add(5);
    A.add(10);
    A.add(15);
    A.add(20);
    A.print();

    // Test with doubles:
    Set<double> B("B");
    B.add(5.5);
    B.add(10.15);
    B.add(20.25);
    B.add(3.35);
    B.print();

    // Test with chars:
    Set<char> C("C");
    C.add('a');
    C.add('b');
    C.add('c');
    C.add('d');
    C.print();

    Set<char> D("D");

    return 0;
}
