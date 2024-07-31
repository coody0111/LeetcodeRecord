#include <stdio.h>
#include <string.h>

#define LEN 12
void swap(char **a, char **b);
void PrintfStrs(char *str[], int len);
void SelectSort(char *str[], int len);
int main()
{

    char *names[LEN] = {
        "Jay",
        "Gloria",
        "Phil",
        "Clair",
        "Cam",
        "Mitch",
        "Joey",
        "Monica",
        "Rachel",
        "Chandler",
        "Phoebe",
        "Ross"};
    PrintfStrs(names, LEN);
    SelectSort(names, LEN);
    PrintfStrs(names, LEN);
    return 0;
}

void PrintfStrs(char *str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%s ", str[i]);
    }
    printf("\n");
}
void SelectSort(char *str[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min_location = i;
        char *min = str[i];
        for (int j = i + 1; j < len; j++)
        {
            if (strcmp(min, str[j]) > 0)
            {
                min = str[j];
                min_location = j;
            }
        }
        // move strp[min_loc] to str[i]
        swap(&str[min_location], &str[i]);
    }
}

void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}