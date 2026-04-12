/*
Toby Hansen
April 12, 2026
SQL Programming
Chapter Five Textbook Assignment
*/

/*Q1*/
insert into ORDERS (Order#, Customer#, OrderDate)
values (2222, 2121, to_date('22-JAN-2016', 'DD-MON-YYYY'));
/*It causes a foreign key violation because the specified Customer# doesn't exist in the CUSTOMERS table*/
insert into ORDERS (Order#, Customer#, OrderDate)
values (2222, 1001, to_date('22-JAN-2016', 'DD-MON-YYYY'));

/*Q2 Create a script using  variables that allow the user to set a new retail price for a book 
based on ISBN. Run your script for the following values: ISBN = 1059831198, and retail = $99.99*/
update BOOKS 
set Retail = :NewRetailPrice 
where Isbn = :IsbnOfBookToModify;

/*Q3*/
select
    Fname || ' ' || Lname as "Author",
    Title as "Book Title",
    round(Retail * (1 - (to_number(:DiscountPercentage) / 100)), 2) as "Discounted Price"
from BOOKS 
    inner join BOOKAUTHOR using (Isbn)
    inner join AUTHOR using (AuthorId)
where upper(substr(Lname, 1, 4)) = upper(substr(:FirstFourLettersAuthorLName, 1, 4))
    and upper(substr(Fname, 1, 1)) = upper(substr(:FirstLetterAuthorFName, 1, 1));

/*Q4*/
insert into ORDERS (Order#, Customer#) 
values (1023, 1009);
/*It causes a not-null violation, because the OrderDate is a required field.*/
insert into ORDERS (Order#, Customer#, OrderDate) 
values (1023, 1009, to_date('22-JAN-2026', 'DD-MON-YYYY'));

/*Q5*/
delete from ORDERITEMS where Order# = 1005;
delete from ORDERS where Order# = 1005;