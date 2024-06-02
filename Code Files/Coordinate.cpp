#include "Coordinate.h"
// Constructor
Coordinate::Coordinate(double x, double y) : x(x), y(y) {}

// Setter methods
void Coordinate::setX(double x) { this->x = x; }
void Coordinate::setY(double y) { this->y = y; }

// Getter methods
double Coordinate::getX() const { return x; }
double Coordinate::getY() const { return y; }

// Print coordinates
void Coordinate::print() const
{
    cout << "Coordinate(" << x << ", " << y << ")" << endl;
}