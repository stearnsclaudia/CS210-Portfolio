#include "CornerGrocer.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

// Constructor runs automatically when a CornerGrocer object is created.
CornerGrocer::CornerGrocer() {
    LoadInputFile();      // Load grocery items from the input file.
    CreateBackupFile();   // Create frequency.dat as a backup file.
}

// Reads grocery items from the input file and counts each item using a map.
void CornerGrocer::LoadInputFile() {
    ifstream inputFile("CS210_Project_Three_Input_File.txt");
    string item;

    // If the file cannot be opened, display an error message.
    if (!inputFile.is_open()) {
        cout << "ERROR: Could not open CS210_Project_Three_Input_File.txt" << endl;
        return;
    }

    // Each word in the file represents one purchased item.
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// Creates the required frequency.dat file for backup purposes.
void CornerGrocer::CreateBackupFile() {
    ofstream outputFile("frequency.dat");

    // Write each item and its frequency to the backup file.
    for (const auto& item : itemFrequency) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}

// Displays the main menu until the user chooses to exit.
void CornerGrocer::DisplayMenu() {
    int choice = 0;

    while (choice != 4) {
        cout << endl;
        cout << "========== Corner Grocer Menu ==========" << endl;
        cout << "1. Search for an item frequency" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display item histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        // Handles invalid input such as letters or symbols.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 4." << endl;
            continue;
        }

        // Runs the correct function based on the user's menu choice.
        switch (choice) {
        case 1:
            SearchItemFrequency();
            break;
        case 2:
            DisplayAllFrequencies();
            break;
        case 3:
            DisplayHistogram();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    }
}

// Menu option 1: searches for a single item and displays its frequency.
void CornerGrocer::SearchItemFrequency() {
    string item;

    cout << "Enter the item you want to search for: ";
    cin >> item;

    // If the item exists in the map, display its count.
    if (itemFrequency.find(item) != itemFrequency.end()) {
        cout << item << " appears " << itemFrequency[item] << " time(s)." << endl;
    }
    else {
        cout << item << " appears 0 time(s)." << endl;
    }
}

// Menu option 2: displays every item with its numeric frequency.
void CornerGrocer::DisplayAllFrequencies() {
    cout << endl;
    cout << left << setw(20) << "Item" << "Frequency" << endl;
    cout << "--------------------------------" << endl;

    // Loops through the map and prints each item with its count.
    for (const auto& item : itemFrequency) {
        cout << left << setw(20) << item.first << item.second << endl;
    }
}

// Menu option 3: displays every item using a text-based histogram.
void CornerGrocer::DisplayHistogram() {
    cout << endl;
    cout << "Item Purchase Histogram" << endl;
    cout << "-----------------------" << endl;

    // Prints one asterisk for each time the item appears in the input file.
    for (const auto& item : itemFrequency) {
        cout << left << setw(20) << item.first;

        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }

        cout << endl;
    }
}