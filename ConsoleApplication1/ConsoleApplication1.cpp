// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    int nNoOfRec = 0;
    int nStartIndex = 0;

    // Inserting the number of Record in the initial
    std::cout << "Enter number of entries\n";
    std::cin >> nNoOfRec;
    while (nNoOfRec <= 0)
    {
        std::cout << "Minimum record should be more one atleast and should not be in negative\n";
        std::cin >> nNoOfRec;
    }
   
    
    int nTotal = nNoOfRec * 3;
    int* nEmpArr = new int[nTotal];

    std::cout << "Enter Employee Details ID, Age, Manger ID!\n";
    int nSwitch = 0;
    int nInloop = 1;
    for (int i = 0; i < nTotal; i++)
    {
        switch (nSwitch)
        {
        case 0:
            std::cin >> nEmpArr[i];
            
            while (nEmpArr[i] <= 0)
            {
                std::cout << " Employee ID should be in positive integers\n";
                std::cin >> nEmpArr[i];
            }
            if (nNoOfRec > 1)
            {
                if (i > 2)
                {
                    nStartIndex = 0;
                    for (; nInloop < nNoOfRec;)
                    {
                        while (nEmpArr[i] == nEmpArr[nStartIndex])
                        {
                            std::cout << " Employee ID should be unique\n";
                            std::cin >> nEmpArr[i];
                        }
                        if (i == 0 || i / 3 == 1)
                            nStartIndex = 0;
                        else
                            nStartIndex += 3;
                        nInloop++;
                    }
                }
            }
            nInloop = 1;
            nSwitch++;
            break;

        case 1:
            std::cin >> nEmpArr[i];
            nSwitch++;
            break;

        case 2:
            std::cin >> nEmpArr[i];
            nSwitch = 0;
            break;
        }
    }
    int nFunction = 0;
    int nInputManagerID = 0;
    std::cout << "Enter 1 for List or 2 for Search by Manger ID \n\n";
    cin >> nFunction;
    if (nFunction == 1)
    {
        for (int i = 0; i < nTotal; i++)
        {
            std::cout << nEmpArr[i] << "\n";
        }
    }
    else if (nFunction == 2)
    {
        std::cout << "Enter Manger ID \n";
        cin >> nInputManagerID;
        int nStartIndexMgrID = 2;
        int nIndex = 0;
        for (int i = 0; i < nNoOfRec; i++)
        {
            if (nInputManagerID == nEmpArr[nStartIndexMgrID])
            {
                nIndex = nStartIndexMgrID;
                std::cout << nEmpArr[nIndex] << nEmpArr[nIndex--] << nEmpArr[nIndex--];
            }
            nStartIndexMgrID += 3;
        }
    }
    else
    { 
        std::cout << "NA \n";
    }
    delete[] nEmpArr;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
