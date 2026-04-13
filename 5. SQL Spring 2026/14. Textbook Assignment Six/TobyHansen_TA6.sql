/*
Toby Hansen
April 12, 2026
SQL Programming
Chapter Six Textbook Assignment
*/

/*Q1 Create a sequence for populating the Customer# column of the CUSTOMERS table. When setting the start 
and increment values, keep in mind that data already exists in this table. The options should be set to 
not cycle the values and not cache any values, and no minimum or maximum values should be declared.*/
select max(nvl(Customer#,0))+1 as "Use this value in the start with clause" from CUSTOMERS;
create sequence startMaxCustomerId_incrementBy1_CUSTOMERS
start with 1021
increment by 1
nocache nocycle;

/*Q2 Add a new customer row by using the sequence created in Q1. The only data currently available 
for the customer is as follows: last name = Shoulders, first name = Frank, and zip = 23567*/
insert into CUSTOMERS (Customer#, Lastname, Firstname, Zip) 
values (startMaxCustomerId_incrementBy1_CUSTOMERS.nextval, 'Shoulders', 'Frank', 23567);

/*Q3 Create a sequence that generates integers starting with the value 5. Each value should 
be three less than the previous value generated. The lowest possible value should be 0, and
the sequence shouldn’t be allowed to cycle. Name the sequence MY_FIRST_SEQ.*/
create sequence MY_FIRST_SEQ
start with 5
increment by -3
minvalue 0
maxvalue 5
nocycle;

/*Q4 Issue a SELECT statement that displays NEXTVAL for MY_FIRST_SEQ three times. 
Because the value isn’t being placed in a table, use the DUAL table in the FROM 
clause of the SELECT statement. What causes the error on the third SELECT?*/
select MY_FIRST_SEQ.nextval from DUAL;
select MY_FIRST_SEQ.nextval from DUAL;
select MY_FIRST_SEQ.nextval from DUAL;
/* The error is caused by attempting to generate a value (-1) that is less than 
the minvalue (0), and since the sequence has nocycle it can't wrap around.*/

/*Q5 Change the setting of MY_FIRST_SEQ so that the minimum value that can be generated is -1000.*/
alter sequence MY_FIRST_SEQ minvalue -1000;

/*Q6 Add an index on the number of days it took to ship the order. 
What do you think about the orders that have not yet shipped?*/
create index Idx_DaysBetweenOrderAndShip on ORDERS (Shipdate-Orderdate);
/*I think that the order that haven't yet shipped aren't going 
to be in the index since they are null in the Shipdate column*/

/*Q7 Add an index on the profit that each book might generate based on cost and retail price.*/
create index Idx_BookProfit on Books (Retail-Cost);

/*Q8.1 Create a B-tree index on the customer's lastname.*/
create index Idx_CustomerLastname on CUSTOMERS (Lastname);

/*Q8.2 Verify that it exists by querying the data dictionary.*/
select index_name
from user_indexes
where table_name = 'CUSTOMERS';

/*Q8.3 Remove the index from the database.*/
drop index Idx_CustomerLastname;