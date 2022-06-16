#include "Header.h"
#include "Ring.h"

int main()
{
    string num1, num2, num3;
    cout << "Enter the sizes of the ring. Format: XCoordinateOfCenter yCoordinateOfCenter InsideRadius OutsideRadius \nFor example:\n";
    cout << "1 2 3 4\n";
    cout << "will create ring with XCoordinateOfCenter = 1, yCoordinateOfCenter = 2, InsideRadius = 3, OutsideRadius = 4\n\n";
    cout << "Or you can create a ring randomly by entering a gap for the outer and inner radius and for x, y coordinates of center. \nFormat: [LoverLimitOfRadiuses, HigherLimitOfRadiuses], [LoverLimitOfCenterCoordinates, HigherLimitOfCenterCoordinates] \nFor example:\n";
    cout << "[1,3], [5,8]\n";
    cout << "will create ring with XCoordinateOfCenterand yCoordinateOfCenter from gap [1,3], InsideRadius and OutsideRadius \nfrom gap [5,8]\n\n";
    cout << "You also can leave the row empty to set its value to 1 (default)\n\n";
    getline(cin, num1);
    getline(cin, num2);
    getline(cin, num3);
    Ring C1 = createRing(num1);
    Ring C2 = createRing(num2);
    Ring C3 = createRing(num3);

    cout << "\nR1:\n";
    C1.displayValue();
    C1.countWidth();
    cout << "\nR2:\n";
    C2.displayValue();
    C2.countWidth();
    cout << "\nR3:\n";
    C3.displayValue();
    C3.countWidth();

    ++C1;
    cout << "\nÑ1 was incremented (Inside radius):\n";
    C1.displayValue();
    C1.countWidth();

    C2++;
    cout << "\nÑ2 was incremented (Outside radius):\n";
    C2.displayValue();
    C2.countWidth();

    C3*=2;
    cout << "\nÑ3 outside radius was multiplied by 2:\n";
    C3.displayValue();
    C3.countWidth();
}