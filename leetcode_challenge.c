#include <stdio.h>

int main()
{
    char word[100], ch, temp;
    int i, j, pos = -1;

    printf("Enter the word: ");
    scanf("%s", word);

    printf("Enter the character: ");
    scanf(" %c", &ch);

    for (i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ch)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        i = 0;
        j = pos;

        while (i < j)
        {
            temp = word[i];
            word[i] = word[j];
            word[j] = temp;

            i++;
            j--;
        }

        printf("Result: %s", word);
    }
    else
    {
        printf("The character entered is not present in the word.");
    }

    return 0;
}


OUPUT 
CASE 1:
Enter the word: abcdef
Enter the character: r
The character entered is not present in the word.
CASE 2:
Enter the word: abcdefd
Enter the character: d
Result: dcbaefd
