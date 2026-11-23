//Names: Hany, Aleeza, Thanh, Victor, and Jacob
//Date: 11/20/2026
//Description: Module 13 - Sorting

#include <iostream>
#include "input.h"
#include "SortingSimulation.h"

using namespace std;

//function prototypes
char menuOption();
void option1();
void option2();

int main()
{
	bool running = true;
	char option;

    while (running)
    {
		system("cls");
        option = menuOption();
        switch (option)
        {
        case '1':
        {
			option1();
            cout << "\n\n";
			system("pause");
            break;
        }
        case '2':
        {
			option2();
			cout << "\n\n";
			system("pause");
            break;
        }
        case '0':
            running = false;
            break;
        default:
            cout << "\n\t\tInvalid option. Please try again.\n";
            break;
        }
	}

	return 0;
}


char menuOption()
{
    cout << "\tCMPR131 Chapter 13: Sortings by Hany, Aleeza, Thanh, Victor, and Jacob (11/20/2026)\n";
    cout << "\t" << string(100, char(205));
    cout << "\n\t\t1> Sorting simulations";
    cout << "\n\t\t2> Application of student records\n";
    cout << "\t" << string(100, char(196));
    cout << "\n\t\t0 > Exit\n";
    cout << "\t" << string(100, char(205));

    char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,0")));
    return option;
}

// Option 1 - Sorting simulations
//precondition: none
//postcondition: displays the sorting simulations menu and allows the user to perform various sorting algorithms on a dynamic array
void option1()
{
    SortingSimulation sorting;

	bool running = true;

    while (running)
    {
		system("cls");
        cout << "\n\t1> Sort simulations";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Create a dynamic array and fill with random elements";
        cout << "\n\t\tB> Display the unsorted array";
        cout << "\n\t\tC> Perform BubbleSort";
        cout << "\n\t\tD> Perform SelectionSort";
        cout << "\n\t\tE> Perform InsertionSort";
        cout << "\n\t\tF> Perform QuickSort";
        cout << "\n\t\tG> Perform MergeSort";
        cout << "\n\t\tH> Perform HeapSort";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));
        char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("A,B,C,D,E,F,G,H,0")));
        switch (option)
        {
        case 'A':
        {
            int newSize = inputInteger("\n\t\tEnter the size of the dynamic array: ", 1, 100000000);

            sorting.createArray(newSize);
			cout << "\n";
			system("pause");
            break;
        }
        case 'B':
        {
            try
            {
                sorting.displayUnsortedArray();
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
            }
			cout << "\n";
			system("pause");
            break;
        }
        case 'C':
        {
            try
            {

                if (sorting.isEmpty())
                {
                    throw string("ERROR: The dynamic array is empty.");
                }
                cout << "\n\t\tBubbleSort:\n";
                char order = toupper(inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("A,D")));

                sorting.performBubbleSort(order == 'A');
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
            }
			cout << "\n";
			system("pause");
            break;
        }
        case 'D':
        {
            try
            {
                if (sorting.isEmpty())
                {
                    throw string("ERROR: The dynamic array is empty.");
                }

                cout << "\n\t\tSelectionSort:\n";
                char order = toupper(inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("A,D")));

                sorting.performSelectionSort(order == 'A');
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
            }
			cout << "\n";
			system("pause");
            break;
        }
        case 'E':
        {
            try
            {
                if (sorting.isEmpty())
                {
                    throw string("ERROR: The dynamic array is empty.");
                }

                cout << "\n\t\tInsertionSort:\n";

                char order = toupper(inputChar(
                    "\n\t\tChoose sort in (A)scending or (D)escending order: ",
                    static_cast<string>("A,D")
                ));

                sorting.performInsertionSort(order == 'A');
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
            }
			cout << "\n";
			system("pause");
            break;
        }
        case 'F':
        {
            try
            {
                // Check whether the dynamic array is empty
                if (sorting.isEmpty())
                {
                    throw string("ERROR: The dynamic array is empty.");
                }

                cout << "\n\t\tQuickSort:\n";

                char order = toupper(inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("A,D")));
                sorting.performQuickSort(order == 'A');
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
            }

            cout << "\n";
            system("pause");

            break;
        }
        case 'G':
        {
            try
            {
                // Check whether the dynamic array is empty
                if (sorting.isEmpty())
                {
                    throw string("ERROR: The dynamic array is empty.");
                }

                cout << "\n\t\tMergeSort:\n";

                char order = toupper(inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("A,D")));

                sorting.performMergeSort(order == 'A');
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
            }

            cout << "\n";
            system("pause");

            break;
        }
        case 'H':
        {
            try            
            {
                // Check whether the dynamic array is empty
                if (sorting.isEmpty())
                {
                    throw string("ERROR: The dynamic array is empty.");
                }
                cout << "\n\t\tHeapSort:\n";
                char order = toupper(inputChar("\n\t\tChoose sort in (A)scending or (D)escending order: ", static_cast<string>("A,D")));
                sorting.performHeapSort(order == 'A');
            }
            catch (const string& error)
            {
                cout << "\n\t\t" << error << "\n";
			}

			cout << "\n";
			system("pause");
            break;
        }
        case '0':
            running = false;
            break;
        default:
            cout << "\n\t\tInvalid option. Please try again.\n";
            break;
        }

    }

}


void option2()
{
    bool running = true;
    while (running)
    {
		system("cls");
        cout << "\n\t2> Application of sorting student records";
        cout << "\n\t" << string(100, char(205));
        cout << "\n\t\tA> Read in data file";
        cout << "\n\t\tB> Display records";
        cout << "\n\t\tC> Insert a record";
        cout << "\n\t\tD> remove a record";
        cout << "\n\t\tE> Sort records by ID, name, major or GPA";
        cout << "\n\t\tF> Write out data file";
        cout << "\n\t" << string(100, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(100, char(205));
        char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("A,B,C,D,E,F,0")));
        switch (option)
        {
        case 'A':
            break;
        case 'B':
            break;
        case 'C':
            break;
        case 'D':
            break;
        case 'E':
            break;
        case 'F':
            break;
        case '0':
            running = false;
            break;
        default:
            cout << "\n\t\tInvalid option. Please try again.\n";
            break;
        }
    }
}

