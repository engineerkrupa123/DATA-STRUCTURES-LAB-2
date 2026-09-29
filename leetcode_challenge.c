#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char word[MAX], ch;
    int i, pos = -1;

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

    if (pos == -1)
    {
        printf("The character entered is not present in the word.");
    }
    else
    {
        for (i = 0; i <= pos; i++)
        {
            push(word[i]);
        }

        for (i = 0; i <= pos; i++)
        {
            word[i] = pop();
        }

        printf("Result: %s", word);
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
