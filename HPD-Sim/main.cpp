#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
	int bossKC, chanceDenom = 2000, chanceNumer = 1, modeChoice, simKills, simKC, dropRoll, skipCount = 0;
	double chanceNum, chanceDen;
	string simChoice;

	//seed rand
	srand(time(NULL));

	cout << "Current Helwyr kill count?" << endl;
	cin >> bossKC;

	cout << "\nChoose a mode\n"
		<< "1. Normal Mode\n"
		<< "2. Challenge Mode\n" << endl;
	cin >> modeChoice;

	while (modeChoice > 2 || modeChoice < 1)
	{
		cout << "Choice must be either 1 or 2" << endl;
		cin >> modeChoice;
	}

	if (modeChoice == 2)
	{
		chanceDenom = 1000;
	}

	chanceNumer += (bossKC / 400);

    chanceNum = chanceNumer;
    chanceDen = chanceDenom;

	cout << "\nYour current chance of obtaining the Helwyr pet is " << chanceNumer << "/" << chanceDenom << endl;
	cout << "This equates to a " << (double)((chanceNum/chanceDen) * 100) << "% chance" << endl;

	cout << "\nSimulate kills? (Y/N)" << endl;
	cin >> simChoice;

	while(simChoice != "Y" && simChoice != "N" && simChoice != "y" && simChoice != "n")
    {
        cout << "Choice must be Y or N" << endl;
        cin >> simChoice;
    }

    if(simChoice == "Y" || simChoice == "y")
    {
        cout << "\nEnter number of kills you wish to simulate: ";
        cin >> simKills;
        cout << endl;

        for(int i = 0; i <= simKills; i++)
        {
            simKC = bossKC + i;
            chanceNumer = (simKC / 400) + 1;

            if(simKC % 400 == 0)
            {
                skipCount++;

                chanceNum = chanceNumer;
                cout << "Current killcount = " << simKC << endl;
                cout << "Pet chance at " << simKC << " KC is " << chanceNumer << "/" << chanceDenom << " or " << chanceNum/chanceDen * 100 << "%" << endl;
                cout << "Press enter to continue simulating kills\n" << endl;

                if(skipCount == 1) cin.get();  //Fixes an error where the first pet chance notification is instantly skipped

                cin.get();
            }

            dropRoll = rand() % chanceDenom + 1;
            //cout << "Drop Roll = " << dropRoll << endl;
            //cin.get();

            if(dropRoll <= chanceNumer)
            {
                cout << "*****Congratulations! You have received the Helwyr pet at kill count " << simKC << "!*****" << endl;
                cout << "Press enter to exit the program\n";
                cin.get();
                return 0;
            }
        }
    }

    return 0;
}
