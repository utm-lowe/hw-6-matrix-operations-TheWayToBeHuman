/**
 * @file affine.cpp
 * @author Bob Lowe
 * @brief Perform affine transformations on 2D points.
 * @version 0.1
 * @copyright Copyright (c) 2024
 */
#include "matrix.h"
#include <iostream>
#include <cmath>

using namespace std;

// Transformation Matrix Creation Functions
Matrix transIdent();
Matrix transRotate(double angle);
Matrix transScale(double sx, double sy);
Matrix translate(double tx, double ty);
Matrix transformMenu();
Matrix getPoint();

int main() 
{
    Matrix transform = transformMenu();

    // Display the transformation matrix
    cout << "Transformation Matrix: " << endl;
    cout << transform << endl;
    cout << endl;

    // transform points
    while(cin) {
        Matrix point = getPoint();

        // Transform the point
        point = transform * point;

        // Display the transformed point
        if(cin) {
            cout << "Transformed Point: (" 
                 << point.at(0,0) << ", " << point.at(1,0) << ")" << endl;
        }
    }
}

// Build an identity matrix
Matrix transIdent()
{
    Matrix I(3,3);
    I.at(0,0) = 1; I.at(0,1) = 0; I.at(0,2) = 0;
    I.at(1,0) = 0; I.at(1,1) = 1; I.at(1,2) = 0;
    I.at(2,0) = 0; I.at(2,1) = 0; I.at(2,2) = 1;
    return I;
}

// Build a rotation matrix
Matrix transRotate(double angle)
{
    Matrix R(3,3);
    double radians = angle * M_PI / 180.0;

    R.at(0,0) = cos(radians); R.at(0,1) = -sin(radians); R.at(0,2) = 0;
    R.at(1,0) = sin(radians); R.at(1,1) = cos(radians);  R.at(1,2) = 0;
    R.at(2,0) = 0;            R.at(2,1) = 0;             R.at(2,2) = 1;

    return R;
}

// Build a scaling matrix
Matrix transScale(double sx, double sy) 
{
    Matrix S(3,3);
    S.at(0,0) = sx; S.at(0,1) = 0;  S.at(0,2) = 0;
    S.at(1,0) = 0;  S.at(1,1) = sy; S.at(1,2) = 0;
    S.at(2,0) = 0;  S.at(2,1) = 0;  S.at(2,2) = 1;
    return S;
}

// Build a translation matrix
Matrix translate(double tx, double ty) 
{
    Matrix T(3,3);
    T.at(0,0) = 1; T.at(0,1) = 0; T.at(0,2) = tx;
    T.at(1,0) = 0; T.at(1,1) = 1; T.at(1,2) = ty;
    T.at(2,0) = 0; T.at(2,1) = 0; T.at(2,2) = 1;
    return T;
}

// Transformation menu
Matrix transformMenu()
{
    Matrix result = transIdent();
    double x,y,angle;
    char choice;

    do {
        cout << "(T)ranslate, (R)otate, (S)cale, or (D)one? ";
        cin >> choice;
        choice = toupper(choice);

        switch(choice)  // <-- fixed from Switch to switch
        {
            case 'T':
                cout << "Enter the x and y translation: ";
                cin >> x >> y;
                result = translate(x,y) * result;
                break;

            case 'R':
                cout << "Enter the angle of rotation (degrees): ";
                cin >> angle;
                result = transRotate(angle) * result;
                break;

            case 'S':
                cout << "Enter the x and y scaling factors: ";
                cin >> x >> y;
                result = transScale(x,y) * result;
                break;

            case 'D':
                break;

           default:
    cout << "Invalid choice. Please try again." << endl;
    break;
        }

    } while(choice != 'D');

    return result;
}

// Get a 3x1 point from user
Matrix getPoint() 
{
    double x,y;
    cout << "Enter x and y: ";
    cin >> x >> y;

    Matrix point(3,1);
    point.at(0,0) = x;
    point.at(1,0) = y;
    point.at(2,0) = 1;

    return point;
}
