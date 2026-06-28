#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <map>
#include <string>

using namespace std;

// CornerGrocer class handles reading grocery data,
// storing item frequencies, creating a backup file,
// and displaying menu options for the user.
class CornerGrocer {
public:
    // Constructor automatically loads input data and creates the backup file.
    CornerGrocer();

    // Displays the menu and processes user selections.
    void DisplayMenu();

private:
    // Stores each grocery item as the key and its purchase count as the value.
    map<string, int> itemFrequency;

    // Reads grocery items from the input file.
    void LoadInputFile();

    // Creates the required frequency.dat backup file.
    void CreateBackupFile();

    // Menu option 1: searches for one item frequency.
    void SearchItemFrequency();

    // Menu option 2: displays all item frequencies.
    void DisplayAllFrequencies();

    // Menu option 3: displays all item frequencies as a histogram.
    void DisplayHistogram();
};

#endif