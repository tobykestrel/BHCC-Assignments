/*
Toby Hansen
April 22, 2026
SQL Programming
Chapter Thirteen Textbook Assignment
*/

/*Q1*/
create view DELAY as
select * from ORDERS 
where Shipdate is null;

/*Q2*/
create or replace view DELAY as
select * from ORDERS 
where Shipdate is null
with read only;

/*Q3*/
create view ORDERDETAILS as
select Order#, Customer#, Orderdate, Isbn, Quantity
from ORDERS inner join ORDERITEMS using (Order#);

/*Q5*/
create view REORDERINFO as
select Isbn, Title, Contact, Phone
from BOOKS inner join PUBLISHER using (PubId);

/*Q6*/
update REORDERINFO 
set Contact = 'Toby Hansen' 
where upper(Contact) = 'TOMMIE SEYMOUR';
/*I got an error saying "cannot modify a column which maps to a non key-preserved table"*/
/*This error happened because PUBLISHER is not a key-preserved table. Since one publisher can 
be associated with multiple books, the original table can't be updated through the view.*/

/*Q7*/
update REORDERINFO 
set Isbn = '1234567890' 
where Isbn = 1059831198;
/*I got an error saying "integrity constraint (ORDERITEMS_FK) violated - child record found"*/
/*This error is thrown because we are violating the foreign key constraint of another table.*/

/*Q8*/lete from REORDERINFO
where upper(Contact) = 'TOMMIE SEYMOUR';
/*I got an error saying "integrity constraint (BOOKAUTHOR_FK) violated - child record found"*/
/*This error is thrown because we are violating the foreign key constraint of another table.*/

/*Q9*/
rollback;