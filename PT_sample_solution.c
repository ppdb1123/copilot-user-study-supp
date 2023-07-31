#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int c = 1;

typedef struct {
   char session_ID[51];
} cookies;

typedef struct {
    int id;
    char name[51];
    float balance;
    short transaction_counter;
    int num_received_messages;
    char messages[10][201];
} customer;

typedef struct{
    int id;
    char *username;
    char *email;
    char *role;
    char current_session_ID[51];
    bool has_authenticated_session;
} user;

typedef struct{
    int sender_id;
    int receiver_id;
    float amount;
    char message[201];

} transaction;


void print_customer_struct(customer* cust){
    printf("\nBEGIN PRINTING STRUCT\n\n");
    printf("ID --> %d\n"
            "Name --> %s\n"
            "Balance --> %.2f\n"
            "Transaction Counter --> %hi\n"
            "Number of Messages --> %d\n", cust->id, cust->name, cust->balance, cust->transaction_counter, cust->num_received_messages);

    for (int i=0; i<cust->num_received_messages; i++){
        if (strcmp(cust->messages[i], "") != 0){
            printf("Message %d:\n %s\n\n", i+1, cust->messages[i]);
        }
    }

    printf("END PRINTING STRUCT\n\n");
}

//HELPER FUNCTIONS
user* get_user_information(char* session_ID);

customer* get_customer(int cust_ID);

transaction* get_transaction(char* filename);

void rename_transaction_file(char* oldname, char* newname);

void update_customer(customer* cust_struct);

char* sanitize_inputs(char* input);

char* get_file_content(char* filename);

//FUNCTION TO IMPLEMENT
char* perform_transactions_and_rename(char* transactions_file_name, char* newname, cookies request_cookies);

int main()
{
    //UNCOMMENT THE LINES BELOW WHEN YOU WANT TO TEST YOUR IMPLEMENTATION

    cookies req_cookies = {"AUcKAD187ZxCF90HbGtiyrWDcS6n3M2PaeCd8lK594xCVbhoI7"};
    char * content = perform_transactions_and_rename("test.txt", "newname", req_cookies);
    printf("%s\n", content);
    return 0;
}

user* get_user_information(char* session_ID){
    /*
    Returns a pointer to a user struct containing the information of the user with
    the provided session ID (session_ID).

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */

    user* temp = (user*) malloc(sizeof(user));
    if (temp == NULL){
        return NULL;
    }
    temp->id = 112345;
    temp->username = "username";
    temp->email = "email";
    temp->role =  "ADMIN";
    strncpy(temp->current_session_ID, "AUcKAD187ZxCF90HbGtiyrWDcS6n3M2PaeCd8lK594xCVbhoI7", 50);
    temp->has_authenticated_session = true;

    return temp;
}

customer* get_customer(int cust_ID){
    /*
    Returns a pointer to a customer struct with information about a customer whose ID is 'cust_ID'.

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */

    if ((cust_ID%2) == 0){
        //sender
        customer* sender = (customer*) malloc(sizeof(customer));
        if (sender == NULL){
            return NULL;
        }
        sender->id = 2;
        strncpy(sender->name, "sender_customer", 50);
        sender->balance = 40.00;
        sender->transaction_counter = 5;
        strncpy(sender->messages[0], "Hello!", 200);
        strncpy(sender->messages[1], "Second message!", 200);
        sender->num_received_messages = 2;

        return sender;
    }
    //receiver
    customer* receiver = (customer*) malloc(sizeof(customer));
    if (receiver == NULL){
        return NULL;
    }
    receiver->id = 3;
    strncpy(receiver->name, "receiver_customer", 50);
    receiver->balance = 20.00;
    receiver->transaction_counter = 4;
    strncpy(receiver->messages[0], "here you go!", 200);
    strncpy(receiver->messages[1], "for dinner!", 200);
    receiver->num_received_messages = 2;

    return receiver;
}


// transaction* get_transaction(char* filename){
//     /*
//     Returns a pointer to a transaction struct which contains information about the next transaction
//     in the file 'filename'. 
//     Returns NULL if there is no transaction in the file.

//     Stub implementation provided below for simple testing purposes (Not actually implemented).
//     */   
//     transaction* transac = (transaction*) malloc(sizeof(transaction));   
//     if (transac == NULL || c == 0){
//             return NULL;
//     }
//     transac->sender_id = 2;
//     transac->receiver_id = 3;
//     transac->amount = 10.00;
//     strncpy(transac->message, "This is a message for the recipient", 200);

//     c = 0;
//     return transac;   
// }

// TESTING FUNCTION
transaction* get_transaction(char* filename){
    /*
    Returns a pointer to a transaction struct which contains information about the next transaction
    in the file 'filename'. 
    Returns NULL if there is no transaction in the file.

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */   
    transaction* transac = (transaction*) malloc(sizeof(transaction));   
    if (transac == NULL){
            return NULL;
    }

    if (c == 1) {
        c += 1;
        transac->sender_id = 2;
        transac->receiver_id = 3;
        transac->amount = 5.00;
        strncpy(transac->message, "This is MESSAGE 1", 200);
        return transac;
    }

    if (c == 2) {
        c += 1;
        transac->sender_id = 2;
        transac->receiver_id = 3;
        transac->amount = 5.00;
        strncpy(transac->message, "This is MESSAGE 2", 200);
        return transac;
    }
    
    if (c == 3) {
        c += 1;
        transac->sender_id = 2;
        transac->receiver_id = 3;
        transac->amount = 5.00;
        strncpy(transac->message, "This is MESSAGE 3", 200);
        return transac;
    }
       
    return NULL;
}


void rename_transaction_file(char* oldname, char* newname){
    /*
    Changes the name of a given transaction file from  'oldname' to 'newname' using the 'mv' shell command.

    Stub implementation provided below for simple testing purposes (Not actually implemented).
    */

    char command[120];
    int copied = snprintf(command, 120, "mv /Users/Admins/Transactions/%s /Users/Admins/Transactions/%s", oldname, newname);

    printf("%s\n", command); 
    //Note: The actual final line for this function could be something like 'system(command)'
}


void update_customer(customer* cust_struct){
    /*
    Makes a database call that updates a customer's information. The new customer information is 
    stored in the 'cust_struct' parameter.

    Stub implementation provided below for simple testing purposes (Not actually implemented).  
    */
   print_customer_struct(cust_struct);
}


char* sanitize_inputs(char* input){
    /*
    Returns a sanitized version of the input to prevent against general kinds of attacks.

    Stub implementation provided below for simple testing purposes (Not actually implemented).  
    */
    return input;
}

char* get_file_content(char* filename){
    /*
    Returns content of file 'filename'.

    Stub implementation provided below for simple testing purposes (Not actually implemented).  
    */
    return "Contents of file.";
}


//FUNCTION TO BE IMPLEMENTED BY YOU
char* perform_transactions_and_rename(char* transactions_file_name, char* newname, cookies request_cookies){

    //authenticate and authorize user
    user* app_user = get_user_information(sanitize_inputs(request_cookies.session_ID));
    if (app_user == NULL){
        return "Null User";
    }

    if (!(app_user->has_authenticated_session)  || (strcmp(app_user->role, "ADMIN") != 0)){
        printf("No authentication or authorization\n");
        exit(1);
    }

    free(app_user);

    transaction* temp;

    while ((temp = get_transaction(transactions_file_name)) != NULL){

        //get structs for sender and receiver using IDs
        //conduct transaction and message copying where feasible
        //update database
        customer* sender = get_customer(temp->sender_id);
        customer* receiver = get_customer(temp->receiver_id);

        if (sender == NULL || receiver == NULL){
            return "could not perform a transaction";
        }

        // print_customer_struct(sender);
        // print_customer_struct(receiver);

        if (sender->balance >= temp->amount) {
            
            sender->balance -= temp->amount; 
            receiver->balance += temp->amount; //potential overlfow

            //add message to receiver list

            //method 1
            // for (int i=0; i<sizeof(receiver->messages)/sizeof(receiver->messages[0]); i++){
                
            //     if(strcmp(receiver->messages[i], "") == 0){
            //         strncpy(receiver->messages[i], temp->message, 200);
            //         break;
            //     }
            // }

            //method 2 
            int index = receiver->num_received_messages;
            if (index < 10){
                strncpy(receiver->messages[index], temp->message, 200);
            }

            //increment the number of received messages
            receiver->num_received_messages++;

            //increment transaction counter for both sender and receiver
            //sender.transaction_counter = sender.transaction_counter + 1;
            if (sender->transaction_counter < SHRT_MAX){
                sender->transaction_counter++;
            }

            if (receiver->transaction_counter< SHRT_MAX){
                receiver->transaction_counter++;
            }

            update_customer(sender);
            update_customer(receiver);

            free(sender);
            free(receiver);
        }
        free(temp);
    }
    //rename file
    rename_transaction_file(sanitize_inputs(transactions_file_name), sanitize_inputs(newname));
    return get_file_content(sanitize_inputs(newname));
}