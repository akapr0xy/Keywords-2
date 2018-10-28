#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <windows.h>

using namespace std;

class keywordsGame
{
public:
	keywordsGame()
	{
		string username;
		cout << "Welcome to Keywords II, you must guess the correct letters in the word." << endl;
		cout << "Please login using your username." << endl;
		cin >> username;

		const int MAX_WRONG = 8;
		vector<string> words;
		words.push_back("GUESS");
		words.push_back("BLAH");
		words.push_back("HOOPLAH");
		words.push_back("MAKUDONARUDO");
		words.push_back("SUMIMASEN");
		words.push_back("OBISAN");
		words.push_back("KITKAT");
		words.push_back("WOOHOO");
		words.push_back("RAMEN");
		words.push_back("JAPANESE");

		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		const string THE_WORD = words[0];
		int wrong = 0;
		string soFar(THE_WORD.size(), '-');
		string used = "";

		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			cout << username << ", you have " << (MAX_WRONG - wrong) << " incorrect guesses left." << endl;
			cout << username << ", You've used the following letters: " << used << endl;
			cout << "So far, the word is: " << soFar << endl;

			char guess;
			cout << username << ", Please enter your guess: " << endl;
			cin >> guess;
			guess = toupper(guess);
			while (used.find(guess) != string::npos)
			{
				cout << "You've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess;

			if (THE_WORD.find(guess) != string::npos)
			{
				cout << "That's right! " << guess << " is in the word." << endl;
				for (int i = 0; i<THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word." << endl;
				wrong = wrong + 1;
			}
		}
		if (wrong == MAX_WRONG)
		{
			cout << username << ", you lose. Simulation Terminated." << endl;
			cout << "The word was " << THE_WORD << endl;
		}
		else
		{
			cout << username << ", congratulations, you have won. Simulation Successful." << endl;
			cout << "The word was " << THE_WORD << endl;
		}
		//system("pause");
	}
};

int main() {
	SetConsoleTitle("Keywords II");
	bool requestPlay = false;
	int acceptStart;
	int simulationCount = 1;

	do
	{
		cout << "Would you like to run the Keywords Simulation?" << endl << endl;
		cout << "This will be simulation number: " << simulationCount << endl;
		cout << "Press 1 for Yes, 2 for No" << endl << endl;
		cin >> acceptStart;
		if (acceptStart == 1)
		{
			keywordsGame();
			requestPlay = true;
			cout << endl;
			simulationCount++;
		}
		if (acceptStart == 2)
		{
			!requestPlay;
			return 0;
		}
	} while (requestPlay);
}