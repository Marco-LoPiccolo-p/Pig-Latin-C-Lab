// MarcoLoPiccolo_PigLatinLab.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>               //Allows us to use String Class and its Functions
#include <sstream>             //Allows us to use the string stream class and its Functions
using namespace std;

string convertToPigLatin(string& userInput);   //Function Header 

int main()
{
    string userInput;                      //Declares string that will be inputted by user
    string pigLatinSentence;               //Declares string that the converted sentence will be stored into

    cout << "Please Enter a Sentence" << endl;   //Prompts user to enter a sentence of any length
    getline(cin, userInput);                //Utilizes the string version of getline so that whitespace doesn't mess up user input

    pigLatinSentence = convertToPigLatin(userInput);   //Calls function to convert sentence into pig latin and stores it in pig latin string

    cout << "Your Sentence in Pig Latin is:" << endl;  //Outputs new sentence
    cout << pigLatinSentence << endl;

    system("Pause");
    return 0;
}

/*Function converts an inputted string that is pass by reference to save memory within the code
The function returns a string of the converted sentence to pig latin*/
string convertToPigLatin(string& userInput) {
    string pigLatinSentence = "";       //Declares string that the sentence will be stored into
    string tempWord;               //Declares a string that is used for string stream later
    stringstream sentence(userInput);  //Declares a string stream which makes the userInput of the string object associated with the string
                                       //This allows us to read values from the string by taking note of the white space 
    while (sentence >> tempWord) {    //The >> allows us to read the indivual value before the whitespace from the string that is saved into the string stream object
                                      //Then the tempword takes that string and then can be used as a place holder for each word in the string
        if (tempWord[0] == 'a' || tempWord[0] == 'e' || tempWord[0] == 'i' || tempWord[0] == 'o' ||
            tempWord[0] == 'u' || tempWord[0] == 'A' || tempWord[0] == 'E' || tempWord[0] == 'I' ||   //Checks for the first letter of the word for a vowel and if it is then
            tempWord[0] == 'O' || tempWord[0] == 'U') {                                               //it adds the string "way" to the string by using the class's ability to add strings to present strings
            tempWord = tempWord + "way";                                                              //by using the + operator
            if (pigLatinSentence == "") {
                pigLatinSentence = pigLatinSentence + tempWord;                                      //Checks if it is the first word in the string and if it is then no space is needed in between tempword and string
            }
            else {
                pigLatinSentence = pigLatinSentence + " " + tempWord;                                //Or the tempword is added to the pig latin sentence with a space in between
            }                         
        }
        else {
            tempWord = tempWord + tempWord[0];                             //If it is a consonant for the first letter, the tempword adds the first letter to the end of the word
            tempWord = tempWord + "ay";                                   //Then it adds the string "ay"
            tempWord = tempWord.erase(0, 1);                              //Then uses the string function of erase to get rid of the index spot of zero and only goes for one space to delete the first letter
            if (pigLatinSentence == "") {
                pigLatinSentence = pigLatinSentence + tempWord;                                    //Checks if it is the first word in the string and if its then no space is needed in between tempword and string
            }
            else {
                pigLatinSentence = pigLatinSentence + " " + tempWord;                                //Or the tempword is added to the pig latin sentence with a space in between
            }
        }
    }
    
    return pigLatinSentence;                    //Returns the converted pig latin sentence to the main function

    }
     

