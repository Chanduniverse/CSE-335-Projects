/**
 * \file Duck.cpp
 *
 * \author Chandan Aralikatti
 * 
 * Class that describes a Duck.
 *
 * Creates a Duck
 */

#include <iostream>
#include "Duck.h"
#include "leak.h"

using namespace std;

/**
 * Obtain information from the user about this duck.
 *
 * Asks the user for the information that describes a duck.
 */
void CDuck::ObtainDuckInformation()
{
    cout << endl;
    cout << "Input information about the duck" << endl;

    cout << "Name: ";
    cin.ignore();
    getline(cin, mName);

    // Obtain the type using a menu. We have a loop so
    // we can handle errors.
    bool valid = false;

    while (mName[0] == ' ' || mName == "")
    {
        cout << "Error: Invalid Name, try again" << endl;
        cout << "Name: ";
        getline(cin, mName);
    }

    while (!valid)
    {
        cout << "1: Mallard Duck" << endl;
        cout << "2: Wood Duck" << endl;
        cout << "3: Disney Duck" << endl;
        cout << "4: Warner Brothers Duck" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin)
        {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (option)
        {
        case 1:
            mType = Type::MallardDuck;
            valid = true;
            break;

        case 2:
            mType = Type::WoodDuck;
            valid = true;
            break;

        case 3:
            mType = Type::DisneyDuck;
            valid = true;
            break;

        case 4:
            mType = Type::WarnerBrothersDuck;
            valid = true;
            break;
        }

    }

}

/**
 * Display information about this duck.
 */
void CDuck::DisplayAnimal()
{
    cout << mName << ": ";
    switch (mType)
    {
    case Type::MallardDuck:
        cout << "Mallard Duck" << endl;
        break;

    case Type::WoodDuck:
        cout << "Wood Duck" << endl;
        break;

    case Type::DisneyDuck:
        cout << "Disney Duck" << endl;
        break;

    case Type::WarnerBrothersDuck:
        cout << "Warner Brothers Duck" << endl;
        break;
    }
}

/** Determine if witch-weight or not.
 *
 * Is witch-weight if the duck is anything other than Disney Duck
 *
 * \returns bool based on witch-weight
 */
bool CDuck::IsWitchWeight()
{
    if (mType == Type::DisneyDuck)
        return false;
    return true;
}