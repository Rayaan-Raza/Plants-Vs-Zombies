#pragma once
#include<iostream>
using namespace std;

struct Coordinate
{
    double x, y;

public:
    Coordinate(double x = 0, double y = 0);

    // Setter methods
    void setX(double x);
    void setY(double y);

    double getX() const;
    double getY() const;


    // Print coordinates
    void print() const;
};

