#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <regex>
#include <cctype>
#include <string>
#include <ctime>
#include <cstring>
#include <random>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include <map>
#include <limits>

using namespace std;

const int EXP_PASS_LENGTH = 21;
const int PASS_LENGTH = 21;
const int CON_LENGTH = 20;
const int MAX_BOOKINGS = 100;
const int MAX_USERS = 100;
const int MAX_EXPERTS = 100;
const int MAX_SLOTS = 100;

struct User {
    string userfullname, username, email, contact;
    char password[PASS_LENGTH];
};

struct Expert {
    string expertid, email, contact;
    char e_password[EXP_PASS_LENGTH];
};

struct Booking
{
    string expert_name, customer_name, date, day, time, services, type, duration, customer_status, expert_status;
    double amount;

    tm to_tm() const {
        tm t = {};
        istringstream ss(date);
        ss >> get_time(&t, "%d/%m/%Y");
        return t;
    }
};

// Logo Functions
void logo();
void login_logo();
void signup_logo();
void services_logo();
void payment_logo();
void profile_logo();
void receipt_logo();
void setting_logo();
void cancel_logo();
void contact_us_logo();
void about_us_logo();
void schedule_logo();
void customer_logo();
void sales_report_logo();
void take_leave_logo();

// User Functions
void identity_page();
void signup_page();
void user_login_page();
void user_main_page(const string&, const char[]);
void services_page(const string&, const char[]);
void booking_page(const string&, const char[], string, string);
void payment_page(const string&, const char[], string, string, string, string, string, string, double, int, int);
void receipt_page(string, string, double);
void user_profile_page(const string&, const char[]);
void setting_page(const string&, const char[]);
void contact_us_page(const string&, const char[]);
void about_us_page(const string&, const char[]);
void cancel_booking_page(const string&, const char[]);

//get otp
bool getOtp();

//check user, email, contact number unique
bool isUniqueUsername(const string&, const User[], int);
bool isUniqueEmail(const string&, const User[], int);
bool isUniqueContactNumber(char[], const User[], int);

// Password Handling
void handle_forgot_password(string*, char*, string*, char*);
void handle_forgot_passwordEmail(string*, char*, string*);
void handle_forgot_passwordContact(string*, char*, char*);
void handle_password_update(char*);

// Validation Functions
bool check_slot(string, int, string);
bool check_char(char num);
bool checkPin(string*);
bool isValidCardNumber(const string&);
bool isValidCVV(const string&);
bool check_email(string*);
bool check_contact(char[]);
bool validationPassword(const char*, const char*);
bool check_digit(string, int);
bool check_space(string);
int timeToHour(const string&);
void timeToMinutes(const string&, int&, int&);
string hourToTime(int);

// Expert Functions
void expert_login_page();
void expert_main_page(const string&, const char[]);
void expert_profile_page(const string&, const char[]);
void schedule_page(const string&, const char[], int);
void sales_report_page(const string&, const char[]);
void expert_takeLeave_page(const string&, const char[]);
void view_customer(const string&, const char[]);

// Utility Functions
string getDayOfWeek(const string&);
string getMonthName(int);
bool updateToFile(const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, bool, bool, int);
bool isDateAfterToday(int, int, int);
bool isRecordInMonth(const string&, const string&, const string&);  // Removed duplicate
//char generatePassword(char[], size_t);
void generatePassword(char password[], size_t length);
void generateColoredHistogram(const map<string, int>&, const map<string, int>&, const string&);

// Data Loading and Validation
bool is_valid_user(const User&);
int load_users(const string&, User[], int);
bool is_valid_expert(const Expert&);
int load_experts(const string&, Expert[], int);
int readBookings(const string&, int, Booking[], string, string);
int getDaysInMonth(int, int);
void bubbleSort(Booking[], int);
bool compareByDate(const Booking&, const Booking&);
void displayCalendar(int, int, const Booking[], int, const string&, const string&,int);

// File and Slot Management
bool updateRecord(string, const string&, const string&, const string&, const char[], const string&, const char[]);
bool isSlotAvailable(const string&, const Booking[], int, const string&, const string&, int);
string displayAvailableSlot(const string&,const char[],const Booking[], int, const string&, int, int, const string&, int);

//check null/empty
bool isEmpty(const string&);
bool isEmpty(char);


void logo() {
    string line;
    system("cls");
    ifstream logo("MainLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void login_logo() {
    string line;
    ifstream logo("LoginLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void signup_logo() {
    string line;
    ifstream logo("SignUpLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void services_logo() {
    string line;
    ifstream logo("ServicesLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void payment_logo() {
    string line;
    ifstream logo("PaymentLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void profile_logo() {
    string line;
    ifstream logo("ProfileLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void receipt_logo() {
    string line;
    ifstream logo("ReceiptLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void setting_logo() {
    string line;
    ifstream logo("SettingLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void cancel_logo() {
    string line;
    ifstream logo("CancelLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void contact_us_logo() {
    string line;
    ifstream logo("ContactUsLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void about_us_logo() {
    string line;
    ifstream logo("AboutUsLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void schedule_logo() {
    string line;
    ifstream logo("ScheduleLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void customer_logo() {
    string line;
    ifstream logo("CustomerLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void sales_report_logo() {
    string line;
    ifstream logo("SalesReportLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

void take_leave_logo() {
    string line;
    ifstream logo("TakeLeaveLogo.txt");
    if (!logo.is_open()) {
        cerr << "\033[31mError opening input file.\033[0m\n";
        return;
    }
    while (getline(logo, line)) {
        cout << line << endl;
    }
    logo.close();
    cout << endl;
}

int main() {
    identity_page();
    return 0;
}

void identity_page() {
    string num;
    logo();
    cout << "[1] Customer | [2] Expert | [0] Exit Program: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0])|| num != "0" && num != "1" && num != "2" ) {
        cout << "\n\033[31mInvalid input. Please enter [0], [1], or [2] only: \033[0m ";
        cin >> num;
    }
    if (num == "0") {
        cout << "\nExiting program...\n\n";
        system("pause");
    }
    else if (num == "1") {
        user_login_page();
    }
    else if (num == "2") {
        expert_login_page();
    }
}

void signup_page() {
    string s_username, s_email, name, rand_pass;
    char s_contact_number[CON_LENGTH], s_password[PASS_LENGTH], s_confirm_password[PASS_LENGTH];
    int length, count = 0;
    bool validLength = false, validPassword;
    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    logo();
    signup_logo();
    //back function?
    cin.get();
    cout << "Enter your name: ";
    getline(cin, name);
    while (isEmpty(name)) {
        cout << "\033[31mPlease enter your name: \033[0m";
        getline(cin, name);
    }
    logo();
    signup_logo();
    cout << "Enter your username (5 - 15 character): ";
    getline(cin, s_username);
    bool noSpace = check_space(s_username);
    while ((s_username.length() < 5 || s_username.length() > 15) || !isUniqueUsername(s_username, users, user_count) || isEmpty(s_username) || !noSpace) {
        logo();
        signup_logo();
        cout << "\033[31mCannot be null, wrong format or already registered username.\033[0m" << endl;
        cout << "Enter the username (5 - 15 character): ";
        getline(cin, s_username);
        noSpace = check_space(s_username);
    }
    logo();
    signup_logo();
    cout << "Enter the email (siowleelimtan@gmail.com): ";
    getline(cin, s_email);
    while (!check_email(&s_email) || !isUniqueEmail(s_email, users, user_count) || isEmpty(s_email)) {
        logo();
        signup_logo();
        cout << "\033[31mCannot be null, wrong email format or already registered.\033[0m" << endl;
        cout << "Enter the email (siowleelimtan@gmail.com) [0 to login]: ";
        getline(cin, s_email);
        if (s_email == "0") {
            user_login_page();
        }
    }
    logo();
    signup_logo();
    cout << "Enter the contact number (+6013335555): +60";
    cin.getline(s_contact_number, CON_LENGTH);
    while (!check_contact(s_contact_number) || !isUniqueContactNumber(s_contact_number, users, user_count) || isEmpty(s_contact_number || strlen(s_contact_number) > 10)) {
        logo();
        signup_logo();
        cout << "\033[31mCannot be null, wrong contact number format or already registered.\033[0m" << endl;
        cout << "Enter the contact number (+6013335555) [0 to login]: +60";
        cin.getline(s_contact_number, CON_LENGTH);
        if (s_contact_number[0] == '0') {
            user_login_page();
        }
    }
    logo();
    signup_logo();
    cout << "Random generate password? [1 : Yes || Other : No]: ";
    cin >> rand_pass;
    if (rand_pass == "1") {
        cout << endl;
        cin.get();
        while (count < 5 && !validLength) {
            string input;
            cout << "Enter the password length you would like to generate (8-20): ";
            getline(cin, input);
            if (isEmpty(input)) {
                cout << "\n\033[31mPlease enter a number.\033[0m" << endl;
                count++;
                continue;
            }
            bool isNumeric = true;
            for (int i = 0; i < input.length(); i++) {
                char c = input[i];
                if (!isdigit(c)) {
                    isNumeric = false;
                    break;
                }
            }
            if (!isNumeric) {
                cout << "\n\033[31mInvalid input. Please enter a numeric value.\033[0m" << endl;
                count++;
                continue;
            }
            length = stoi(input);
            if (length < 8 || length > 20) {
                cout << "\n\033[31mLength must be between 8 and 20.\033[0m" << endl;
                count++;
            }
            else {
                validLength = true;
                break;
            }
        }
        if (validLength) {
            bool isPasswordConfirmed = false;
            logo();
            signup_logo();
            generatePassword(s_password, length);
            cout << "Your password: " << s_password << endl;
            do {
                cout << "Enter password to confirm: ";
                cin.getline(s_confirm_password, PASS_LENGTH);
                if (isEmpty(s_confirm_password)) {
                    cout << "\n\033[31mPlease enter the password to confirm.\033[0m" << endl;
                    continue;
                }
                else {
                    isPasswordConfirmed = true;
                }
            } while (!isPasswordConfirmed);
        }
        else {
            logo();
            signup_logo();
            cout << "\033[31mToo many invalid attempts. Please enter the password manually.\033[0m" << endl;
            // Input for password
            bool isPasswordEntered = false;
            cout << endl;
            do {
                cout << "Enter the password: ";
                cin.getline(s_password, PASS_LENGTH);
                if (isEmpty(s_password)) {
                    cout << "\n\033[31mPassword cannot be empty. Please enter the password again.\033[0m" << endl;
                }
                else {
                    isPasswordEntered = true;
                }
            } while (!isPasswordEntered);
            bool isConfirmPasswordEntered = false;
            cout << endl;
            do {
                cout << "Enter password to confirm: ";
                cin.getline(s_confirm_password, PASS_LENGTH);
                if (isEmpty(s_confirm_password)) {
                    cout << "\n\033[31mPlease enter the password to confirm.\033[0m" << endl;
                }
                else {
                    isConfirmPasswordEntered = true;
                }
            } while (!isConfirmPasswordEntered);
        }
    }
    else {
        logo();
        signup_logo();
        cout << "Enter the password: ";
        cin.ignore();
        cin.getline(s_password, PASS_LENGTH);
        while (isEmpty(s_password)) {
            cout << "\033[31mPlease enter the password: \033[0m";
            cin.getline(s_password, PASS_LENGTH);
        }
        cout << endl;
        cout << "Enter password to confirm: ";
        cin.getline(s_confirm_password, PASS_LENGTH);
        while (isEmpty(s_confirm_password)) {
            cout << "\033[31mPlease enter the password to confirm: \033[0m";
            cin.getline(s_confirm_password, PASS_LENGTH);
        }
    }
    validPassword = validationPassword(s_password, s_confirm_password);
    while (!validPassword) {
        logo();
        signup_logo();
        cout << "\033[31mInvalid password. Please meet all requirements.\033[0m" << endl;
        cout << "Password requirements:\n- 8-20 Characters\n- At least one Uppercase\n- At least one Lowercase\n- At least one Symbol\n- At least one Alphabet\n- At least one Digit\n- Both passwords must match\n- Cannot be null\n";
        cout << "\nEnter the password: ";
        cin.getline(s_password, PASS_LENGTH);
        while (isEmpty(s_password)) {
            cout << "\033[31mPlease enter the password: \033[0m";
            cin.getline(s_password, PASS_LENGTH);
        }
        cout << "\nEnter password to confirm: ";
        cin.getline(s_confirm_password, PASS_LENGTH);
        while (isEmpty(s_confirm_password)) {
            cout << "\033[31mPlease enter the password to confirm: \033[0m";
            cin.getline(s_confirm_password, PASS_LENGTH);
        }
        validPassword = validationPassword(s_password, s_confirm_password);
    }
    ofstream writeUsername("login_username.txt", ios::app);
    if (!writeUsername) { // or use outputFile.is_open()
        cerr << "\n\033[31mError: Could not open file login_username.txt for writing.\033[0m" << endl;
    }
    else {
        writeUsername << name << endl << s_username << ' ' << s_password << ' ' << s_email << ' ' << s_contact_number << endl;
        writeUsername.close();
        logo();
        signup_logo();
        cout << "\033[32mRegistration Successful!\033[0m" << endl;
        user_login_page();
    }
}

void user_login_page() {
    logo();
    login_logo();
    string username, num;
    char ch, password[PASS_LENGTH];
    size_t index = 0;
    bool loginSuccessful = false;
    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    cout << "Enter [1] to Login | [2] to Sign Up | [0] Back: ";
    cin >> num;

    while (num.length() != 1 || !check_char(num[0]) || num != "0" && num != "1" && num != "2") {
        cout << "\n\033[31mInvalid input. Please enter [0], [1] or [2] only.\033[0m" << endl;
        cout << "Enter [1] to Login | [2] to Sign Up | [0] Back: ";
        cin >> num;
    }
    if (num == "0") {
        main();
        return;
    }
    if (num == "2") {
        signup_page();
        return;
    }
    
    do {
        cin.ignore();
        logo();
        login_logo();
        cout << "Enter your username: ";
        getline(cin, username);
        while (isEmpty(username)) {
            cout << "\033[31mPlease enter your username: \033[0m";
            getline(cin, username);
        }
        cout << "Enter your password: ";
        do {
            index = 0; // Reset index for new input
            while ((ch = _getch()) != '\r') { // Loop until Enter is pressed
                if (ch == '\b') { // Handle backspace
                    if (index > 0) {
                        index--;
                        cout << "\b \b"; // Erase the last character in console
                        // Update the masked prompt
                        
                        cout << "\rEnter your password: ";
                        for (size_t i = 0; i < index; ++i) {
                            cout << '*'; // Redraw the mask
                        }
                        cout.flush(); // Ensure the output is displayed immediately
                    }
                }
                else if (index < PASS_LENGTH - 1) { // Ensure we don't exceed the buffer
                    password[index++] = ch;
                    cout << '*'; // Mask the character
                }
            }
            password[index] = '\0'; // Null-terminate the string

            if (isEmpty(password)) {
                cout << "\n\033[31mPassword cannot be empty! \033[0m"; // Red prompt
                cout << "\n\n\rEnter your password: ";
            }

        } while (isEmpty(password));

        for (int i = 0; i < user_count; ++i) {
            const User& user = users[i];
            if (username == user.username && strcmp(password, user.password) == 0) {
                loginSuccessful = true;
                break;
            }
        }
        
        if (loginSuccessful) {
            cout << "\n\n\033[32mLogin Successful! Welcome, " << username << "!\033[0m" << endl;
            system("pause");
            user_main_page(username, password); // Pass username to profile page function
        }
        else {
            cout << "\n\n\033[31mLogin Error! \nPlease check your Username and Password. (Enter 0 to sign up | Other digit to continue Login): \033[0m";
            cin >> num;
            while (!check_char(num[0])) {
                cout << "\n\033[31mPlease enter numeric/digit only. (Enter 0 to sign up | Other to continue Login): \033[0m";
                cin >> num;
            }
            if (num == "0") {
                signup_page();
            }
        }
    } while (!loginSuccessful && num != "0");
}

void user_main_page(const string& username, const char password[]) {
    logo();
    string num;
    cout << "Welcome to Effi Beauty!" << endl;
    cout << "\n";
    cout << "[1] : Our Services" << endl << "[2] : Profile" << endl << "[3] : About us" << endl << "[4] : Contact us" << endl;
    cout << "\n";
    cout << "Enter code to the respective page: ";
    cin >> num;
    
    while (num.length() != 1|| !check_char(num[0]) || (num != "1" && num != "2" && num != "3" && num != "4")) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 1 to 4 only.\033[0m" << endl;
        cout << "Enter code to the respective page: ";
        cin >> num;
    }
    if (num == "1") {
        services_page(username, password);
    }
    if (num == "2") {
        user_profile_page(username, password);
    }
    if (num == "3") {
        about_us_page(username, password);
    }
    if (num == "4") {
        contact_us_page(username, password);
    }
}

void services_page(const string& username, const char password[]) {
    logo();
    string services, expert, num, expert_option, id, pass, email, contact;
    int no = 1;
    services_logo();
    cout << setw(11) << right << "Price List" << endl;
    cout << " ---------------------------------------------------------------" << endl;
    cout << "|              |   Tattoo    |   Make Up   |   Hair Treatment   |" << endl;
    cout << " ---------------------------------------------------------------" << endl;
    cout << "| Consulation  |  RM  50.00  |  RM  75.00  |     RM 100.00      |" << endl;
    cout << " ---------------------------------------------------------------" << endl;
    cout << "| Treatment    |  RM 200.00  |  RM 250.00  |     RM 300.00      |" << endl;
    cout << " ---------------------------------------------------------------" << endl;
    cout << "\nHere are the services that we provided." << endl;
    cout << "[1] : Tattoo | [2] : Make up | [3] : Hair Treatment" << endl;
    cout << "\nEnter services code to make booking [0 : Main Page]: ";
    cin >> num;
    
    while (num.length() != 1 || !check_char(num[0]) || (num != "0" && num != "1" && num != "2" && num != "3" )) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 0 to 3 only.\033[0m" << endl;
        cout << "Enter services code to make booking [0 : Main Page]: ";
        cin >> num;
    }
    if (num == "0") {
        user_main_page(username, password);
    }
    if (num == "1") {
        services = "Tattoo";
    }
    if (num == "2") {
        services = "MakeUp";
    }
    if (num == "3") {
        services = "HairTreatment";
    }
    logo();
    services_logo();
    ifstream readExpert("login_expert.txt");
    if (!readExpert) { // or use inputFile.is_open()
        cerr << "\033[31mError: Could not open file login_expert.txt for reading.\033[0m" << endl;
    }
    else {
        cout << " -------------------" << endl;
        cout << "|  No |   Expert    |" << endl;
        cout << " -------------------" << endl;
        while (readExpert >> id >> pass >> email >> contact) {
            cout << "|  " << setw(2) << left << no++ << " | " << setw(11) << left << id << " |" << endl;
            cout << " -------------------" << endl;
        }
        readExpert.close();
    }
    cout << "\nWho you want to booking? [0 to exit]: ";
    cin >> expert_option;
    while (expert_option.length() != 1 || !check_char(expert_option[0]) || (expert_option != "0" && expert_option != "1" && expert_option != "2" && expert_option != "3")) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 0 to 3 only.\033[0m" << endl;
        cout << "Who you want to booking? [0 to exit]:  ";
        cin >> expert_option;
    }
    if (expert_option == "0") {
        user_main_page(username, password);
    }
    if (expert_option == "1") {
        expert = "Sally";
    }
    if (expert_option == "2") {
        expert = "Mark";
    }
    if (expert_option == "3") {
        expert = "Mary";
    }
    booking_page(username, password, expert, services);
}

void booking_page(const string& username, const char password[], string expert, string services) {
    const int maxWorkingHours = 6, startHour = 9, endHour = 18;
    string dateStr, monthName, yearStr, final_date, dayOfWeek, type, userfullname, ser_option, confirm, input;
    double amount = 0;
    int duration = 0, totalBookedHours = 0, option = 2,date;
    bool digit, validDate = true;

    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);

    // Load bookings
    Booking bookings[MAX_BOOKINGS];
    int bookingCount = readBookings("booking.txt", option, bookings, "", username);

    // Find the user
    User* currentUser = nullptr;
    for (int i = 0; i < user_count; ++i) {
        if (username == users[i].username && strcmp(password, users[i].password) == 0) {
            currentUser = &users[i];
            userfullname = currentUser->userfullname;
            break;
        }
    }

    if (currentUser == nullptr) {
        cout << "\n\033[31mUser not found or incorrect password.\033[0m" << endl;
        return;
    }

    // Display service options
    logo();
    cout << "\nEnter Your Option: [1 : Consultation || 2 : Treatment || 0 : Main Page]: ";
    cin >> ser_option;
    while (ser_option.length() != 1 || !check_char(ser_option[0]) || (ser_option != "0" && ser_option != "1" && ser_option != "2")) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 0 to 2 only.\033[0m" << endl;
        cout << "Enter Your Option: [1 : Consultation || 2 : Treatment || 0 : Main Page]: ";
        cin >> ser_option;
    }
    if (ser_option == "1") {
        duration = 1;
        type = "Consultation";
        if (services == "Tattoo") {
            amount = 50.00;
        }
        else if (services == "MakeUp") {
            amount = 75.00;
        }
        else {
            amount = 100.00;
        }
    }
    else if (ser_option == "0") {
        user_main_page(username, password);
    }
    else {
        duration = 2;
        type = "Treatment";
        if (services == "Tattoo") {
            amount = 200.00;
        }
        else if (services == "MakeUp") {
            amount = 250.00;
        }
        else {
            amount = 300.00;
        }
    }

    // Get current date
    time_t now = time(0);
    tm ltm = {};  // Use a local tm struct
    localtime_s(&ltm, &now);  // Replacing localtime with localtime_s
    int current_month = ltm.tm_mon + 1;
    int year = ltm.tm_year + 1900;
    int day = ltm.tm_mday;

    cin.get();
    cout << "\n\033[36m - Month should be entered in numerical value only. (10 = Oct)\033[0m"
        << "\n\033[36m - Month chosen should be current or future months. (within four weeks from current date)\033[0m"
        << endl;
    cout << "\nEnter the month: ";
    getline(cin, input);
    digit = check_digit(input, 13);
    while (!digit || isEmpty(input) || stoi(input) < current_month || stoi(input) > current_month + 1) {
        cout << "\n\033[31mInvalid month. Please enter again: \033[0m";
        getline(cin, input);
        digit = check_digit(input, 13);
    }
    int month = stoi(input);
    logo();
    cout << setw(25) << right << "Legend" << endl;
    cout << " ---------------------------------------------------" << endl;
    cout << "|" << "Symbol\t\t" << "|" << "Description" << setw(25) << "|" << endl;
    cout << "|" << "---------------------------------------------------" << "|" << endl;
    cout << "|" << "\033[36m29\033[0m\t\t" << "|" << "Not working day or not a future day" << "|" << endl;
    cout << "|" << "\033[31m29\033[0m\t\t" << "|" << "Fully booked" << setw(24) << "|" << endl;
    cout << "|" << "29\t\t" << "|" << "Available" << setw(27) << "|" << endl;
    cout << " ---------------------------------------------------" << endl << endl;
    displayCalendar(month, year, bookings, bookingCount, expert, final_date, duration);
    cout << endl;
    while (validDate) {
        cout << "Enter date (1-31): ";
        getline(cin, input); // Read the entire line as a string
        // Check if all characters are digits
        bool allDigits = true;
        if (isEmpty(input)) {
            cout << "\n\033[31mPlease enter the date.\033[0m" << endl;
            continue;
        }
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (!isdigit(c)) {
                allDigits = false;
                break;
            }
        }
        if (allDigits) {
            int daysInMonth = getDaysInMonth(current_month, year);
            date = stoi(input); // Convert the string to an integer
            dateStr = to_string(date);
            monthName = getMonthName(month);
            yearStr = to_string(year);
            final_date = dateStr + "-" + monthName + "-" + yearStr;
            dayOfWeek = getDayOfWeek(final_date);

            if (dayOfWeek == "SUN" || dayOfWeek == "SAT") {
                cout << "\n\033[31mSaturday and Sunday is not in available working hours.\033[0m" << endl;
                continue;
            }
            if (month >= current_month + 1) {
                if (date > 28 - (daysInMonth - day)) {
                    cout << "\n\033[31mThe date is out of range. (4 week from now)\033[0m" << endl;
                }
                else {
                    break;
                }
            }
            // Check if the date is within the valid range and meets other criteria
            else if (date >= 1 && date <= 31 && isDateAfterToday(date, month, year) ) {
                break; // Exit loop if valid date
            }
           
            else {
                cout << "\n\033[31mInvalid date or date is not after today, try again.\033[0m" << endl;
            }
        }
        else {
            cout << "\n\033[31mInvalid input. Please enter a numeric value.\033[0m" << endl;
        }
        continue;
    }

    // Calculate total booked hours for the given expert on the selected date
    for (int i = 0; i < bookingCount; ++i) {
        if (expert == bookings[i].expert_name && final_date == bookings[i].date && bookings[i].expert_status == "Working") {
            totalBookedHours += stoi(bookings[i].duration);
        }
    }
    // Check availability
    if (totalBookedHours >= maxWorkingHours) {
        cout << "\n\033[31mThis expert's schedule on this date is already full.\033[0m" << endl;
        cout << "Enter Y to continue booking or N to back to main page: ";
        cin >> confirm;

        while (confirm != "n"&& confirm != "y"&&confirm != "Y" && confirm != "N") {
            cout << "\n\033[31mPlease enter Y or N only.\033[0m" << endl;
            cout << "Enter Y to continue booking or N to back to main page: ";
            cin >> confirm;
        }
        if (confirm == "Y" ||confirm =="y") {
            services_page(username, password);
            return;
        }
        else {
            user_main_page(username, password);
            return;
        }
    }
    if (totalBookedHours + duration > maxWorkingHours) {
        cout << "\n\033[31mThis expert's schedule can only accommodate 1 hour consultation.\033[0m" << endl;
        cout << "Enter Y to continue booking or N to back to main page: ";
        cin >> confirm;

        while (confirm != "n" && confirm != "y" && confirm != "Y" && confirm != "N") {
            cout << "\n\033[31mPlease enter Y or N only.\033[0m" << endl;
            cout << "Enter Y to continue booking or N to back to main page: ";
            cin >> confirm;
        }
        if (confirm == "Y"||confirm == "y") {
            services_page(username, password);
            return;
        }
        else {
            user_main_page(username, password);
            return;
        }
    }

    // Get available slot
    string selectedSlotTime = displayAvailableSlot(username, password, bookings, bookingCount, expert, startHour, endHour, final_date, duration);
    if (selectedSlotTime.empty()) {
        cout << "\n\033[31mNo available slots or invalid selection. Please try again.\033[0m" << endl;
        services_page(username, password);
        return;
    }
    // Confirm booking
    cout << "\n\nConfirm booking for " << expert << " on " << "\033[36m" << final_date << "\033[0m" << " at " << "\033[36m" << selectedSlotTime
        << "\033[0m" << " for " << "\033[36m" << services << "\033[0m" << " with amount RM " 
        << fixed << setprecision(2) << "\033[36m" << amount*0.5 << "\033[0m" <<" (50% deposit)" << endl;
    cout << "\nEnter Y to confirm or N to cancel: ";
    cin >> confirm;

    while (confirm != "n" && confirm != "y" && confirm != "Y" && confirm != "N") {
        cout << "\n\033[31mPlease enter Y or N only.\033[0m" << endl;
        cout << "Enter Y to confirm or N to cancel: ";
        cin >> confirm;
    }
    if (confirm == "Y" || confirm == "y") {
        cout << "\n\033[32mBooking confirmed!\033[0m" << endl;
        dayOfWeek = getDayOfWeek(final_date);
        payment_page(username, password, expert, final_date, dayOfWeek, selectedSlotTime, services, type, amount, duration, totalBookedHours);
    }
    else {
        cout << "\n\033[32mBooking cancelled.\033[0m" << endl;
        services_page(username, password);
    }
}

void payment_page(const string& username, const char password[], string expert, string date, string day, string time, string services, string type, double amount, int duration, int hours) {
    string con, tng_id, tng_pin, bank_name, bank_pin, cardNumber, cvv, choiceofpaymentmethod, payment_method, bank, num, userfullname, id, otp;
    string filename = "booking.txt";
    bool validPin, validOtp;
    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    for (int i = 0; i < user_count; ++i) {
        const User& user = users[i];
        if (username == user.username && strcmp(password, user.password) == 0) {
            userfullname = user.userfullname;
        }
    }
    logo();
    payment_logo();
    cout << left << setw(35) << "Your name" << ": " << userfullname << endl
        << left << setw(35) << "Expert" << ": " << expert << endl
        << left << setw(35) << "Services" << ": " << services << endl
        << left << setw(35) << "Date" << ": " << date << endl
        << left << setw(35) << "Time" << ": " << time << endl
        << left << setw(35) << "Deposit [NO REFUND IF CANCEL]" << ": RM" << fixed << setprecision(2) << amount*0.5 << endl;
    cout << "\nSure booking? [0 to exit || Other to continue process]: ";
    cin >> con;
    if (con == "0") {
        user_main_page(username, password);
    }
    else {
        logo();
        cout << "[1] : Touch n GO" << endl;
        cout << "[2] : Online Banking" << endl;
        cout << "[3] : Credit/Drebit" << endl;
        cout << "\nChoose your payment method: ";
        cin >> payment_method;
        while (payment_method.length() != 1 || !check_char(payment_method[0]) || (payment_method != "1" && payment_method != "2" && payment_method != "3")) {
            cout << "\n\033[31mInvalid input. Please enter numeric/digit only and between 1 to 3 only.\033[0m" << endl;
            cout << "Choose your payment method: ";
            cin >> payment_method;
        }
        if (payment_method == "1") {
            choiceofpaymentmethod = "Touch and Go";
            logo();
            cin.get();
            cout << "Enter your Touch n GO ID: ";
            getline(cin, tng_id);
            while (isEmpty(tng_id)) {
                cout << "\n\033[31mPlease enter the ID: \033[0m";
                getline(cin, tng_id);
            }
            id = tng_id;
            cout << endl;
            do {
                cout << "Enter your PIN [6-digit]: ";
                getline(cin, tng_pin); // Use getline to read the entire line
                validPin = checkPin(&tng_pin);
                if (!validPin || tng_pin.length() != 6 || isEmpty(tng_pin)) {
                    cout << "\n\033[31mInvalid! Please enter numeric digits only and PIN should be exactly 6 digits.\033[0m" << endl;
                    validPin = false; // Ensure the loop continues
                }
            } while (!validPin);
            logo();
            validOtp = getOtp();
        }
        if (payment_method == "2") {
            choiceofpaymentmethod = "Online Banking";
            logo();
            cout << "[1] : Public Bank" << endl;
            cout << "[2] : Maybank" << endl;
            cout << "[3] : CIMB Bank" << endl;
            cout << "[4] : RHB Bank" << endl;
            cout << "[5] : HONG LEONG Bank" << endl;
            cout << "[6] : Bank Islam Malaysia" << endl;
            cout << "\nEnter your choice: ";
            cin >> bank;
            while (bank.length() != 1 || !check_char(bank[0]) || (bank < "1" || bank > "6")) {
                cout << "\n\033[31mInvalid! Please enter numeric/digit only and between 1-6 only.\033[0m" << endl;
                cout << "Enter your choice: ";
                cin >> bank;
            }
            logo();
            cin.get();
            cout << "Enter your bank username: ";
            getline(cin, bank_name);
            while (isEmpty(bank_name)) {
                cout << "\033[31mPlease enter the bank username: \033[0m";
                getline(cin, bank_name);
            }
            id = bank_name;
            cout << endl;
            do {
                cout << "Enter your PIN [6-digit]: ";
                getline(cin, bank_pin); // Use getline to read the entire line
                validPin = checkPin(&bank_pin);
                if (!validPin || bank_pin.length() != 6 || isEmpty(bank_pin)) {
                    cout << "\n\033[31mInvalid! Please enter numeric digits only and PIN should be exactly 6 digits.\033[0m" << endl;
                    validPin = false; // Ensure the loop continues
                }
            } while (!validPin);
            logo();
            validOtp = getOtp();
        }
        if (payment_method == "3") {
            choiceofpaymentmethod = "Credit/Debit card";
            logo();
            cin.get();
            cout << "Enter your credit/debit card number (13-19 digits): ";
            getline(cin, cardNumber);
            while (!isValidCardNumber(cardNumber) || isEmpty(cardNumber)) {
                cout << "\n\033[31mInvalid card number. Please enter a valid card number (13-19 digits): \033[0m";
                getline(cin, cardNumber);
            }
            id = cardNumber;
            logo();
            cout << "Enter CVV (3 or 4 digits): ";
            getline(cin, cvv);
            while (!isValidCVV(cvv) || isEmpty(cvv)) {
                cout << "\n\033[31mInvalid CVV. Please enter a valid CVV (3 or 4 digits): \033[0m";
                getline(cin, cvv);
            }
            logo();
            validOtp = getOtp();
        }
        if (!validOtp) {
            logo();
            cout << "\033[31mInvalid OTP. \nTransaction Unsuccessful!\033[0m" << endl;
        }
        else {
            updateToFile(filename, expert, userfullname, date, time, type, services, "", false, true, duration);
            receipt_page(choiceofpaymentmethod, id, amount*0.5);
            logo();
            cout << "\033[32mBooking Successful!\033[0m" << endl;
        }
        cout << "\nEnter 0 to exit this page: ";
        cin >> num;
        while (num.length() != 1 || !check_char(num[0]) || num != "0") {
            cout << "\n\033[31mInvalid input. Please enter numeric/digit only and [0 : Main Page]: \033[0m";
            cin >> num;
        }
        if (num == "0") {
            user_main_page(username, password);
        }
        updateToFile(filename, expert, userfullname, date, time, type, services, "", false, true, duration);
        receipt_page(choiceofpaymentmethod, id, amount*0.5);
        logo();
        cout << "Booking Successful!" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
        while (num.length() != 1 || !check_char(num[0]) || num != "0") {
            cout << "\n\033[31mInvalid input. Please enter numeric/digit only and [0 : Main Page]: \033[0m";
            cin >> num;
        }
        if (num == "0") {
            user_main_page(username, password);
        }
    }
}

void receipt_page(string payment_method, string id, double amount) {
    int number = rand() % 900000 + 100000;
    const string symbols = "!@#$%^&*";
    char symbol = symbols[rand() % symbols.size()];
    string involve = "Effi";
    involve += to_string(number);
    involve += 'A' + rand() % 26;
    involve += 'A' + rand() % 26;
    involve += 'a' + rand() % 26;
    involve += 'a' + rand() % 26;
    involve += symbol;
    logo();
    receipt_logo();
    cout << "\033[32mYour Transaction Successful!\033[0m" << endl;
    cout << "\nInvoice Number: " << involve << endl;
    cout << "------------------------------------------" << endl << endl;
    cout << left << setw(27) << "Payment Method" << ": " << payment_method << endl;
    cout << left << setw(27) << "ID"  << ": " << id << endl;
    cout << left << setw(27) << "Paid" << ": " << "RM " << fixed << setprecision(2) << amount << endl << endl;
    system("pause");
}

void user_profile_page(const string& username, const char password[]) {
    logo();
    profile_logo();
    string num;
    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    for (int i = 0; i < user_count; ++i) {
        const User& user = users[i];
        if (username == user.username && strcmp(password, user.password) == 0) {
            cout << "Full Name: " << user.userfullname << endl;
            cout << "Username: " << user.username << endl;
            cout << "Email: " << user.email << endl;
            cout << "Contact: +60" << user.contact << endl;
        }
    }
    cout << "\n[1] : Cancel Booking" << endl;
    cout << "[2] : Settings" << endl;
    cout << "[3] : Log Out" << endl;
    cout << "\nEnter code to the respective page [0 : Main Page]: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || (num != "0" && num != "1" && num != "2" && num != "3")) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 0 to 3 only.\033[0m" << endl;
        cout << "Enter code to the respective page [0 : Main Page]: ";
        cin >> num;
    }
    if (num == "0") {
        user_main_page(username, password);
    }
    if (num == "1") {
        cancel_booking_page(username, password);
    }
    if (num == "2") {
        setting_page(username, password);
    }
    else {
        logo();
        cout << "\033[32mYou have been logged out\033[0m" << endl;
        cout << "\033[32mThank you!\033[0m" << endl << endl;
        system("pause");
        exit(0);
    }
}

void setting_page(const string& username, const char password[]) {
    logo();
    setting_logo();

    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    User currentUser;
    bool userFound = false;
    string current_username = username;

    // Find the current user
    for (int i = 0; i < user_count; ++i) {
        if (users[i].username == username && strcmp(users[i].password, password) == 0) {
            currentUser = users[i];
            userFound = true;
            break;
        }
    }

    if (!userFound) {
        cout << "\n\033[31mUser not found or incorrect password.\033[0m" << endl;
        return;
    }

    char num, ch, new_contact[CON_LENGTH], pre_pass[PASS_LENGTH];
    string option, new_user, new_email;
    bool updateSuccess, validPassword = false;
    size_t index = 0;

    cout << "Want to change your profile? [Enter 1 || 0 to exit]: ";
    cin >> num;
    while (!isdigit(num) || (num != '0' && num != '1')) {
        cout << "\n\033[31mPlease enter numeric/digit only and [0] or [1] only.\033[0m" << endl;
        cout << "Want to change your profile? [Enter 1 || 0 to exit]: ";
        cin >> num;
    }
    if (num == '0') {
        user_profile_page(username, password);
        return;
    }
    logo();
    setting_logo();
    cin.get();
    cout << "Enter new username (5-15 characters): ";
    getline(cin, new_user);
    bool noSpace = check_space(new_user);
    while ((new_user.length() < 5 || new_user.length() > 15) || !isUniqueUsername(new_user, users, user_count) || isEmpty(new_user) || !noSpace) {
        cout << "\n\033[31mInvalid or already registered username.\033[0m" << endl;
        cout << "Enter the username: ";
        getline(cin, new_user);
        noSpace = check_space(new_user);
    }
    logo();
    setting_logo();
    cout << "Change email? [Y/N]: ";
    cin >> option;
    while (option != "n" && option != "y" && option != "Y" && option != "N") {
        cout << "\033[31mPlease enter Y or N only.\033[0m" << endl;
        cout << "Change email? [Y/N]: ";
        cin >> option;
    }
    if (option == "Y" || option == "y") {
        logo();
        setting_logo();
        cin.get();
        cout << "Enter new email (siowleelimtan@gmail.com): ";
        getline(cin, new_email);
        while (!check_email(&new_email) || !isUniqueEmail(new_email, users, user_count) || isEmpty(new_email)) {
            cout << "\n\033[31mInvalid email format or already registered.\033[0m" << endl;
            cout << "Enter the email (siowleelimtan@gmail.com) [0 to login]: ";
            getline(cin, new_email);
            if (new_email == "0") {
                user_login_page();
            }
        }
    }
    else {
        new_email = currentUser.email;
    }
    logo();
    setting_logo();
    cout << "Change contact number? [Y/N]: ";
    cin >> option;
    while (option != "n" && option != "y" && option != "Y" && option != "N") {
        cout << "\033[31mPlease enter Y or N only.\033[0m" << endl;
        cout << "Change contact number? [Y/N]: ";
        cin >> option;
    }
    cin.get();
    if (option == "Y"|| option =="y") {
        logo();
        setting_logo();
        cout << "Enter new contact number (+60183335555): +60";
        cin.getline(new_contact, CON_LENGTH);
        while (!check_contact(new_contact) || !isUniqueContactNumber(new_contact, users, user_count)) {
            cout << "\n\033[31mInvalid contact number or already registered.\033[0m" << endl;
            cout << "Enter the contact number (+6013335555) [0 to login]: +60";
            cin.getline(new_contact, CON_LENGTH);
            if (new_contact[0] == '0') {
                user_login_page();
            }
        }
    }
    else {
        strncpy_s(new_contact, currentUser.contact.c_str(), CON_LENGTH - 1);
        // Ensure null termination
        new_contact[CON_LENGTH - 1] = '\0';
    }
    logo();
    setting_logo();
    int count = 1;
    option = "n";
        do {
            do {
                index = 0; // Reset index for new input
                cout << "Enter your previous password: ";

                // Reading password with masking
                while ((ch = _getch()) != '\r') { // Loop until Enter is pressed
                    if (ch == '\b') { // Handle backspace
                        if (index > 0) {
                            index--;
                            cout << "\b \b"; // Erase the last character in console

                            // Re-draw the masked prompt
                            cout << "\rEnter your previous password: ";
                            for (size_t i = 0; i < index; ++i) {
                                cout << '*'; // Redraw the mask
                            }
                            cout.flush(); // Ensure the output is displayed immediately
                        }
                    }
                    else if (index < PASS_LENGTH - 1) { // Ensure we don't exceed the buffer
                        pre_pass[index++] = ch;
                        cout << '*'; // Mask the character
                    }
                }
                pre_pass[index] = '\0'; // Null-terminate the string

                if (isEmpty(pre_pass)) {
                    cout << "\n\033[31mPlease enter the previous password.\033[0m" << endl << endl;
                    continue; // Ask for password again
                }

                // Check if the entered password is correct
                validPassword = validationPassword(pre_pass, password);
                if (!validPassword) {
                    cout << "\n\033[31mInvalid Password!\033[0m" << endl;
                    count++;
                }
            } while (!validPassword && count <= 3);

            if (validPassword) {
                handle_password_update(currentUser.password);
                option = "y";
            }

            if (count > 3) {
                cout << "\n\nForgot Password? [Enter Y/N]: ";
                cin >> option;
                while (option != "n" && option != "y" && option != "Y" && option != "N") {
                    cout << "\n\033[31mPlease enter Y / N only.\033[0m" << endl;
                    cout << "Forgot Password? [Enter Y/N]: ";
                    cin >> option;
                }
                if (option == "Y" || option == "y") {
                    handle_forgot_password(&new_user, currentUser.password, &new_email, new_contact);
                }
            }
        } while (option == "n" || option == "N");

    //updateSuccess = updateRecord("login_username.txt", currentUser.userfullname, new_user, currentUser.password, new_email, new_contact);
    updateSuccess = updateRecord(current_username, "login_username.txt", currentUser.userfullname, new_user, currentUser.password, new_email, new_contact);
    logo();
    if (updateSuccess) {
        cout << "\033[32mUpdate Successful!\033[0m" << endl;
    }
    else {
        cout << "\033[31mUpdate Unsuccessful!\033[0m" << endl;
    }
    cout << "\nEnter 0 to exit this page: ";
    cin >> num;
    while (!isdigit(num) || num != '0') {
        cout << "\n\033[31mPlease enter numeric/digit only and [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == '0') {
        user_profile_page(new_user, currentUser.password);
    }
}

void contact_us_page(const string& username, const char password[]) {
    string name, email, contact, num;
    double star;
    int yearofexperience;
    ifstream readExpert("expert_contact.txt");
    logo();
    contact_us_logo();
    if (!readExpert) { // or use inputFile.is_open()
        cerr << "\033[31mError: Could not open file expert_staff_contact.txt for reading.\033[0m" << endl;
    }
    else {
        cout << fixed << setprecision(1); // Set decimal precision for star rating
        cout << " -------------------------------------------------------------------------------------------" << endl;
        cout << "|    Name    |        Email         |     Contact    | Experience of year |  Range of star  |" << endl;
        cout << " -------------------------------------------------------------------------------------------" << endl;
        while (readExpert >> name >> email >> contact >> yearofexperience >> star) {
            cout << "|   " << setw(8) << left << name << " | " << setw(20) << left << email << " | "
                << setw(3) << left << "+60" << contact << "   | " << setw(18) << left << yearofexperience << " | " << setw(15) << left << star << " |" << endl;
            cout << " -------------------------------------------------------------------------------------------" << endl;
        }
        readExpert.close();
    }
    cout << "\nEnter 0 to exit this page: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || (num != "0")) {
        cout << "\n\033[31mPlease enter numeric/digit only and [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == "0") {
        user_main_page(username, password);
    }
}

void about_us_page(const string& username, const char password[]) {
    string continue_ask, question, num;
    do {
        logo();
        about_us_logo();
        cout << "[1] : Why I cannot sign in an account using the same phone number?" << endl;
        cout << "[2] : Why I cannot change my profile?" << endl;
        cout << "[3] : Why the online payment keeps displaying 'Transaction Unsuccessful.'?" << endl;
        cout << "[4] : Why are the services provided so inexpensive?" << endl;
        cout << "[5] : How can I change my profile?" << endl;
        cout << "[6] : How can I contact the staff to get information?" << endl;
        cout << "[7] : Why develop this system?" << endl;
        cout << "[8] : How can I apply for work here?" << endl;
        cout << "\n\nEnter the frequently asked questions that you wanted to ask [0 : Main Page]: ";
        cin >> question;
        while (question.length() != 1 || !check_char(question[0]) || question < "0" || question > "8") {
            cout << "\n\033[31mPlease enter numeric/digit only and between 0 to 8 only.\033[0m" << endl;
            cout << "Enter the frequently asked question you wanted to ask [0 : Main Page]: ";
            cin >> question;
        }
        logo();
        if (question == "0") {
            user_main_page(username, password);
            break;
        }
        if (question == "1") {
            cout << "Why I cannot sign in an account using the same phone number?" << endl;
            cout << "\n\t- Same phone number cannot have more than one account, phone number must be unique for each customer." << endl;
        }
        if (question == "2") {
            cout << "Why I cannot change my profile?" << endl;
            cout << "\n\t1. Due to using the same email/phone number that you have registered before.\n\t2. Due to you input the password without fulfilling the requirements." << endl;
        }
        if (question == "3") {
            cout << "Why the online payment keeps displaying 'Transaction Unsuccessful.'?" << endl;
            cout << "\n\t1. Due to incorrect OTP.\n\t2. Due to internet problem." << endl;
        }
        if (question == "4") {
            cout << "Why are the services provided so inexpensive?" << endl;
            cout << "\n\t- We would like to provide high quality services to the customers and satisfy them." << endl;
        }
        if (question == "5") {
            cout << "How can I change my profile?" << endl;
            cout << "\n\t- Back to Main Page and go to Profile Page, then go to Setting Page to change your profile." << endl;
        }
        if (question == "6") {
            cout << "How can I contact the staff to get information?" << endl;
            cout << "\n\t- Back to Main Page and go to Contact Us Page to view the information of each staff." << endl;
        }
        if (question == "7") {
            cout << "Why develop this system?" << endl;
            cout << "\n\t1. Customers are able to book appointments in a more convenient way.\n\t2. Customers can get more information / reviews through the social media" << endl;
        }
        if (question == "8") {
            cout << "How can I apply for work here?" << endl;
            cout << "\n\t- You can apply for work by contacting our staff, then you will need to come for a physical interview." << endl;
        }
        system("pause");
        logo();
        cout << "Continue to view other question? (Y/N): ";
        cin >> continue_ask;
        while (continue_ask != "Y" && continue_ask != "N"&& continue_ask != "y"&& continue_ask != "n") {
            logo();
            cout << "\033[31mInvalid, try again.\033[0m" << endl;
            cout << "Continue to view other question? (Y/N): ";
            cin >> continue_ask;
        }
    } while (continue_ask == "Y" || continue_ask == "y");
    logo();
    cout << "Enter 0 to exit this page: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || num != "0") {
        cout << "\n\033[31mPlease enter numeric/digit only and [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == "0") {
        user_main_page(username, password);
    }
}

void cancel_booking_page(const string& username, const char password[]) {
    char num;
    int option = 3, no = 1;
    string slot, userfullname, new_status = "Cancelled";
    logo();
    cancel_logo();   // Assume this is defined elsewhere in your code
    string filename = "booking.txt";
    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    Booking bookings[MAX_BOOKINGS];
    for (int i = 0; i < user_count; ++i) {
        const User& user = users[i];
        if (username == user.username && strcmp(password, user.password) == 0) {
            userfullname = user.userfullname;
            break;
        }
    }
    int bookingCount = readBookings(filename, option, bookings, "", userfullname);
    if (bookingCount == 0) {
        cout << "\n\033[31mNo bookings found for this user.\033[0m" << endl;
        cout << "Enter any key to profile page...";
        cin >> num;
        user_profile_page(username, password);
        return;
    }
    bubbleSort(bookings, bookingCount); // Adjust bubbleSort to work with array and count
    cout << " ----------------------------------------------------------------------------------------------------------" << endl;
    cout << "|  No |  Expert Name  |     Date     | Day |      Time       |   Services    |     Type     |    Status    |" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < bookingCount; ++i) {
        const auto& booking = bookings[i];
        cout << "| " << setw(3) << left << no++
            << " |  " << setw(12) << left << booking.expert_name
            << " | " << setw(12) << left << booking.date
            << " | " << setw(3) << left << booking.day
            << " | " << setw(15) << left << booking.time
            << " | " << setw(13) << left << booking.services
            << " | " << setw(12) << left << booking.type
            << " | " << setw(12) << left << booking.customer_status
            << " |" << endl;
        cout << " ----------------------------------------------------------------------------------------------------------" << endl;
    }
    cin.get();
    cout << "\nChoose the num that you can't attend [0 to exit this page]: ";
    getline(cin, slot);
    bool validSlot = check_slot(slot, option, userfullname);
    while (!validSlot) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 0 to " << bookingCount << " only.\033[0m" << endl;
        cout << "Choose the num that you can't attend [0 to exit this page]: ";
        cin >> slot;
        validSlot = check_slot(slot, option, userfullname);
    }
    if (stoi(slot) == 0) {
        user_profile_page(username, password);
    }
    else {
        Booking selectedBooking = bookings[stoi(slot) - 1];
        string date = selectedBooking.date, time = selectedBooking.time, type = selectedBooking.type, services = selectedBooking.services;
        // Update expert status to 'Leave' for the specific booking
        bool valid = updateToFile(filename, "", userfullname, date, time, type, services, new_status, false, false, 0); // true indicates updating expert status
        if (valid) {
            logo();
            cout << "\033[32mCancellation successful!\033[0m" << endl;
        }
        else {
            logo();
            cout << "\033[32mCancellation failed.\033[0m" << endl;
        }
    }
    cout << "\nEnter 0 to exit this page: ";
    cin >> num;
    while (num != '0') {
        cout << "\n\033[31mPlease enter [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == '0') {
        user_profile_page(username, password); // Assume this is defined elsewhere in your code
    }
}

bool getOtp() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    int otp, attempts = 0; // Variable to hold the OTP
    string input;
    const int maxAttempts = 3; // Maximum allowed attempts
    logo();
    otp = rand() % 900000 + 100000; // Generate a new OTP
    cout << "Your OTP: " << otp << endl; // Remove or mask in production
    cout << endl;
    while (attempts < maxAttempts) {
        cout << "Enter the OTP: ";
        getline(cin, input); // Read input as a string
        if (isEmpty(input)) {
            cout << "\n\033[31mPlease enter the OTP.\033[0m" << endl;
            continue;
        }
        // Check if the input is numeric
        bool isNumeric = true;
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }
        if (isNumeric && !input.empty()) {
            // Convert to integer and compare with OTP
            int enteredOtp = stoi(input);
            if (enteredOtp == otp) {
                cout << "\n\033[32mOTP confirmed successfully!\033[0m" << endl;
                return true; // OTP is correct
            }
            else {
                attempts++;
                cout << "\n\033[31mInvalid OTP. You have " << (maxAttempts - attempts) << " attempts left.\033[0m" << endl;
            }
        }
        else {
            cout << "\n\033[31mInvalid input. Please enter a numeric value.\033[0m" << endl;
        }
    }
    return false; // Failed after 3 attempts
}

bool isUniqueUsername(const string& username, const User users[], int user_count) {
    for (int i = 0; i < user_count; ++i) {
        if (username == users[i].username) {
            return false;
        }
    }
    return true;
}

bool isUniqueEmail(const string& email, const User users[], int user_count) {
    for (int i = 0; i < user_count; ++i) {
        if (email == users[i].email) {
            return false;
        }
    }
    return true;
}

bool isUniqueContactNumber(char contact_number[], const User users[], int user_count) {
    for (int i = 0; i < user_count; ++i) {
        if (contact_number == users[i].contact) {
            return false;
        }
    }
    return true;
}

bool is_valid_user(const User& user) {
    return !user.userfullname.empty() && !user.username.empty() && strlen(user.password) > 0 && !user.email.empty() && !user.contact.empty();
}

int load_users(const string& filename, User users[], int max_users) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "\n\033[31mError opening file: \033[0m" << filename << endl;
        return 0;
    }
    int count = 0;
    string line;
    while (getline(file, line) && count < max_users) {
        User& user = users[count];
        user.userfullname = line;

        if (getline(file, line)) {
            istringstream iss(line);
            if (iss >> user.username >> user.password >> user.email >> user.contact) {
                if (is_valid_user(user)) {
                    count++;
                }
                else {
                    cerr << "\n\033[31mInvalid user data detected. Skipping record.\033[0m" << endl;
                }
            }
            else {
                cerr << "\n\033[31mError parsing user data: \033[0m" << line << endl;
                // Clear the error state and ignore the rest of the line to continue
                file.clear();
                file.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else {
            // Handle end-of-file or incomplete data
            if (file.eof()) {
                cout << "End of file reached. Total users loaded: " << count << endl;
            }
            else {
                //skip rest of the line
                cerr << "\n\033[31mError reading user details for: \033[0m" << user.userfullname << endl;
            }
        }
    }
    file.close();
    return count;
}

bool is_valid_expert(const Expert& expert) {
    return !expert.expertid.empty() && strlen(expert.e_password) > 0 && !expert.email.empty() && !expert.contact.empty();
}

int load_experts(const string& filename, Expert experts[], int max_experts) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "\n\033[31mError opening file: \033[0m" << filename << endl;
        return 0;
    }

    int count = 0;
    string line;
    while (getline(file, line) && count < max_experts) {
        Expert& expert = experts[count];
        istringstream iss(line);
        if (iss >> expert.expertid >> expert.e_password >> expert.email >> expert.contact) {
            if (is_valid_expert(expert)) {
                count++;
            }
            else {
                cerr << "\n\033[31mInvalid expert data detected. Skipping record.\033[0m" << endl;
            }
        }
        else {
            //skip the rest of the data
            cerr << "\n\033[31mError parsing expert data: \033[0m" << line << endl;
            file.clear();
            file.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    file.close();
    return count;
}

int readBookings(const string& filename, int option, Booking bookings[], string expertid, string userfullname) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "\n\033[31mError opening file.\033[0m" << endl;
        return 0;
    }
    string line, expert_name, customer_name, date, day, time, services, type, duration, customer_status, expert_status;
    int count = 0;
    while (getline(file, expert_name) &&
        getline(file, customer_name) &&
        getline(file, line)) {
        istringstream iss(line);
        if (iss >> date >> day >> time >> services >> type >> duration >> customer_status >> expert_status) {
            Booking booking = { expert_name, customer_name, date, day, time, services, type, duration, customer_status, expert_status,0.0 };
            
            // Determine the star rating based on conditions
            if (customer_status == "Booked") {
                if (type == "Consultation") {
                    if (services == "Tattoo") {
                        booking.amount = 50.00;
                    }
                    else if (services == "MakeUp") {
                        booking.amount = 75.00;
                    }
                    else {
                        booking.amount = 100.00;
                    }
                }
                else {
                    booking.amount = 200.00;
                    if (services == "Tattoo") {
                        booking.amount = 200.00;
                    }
                    else if (services == "MakeUp") {
                        booking.amount = 250.00;
                    }
                    else {
                        booking.amount = 300.00;
                    }
                }
            }
            // Add booking based on option
            if ((option == 1 || option == 4) && expert_name == expertid) {
                if (count < MAX_BOOKINGS) {
                    bookings[count++] = booking;
                }
            }
            else if (option == 2) {
                if (count < MAX_BOOKINGS) {
                    bookings[count++] = booking;
                }
            }
            else if (option == 3 && customer_name == userfullname) {
                if (count < MAX_BOOKINGS) {
                    bookings[count++] = booking;
                }
            }
        }
        else {
            cerr << "\n\033[31mError parsing line: \033[0m" << line << endl;
        }
    }
    file.close();
    return count; // Return the number of bookings read
}

int getDaysInMonth(int month, int year) {
    if (month == 2) { // February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29; // Leap year
        }
        else {
            return 28; // Non-leap year
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30; // April, June, September, November
    }
    else {
        return 31; // January, March, May, July, August, October, December
    }
}

void bubbleSort(Booking bookings[], int count) {
    // Bubble sort algorithm for an array
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (compareByDate(bookings[j + 1], bookings[j])) {
                // Swap bookings[j] and bookings[j + 1]
                Booking temp = bookings[j];
                bookings[j] = bookings[j + 1];
                bookings[j + 1] = temp;
            }
        }
    }
}

// Function to convert date string to comparable format
bool compareByDate(const Booking& a, const Booking& b) {
    tm a_tm = a.to_tm();
    tm b_tm = b.to_tm();
    if (a_tm.tm_year != b_tm.tm_year)
        return a_tm.tm_year < b_tm.tm_year;
    if (a_tm.tm_mon != b_tm.tm_mon)
        return a_tm.tm_mon < b_tm.tm_mon;
    return a_tm.tm_mday < b_tm.tm_mday;

}

void displayCalendar(int month, int year, const Booking bookings[], int bookingCount, const string& expert, const string& dateStr, int duration) {
    const char* daysOfWeek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    // Create a tm struct and initialize it
    tm timeIn = {};
    timeIn.tm_year = year - 1900; // tm_year is years since 1900
    timeIn.tm_mon = month - 1;    // tm_mon is 0-based
    timeIn.tm_mday = 1;           // Start at the first day of the month
    mktime(&timeIn);

    // Display the calendar header
    cout << "Su Mo Tu We Th Fr Sa\n";

    // Display leading spaces
    int startDay = timeIn.tm_wday;
    for (int i = 0; i < startDay; ++i) {
        cout << "   ";
    }

    // Get the total days in the month
    int daysInMonth = getDaysInMonth(month, year);
    for (int day = 1; day <= daysInMonth; ++day) {
        timeIn.tm_mday = day;
        mktime(&timeIn);
        bool isWeekend = (timeIn.tm_wday == 0 || timeIn.tm_wday == 6); // Sunday or Saturday

        // Check if the date is fully booked
        string currentDate = to_string(day) + "-" + getMonthName(month) + "-" + to_string(year);
        int totalBookedHours = 0;

        for (int i = 0; i < bookingCount; ++i) {
            if (expert == bookings[i].expert_name && currentDate == bookings[i].date && bookings[i].expert_status == "Working") {
                totalBookedHours += stoi(bookings[i].duration);
            }
        }

        if (!isDateAfterToday(day, month, year) || isWeekend) {
            cout << "\033[36m";
        }

        // Color coding for weekends and fully booked dates
        else if (totalBookedHours >= 6 || totalBookedHours + duration > 6) {
            cout << "\033[31m"; // Red color for unavailable dates
        }

        cout << setw(2) << day << "\033[0m "; // Reset color after day

        if ((startDay + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

bool updateRecord(string current_username, const string& filename, const string& nameToUpdate, const string& newUsername, const char newPassword[], const string& newEmail, const char newContact[]) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "\n\033[31mError opening input file.\033[0m" << endl;
        return false;
    }
    // Create a temporary file
    string tempFilename = "tempfile.txt";
    ofstream tempFile(tempFilename);
    if (!tempFile.is_open()) {
        cerr << "\n\033[31mError opening temporary file.\033[0m" << endl;
        inputFile.close();
        return false;
    }
    string line;
    string name, user, email;
    char pass[PASS_LENGTH], contact[CON_LENGTH];
    while (getline(inputFile, line)) {
        // Read the name line
        name = line;
        // Read the next line for credentials
        if (getline(inputFile, line)) {
            istringstream iss(line);
            if (iss >> user >> pass >> email >> contact) {
                if (user == current_username) {
                    // Write updated record to temp file
                    tempFile << name << "\n";
                    tempFile << newUsername << " " << newPassword << " " << newEmail << " " << newContact << "\n";
                }
                else {
                    // Write unchanged record to temp file
                    tempFile << name << "\n";
                    tempFile << user << " " << pass << " " << email << " " << contact << "\n";
                }
            }
        }
    }
    // Close files
    inputFile.close();
    tempFile.close();
    // Replace the original file with the temp file
    if (remove(filename.c_str()) != 0) {
        cerr << "\n\033[31mError deleting original file.\033[0m" << endl;
        return false;
    }
    if (rename(tempFilename.c_str(), filename.c_str()) != 0) {
        cerr << "\n\033[31mError renaming temporary file.\033[0m" << endl;
        return false;
    }
    return true;
}

bool isSlotAvailable(const string& proposedTimeSlot, const Booking bookings[], int bookingCount, const string& expert, const string& date, int duration) {
    int startProposed = timeToHour(proposedTimeSlot.substr(0, 5));
    int endProposed = timeToHour(proposedTimeSlot.substr(6, 5));

    // Check if proposed slot has the correct duration
    if (endProposed - startProposed != duration) {
        return false; // Duration mismatch
    }

    for (int i = 0; i < bookingCount; ++i) {
        if (bookings[i].expert_name == expert && bookings[i].date == date) {
            string bookedTimeSlot = bookings[i].time;
            int startBooked = timeToHour(bookedTimeSlot.substr(0, 5));
            int endBooked = timeToHour(bookedTimeSlot.substr(6, 5));

            // Check if the slot is booked or if the expert is on leave
            if (bookings[i].customer_status == "Booked" || bookings[i].expert_status == "Leave") {
                if (startProposed < endBooked && endProposed > startBooked) {
                    return false; // Slot is not available due to overlap
                }
            }

            // Check for pending bookings
            if (bookings[i].customer_status == "Cancelled") {
                if (startProposed == startBooked && endProposed == endBooked) {
                    continue;
                }
                else {
                    if (startProposed < endBooked && endProposed > startBooked) {
                        continue;
                    }
                }
            }
        }
    }

    return true; // Slot is available if all checks pass
}

string displayAvailableSlot(const string& username, const char password[], const Booking bookings[], int bookingCount, const string& expert, int startHour, int endHour, const string& date, int duration) {
    cout << "\nAvailable Time Slots (" << startHour << ":00 to " << endHour - 1 << ":00):" << endl;
    cout << "\n --------------------------------------" << endl;
    cout << "|  No |     Time     |  Availability   |" << endl;
    cout << " --------------------------------------" << endl;

    string availableSlots[MAX_SLOTS]; // Store available slots
    int no = 1, availableCount = 0; // Count of available slots

    // Iterate over possible time slots
    for (int hour = startHour; hour + duration <= endHour; hour += (duration == 1 ? 1 : 2)) {
        string s_time = hourToTime(hour);
        string e_time = hourToTime(hour + duration);
        string timeSlot = s_time + "-" + e_time;

        // Check if the slot is available
        bool isAvailable = isSlotAvailable(timeSlot, bookings, bookingCount, expert, date, duration);

        if (isAvailable) {
            // Slot is available for booking
            if (availableCount < MAX_SLOTS) {
                availableSlots[availableCount++] = timeSlot;
            }
            cout << "|  " << setw(2) << left << no++ << " | " << setw(12) << left << timeSlot << " |  " << setw(15) << "\033[32mAvailable\033[0m" << "      |" << endl;
        }
        else {
            cout << "|  " << setw(2) << left << "-" << " | " << setw(12) << left << timeSlot << " |  " << setw(15) << "Unavailable" << "|" << endl;
        }
        cout << " --------------------------------------" << endl; // Line between slots
    }

    if (availableCount == 0) {
        cout << "\n\033[31mNo slots available.\033[0m" << endl;
        return ""; // No slots available
    }

    // Slot selection logic
    cout << endl;
    bool valid = true;
    while (valid) {
        string input;
        cout << "Select the number of the available slot [0 to exit]: ";
        getline(cin, input);

        // Check for empty input
        if (input.empty()) {
            cout << "\n\033[31mPlease enter the number.\033[0m" << endl;
            continue;
        }

        if (input == "0") {
            user_main_page(username, password);
            return ""; // Exit or cancel slot selection
        }

        // Validate input is numeric
        if (!all_of(input.begin(), input.end(), ::isdigit)) {
            cout << "\n\033[31mInvalid input. Please enter a numeric value.\033[0m" << endl;
            continue;
        }

        int selectedSlot = stoi(input);
        if (selectedSlot < 0 || selectedSlot > availableCount) {
            cout << "\n\033[31mInvalid selection. Please select a valid slot number.\033[0m" << endl;
        }
        else {
            // Proceed to book the selected slot (implement your booking logic here)
            return availableSlots[selectedSlot - 1]; // Return the selected slot
        }
    }
}

string getDayOfWeek(const string& dateStr) {
    // Define the date format
    const string format = "%d-%b-%Y"; // Format for 09-Jan-2025
    // Create a tm structure
    tm tm = {};
    // Create a stringstream to parse the date string
    stringstream ss(dateStr);
    ss >> get_time(&tm, format.c_str());
    // Check if parsing was successful
    if (ss.fail()) {
        cerr << "\n\033[31mError parsing date string: \033[0m" << dateStr << endl;
        return "Invalid date";
    }
    // Convert tm to time_t
    time_t t = mktime(&tm);
    if (t == -1) {
        cerr << "\n\033[31mError converting tm to time_t\033[0m" << endl;
        return "Error";
    }
    // Get day of the week from tm structure
    std::tm timeinfo;
    errno_t err = localtime_s(&timeinfo, &t);
    if (err != 0) {
        cerr << "\n\033[31mError getting local time\033[0m" << endl;
        return "Error";
    }
    // Array of day names
    const char* days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    return days[timeinfo.tm_wday];
}

string getMonthName(int month) {
    // Array of month names, index 0 is not used
    const string months[] = {
        "\033[31mInvalid Month\033[0m","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"
    };
    // Check if month is within valid range
    if (month < 1 || month > 12) {
        return months[0];
    }
    // Return the corresponding month name
    return months[month];
}

bool updateToFile(const string& filename, const string& expertID, const string& customerName, const string& date, const string& time, const string& type, const string& services, const string& newStatus, bool isExpertStatus, bool isBookingStatus, int duration) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "\n\033[31mError opening input file.\033[0m" << endl;
        return false;
    }

    // Create a temporary file
    string tempFilename = "tempfile.txt";
    ofstream tempFile(tempFilename);
    if (!tempFile.is_open()) {
        cerr << "\n\033[31mError opening temporary file.\033[0m" << endl;
        inputFile.close();
        return false;
    }

    // Define a fixed-size array for bookings
    Booking bookings[MAX_BOOKINGS];
    int count = 0;
    string line;

    // Read the file and load bookings into the array
    while (getline(inputFile, line) && count < MAX_BOOKINGS) {
        Booking booking;
        booking.expert_name = line;
        getline(inputFile, booking.customer_name);
        getline(inputFile, line);
        istringstream detailsStream(line);
        detailsStream >> booking.date >> booking.day >> booking.time
            >> booking.services >> booking.type >> booking.duration
            >> booking.customer_status >> booking.expert_status;

        bookings[count++] = booking;
    }
    inputFile.close();

    bool updated = false, recordFound = false;

    // Convert the new booking time and duration to minutes
    int newStartTimeMinutes, newEndTimeMinutes, newDurationMinutes = duration;
    timeToMinutes(time, newStartTimeMinutes, newEndTimeMinutes);
    newEndTimeMinutes += newDurationMinutes;

    // Process records for overlap
    for (int i = 0; i < count; ++i) {
        Booking& b = bookings[i];

        if (b.expert_name == expertID && b.date == date && b.time == time) {
            // Convert existing booking time and duration to minutes
            int existingStartTimeMinutes, existingEndTimeMinutes;
            timeToMinutes(b.time, existingStartTimeMinutes, existingEndTimeMinutes);
            int existingDurationMinutes = stoi(b.duration); // Convert string duration to int
            existingEndTimeMinutes += existingDurationMinutes; // Adjust end time with duration

            // Check for time slot overlap
            bool overlap = (newStartTimeMinutes < existingEndTimeMinutes) && (newEndTimeMinutes > existingStartTimeMinutes);

            if (overlap) {
                if (b.expert_status == "Pending") {
                    // Update the existing "Pending" record to "Working" for overlap case
                    b.customer_name = customerName;
                    b.time = time;
                    b.services = services;
                    b.type = type;
                    b.duration = to_string(duration);
                    b.expert_status = "Working";
                    b.customer_status = "Booked";
                    updated = true;
                    recordFound = true;
                }
            }
        }
    }

    // Separate loop to update status based on isExpertStatus and booking status
    for (int i = 0; i < count; ++i) {
        Booking& b = bookings[i];

        if (b.date == date && b.time == time && b.type == type && b.services == services) {
            if (isBookingStatus) {
                if (b.expert_name == expertID) {
                    if (b.expert_status == "Pending") {
                        // Update the existing "Pending" record to "Working"
                        b.expert_status = "Working";
                        b.customer_status = "Booked";
                        updated = true;
                        recordFound = true;
                    }
                }
            }
            else {
                // Update status based on flags
                if (b.expert_name == expertID || b.customer_name == customerName) {
                    if (isExpertStatus) {
                        b.customer_status = newStatus;
                        b.expert_status = newStatus;
                    }
                    else {
                        b.customer_status = newStatus;
                        b.expert_status = "Pending";
                    }
                    updated = true;
                    recordFound = true;
                }
            }
        }
    }

    // Add new booking if slot was available and isBookingStatus is true
    if (isBookingStatus && !recordFound) {
        Booking newBooking;
        newBooking.expert_name = expertID;
        newBooking.customer_name = customerName;
        newBooking.date = date;
        newBooking.day = getDayOfWeek(date); // Assuming this function provides the day of the week from the date
        newBooking.time = time;
        newBooking.services = services;
        newBooking.type = type;
        newBooking.duration = to_string(duration); // Convert int duration to string
        newBooking.customer_status = "Booked";
        newBooking.expert_status = "Working";

        bookings[count++] = newBooking;
        updated = true;
    }

    // Write updated bookings to the temp file
    for (int i = 0; i < count; ++i) {
        const Booking& b = bookings[i];
        tempFile << b.expert_name << endl;
        tempFile << b.customer_name << endl;
        tempFile << b.date << " " << b.day << " " << b.time << " " << b.services << " " << b.type << " " << b.duration << " " << b.customer_status << " " << b.expert_status << endl;
    }
    tempFile.close();

    // Replace the original file with the temp file
    if (remove(filename.c_str()) != 0) {
        cerr << "\n\033[31mError deleting original file.\033[0m" << endl;
        return false;
    }
    if (rename(tempFilename.c_str(), filename.c_str()) != 0) {
        cerr << "\n\033[31mError renaming temporary file.\033[0m" << endl;
        return false;
    }

    return updated;
}

bool isDateAfterToday(int day, int month, int year) {
    time_t now = time(0);
    tm local_tm = {};
    if (localtime_s(&local_tm, &now) != 0) {
        cerr << "\n\033[31mError getting local time\033[0m" << endl;
        return false; // Return false if there's an error
    }
    int currentYear = local_tm.tm_year + 1900, currentMonth = local_tm.tm_mon + 1, currentDay = local_tm.tm_mday;

    if (year > currentYear) return true;
    if (year == currentYear && month > currentMonth) return true;
    if (year == currentYear && month == currentMonth && day > currentDay) return true;

    return false;
}

bool isRecordInMonth(const string& date, const string& month, const string& year) {
    istringstream iss(date);
    string day, monthInDate, yearInDate;

    if (getline(iss, day, '-') && getline(iss, monthInDate, '-') && getline(iss, yearInDate)) {
        return (monthInDate == month && yearInDate == year);
    }

    return false;
}

//char generatePassword(char password[], size_t length) {
//    string charSet;
//    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
//    const char digits[] = "0123456789";
//    const char symbols[] = "!@#$%^&*()-_+=[]{}|;:,.<>?";
//    charSet = uppercase;
//    charSet += lowercase;
//    charSet += digits;
//    charSet += symbols;
//    // Random number generator
//    static mt19937 engine(static_cast<unsigned int>(time(nullptr))); // Seed with the current time
//    uniform_int_distribution<> dist(0, charSet.size() - 1);
//    // Allocate memory for the password
//    for (size_t i = 0; i < length; ++i) {
//        password[i] = charSet[dist(engine)];
//    }
//    password[length] = '\0'; // Null-terminate the C-string
//    return password[length];
//}

void generatePassword(char password[], size_t length) {
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*()-_+=[]{}|;:,.<>?";
    const char* charSets[] = { uppercase, lowercase, digits, symbols };
    const size_t charSetCount = sizeof(charSets) / sizeof(charSets[0]);

    // Random number generator
    static mt19937 engine(static_cast<unsigned int>(time(nullptr))); // Seed with the current time

    // Ensure at least one character from each set
    for (size_t i = 0; i < charSetCount && i < length; ++i) {
        uniform_int_distribution<> dist(0, strlen(charSets[i]) - 1);
        password[i] = charSets[i][dist(engine)];
    }

    // Fill the rest of the password
    string allChars = uppercase + string(lowercase) + digits + symbols;
    uniform_int_distribution<> dist(0, allChars.size() - 1);
    for (size_t i = charSetCount; i < length; ++i) {
        password[i] = allChars[dist(engine)];
    }

    // Shuffle the password
    shuffle(password, password + length, engine);

    password[length] = '\0'; // Null-terminate the C-string
}

void generateColoredHistogram(const map<string, int>& serviceCounts, const map<string, int>& weekCounts, const map<string, int>& customerCounts, const string& highest_week) {
    int count = 0, loop = 0;
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";
    if (serviceCounts.empty() && weekCounts.empty() && customerCounts.empty()) {
        cout << "No data to display.\n";
        return;
    }

    int minServiceCount = INT_MAX, maxServiceCount = INT_MIN;
    for (const auto& entry : serviceCounts) {
        if (entry.second < minServiceCount) minServiceCount = entry.second;
        if (entry.second > maxServiceCount) maxServiceCount = entry.second;
    }

    int minWeekCount = INT_MAX,  maxWeekCount = INT_MIN;
    for (const auto& entry : weekCounts) {
        if (entry.second < minWeekCount) minWeekCount = entry.second;
        if (entry.second > maxWeekCount) maxWeekCount = entry.second;
    }

    int minCustomerCount = INT_MAX, maxCustomerCount = INT_MIN;
    for (const auto& entry : customerCounts) {
        if (entry.second < minCustomerCount) minCustomerCount = entry.second;
        if (entry.second > maxCustomerCount) maxCustomerCount = entry.second;
    }

    // Print service counts histogram
    cout << "\nService Booking Histogram:\n";
    cout << "---------------------------------------------------\n";
    for (const auto& entry : serviceCounts) {
        string color;
        int forcount = 0;
        if (entry.second == maxServiceCount) {
            color = GREEN;
        }
        else if (entry.second == minServiceCount) {
            color = RED;
        }
        else {
            color = RESET;
        }

        cout << setw(30) << left << entry.first << " | ";
        cout << color;
        for (int i = 0; i < entry.second; ++i) {
            cout << "#";
            forcount++;
        }

        count++;
        
        if (count == 1) {
            cout << RESET;
            cout << setw(forcount) << right << " (" << entry.second << ")\n";
            loop = forcount;
        }
        if (count >1) {
            cout << RESET;
            cout << setw((loop * 2) - forcount) << right << " (" << entry.second << ")\n";
        }
        
    }

    // Print week counts histogram
    cout << "\nWeek Booking Histogram:\n";
    cout << "----------------------------------------------------\n";
    for (const auto& entry : weekCounts) {
        string color;
        int forcount = 0;
        if (entry.second == maxWeekCount) {
            color = GREEN;
        }
        else if (entry.second == minWeekCount) {
            color = RED;
        }
        else {
            color = RESET;
        }

        cout << setw(30) << left << entry.first << " | ";
        cout << color;
        for (int i = 0; i < entry.second; ++i) {
            cout << "#";
            forcount++;
        }
        count++;
        if (count == 1) {
            cout << RESET;
            cout << setw(forcount) << right << " (" << entry.second << ")\n";
            loop = forcount;
        }
        if (count > 1) {
            cout << RESET;
            cout << setw((loop * 2) - forcount) << right << " (" << entry.second << ")\n";
        }
    }

    // Print the expert highest custoimer name booked counts histogram
    cout << "\nYour Customer Booking Histogram:\n";
    cout << "----------------------------------------------------\n";
    for (const auto& entry : customerCounts) {
        string color;
        int forcount = 0;
        if (entry.second == maxCustomerCount) {
            color = GREEN;
        }
        else if (entry.second == minCustomerCount) {
            color = RED;
        }
        else {
            color = RESET;
        }

        cout << setw(30) << left << entry.first << " | ";
        cout << color;
        for (int i = 0; i < entry.second; ++i) {
            cout << "#";
            forcount++;
        }
        count++;
        if (count == 1) {
            cout << RESET;
            cout << setw(forcount) << right << " (" << entry.second << ")\n";
            loop = forcount;
        }
        if (count > 1) {
            cout << RESET;
            cout << setw((loop * 2) - forcount) << right << " (" << entry.second << ")\n";
        }
    }
}

void handle_forgot_password(string* user, char* pass, string* email, char* contact) {
    string num;
    int digit;
    logo();
    cout << "[0] : Don't want to change already. \n[1] : Email \n[2] : Contact Number" << endl;
    cout << "\nEnter your option that can verify your identity: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || (num != "0" && num != "1" && num != "2")) {
        logo();
        cout << "\033[31mPlease enter numeric/digit only and between 0 to 2 only.\033[0m" << endl;
        cout << "[0] : Don't want to change already. \n[1] : Email \n[2] : Contact Number";
        cout << "\nEnter your option that can verify your identity: ";
        cin >> num;
    }
    digit = stoi(num);
    switch (digit) {
    case 0:
        break;
    case 1:
        handle_forgot_passwordEmail(user, pass, email);
        break;
    case 2:
        handle_forgot_passwordContact(user, pass, contact);
        break;
    }
}

void handle_forgot_passwordEmail(string* user, char* pass, string* email) {
    string pass_email;
    char new_pass[PASS_LENGTH], new_c_pass[PASS_LENGTH];
    logo();
    cin.get();
    cout << "Enter your new email: ";
    getline(cin, pass_email);
    while (!check_email(&pass_email) || pass_email != *email || isEmpty(pass_email)) {
        cout << "\n\033[31mInvalid email or does not match registered email.\033[0m" << endl;
        cout << "Enter the email (siowleelimtan@gmail.com): ";
        getline(cin, pass_email);
    }
    logo();
    cout << "Enter new password: ";
    cin.getline(new_pass, PASS_LENGTH);
    while (isEmpty(new_pass)) {
        cout << "\n\033[31mPlease enter the password: \033[0m";
        cin.getline(new_pass, PASS_LENGTH);
    }
    cout << endl;
    cout << "Enter one more time to confirm: ";
    cin.getline(new_c_pass, PASS_LENGTH);
    while (isEmpty(new_c_pass)) {
        cout << "\n\033[31mPlease enter the password one more time: \033[0m";
        cin.getline(new_c_pass, PASS_LENGTH);
    }
    bool validPassword = validationPassword(new_pass, new_c_pass);
    while (!validPassword) {
        logo();
        cout << "\033[31mInvalid Password! Please meet all requirements.\033[0m" << endl;
        cout << "Password requirements:\n- 8-20 Characters\n- At least one Uppercase\n- At least one Lowercase\n- At least one Symbol\n- At least one Alphabet\n- At least one Digit\n- Both passwords must match\n- Cannot be null\n";
        cout << "\nEnter the password: ";
        cin.getline(new_pass, PASS_LENGTH);
        while (isEmpty(new_pass)) {
            cout << "\n\033[31mPlease enter the password: \033[0m";
            cin.getline(new_pass, PASS_LENGTH);
        }
        cout << endl;
        cout << "Enter the password to confirm: ";
        cin.getline(new_c_pass, PASS_LENGTH);
        while (isEmpty(new_c_pass)) {
            cout << "\n\033[31mPlease enter the password one more time: \033[0m";
            cin.getline(new_c_pass, PASS_LENGTH);
        }
        validPassword = validationPassword(new_pass, new_c_pass);
    }
    errno_t err = strcpy_s(pass, PASS_LENGTH, new_c_pass);
    if (err != 0) {
        cerr << "\033[31mError copying password.\033[0m" << endl;
    }
    strcpy_s(new_pass, new_c_pass);
}

void handle_forgot_passwordContact(string* user, char* pass, char* contact) {
    char new_pass[PASS_LENGTH], new_c_pass[PASS_LENGTH];
    char pass_contact[CON_LENGTH];
    bool contact_number_match;
    logo();
    cin.get();
    cout << "Enter your contact number: +60";
    cin.getline(pass_contact, CON_LENGTH);
    bool contact_number_digit = check_contact(pass_contact);
    contact_number_match = strcmp(pass_contact, contact) == 0;
    while (!contact_number_digit || !contact_number_match || isEmpty(pass_contact)) {
        cout << "\n\033[31mInvalid contact number or does not match registered contact number.\033[0m" << endl;
        cout << "Enter the contact number (+60183335555): +60";
        cin.getline(pass_contact, CON_LENGTH);
        contact_number_digit = check_contact(pass_contact);
        contact_number_match = strcmp(pass_contact, contact) == 0;
    }
    logo();
    cout << "Enter new password: ";
    cin.getline(new_pass, PASS_LENGTH);
    while (isEmpty(new_pass)) {
        cout << "\033[31mPlease enter the password: \033[0m";
        cin.getline(new_pass, PASS_LENGTH);
    }
    cout << endl;
    cout << "Enter one more time to confirm: ";
    cin.getline(new_c_pass, PASS_LENGTH);
    while (isEmpty(new_c_pass)) {
        cout << "\033[31mPlease enter the password one more time: \033[0m";
        cin.getline(new_c_pass, PASS_LENGTH);
    }
    bool validPassword = validationPassword(new_pass, new_c_pass);
    while (!validPassword) {
        logo();
        cout << "\033[31mInvalid Password! Please meet all requirements.\033[0m" << endl;
        cout << "Password requirements:\n- 8-20 Characters\n- At least one Uppercase\n- At least one Lowercase\n- At least one Symbol\n- At least one Alphabet\n- At least one Digit\n- Both passwords must match\n- Cannot be null\n";
        cout << "\nEnter the password: ";
        cin.getline(new_pass, PASS_LENGTH);
        while (isEmpty(new_pass)) {
            cout << "\033[31mPlease enter the password: \033[0m";
            cin.getline(new_pass, PASS_LENGTH);
        }
        cout << endl;
        cout << "Enter the password to confirm: ";
        cin.getline(new_c_pass, PASS_LENGTH);
        while (isEmpty(new_c_pass)) {
            cout << "\033[31mPlease enter the password one more time: \033[0m";
            cin.getline(new_c_pass, PASS_LENGTH);
        }
        validPassword = validationPassword(new_pass, new_c_pass);
    }
    errno_t err = strcpy_s(pass, PASS_LENGTH, new_c_pass);
    if (err != 0) {
        cerr << "\033[31mError copying password.\033[0m" << endl;
    }
    strcpy_s(new_pass, new_c_pass);
}

void handle_password_update(char* pass) {
    char new_pass[PASS_LENGTH], new_c_pass[PASS_LENGTH];
    logo();
    setting_logo();
    cout << "Enter new password: ";
    cin.getline(new_pass, PASS_LENGTH);
    while (isEmpty(new_pass)) {
        cout << "\033[31mPlease enter the password: \033[0m";
        cin.getline(new_pass, PASS_LENGTH);
    }
    cout << endl;
    cout << "Enter one more time to confirm: ";
    cin.getline(new_c_pass, PASS_LENGTH);
    while (isEmpty(new_c_pass)) {
        cout << "\033[31mPlease enter the password one more time: \033[0m";
        cin.getline(new_c_pass, PASS_LENGTH);
    }
    bool validPassword = validationPassword(new_pass, new_c_pass);
    while (!validPassword) {
        logo();
        setting_logo();
        cout << "\033[31mInvalid Password! Please meet all requirements.\033[0m" << endl;
        cout << "Password requirements:\n- 8-20 Characters\n- At least one Uppercase\n- At least one Lowercase\n- At least one Symbol\n- At least one Alphabet\n- At least one Digit\n- Both passwords must match\n- Cannot be null\n";
        cout << "\nEnter the password: ";
        cin.getline(new_pass, PASS_LENGTH);
        while (isEmpty(new_pass)) {
            cout << "\033[31mPlease enter the password: \033[0m";
            cin.getline(new_pass, PASS_LENGTH);
        }
        cout << endl;
        cout << "Enter the password to confirm: ";
        cin.getline(new_c_pass, PASS_LENGTH);
        while (isEmpty(new_c_pass)) {
            cout << "\033[31mPlease enter the password one more time: \033[0m";
            cin.getline(new_c_pass, PASS_LENGTH);
        }
        validPassword = validationPassword(new_pass, new_c_pass);
    }
    errno_t err = strcpy_s(pass, PASS_LENGTH, new_c_pass);
    if (err != 0) {
        cerr << "\033[31mError copying password.\033[0m" << endl;
    }
    strcpy_s(new_pass, new_c_pass);
}

bool check_slot(string slot, int option, string name) {
    string filename = "booking.txt";
    User users[MAX_USERS];
    int user_count = load_users("login_username.txt", users, MAX_USERS);
    Booking bookings[MAX_BOOKINGS];
    int bookingCount = readBookings(filename, option, bookings, "", name);
    for (int i = 0; i < bookingCount; i++) {
        char c = slot[i];
        if (!isdigit(c)) {
            return false;
        }
        else if (stoi(slot) < 0 || stoi(slot) > bookingCount) {
            return false;
        }
        else {
            return true;
        }
    }
}

bool check_char(char num) {
    return isdigit(static_cast<unsigned char>(num)) != 0;
}

bool checkPin(string* pin) {
    const string& input = *pin;  // Dereference the pointer to access the string
    for (char ch : input) {
        if (!isdigit(ch)) {
            return false;  // Not all characters are digits
        }
    }
    return true;
}

bool isValidCardNumber(const string& cardNumber) {
    // Basic check: length should be between 13 and 19 digits
    if (cardNumber.length() < 13 || cardNumber.length() > 19) {
        return false;
    }
    for (int i = 0; i < cardNumber.length(); ++i) {
        char ch = cardNumber[i];
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool isValidCVV(const string& cvv) {
    // Basic check: CVV should be 3 or 4 digits
    if (cvv.length() != 3 && cvv.length() != 4) {
        return false;
    }
    for (int j = 0; j < cvv.length(); ++j) {
        char ch = cvv[j];
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool check_email(string* email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(*email, pattern);
}

bool check_contact(char number[]) {
    int length = strlen(number);
    if (length == 9 || length == 10) {
        for (int count = 0; count < length; count++) {
            if (!isdigit(number[count])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool validationPassword(const char* pass1, const char* pass2) {
    int len = strlen(pass2);
    bool length = false, has_upper = false, has_lower = false, has_symbol = false, has_digit = false;
    if (strcmp(pass1, pass2) == 0) {
        if (len >= 8 || len <= 20) {
            length = true;
        }
        for (int i = 0; i < len; i++) {
            if (isupper(pass2[i])) {
                has_upper = true;
            }
            if (islower(pass2[i])) {
                has_lower = true;
            }
            if (isdigit(pass2[i])) {
                has_digit = true;
            }
            if (ispunct(pass2[i])) {
                has_symbol = true;
            }
        }
        if (!(length && has_upper && has_lower && has_digit && has_symbol)) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

bool check_digit(string input, int no) {
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (!isdigit(c)) {
            return false;
        }
        else if (stoi(input) < 0 || stoi(input) >= no) {
            return false;
        }
        else {
            return true;
            break;
        }
    }
}

bool check_space(string username) {
    for (int i = 0; i < username.length(); i++) {
        char c = username[i];
        if (c == ' ') {
            return false;
        }
    }
    return true;
}

// Convert time string to integer hour
int timeToHour(const string& timeStr) {
    return stoi(timeStr.substr(0, 2)); // Extract hour part and convert to integer
}

// Convert integer hour to time string
string hourToTime(int hour) {
    return (hour < 10 ? "0" : "") + to_string(hour) + ":00";
}

void timeToMinutes(const string& timeStr, int& startMinutes, int& endMinutes) {
    // Find the position of the dash ('-') in the time string
    size_t dashPos = timeStr.find('-');
    if (dashPos != string::npos) {
        // Extract the start and end times from the string
        string startTimeStr = timeStr.substr(0, dashPos);
        string endTimeStr = timeStr.substr(dashPos + 1);

        // Convert start time to minutes
        int startHour = stoi(startTimeStr.substr(0, 2));
        int startMinute = stoi(startTimeStr.substr(3, 2));
        startMinutes = startHour * 60 + startMinute;

        // Convert end time to minutes
        int endHour = stoi(endTimeStr.substr(0, 2));
        int endMinute = stoi(endTimeStr.substr(3, 2));
        endMinutes = endHour * 60 + endMinute;
    }
}

void expert_login_page() {
    logo();
    login_logo();
    char ch,password[PASS_LENGTH];
    string expertid, num;
    size_t index = 0;
    bool loginSuccessful = false;
    Expert experts[MAX_EXPERTS];
    int expert_count = load_experts("login_expert.txt", experts, MAX_EXPERTS);
    cout << "[1] Continue as Expert | [0] Back: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || (num != "0" && num != "1")) {
        cout << "\n\033[31mPlease enter [0] or [1] only.\033[0m" << endl;
        cout << "[1] Continue as Expert | [0] Back: ";
        cin >> num;
    }
    if (num == "0") {
        identity_page();
        return;
    }
    else if (num == "1") {
        logo();
        login_logo();
        cin.get();
        cout << "Enter your ID: ";
        getline(cin, expertid);
        expertid = expertid.substr(0, 120);  // Assume MAX_ID_LENGTH is defined
        while (isEmpty(expertid)) {
            cout << "\033[31mPlease enter your ID: \033[0m";
            getline(cin, expertid);
        }
        cout << endl;
        cout << "Enter your password: ";
        do {
            index = 0; // Reset index for new input
            while ((ch = _getch()) != '\r') { // Loop until Enter is pressed
                if (ch == '\b') { // Handle backspace
                    if (index > 0) {
                        index--;
                        cout << "\b \b"; // Erase the last character in console
                        // Update the masked prompt

                        cout << "\rEnter your password: ";
                        for (size_t i = 0; i < index; ++i) {
                            cout << '*'; // Redraw the mask
                        }
                        cout.flush(); // Ensure the output is displayed immediately
                    }
                }
                else if (index < PASS_LENGTH - 1) { // Ensure we don't exceed the buffer
                    password[index++] = ch;
                    cout << '*'; // Mask the character
                }
            }
            password[index] = '\0'; // Null-terminate the string

            if (isEmpty(password)) {
                cout << "\n\033[31mPassword cannot be null! \033[0m"; // Red prompt
                cout << "\n\n\rEnter your password: ";
            }

        } while (isEmpty(password));
        for (int i = 0; i < expert_count; ++i) {
            const Expert& expert = experts[i];
            if (expertid == expert.expertid && strcmp(password, expert.e_password) == 0) {
                loginSuccessful = true;
                break;
            }
        }
        if (loginSuccessful) {
            cout << "\n\n\033[32mLogin Successful! Welcome, " << expertid << "!\033[0m" << endl;
            system("pause");
            expert_main_page(expertid, password);
            return; // or call expert_main_page() if you have a expert_main_page function
        }
        else {
            cout << "\n\n\033[31mLogin Error! \nPlease check your ID and Password. (Enter 1 to continue login || 0: Back): \033[0m";
            cin >> num;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while (num.length() != 1 || !check_char(num[0]) || (num != "0" && num != "1")) {
                cout << "\n\033[31mPlease enter numeric/digit only and [0] or [1] only.\033[0m" << endl;
                cout << "(Enter 0 to go back || 1 to continue login): ";
                cin >> num;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (num == "0") {
                identity_page();
                return; // or call main() if you have a main function
            }
            else {
                expert_login_page(); // Retry login
            }
        }
    }
}

void expert_main_page(const string& expertid, const char password[]) {
    logo();
    string num;
    cout << "[1] : Profile" << endl << "[2] : View Customer" << endl;
    cout << "\nEnter code to the respective page: ";
    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (num.length() != 1 || !check_char(num[0]) || (num != "1" && num != "2")) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 1 to 2 only.\033[0m" << endl;
        cout << "Enter code to the respective page: ";
        cin >> num;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (num == "1") {
        expert_profile_page(expertid, password);
    }
    if (num == "2") {
        view_customer(expertid, password);
    }
}

void expert_profile_page(const string& expertid, const char password[]) {
    int digit;
    logo();
    profile_logo();

    Expert experts[MAX_EXPERTS];
    int expert_count = load_experts("login_expert.txt", experts, MAX_EXPERTS);
    string num;
    bool profileFound = false;
    for (int i = 0; i < expert_count; ++i) {
        const Expert& expert = experts[i];
        if (expertid == expert.expertid && strcmp(password, expert.e_password) == 0) {
            cout << "Your ID: " << expert.expertid << endl;
            cout << "Your Email: " << expert.email << endl;
            cout << "Your Contact Number: +60" << expert.contact << endl;
            profileFound = true;
            break;
        }
    }
    if (!profileFound) {
        cout << "\n\033[31mProfile not found or incorrect credentials.\033[0m" << endl;
        return;
    }
    cout << "\n[1] : Your Schedule" << endl;
    cout << "[2] : Sales Report" << endl;
    cout << "[3] : Take Leave" << endl;
    cout << "[4] : Log Out" << endl;

    cout << "\nEnter code to the respective page [0 : Main Page]: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || (num != "0" && num != "1" && num != "2" && num != "3" && num != "4")) {
        cout << "\n\033[31mPlease enter numeric/digit only and between 0 to 4 only.\033[0m" << endl;
        cout << "Enter code to the respective page: [0 : Main Page]: ";
        cin >> num;
    }
    digit = stoi(num);
    switch (digit) {
    case 0:
        expert_main_page(expertid, password);
        break;
    case 1:{
        logo();
        schedule_logo();
        cout << "[1] : INDIVIDUAL" << endl;
        cout << "[2] : OVERALL" << endl;
        cout << "\nEnter number [0 to exit this page]: ";
        string schedule;
        cin >> schedule;
        while (schedule.length() != 1 || !check_char(schedule[0]) || (schedule != "0" && schedule != "1" && schedule != "2")) {
            cout << "\n\033[31mPlease enter numeric/digit only and between [0], [1] or [2] only.\033[0m" << endl;
            cout << "Enter number [0 to exit this page]: ";
            cin >> schedule;
        }
        if (schedule == "1" || schedule == "2") {
            int option = stoi(schedule);
            schedule_page(expertid, password, option);
        }
        else {
            expert_profile_page(expertid, password);
        }
        break;
    }
    case 2:
        sales_report_page(expertid, password);
        break;
    case 3:
        expert_takeLeave_page(expertid, password);
        break;
    case 4:
        logo();
        cout << "\033[32mYou have been logged out\033[0m" << endl;
        cout << "\033[32mThank you!\033[0m" << endl << endl;
        system("pause");
        exit(0);
    }
}

void schedule_page(const string& expertid, const char password[], int option) {
    string ch;
    int bookingCount,no = 1;
    logo();
    schedule_logo(); // Assume this is defined elsewhere in your code
    char num;
    Booking bookings[MAX_BOOKINGS];
    string filename = "booking.txt"; // Ensure expertid is defined
    // Read bookings based on the option
    if (option == 1 || option == 2) {
        bookingCount = readBookings(filename, option, bookings, expertid, "");
    }
    else {
        cerr << "\n\033[31mInvalid option.\033[0m" << endl;
        return;
    }
    // Sort bookings by date using bubble sort
    bubbleSort(bookings, bookingCount);
    if (option == 1) {
        cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "| No  |    Customer     |     Date     | Day |       Time      |    Services    |     Type      |  Expert Status   |" << endl;
        cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < bookingCount; ++i) {
            const auto& booking = bookings[i];
            cout << "| " << setw(3) << left << no++ << " | " << setw(15) << left << booking.customer_name << " | " << setw(12) << left << booking.date << " | "
                << setw(3) << left << booking.day << " | " << setw(15) << left << booking.time << " |  " << setw(13) << left << booking.services << " |  " << setw(13) << left
                << booking.type << "|  " << setw(15) << left << booking.expert_status << " |" << endl;
            cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "\nTake Leave? [Enter Y/N]: ";
        cin >> ch;
        while (ch != "n" && ch != "y" && ch != "Y" && ch != "N") {
            cout << "\n\033[31mPlease enter Y or N only.\033[0m" << endl;
            cout << "Take Leave? [Enter Y/N]: ";
            cin >> ch;
        }
        if (ch == "Y" || ch == "y") {
            expert_takeLeave_page(expertid, password);
            return;
        }
        else {
            expert_profile_page(expertid, password);
        }
    }
    else if (option == 2) {
        cout << " --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "| No  |   Expert    |    Customer     |     Date     | Day |       Time      |    Services    |      Type      | Customer Status |  Expert Status  |" << endl;
        cout << " --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < bookingCount; ++i) {
            const auto& booking = bookings[i];
            cout << "| " << setw(3) << left << no++ << " | " << setw(11) << left << booking.expert_name << " | " << setw(15) << left << booking.customer_name << " | "
                << setw(12) << left << booking.date << " | " << setw(3) << left << booking.day << " | " << setw(15) << left << booking.time << " |  " << setw(13) << left << booking.services << " |  "
                << setw(14) << left << booking.type << " | " << setw(14) << left << booking.customer_status << " |  " << setw(14) << left << booking.expert_status << " |" << endl;
            cout << " --------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    cout << "\n\nEnter 0 to exit this page: ";
    cin >> num;
    while (num != '0') {
        cout << "\n\033[31mPlease enter [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == '0') {
        expert_profile_page(expertid, password); // Assume this is defined elsewhere in your code
    }
}

void sales_report_page(const string& expertid, const char password[]) {
    logo();
    sales_report_logo();
    Booking bookings[MAX_BOOKINGS];
    int option = 2; // For example, to read all bookings
    int recordCount = readBookings("booking.txt", option, bookings, expertid, "");
    double total_amount = 0.0,total_deposit = 0.0;

    time_t t = time(nullptr);
    tm tmStruct = {};
    localtime_s(&tmStruct, &t);
    char buffer[12];
    strftime(buffer, sizeof(buffer), "%d-%b-%Y", &tmStruct);
    string currentDate(buffer);

    // Extract current month and year
    string targetMonth = currentDate.substr(3, 3);
    string targetYear = currentDate.substr(7, 4);

    Booking filteredBookings[MAX_BOOKINGS];
    int filteredCount = 0;

    cout << fixed << setprecision(2);

    // Filter bookings based on current date and status
    for (int i = 0; i < recordCount; ++i) {
        const auto& booking = bookings[i];

        // Check if the booking date is before the current date
        if (booking.date < currentDate && booking.customer_status == "Booked") {
            string month = booking.date.substr(3, 3);
            string year = booking.date.substr(7, 4);

            if (month == targetMonth && year == targetYear) {
                filteredBookings[filteredCount++] = booking; // Store relevant bookings
            }
        }
    }

    cout << "\033[1m\033[36mExpert ID: " << expertid << "\033[0m" << endl << endl;

    // Display the table header
    cout << " -------------------------------------------------------------------------------------------------------\n";
    cout << "| No  | Customer Name  |     Date     | Day |       Time      |  Services  | Amount (RM) | Deposit (RM) |\n";
    cout << " -------------------------------------------------------------------------------------------------------\n";

    // Display the filtered and sorted bookings
    for (int i = 0; i < filteredCount; ++i) {
        const auto& booking = filteredBookings[i];
        cout << "| " << setw(4) << left << (i + 1)
            << "| " << setw(14) << left << booking.customer_name
            << " |  " << setw(11) << left << booking.date
            << " | " << setw(3) << left << booking.day
            << " |  " << setw(14) << left << booking.time
            << " | " << setw(10) << left << booking.services
            << " | " << setw(11) << left << booking.amount
            << " | " << setw(12) << left << booking.amount*0.5 << " |\n";
        cout << " -------------------------------------------------------------------------------------------------------\n";
        total_amount += booking.amount;
        total_deposit += (booking.amount * 0.5);
    }

    cout << "\033[32mTotal amount: RM" << fixed << setprecision(2) << total_amount << "\033[0m" << endl;
    cout << "\033[32mTotal deposit: RM" << fixed << setprecision(2) << total_deposit << "\033[0m" << endl;

    // Count services for histogram generation
    map<string, int> serviceCounts;
    map<string, int> weekCounts;
    map<string, int> customerCounts;

    for (int i = 0; i < filteredCount; ++i) {
        const auto& booking = filteredBookings[i];
        serviceCounts[booking.services]++;
        weekCounts[booking.day]++;
        customerCounts[booking.customer_name]++;
    }

    // Find the week with the highest number of bookings
    string highestWeek;
    int maxWeekBookings = 0;
    for (const auto& entry : weekCounts) {
        if (entry.second > maxWeekBookings) {
            highestWeek = entry.first;
            maxWeekBookings = entry.second;
        }
    }

    cout << "\n\033[31m#\033[0m represents lowest record. " << endl;
    cout << "\n\033[32m#\033[0m represents highest record. " << endl;

    cout << "\n\nSales Report for " << targetMonth << " " << targetYear << ":\n";
    cout << "---------------------------------------------------\n";
    cout << "The highest bookings day in a week: " << highestWeek << " (" << maxWeekBookings << " bookings)\n";

    // Generate histograms
    generateColoredHistogram(serviceCounts, weekCounts, customerCounts, highestWeek);

    char num;
    cout << "\nEnter 0 to exit this page: ";
    cin >> num;
    while (num != '0') {
        cout << "\n\033[31mPlease enter [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }

    if (num == '0') {
        expert_profile_page(expertid, password); // Assuming this function is defined elsewhere
    }
}

void expert_takeLeave_page(const string& expertid, const char password[]) {
    char num;
    int option = 4, no = 1, slot;
    string new_status = "Leave";
    logo();
    take_leave_logo(); // Assume this is defined elsewhere in your code
    string filename = "booking.txt";
    Booking bookings[MAX_BOOKINGS];
    int bookingCount = readBookings(filename, option, bookings, expertid, "");
    bool validSlot;
    if (bookingCount == 0) {
        cout << "\033[31mNo bookings found for this expert.\033[0m" << endl;
        cin.get(); // Wait for user input
        expert_profile_page(expertid, password); // Assume this is defined elsewhere in your code
        return;
    }
    // Sort bookings by date using bubble sort
    bubbleSort(bookings, bookingCount); // Adjust bubbleSort to work with array and count
    cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| No  |    Customer     |     Date     | Day |       Time      |    Services    |      Type      |  Expert Status  |" << endl;
    cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < bookingCount; ++i) {
        const auto& booking = bookings[i];
        cout << "| " << setw(3) << left << no++ << " | " << setw(15) << left << booking.customer_name << " | " << setw(12) << left << booking.date << " | "
            << setw(3) << left << booking.day << " | " << setw(14) << left << booking.time << " |   " << setw(13) << left << booking.services << " |  " << setw(13) << left
            << booking.type << " | " << setw(15) << left << booking.expert_status << " |" << endl;
        cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
    }
    // Read expert details from login_expert.txt
    ifstream readExpert("login_expert.txt");
    if (!readExpert) { // or use inputFile.is_open()
        cerr << "\n\033[31mError: Could not open file login_expert.txt for reading.\033[0m" << endl;
    }
    else {
        string id, pass, email, contact, input;
        while (readExpert >> id >> pass >> email >> contact) {
            if (expertid == id) {
                cout << "\nExpert ID: " << expertid << "\nYour Email: " << email << endl;
                break;
            }
        }
        readExpert.close();
        cout << endl;
        cin.get();
        do {
            cout << "Choose the number that you want to take leave [0 to exit this page]: ";
            getline(cin, input);
            validSlot = check_digit(input, no);
            if (!validSlot) {
                cout << "\n\033[31mPlease enter a number between 0 and " << no - 1 << ".\033[0m" << endl;
                continue;
            }
        } while (!validSlot);
        slot = stoi(input);
        if (slot == 0) {
            expert_profile_page(expertid, password);
        }
        else {
            Booking selectedBooking = bookings[slot - 1];
            string date = selectedBooking.date, time = selectedBooking.time, type = selectedBooking.type, services = selectedBooking.services;
            // Update expert status to 'Leave' for the specific booking
            bool valid = updateToFile(filename, expertid, "", date, time, type, services, new_status, true, false, 0); // true indicates updating expert status
            if(valid) {
                logo();
                cout << "\n\033[32mLeave request successful!\033[0m" << endl;
            }
            else {
                logo();
                cout << "\n\033[31mLeave request failed.\033[0m" << endl;
            }
        }
    }
    cout << "\nEnter 0 to exit this page: ";
    cin >> num;
    while (num != '0') {
        cout << "\n\033[31mPlease enter [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == '0') {
        expert_profile_page(expertid, password); // Assume this is defined elsewhere in your code
    }
}

void view_customer(const string& expertid, const char password[]) {
    char pass[PASS_LENGTH];
    string name, user, email, contact, line,num;
    ifstream readCustomer("login_username.txt");
    logo();
    customer_logo();
    if (!readCustomer) { // or use inputFile.is_open()
        cerr << "\033[31mError: Could not open file expert_staff_contact.txt for reading.\033[0m" << endl;
    }
    else {
        cout << fixed << setprecision(1); // Set decimal precision for star rating
        cout << " -----------------------------------------------------------" << endl;
        cout << "|      Name       |        Email         |  Contact Number  |" << endl;
        cout << " -----------------------------------------------------------" << endl;
        // Read data from the file and print the table rows
        while (getline(readCustomer, name)) {
            if (getline(readCustomer, line)) {
                istringstream iss(line);
                if (iss >> user >> pass >> email >> contact) {
                    cout << "| " << setw(15) << left << name << " | " << setw(20) << left << email << " | " << setw(16) << left << "+60" + contact << " |" << endl;
                    cout << " -----------------------------------------------------------" << endl;
                }
                else {
                    cerr << "\n\033[31mError parsing line: \033[0m" << line << endl;
                }
            }
            else {
                cerr << "\n\033[31mError reading line for details.\033[0m" << endl;
            }
        }
        readCustomer.close();
    }
    cout << "\nEnter 0 to exit this page: ";
    cin >> num;
    while (num.length() != 1 || !check_char(num[0]) || (num != "0")) {
        cout << "\n\033[31mPlease enter numeric/digit only and [0] only.\033[0m" << endl;
        cout << "Enter 0 to exit this page: ";
        cin >> num;
    }
    if (num == "0") {
        expert_main_page(expertid, password);
    }
}

bool isEmpty(const string& str) {
    return str.empty();
}

bool isEmpty(char value) {
    return value == '\0'; // Assuming '\0' is considered "empty" or invalid
}