/*********************************************
 * Alabama A&M University - EE109 - Fall 2023
 * Lesson 13 exercise code: Making a Save File
 * By:            Prof J Zehnpfennig, PE
 * Created:       28 September 2023
 * Last Updated:  28 September 2023
 *********************************************/

#include <fstream>  //JZ - used to work with files
#include <iostream> //JZ - used to work with input/output streams
#include <string>   //JZ - used to work with strings

using namespace std;

int fileRead(string inFile);
int fileWrite(string outFile);

int main() 
{
  int choice = -1;
  string fileName;
  ofstream killFile; 
  
  while (choice!=0)
    {
      system("clear");
      
      cout << "\t\t\t\tWelcome to SaveFile!\n\n1. Add a new entry\n2. Read and display file contents\n3. Erase file contents\n0. Exit program\n\nMake a selection:  ";
      cin >> choice;
      
      cout << "\n\nPlease input the file name with extension (ex: file.txt):  ";
      cin >> fileName;  
      
      switch(choice)
        {
          case 0:
            {
              system("clear");
              cout << "I'll keep your data safe - see you soon!";
              return 0;
            }
          case 1:
            {
              fileWrite(fileName);
              choice = -1;
              break;
            }
          case 2:
            {
              fileRead(fileName);
              choice = -1;
              break;
            }
          case 3:
            {
              killFile.open(fileName);
              killFile.close();
              choice = -1;
              break;
            }
        }
    }
  return 0;
}//JZ - end of fileWrite

////////////////////////////////////////////////////////

int fileWrite(string outFile);
{
  string name; //JZ - input strings for first, last, and nick names
  float age = 0.0; //JZ - used a float b/c some people like fractional ages
  char ans = 'Y'; //JZ - condition for the loop
 
  ofstream writer;
  writer.open(outFile);
  
  while (ans == 'y' || ans =="Y") 
  {
    ans = 'z'; //JZ - we do this so that the loop below will run.  Without making ans out of bounds we'd have an infinite loop.
    system("clear)");

    cout << "\t\t\t\tData Input!"; 
    cout << "\n\nPlease input the first name:  ";
    cin >> name;
    writer << name << endl; //JZ - writes the user's input to file and then goes to a new line in the file

    cout << "\n\nPlease input the last name:  ";
    cin >> name;    //JZ - note, since we already "saved" the last input to file, we can re-use the same variable.  This saves memory for the computer and saves you trouble in remembering a bunch of variable names.
    writer << name << endl; //JZ - writes the user's input to file and then goes to a new line in the file

//JZ - Build the code for inputting and saving the nick name and age below (copy-paste is your friend!):

    while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N' && )
      {
        cout << "\n\nWould you like to enter another set of data? (y/n):  ";
        cin >> ans;
      }
  }

  writer.close();
  return 0;
} //JZ - end of fileWrite


///////////////////////////////////////////////////////
int fileRead(string inFile)
{
  string name;
  float age;
  
  ifstream reader;
  reader.open(inFile);

  system("clear");
  cout << "\t\t\t\File Reader!";
  
  if (reader.eof()) //JZ - verify that there is content in the file
  {
    cout << "\n\n" << inFile << " is an empty file.";
    return 0;
  }
  
  while(!reader.eof())
    {
      reader >> name;
      cout << "First Name:\t " << name << endl;
      reader >> name;
      cout << "Last Name:\t " << name << endl;
      reader >> name;
      cout << "Nick Name:\t " << name << endl;
      reader >> age;
      cout << "Age:\t\t " << name << endl;
    }
  reader.close();
  return 0;
}