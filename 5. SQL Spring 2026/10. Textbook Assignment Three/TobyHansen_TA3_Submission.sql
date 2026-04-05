/*
Toby Hansen
April 4, 2026
SQL Programming
Chapter Three Textbook Assignment
*/

/*Q1*/
create table CATEGORY (
    Category_code number(2) primary key,
    Category_title varchar2(10) not null,
    Category_description varchar2(255)
);

/*Q2*/
create table EMPLOYEES_TH (
    Emp# number(5) primary key,
    Lastname varchar2(20) not null,
    Firstname varchar2(20) not null,
    Job_class varchar2(4)
);

/*Q3*/
alter table EMPLOYEES_TH 
add (
    Empdate date default sysdate not null,
    Enddate date
);

/*Q4*/
alter table EMPLOYEES_TH 
modify Job_class varchar2(2);
/*If the table already had data, then a statement would have to be run prior to shorten the data.*/
update EMPLOYEES_TH 
set Job_class = SUBSTR(Job_class, 1, 2) 
where length(Job_class) > 2;

/*Q5*/
alter table EMPLOYEES_TH
drop column Enddate;

/*Q6*/
rename EMPLOYEES_TH to JL_EMPS;

/*Q7*/ 
create table BOOK_PRICING as select
    Isbn as Id,
    Cost,
    Retail,
    Category
from BOOKS;
alter table BOOK_PRICING
add constraint BOOK_PRICING_PK primary key (Id);
desc BOOK_PRICING;

/*Q8*/ 
alter table BOOK_PRICING SET UNUSED COLUMN Category;
desc BOOK_PRICING;

/*Q9*/ 
truncate table BOOK_PRICING;
select * from BOOK_PRICING;

/*Q10.1*/
drop table BOOK_PRICING purge;
desc BOOK_PRICING;

/*Q10.2*/ 
drop table JL_EMPS;
desc JL_EMPS;
flashback table JL_EMPS to before drop;
desc JL_EMPS;