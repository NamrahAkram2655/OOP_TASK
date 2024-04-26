#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char c)
{
    c = tolower(c); // Convert to lowercase for easier comparison
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void vowelsPerWord(const char *str)
{
    if (strlen(str) == 0)
    {
        cout << "Empty string." << endl;
        return;
    }

    cout << "Word\tVowel Count" << endl;
    char word[50];
    int vowels = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            word[vowels++] = str[i];
        }
        else if (vowels > 0)
        {
            word[vowels] = '\0'; // Null terminate the word
            int vowelCount = 0;
            for (int j = 0; j < vowels; j++)
            {
                if (isVowel(word[j]))
                {
                    vowelCount++;
                }
            }
            cout << word << "\t" << vowelCount << endl;
            vowels = 0; // Reset vowel count for the next word
        }
    }

    if (vowels > 0)
    {
        word[vowels] = '\0'; // Null terminate the last word
        int vowelCount = 0;
        for (int j = 0; j < vowels; j++)
        {
            if (isVowel(word[j]))
            {
                vowelCount++;
            }
        }
        cout << word << "\t" << vowelCount << endl;
    }
}

int main()
{
    const int MAX_LENGTH = 50;
    char input[MAX_LENGTH];

    cout << "Enter a string (max 50 characters): ";
    cin.getline(input, MAX_LENGTH);

    vowelsPerWord(input);

    return 0;
}
