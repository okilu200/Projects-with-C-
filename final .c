#include <stdio.h>
#include <string.h>
#include <windows.h>

int checkPasscode(char *entered, char *correct)
{
    if (strcmp(entered, correct) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char correctPasscode[10] = "12345";
    char enteredPasscode[10];
    int attempts;
    int maxAttempts = 5;
    int tries = 0;
    printf("WELCOME TO YOUR PHONE\n");
    printf("Enter Your password to unlock!\n");
    while (1)
    {
        attempts = 0;
        while (attempts < maxAttempts)
        {
            printf("\nEnter Your Password: ");
            scanf("%s", enteredPasscode);

            if (checkPasscode(enteredPasscode, correctPasscode))
            {
                printf("\n YOUR PHONE IS UNLOCKED!");
                return 0;
            }
            else
            {
                attempts++;
                printf(" Wrong Password! Attempts left: %d\n", maxAttempts - attempts);
            }
        }

        tries++;
        if (tries == 1)
        {
            printf("\n Too many wrong attempts. Wait 5 sec to try again....\n");
            Sleep(5000);
            printf("\nYou can try again now.\n");
        }
        else
        {
            printf("\n Your Phone is permanently locked!\n");
            printf("Contact support Server\n");
            printf("For support, visit: https://support.apple.com/iphone\n");
            return 0;
        }
    }

    return 0;
}
