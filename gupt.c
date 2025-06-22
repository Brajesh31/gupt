#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char *vs(char *s)
{
    int f = 0;
    while (f == 0)
    {
        scanf("%*c%[^\n]", s);
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] == ' ')
                f = 1;
            else
            {
                f = 0;

                printf("sorry you text is invalid\ntry again\n");
                break;
            }
        }
    }
    return s;
}

void additive()
{
    printf("ADDITIVE CIPHER\n");
    printf("==============================================================================================\n");
    int vk()
    {
        int key;
        int j = 0;
        while (j == 0)
        {
            char k[10000];
            key = 0;
            printf("enter your key\n");
            scanf("%*c%[^\n]", k);
            for (int i = 0; k[i] != '\0'; i++)
            {
                if (isdigit(k[i]))
                {
                    j = 1;
                    key = 10 * key + ((int)k[i] - 48);
                }
                else
                {
                    j = 0;
                    printf("sorry your key is invalid\n");
                    break;
                }
            }
        }
        return (key);
    }
    char *encrypt(char *s, int key)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = (((s[i] - 97) + key) % 26) + 97;
            }
            else if (s[i] == ' ')
            {
                s[i] = s[i];
            }
        }
        return s;
    }
    char *decrypt(char *s, int key)
    {
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = ((s[i] - 97 - key + 26) % 26) + 97;
            }
            else if (s[i] == ' ')
            {
                s[i] = s[i];
            }
        }
        return s;
    }

    void key()
    {
        char es[10000], ps[10000];
        printf("enter plain text\n");
        vs(ps);
        printf("enter encrypted text\n");
        vs(es);
        int i = 0;
        while (1)
        {
            char l[10000];
            strcpy(l, ps);
            if (strcmp(encrypt(l, i), es) == 0)
            {
                printf("key is %d\n ", i);
                break;
            }
            i++;
        }
    }
    while (1)
    {
        int n;
        
        
        printf("1. for encryption\n");
        printf("2. for decryption\n");
        printf("3. for key\n");
        printf("4. for exit\n");
        printf("choose your option\n");
        scanf("%i", &n);
        printf("==============================================================================================\n");
        switch (n)
        {
        case 1:
        {
            char s[1000];
            printf("enter plain text\n");
            vs(s);
            printf("encrypted text is %s \n", encrypt(s, vk()));
            printf("==============================================================================================\n");
        }
        break;
        case 2:
        {
            char s[1000];
            printf("enter encrypted text\n");
            vs(s);
            printf("decrypted text is %s \n", decrypt(s, vk()));
            printf("==============================================================================================\n");
        }
        break;
        case 3:
        {
            key();
            printf("==============================================================================================\n");
        }
        break;
        case 4:
        {
            printf("we are exiting\n");
            printf("==============================================================================================\n");
            return;
        }
        break;
        default:
        {
            printf("invalid input\n");
            scanf("%*c");
        }
        break;
        }
    }
}
void multiplicative()
{
    printf("MULTIPLICATIVE CIPHER\n");
    printf("==============================================================================================\n");
    int vk()
    {
        int key;
        int j = 0;
        while (j == 0)
        {
            char k[10000];
            key = 0;
            printf("enter your key\n");
            scanf("%*c%[^\n]", k);
            for (int i = 0; k[i] != '\0'; i++)
            {
                if (isdigit(k[i]))
                {
                    j = 1;
                    key = 10 * key + ((int)k[i] - 48);
                }
                else
                {
                    j = 0;
                    printf("sorry your key is invalid\n");
                    break;
                }
            }
        }
        if((key % 2 != 0) && (key % 13 != 0)) return (key);
        else printf("soory your key is invalid\n");
        return (vk());
    }

    char *encrypt(char *s, int key)
    {

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = (((s[i] - 97) * key) % 26) + 97;
            else if (s[i] == ' ')
            {
                s[i] = ' ';
            }
        }
        return s;
    }
    char *decrypt(char *s, int key)
    {
        int j = 0;
        while (j >= 0)
        {
            if (key * j % 26 == 1)
            {
                break;
            }
            j++;
        }
        printf("%d\n", j);
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = (((s[i] - 97) * j) % 26) + 97;
            }

            else if (s[i] == ' ')
            {
                s[i] = s[i];
            }
        }
        return s;
    }
    void key()
    {
        char es[10000], ps[10000];
        printf("enter plain text\n");
        vs(ps);
        printf("enter encrypted text\n");
        vs(es);
        int i = 0;
        while (1)
        {
            char l[10000];
            strcpy(l, ps);
            if (strcmp(encrypt(l, i), es) == 0)
            {
                printf("key is %d\n ", i);
                break;
            }
            i++;
        }
    }
    while (1)
    {
        int n;
        printf("1. for encryption\n");
        printf("2. for decryption\n");
        printf("3. for key\n");
        printf("4. for exit\n");
        printf("choose your option\n");
        scanf("%i", &n);
        printf("==============================================================================================\n");
        switch (n)
        {
        case 1:
        {
            char s[1000];
            printf("enter plain text\n");
            vs(s);
            printf("encrypted text is %s \n", encrypt(s, vk()));
            printf("==============================================================================================\n");
        }
        break;
        case 2:
        {
            char s[1000];
            printf("enter encrypted text\n");
            vs(s);
            printf("decrypted text is %s \n", decrypt(s, vk()));
            printf("==============================================================================================\n");
        }
        break;
        case 3:
        {
            key();
            printf("==============================================================================================\n");
        }
        break;
        case 4:
        {
            printf("we are exiting\n");
            printf("==============================================================================================\n");
            return;
        }
        break;
        default:
        {
            printf("invalid input\n");
            scanf("%*c");
        }
        break;
        }
    }
}
int main()
{
    printf("==============================================================================================\n\n");
    printf("*********   *       *   *********   *********\n");
    printf("*           *       *   *       *       *    \n");
    printf("*           *       *   *       *       *    \n");
    printf("*    ****   *       *   *********       *    \n");
    printf("*       *   *       *   *               *    \n");
    printf("*       *   *       *   *               *    \n");
    printf("*********   *********   *               *    \n\n");

    printf("==============================================================================================\n");
    printf("this is the tool for encryption, decryption and for finding keys\n");
    printf("==============================================================================================\n");
    while (1)
    {
        int n;
        printf("1. for additive cipher\n");
        printf("2. for multiplicative cipher\n");
        printf("3. for exit\n");
        printf("choose your option\n");
        scanf("%i", &n);
        printf("==============================================================================================\n");
        switch (n)
        {
        case 1:
        {
            additive();
        }
        break;
        case 2:
        {
            multiplicative();
        }
        break;
        case 3:
        {
            printf("THANK YOU!\n");
            printf("==============================================================================================\n");
            exit(0);
        }
        break;
        default:
        {
            printf("invalid input\n");
            scanf("%*c");
        }
        break;
        }
    }
}
