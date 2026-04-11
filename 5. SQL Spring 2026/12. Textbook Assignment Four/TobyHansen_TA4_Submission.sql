/*
Toby Hansen
April 10, 2026
SQL Programming
Chapter Four Textbook Assignment
*/

/*Q1*/
create table CONTACTS (
    ContactId number(2),
    ContactName varchar2(255),
    ContactPhoneNumber varchar2(20),
    ContactJobPosition varchar2(255)
);

/*Q2*/
alter table CONTACTS
add constraint PK_CONTACTS primary key (ContactId);

/*Q3*/
alter table CONTACTS
modify (
    ContactName not null,
    ContactJobPosition not null
);

/*Q4*/
alter table CONTACTS
add ContactSalary number(8,2);
alter table CONTACTS
add constraint CK_SALARY check (ContactSalary > 0);

/*Q5*/
alter table PUBLISHER
add ContactId number(2);

/*Q6*/
alter table PUBLISHER
add constraint FK_PUBLISHER_CONTACTS foreign key (ContactId) references CONTACTS(ContactId);

/*Q7*/
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