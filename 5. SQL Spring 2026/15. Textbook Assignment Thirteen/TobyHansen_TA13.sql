/*
Toby Hansen
April 22, 2026
SQL Programming
Chapter Thirteen Textbook Assignment
*/

/*Q1 Create a view called DELAY with all of the information stored in ORDERS 
table for all orders that have not yet shipped (shipdate is NULL).*/
create view DELAY as
select * from ORDERS 
where Shipdate is null;

/*Q2 Change the DELAY view so users are not able to perform any DML operations on the view.*/
create or replace view DELAY as
select * from ORDERS 
where Shipdate is null
with read only;

/*Q3 Create a VIEW called ORDERDETAILS that contains the Order#, Customer#, and Orderdate 
from the Orders table, joined to the ISBN and Quantity from the OrderItems table.*/
create view ORDERDETAILS as
select Order#, Customer#, Orderdate, Isbn, Quantity
from ORDERS inner join ORDERITEMS using (Order#);

/*Complete Questions 5, 6, 7, 8, 9 on pages 537-538 of your textbook.*/

/*Q5 Create a view that lists the ISBN and title for each book in inventory along with the name
and phone number of the person to contact if the book needs to be reordered. Name the
view REORDERINFO.*/
create view REORDERINFO as
select Isbn, Title, Contact, Phone
from BOOKS inner join PUBLISHER using (PubId);

/*Q6 Try to change the name of a contact person in the REORDERINFO view to your name.
Was an error message displayed when performing this step? If so, what was the cause
of the error message?*/
update REORDERINFO 
set Contact = 'Toby Hansen' 
where upper(Contact) = 'TOMMIE SEYMOUR';
/*I got an error saying "cannot modify a column which maps to a non key-preserved table"*/
/*This error happened because PUBLISHER is not a key-preserved table. Since one publisher can 
be associated with multiple books, the original table can't be updated through the view.*/

/*Q7 Select one of the books in the REORDERINFO view and try to change its ISBN. Was an error
message displayed when performing this step? If so, what was the cause of the error message?*/
update REORDERINFO 
set Isbn = '1234567890' 
where Isbn = 1059831198;
/*I got an error saying "integrity constraint (ORDERITEMS_FK) violated - child record found"*/
/*This error is thrown because we are violating the foreign key constraint of another table.*/

/*Q8 Delete the record in the REORDERINFO view containing your name. (If you weren’t able to
perform #6 successfully, delete one of the contacts already listed in the table.) Was an error
message displayed when performing this step? If so, what was the cause of the error message?*/
delete from REORDERINFO
where upper(Contact) = 'TOMMIE SEYMOUR';
/*I got an error saying "integrity constraint (BOOKAUTHOR_FK) violated - child record found"*/
/*This error is thrown because we are violating the foreign key constraint of another table.*/

/*Q9 Issue a rollback command to undo any changes made with the preceding DML operations.*/
rollback;