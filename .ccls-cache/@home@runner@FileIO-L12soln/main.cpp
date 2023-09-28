/*********************************************
 * Alabama A&M University - EE109 - Fall 2023
 * Lesson 12 exercise code: File read and write
 * By:            Prof J Zehnpfennig, PE
 * Created:       26 September 2023
 * Last Updated:  26 September 2023
 *********************************************/

#include <fstream>  //JZ - used to work with files
#include <iostream> //JZ - used to work with input/output streams
#include <string>   //JZ - used to work with strings

using namespace std;

int main() 
{
  string fileInput, usrInput;
  
  ifstream reader;
  ofstream writer;

   writer.open("UserInput.txt");
   reader.open("words.txt");

  while (!reader.eof()) 
  {
    // JZ - input the code to read the next line of text from 'reader' into
    // fileInput
    reader >> fileInput;
    cout << "\t" << fileInput;
  }

  cout << "\n\nPlease write a sentence that you'd like to write to file: ";
  getline(cin, usrInput);
  writer << usrInput << endl;
  writer.close();
  reader.close();
  // JZ - write the line of code that places the contents of usrInput into the
  // output stream 'writer'
}