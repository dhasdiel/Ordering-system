#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-------------------------------------------------------------
// Ordering System.
//-------------------------------------------------------------
//
// General: The program manage the names of the guests who
// come to the restaurant.
//
// Input: Operator and then the operands for the game.
//
// Process: The program activates a function to perform the
// operation according to the actoin of the user.
//
// Output: Print the results of the actoin of the user.
//
//-------------------------------------------------------------
// Programmer: Daniel Hasdiel.
// Student num: *********
// Date: **/**/****
//-------------------------------------------------------------
// Function prototype
// -----------------------
void PrintListOfGuests(char** arrAllGuests, int* ionGuestCounter);
char** AddAGuest(char** arrAllGuests, int* ionGuestCounter, char* szName);
char** CancelGuest(char** arrAllGuests, int* ionGuestCounter, char* szName);
char** CancelAllGuests(char** arrAllGuests, int* ionGuestCounter);
int ExitList(int nNum);
void MenuList();
void DrawLine();
//-------------------------------------------------------------
int main()
{
    // Variable definition
    char** sGuests = NULL, sName[256] = { 0 };
    int nCount = 0, nNum = 0;
 
    // Code Section
    DrawLine();
    while (!ExitList(nNum)) {
        MenuList();
        printf("Enter the num: ");
        scanf("%d", &nNum);
        switch (nNum) {
        case 1:
            PrintListOfGuests(sGuests, &nCount);
            break;
        case 2:
            printf("-> Enter the name of the guest you want to add: ");
            scanf("%s", sName);
            sGuests = AddAGuest(sGuests, &nCount, sName);
            break;
        case 3:
            printf("-> Enter the name of the guest you want to cancel: ");
            scanf("%s", sName);
            sGuests = CancelGuest(sGuests, &nCount, sName);
            break;
        case 4:
            sGuests = CancelAllGuests(sGuests, &nCount);
            break;
        case 5:
            ExitList(nNum);
            break;
        default:
            printf("Invaild input\n");
            break;
        }
        DrawLine();
    }
    return 0;
}
//-------------------------------------------------------------
// Functions
//-------------------------------------------------------------
// Print list of guests
// -----------------------
//
// General: The function print the list of guests.
//
// Parameters: Get the arr of the strings and the counter(index).
//
// Return value: The function print the list of guests.
//
//-------------------------------------------------------------
void PrintListOfGuests(char** arrAllGuests, int* ionGuestCounter) {
    // Variable definition
    int i;
    // Code Section
    if (!*ionGuestCounter) {
        printf("The list is empty.\nTo add a guest click |2|.\n");
        return;
    }
    for (i = 0; i < *ionGuestCounter; i++) {
        printf("| In place %d: %s.\n", i + 1, arrAllGuests[i]);
    }
}
//-------------------------------------------------------------
// Add a guest
// -----------------------
//
// General: The function add a guest to the list.
//
// Parameters: Get the arr of the strings and the counter(index)
// with the name from the user.
//
// Return value: The function add a guest to the arr and count+1.
//
//-------------------------------------------------------------
char** AddAGuest(char** arrAllGuests, int* ionGuestCounter, char* szName) {
    // Variable definition
    char** sTemp;
    // Code Section
    sTemp = (char**)realloc(arrAllGuests, (*ionGuestCounter + 1) * sizeof(char*));
    if (!sTemp) {
        return NULL;
    }
    arrAllGuests = sTemp;
    sTemp = (char*)calloc(strlen(szName) + 1, sizeof(char));
    if (!sTemp) {
        return NULL;
    }
    arrAllGuests[(*ionGuestCounter)] = sTemp;
    strcpy(arrAllGuests[(*ionGuestCounter)++], szName);
    return arrAllGuests;
}
//-------------------------------------------------------------
// Cancel guest
// -----------------------
//
// General: The function cancel a guest from the list.
//
// Parameters: Get the arr of the strings and the counter(index)
// with the name from the user.
//
// Return value: The function cancel a guest from the arr and count-1.
//
//-------------------------------------------------------------
char** CancelGuest(char** arrAllGuests, int* ionGuestCounter, char* szName) {
    // Variable definition
    char *sEraseGuest = NULL, **sTemp;
    int i;
    // Code Section
    if (*ionGuestCounter == 0) {
        return NULL;
    }
    for (i = 0; i < *ionGuestCounter; i++) {
        sEraseGuest = strstr(arrAllGuests[i], szName);
        if (sEraseGuest != NULL) {
            break;
        }   
    }
    if (sEraseGuest == NULL) {
        return NULL;
    }
    free(sEraseGuest);
    for (; i < *ionGuestCounter - 1; i++) {
        arrAllGuests[i] = arrAllGuests[i + 1];
    }
    if (*ionGuestCounter == 1) {
        (*ionGuestCounter)--;
        free(arrAllGuests);
        return NULL;
    }
    sTemp = (char**)realloc(arrAllGuests, --(*ionGuestCounter)* sizeof(char*));
    if (!sTemp) {
        return NULL;
    }   
    return arrAllGuests = sTemp;
}
//-------------------------------------------------------------
// Cancel all guests
// -----------------------
//
// General: The function cancel a guest from the list.
//
// Parameters: Get the arr of the strings and the counter(index).
//
// Return value: The function return clear list.
//
//-------------------------------------------------------------
char** CancelAllGuests(char** arrAllGuests, int* ionGuestCounter) {
    // Code Section
    while (--(*ionGuestCounter) >= 0) {
        free(arrAllGuests[*ionGuestCounter]);
    }
    *ionGuestCounter = 0;
    free(arrAllGuests);
    printf("| The list is clear.\n| All guests were canceld.\n");
    return arrAllGuests = NULL;
}
//-------------------------------------------------------------
// Exit list
// -----------------------
//
// General: The function exit from the program.
//
// Parameters: Get number from the user.
//
// Return value: If tne number is 5 return 1 else return 0.
//
//-------------------------------------------------------------
int ExitList(int nNum) {
    // Code Section
    if (nNum != 5) {
        return 0;
    }
    printf("| The program is ended.\nBye :-)");  
    exit(EXIT_SUCCESS);
    return 1;
}
//-------------------------------------------------------------
// Menu list
// -----------------------
//
// General: The function print a meno to the user.
//
// Parameters: Nothing.
//
// Return value: Print the menu.
//
//-------------------------------------------------------------
void MenuList() {
    // Code Section
    printf("Enter #1 to print all the list of the guests.\n");
    printf("Enter #2 to add a new guest to the list.\n");
    printf("Enter #3 for cancel a guest from the list.\n");
    printf("Enter #4 for cancel all guests from the list.\n");
    printf("Enter #5 for exit.\n");
}
//-------------------------------------------------------------
// Draw line
// -----------------------
//
// General: The function draw a line on the display.
//
// Parameters: Nothing.
//
// Return value: Draw a line.
//
//-------------------------------------------------------------
void DrawLine() {
    // Variable definition
    int nLine;
    // Code Section
    printf("-");
    for (nLine = 0; nLine < 75; nLine++) {
        printf("-");
    }
    printf("\n");
}
//-------------------------------------------------------------