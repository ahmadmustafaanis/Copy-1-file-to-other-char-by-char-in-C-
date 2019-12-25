/*
Created by: Ahmad Mustafa Anis
Title: Copy Text from 1 file to Other
Working: Saves a string in 1st file from user and then copy it char by char in 2nd file
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream putIn1File;
	fstream secondFile;
	int choice;
	string OrignalFile;
	char charbycharCopy=' ';
	string check;
	
	do {
		cout << "Type 1 to Input text to save in Orignal File\n2 to Copy txt from Orignal File to Other File\n3 to output from 2nd file\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			putIn1File.close();//I close it because let say when we come from case 2 or case 3 we dont know where is pointer at putin1file so we close it and reopen it so it points at begging of file
			putIn1File.open("orignal.txt", ios::out | ios::in);
			if (!putIn1File.good())
			{
				cout << "File Not Found\n";
				exit(-1);
			}


			cout << "Type Word to Input In 1st File";
			cin.ignore(10, '\n');
			getline(cin, check); //takes string from user
			putIn1File << check;//adds that string in 1st file
			break;
		case 2:
			putIn1File.close();
			putIn1File.open("orignal.txt", ios::out | ios::in);
			secondFile.close();
			secondFile.open("copied.txt", ios::in | ios::out);
			if (!putIn1File.good())
			{
				cout << "File Not Found\n";
				exit(-1);
			}
			if (!secondFile)
			{
				cout << "NOT OPENED\n";
				exit(-1);
			}
			while (putIn1File.get(charbycharCopy))//we copy char by char from beg of 1st file unitll eof
			{
				secondFile << charbycharCopy;//paste that char we copied from first file in 2nd file
			}
		case 3:
			secondFile.close();
			secondFile.open("copied.txt", ios::in | ios::out);
			while (secondFile.get(charbycharCopy))
			{
				  cout << charbycharCopy;//simply outputs the second file
			}
		default:
			break;
		}

	} while (choice != 4);
	putIn1File.close();
	secondFile.close();
}