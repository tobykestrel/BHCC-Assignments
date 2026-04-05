/*
Toby Hansen
April 4, 2026
SQL Programming
Chapter Three Textbook Assignment
*/

/*Q1 Create a new CATEGORY table for the JustLee Bookstore database. It should have the following fields:
- Category_code: 2-digit auto-incremented (more on this later, you do not need 
to specify anything yet for this column) number (this will be your Primary key)
- Category_title: 10 characters or less containing a brief description like “Cooking”
- Category_description: a variable-length description, which will contain things like “Cookbooks, healthy 
eating, and special diet advice” or “Computer and related technology including textbooks and training material”.*/
create table CATEGORY (
    Category_code number(2) primary key,
    Category_title varchar2(10) not null,
    Category_description varchar2(255)
);

/* Also, complete the following Hands-On Assignments from your textbook on page 97
Questions 2, 3, 4, 5, 6 table name should include your initials, for example: employees_dv*/

/*Q2 Create a new table containing these four columns: Emp#, Lastname, Firstname, and Job_class. 
The table name should be EMPLOYEES. The Job_class column should be able to store character 
strings up to a maximum length of four, but the column values shouldn’t be padded if the value 
has less than four characters. The Emp# column contains a numeric ID and should allow a five-
digit number. Use column sizes you consider suitable for the Firstname and Lastname columns.*/
create table EMPLOYEES_TH (
    Emp# number(5) primary key,
    Lastname varchar2(20) not null,
    Firstname varchar2(20) not null,
    Job_class varchar2(4)
);

/*Q3 Add two columns to the EMPLOYEES table. One column, named EmpDate, contains 
the date of employment for each employee, and its default value should be the system 
date. The second column, named EndDate, contains employees’ date of termination.*/
alter table EMPLOYEES_TH 
add (
    Empdate date default sysdate not null,
    Enddate date
);

/*Q4 Modify the Job_class column of the EMPLOYEES table so 
that it allows storing a maximum width of two characters.*/
alter table EMPLOYEES_TH 
modify Job_class varchar2(2);
/*If the table already had data, then a statement would have to be run prior to shorten the data.*/
update EMPLOYEES_TH 
set Job_class = SUBSTR(Job_class, 1, 2) 
where length(Job_class) > 2;

/*Q5 Delete the EndDate column from the EMPLOYEES table.*/
alter table EMPLOYEES_TH
drop column Enddate;

/*Q6 Rename the EMPLOYEES table as JL_EMPS.*/
rename EMPLOYEES_TH to JL_EMPS;

/*Questions 7, 8, 9, 10 Make sure you VERIFY your tables and include a 
query to do that in your answers, e. g. SELECT or DESCRIBE statement*/

/*Q7  Create a new table containing these four columns from the existing BOOKS table: 
ISBN, Cost, Retail, and Category. The name of the ISBN column should be ID, and the 
other columns should keep their original names. Name the new table BOOK_PRICING.*/ 
create table BOOK_PRICING as select
    Isbn as Id,
    Cost,
    Retail,
    Category
from BOOKS;
alter table BOOK_PRICING
add constraint BOOK_PRICING_PK primary key (Id);
desc BOOK_PRICING;

/*Q8 Mark the Category column of the BOOK_PRICING table as unused. 
Verify that the column is no longer available.*/ 
alter table BOOK_PRICING SET UNUSED COLUMN Category;
desc BOOK_PRICING;

/*Q9 Truncate the BOOK_PRICING table, and then verify that 
the table still exists but no longer contains any data.*/ 
truncate table BOOK_PRICING;
select * from BOOK_PRICING;

/*Q10.1 Delete the BOOK_PRICING table permanently so that it isn’t moved to the recycle bin.*/
drop table BOOK_PRICING purge;
desc BOOK_PRICING;

/*Q10.2 Delete the JL_EMPS table so that it can be restored. 
Restore the JL_EMPS table and verify that it’s available again.*/ 
drop table JL_EMPS;
desc JL_EMPS;
flashback table JL_EMPS to before drop;
desc JL_EMPS;