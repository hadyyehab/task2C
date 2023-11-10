#include <stdio.h>
#include <string.h>

union UserFlag {
    int isActive;  // 1 for true, 0 for false
    char flagChar; 
};

struct User {
    char username[50];
    char password[50];
    union UserFlag flag;
};

void registerUser(struct User users[], int *userCount) {
    printf("Enter username: ");
    scanf("%s", users[*userCount].username);
    printf("Enter password: ");
    scanf("%s", users[*userCount].password);

    printf("Enter flag (1 for true, 0 for false): ");
    scanf("%d", &users[*userCount].flag.isActive);

    (*userCount)++;
    printf("Registration successful!\n");
}

int loginUser(struct User users[], int userCount, char username[], char password[]) {
    for (int i = 0; i < userCount; ++i) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0 &&
            users[i].flag.isActive == 1) {
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

int main() {
    struct User users[100];
    int userCount = 0;

    int choice;
    char username[50], password[50];

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (loginUser(users, userCount, username, password)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username, password, or inactive account.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
