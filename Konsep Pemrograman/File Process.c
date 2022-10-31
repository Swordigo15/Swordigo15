struct clientData {
9 int account;
10 char lastName[15];
11 char firstName[10];
12 double balance;
13 }; 

// prototypes
16 int enterChoice(void);
17 void textFile(FILE *readPtr);
18 void updateRecord(FILE *fPtr);
19 void newRecord(FILE *fPtr);
20 void deleteRecord(FILE *fPtr);
21
22 int main(void) {
23 FILE *cfPtr = NULL; // accounts.dat file pointer
24
25 // fopen opens the file; exits if file cannot be opened
26 if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {
27 puts("File could not be opened.");
28 }
29 else {
30 int choice = 0; // user
31
32 // enable user to specify action
33 while ((choice = enterChoice()) != 5) {
34 switch (choice) {
35 case 1: // create text file from record file
36 textFile(cfPtr);
37 break;
38 case 2: // update record
39 updateRecord(cfPtr);
40 break;
41 case 3: // create record
42 newRecord(cfPtr);
43 break;
44 case 4: // delete existing record
45 deleteRecord(cfPtr);
46 break;
47 default: // display message for invalid choice
48 puts("Incorrect choice");
49 break;
50 }
51 }
52
53 fclose(cfPtr); // fclose closes the file
54 }
55 }
56
57 // create formatted text file for printing
58 void textFile(FILE *readPtr) {
59 FILE *writePtr = NULL; // accounts.txt file pointer
60
61 // fopen opens the file; exits if file cannot be opened
62 if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
63 puts("File could not be opened.");
64 } else {
66 rewind(readPtr); // sets pointer to beginning of file
67 fprintf(writePtr, "%-6s%-16s%-11s%10s\n",
68 "Acct", "Last Name", "First Name","Balance");
69
70 // copy all records from random-access file into text file
71 while (!feof(readPtr)) {
72 // create clientData with default information
73 struct clientData client = {0, "", "", 0.0};
74 size_t result =
75 fread(&client, sizeof(struct clientData), 1, readPtr);
76
77 // write single record to text file
78 if (result != 0 && client.account != 0) {
79 fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.account,
80 client.lastName, client.firstName, client.balance);
81 }
82 }
83
84 fclose(writePtr); // fclose closes the file
85 }
86 }
87
88 // update balance in record
89 void updateRecord(FILE *fPtr) {
90 // obtain number of account to update
91 printf("%s", "Enter account to update (1 - 100): ");
92 int account = 0; // account number
93 scanf("%d", &account);
94
95 // move file pointer to correct record in file
96 fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
97
98 // read record from file
99 struct clientData client = {0, "", "", 0.0};
100 fread(&client, sizeof(struct clientData), 1, fPtr);
101
102 // display error if account does not exist
103 if (client.account == 0) {
104 printf("Account #%d has no information.\n", account);
105 }
106 else { // update record
107 printf("%-6d%-16s%-11s%10.2f\n\n", client.account, client.lastName,
108 client.firstName, client.balance);
109
110 // request transaction amount from user
111 printf("%s", "Enter charge (+) or payment (-): ");
112 double transaction = 0.0; // transaction amount
113 scanf("%lf", &transaction);
114 client.balance += transaction; // update record balance
    116 printf("%-6d%-16s%-11s%10.2f\n", client.account, client.lastName,
117 client.firstName, client.balance);
118
119 // move file pointer to correct record in file
120 fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
121
122 // write updated record over old record in file
123 fwrite(&client, sizeof(struct clientData), 1, fPtr);
124 }
125 }
126
127 // create and insert record
128 void newRecord(FILE *fPtr) {
129 // obtain number of account to create
130 printf("%s", "Enter new account number (1 - 100): ");
131 int account = 0; // account number
132 scanf("%d", &account);
133
134 // move file pointer to correct record in file
135 fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
136
137 // read record from file
138 struct clientData client = {0, "", "", 0.0};
139 fread(&client, sizeof(struct clientData), 1, fPtr);
140
141 // display error if account already exists
142 if (client.account != 0) {
143 printf("Account #%d already contains information.\n",
144 client.account);
145 }
146 else { // create record
147 // user enters last name, first name and balance
148 printf("%s", "Enter lastname, firstname, balance\n? ");
149 scanf("%14s%9s%lf", &client.lastName, &client.firstName,
150 &client.balance);
151
152 client.account = account;
153
154 // move file pointer to correct record in file
155 fseek(fPtr, (client.account - 1) * sizeof(struct clientData),
156 SEEK_SET);
157
158 // insert record in file
159 fwrite(&client, sizeof(struct clientData), 1, fPtr);
160 }
161 }
162
163 // delete an existing record
164 void deleteRecord(FILE *fPtr) {
165 // obtain number of account to delete
166 printf("%s", "Enter account number to delete (1 - 100): ");
167 int account = 0; // account number
168 scanf("%d", &account);
   169
170 // move file pointer to correct record in file
171 fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
172
173 // read record from file
174 struct clientData client = {0, "", "", 0.0};
175 fread(&client, sizeof(struct clientData), 1, fPtr);
176
177 // display error if record does not exist
178 if (client.account == 0) {
179 printf("Account %d does not exist.\n", account);
180 }
181 else { // delete record
182 // move file pointer to correct record in file
183 fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
184
185 struct clientData blankClient = {0, "", "", 0}; // blank client
186
187 // replace existing record with blank record
188 fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
189 }
190 }
191
192 // enable user to input menu choice
193 int enterChoice(void) {
194 // display available options
195 printf("%s", "\nEnter your choice\n"
196 "1 - store a formatted text file of accounts called\n"
197 " \"accounts.txt\" for printing\n"
198 "2 - update an account\n"
199 "3 - add a new account\n"
200 "4 - delete an account\n"
201 "5 - end program\n? ");
202
203 int menuChoice = 0; // variable to store user
204 scanf("%d", &menuChoice); // receive choice from user
205 return menuChoice;
206 } 
