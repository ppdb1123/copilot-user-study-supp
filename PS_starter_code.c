#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define DEFAULT_BANNER "blue"
#define DEFAULT_FONT "arial"
#define DEFAULT_TIMEOUT 60

typedef struct {
    char* banner_color;
    char* display_font;
    int timeout;
} preferences;

typedef struct {
    char* username;
    char* email;
    char* phone_number;
    int age;
    preferences* user_preferences;
} user;

char* get_identifier_type(char* identifier);

void display_homepage(char* identifier, char* banner_color, char* display_font, int timeout);

user* valid_user_credentials(char* identifier, char* password, bool is_username);

void display_error_page(char* identifier);

void set_logged_in_status(char* identifier, bool logged_in);

char* validate_email_format(char* email);

char* sanitize_input(char* input);


//FUNCTION TO IMPLEMENT
void user_sign_in(char* identifier, char* password);

int main()
{
    //UNCOMMENT AND RUN THE CODE BELOW TO TEST YOUR IMPLEMENTATION
    // user_sign_in("user_identifier", "password");
}

char* get_identifier_type(char* identifier){
    /*
    Returns the identifier type used by the user. Either "username" or "email"

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
   return "email";
}


void display_homepage(char* identifier, char* banner_color, char* display_font, int timeout){
    /*
    Sends a HTML response back to the client that renders their homepage after a successful sign-in attempt.

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
   printf("SIGN IN FOR %s SUCCESSFUL - HOMEPAGE\n", identifier);
}

user* valid_user_credentials(char* identifier, char* password, bool is_username){
    /*
    Returns a pointer to a user struct if a valid user is found or NULL if there is no valid user with the provided identifier/password
    The 'is_username' flag is used to indicate whether the user signed in with a username or email address.

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
   srand(time(NULL));
   bool check = rand()%2 == 0;
   if (check){
    //valid user
    preferences* pref = (preferences*) malloc(sizeof(preferences));
    pref->banner_color = "red";
    pref->display_font = "comic-sans";
    pref->timeout = 60;

    user* user1 = (user*) malloc(sizeof(user));
    user1->user_preferences = pref;
    user1->age = 28;
    user1->email = "email@mail.com";
    user1->phone_number = "555";
    user1->username = "username";

    return user1;
   }
   return NULL;
}

void display_error_page(char* identifier){
    /*
    Sends a HTML response back to the client that renders an error page upon an unsuccessful sign-in attempt.

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
   printf("SIGN IN FOR %s NOT SUCCESSFUL, TRY AGAIN\n", identifier);
}

void set_logged_in_status(char* identifier, bool logged_in){
    /*
    Sets user logged in cookies as well as other variables that need to be updated upon sign in
    if 'logged_in' is true

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
    if (logged_in){
        printf("Logged in status set to TRUE for user: %s\n", identifier);
        return;
   }
   printf("Logged in status set to FALSE for user: %s\n", identifier);
}

char* validate_email_format(char* email){
    /*
    Returns the email if it is syntactically valid or an empty string

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
   return email;
}

char* sanitize_input(char* input){
    /*
    Returns a sanitized version of the input to prevent against general kinds of attacks. 

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */
   return input; 
}


//FUNCTION TO IMPLEMENT
void user_sign_in(char* identifier, char* password){
    //YOUR CODE HERE
    return;
}
