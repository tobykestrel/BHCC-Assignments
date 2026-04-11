/*
Toby Hansen
April 10, 2026
SQL Programming
Chapter Four Textbook Assignment
*/

/*Q1 Create a new database table for JustLee store. This table will contain information about the JustLee publisher contacts. The following fields are required but you can name them as you feel appropriate:
Contact code: 2 digit unique number
Contact name: variable-length field containing first and last names (may be two columns)
Contact phone number: fixed or variable-length string containg phone number.
Contact position: variable length field will contain job description, e.g. manager, operator, data entry clerk, etc.*/
create table CONTACTS (
    ContactId number(2),
    ContactName varchar2(255),
    ContactPhoneNumber varchar2(20),
    ContactJobPosition varchar2(255)
);

/*Q2 Add a primary key to the contacts table you have created in your prior assignment so that all contact codes store unique two-digit values.*/
alter table CONTACTS
add constraint PK_CONTACTS primary key (ContactId);

/*Q3 Change your contacts table so NULL values can not be entered for the name and position columns.*/
alter table CONTACTS
modify (
    ContactName not null,
    ContactJobPosition not null
);

/*Q4 Add a column to the contacts table that stores contact salary. The column should have a datatype of NUMBER (8, 2) and use the constraint to ensure the amount entered is above zero.*/
alter table CONTACTS
add ContactSalary number(8,2);
alter table CONTACTS
add constraint CK_SALARY check (ContactSalary > 0);

/*Q5 Add a new column for the 2-digit contact code in the PUBLISHER table.*/
alter table PUBLISHER
add ContactId number(2);

/*Q6 Add a foreign key constraint between your contacts table and PUBLISHER table.*/
alter table PUBLISHER
add constraint FK_PUBLISHER_CONTACTS foreign key (ContactId) references CONTACTS(ContactId);

/*Note: We can later eliminate contact and phone columns from PUBLISHER table 
once we move all our contact information to a newly created table for publisher 
contacts and will only leave a code column in PUBLISHER to look up the names, 
phones, and positions of the contacts associated with each publisher.*/


/*Q7 Advanced Challenge on page 139*/
create table PROJECT (
    Proj# number constraint PK_PROJECT primary key, 
    P_name varchar2(255) not null constraint UQ_PROJECT_NAME unique,
    P_desc varchar2(255),
    P_budget number
);

create table WORKORDERS (
    Wo# number constraint PK_WORKORDERS primary key,
    Proj# number not null constraint FK_WORKORDERS_PROJECT references PROJECT(Proj#),
    Wo_desc varchar2(255) not null constraint UQ_WORKORDERS_DESC unique,
    Wo_assigned varchar2(255),
    Wo_hours number not null constraint CK_WORKORDERS_HOURS check (Wo_hours > 0),
    Wo_start date,
    Wo_due date,
    Wo_complete char constraint CK_WORKORDERS_COMPLETE check (Wo_complete in ('Y', 'N'))
);