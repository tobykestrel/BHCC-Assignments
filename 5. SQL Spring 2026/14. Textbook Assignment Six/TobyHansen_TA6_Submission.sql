/*
Toby Hansen
April 12, 2026
SQL Programming
Chapter Six Textbook Assignment
*/

/*Q1*/
select max(nvl(Customer#,0))+1 as "Use this value in the start with clause" from CUSTOMERS;
create sequence startMaxCustomerId_incrementBy1_CUSTOMERS
start with 1021
increment by 1
nocache nocycle;

/*Q2*/
insert into CUSTOMERS (Customer#, Lastname, Firstname, Zip) 
values (startMaxCustomerId_incrementBy1_CUSTOMERS.nextval, 'Shoulders', 'Frank', 23567);

/*Q3*/
create sequence MY_FIRST_SEQ
start with 5
increment by -3
minvalue 0
maxvalue 5
nocycle;

/*Q4*/
select MY_FIRST_SEQ.nextval from DUAL;
select MY_FIRST_SEQ.nextval from DUAL;
select MY_FIRST_SEQ.nextval from DUAL;
/* The error is caused by attempting to generate a value (-1) that is less than 
the minvalue (0), and since the sequence has nocycle it can't wrap around.*/

/*Q5*/
alter sequence MY_FIRST_SEQ minvalue -1000;

/*Q6*/
create index Idx_DaysBetweenOrderAndShip on ORDERS (Shipdate-Orderdate);
/*I think that the order that haven't yet shipped aren't going 
to be in the index since they are null in the Shipdate column*/

/*Q7*/
create index Idx_BookProfit on Books (Retail-Cost);

/*Q8.1*/
create index Idx_CustomerLastname on CUSTOMERS (Lastname);

/*Q8.2*/
select index_name
from user_indexes
where table_name = 'CUSTOMERS';

/*Q8.3*/
drop index Idx_CustomerLastname;