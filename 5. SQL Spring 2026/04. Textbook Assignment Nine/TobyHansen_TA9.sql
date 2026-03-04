/*
Toby Hansen
February 26, 2026
SQL Programming
Chapter Nine Textbook Assignment
*/

/*1a.*/
select Title as "Book Title", 
    Name as "Publisher Name",
    Contact as "Contact Name",
    Phone as "Contact Phone#"
from BOOKS, PUBLISHER
where BOOKS.PubID = PUBLISHER.PubID
    and Retail < 100
    and (Category = 'computer'
        or Category = 'Computer'
        or Category = 'COMPUTER');
        
/*1b.*/
select Title as "Book Title", 
    Name as "Publisher Name",
    Contact as "Contact Name",
    Phone as "Contact Phone#"
from BOOKS
inner join PUBLISHER on BOOKS.PubID = PUBLISHER.PubID
where Retail < 100
    and (Category = 'computer'
        or Category = 'Computer'
        or Category = 'COMPUTER');

/*2a.*/
select Title as "Book Title", 
    Firstname || ' ' || Lastname as "Customer Name"
from BOOKS, ORDERITEMS, ORDERS, CUSTOMERS
where BOOKS.Isbn = ORDERITEMS.Isbn(+)
    and ORDERITEMS.Order# = ORDERS.Order#(+)
    and ORDERS.Customer# = CUSTOMERS.Customer#(+)
order by Title;

/*2b.*/
select Title as "Book Title", 
    Firstname || ' ' || Lastname as "Customer Name"
from BOOKS
left join ORDERITEMS on BOOKS.Isbn = ORDERITEMS.Isbn
left join ORDERS on ORDERITEMS.Order# = ORDERS.Order#
left join CUSTOMERS on ORDERS.Customer# = CUSTOMERS.Customer#
order by Title;

/*3a.*/
select distinct Name as "Publishers With No Cooking Books"
from PUBLISHER
minus
select distinct Name
from PUBLISHER, BOOKS
where PUBLISHER.PubID = BOOKS.PubID
    and (Category = 'cooking'
        or Category = 'Cooking'
        or Category = 'COOKING');

/*3b.*/
select distinct Name as "Publishers With No Cooking Books"
from PUBLISHER
minus
select distinct Name
from PUBLISHER
inner join BOOKS on PUBLISHER.PubID = BOOKS.PubID
where Category = 'cooking'
    or Category = 'Cooking'
    or Category = 'COOKING';

/*4a.*/
select BOOKS.Isbn, 
    Title as "Book Title",
    listagg(Lname, ', ') 
        within group (order by Lname) 
        as "Author Last Name(s)",
    Retail as "Retail Price",
    Gift as "Promotional Gift"
from BOOKS, BOOKAUTHOR, AUTHOR, PROMOTION
where BOOKS.Isbn = BOOKAUTHOR.Isbn
    and BOOKAUTHOR.AuthorID = AUTHOR.AuthorID
    and BOOKS.Retail >= PROMOTION.Minretail(+)
    and BOOKS.Retail <= PROMOTION.Maxretail(+)
group by BOOKS.Isbn, Title, Retail, Gift
order by Title;

/*4b*/
select BOOKS.Isbn, 
    Title as "Book Title",
    listagg(Lname, ', ') 
        within group (order by Lname) 
        as "Author Last Name(s)",
    Retail as "Retail Price",
    Gift as "Promotional Gift"
from BOOKS
inner join BOOKAUTHOR on BOOKS.Isbn = BOOKAUTHOR.Isbn
inner join AUTHOR on BOOKAUTHOR.AuthorID = AUTHOR.AuthorID
left join PROMOTION 
    on BOOKS.Retail >= PROMOTION.Minretail
    and BOOKS.Retail <= PROMOTION.Maxretail
group by BOOKS.Isbn, Title, Retail, Gift
order by Title;

/*5a*/
select
    e1.Fname || ' ' || e1.Lname as "Employee Name",
    e1.Job as "Job Title",
    e2.Fname || ' ' || e2.Lname as "Manager Name"
from JL_EMPLOYEES e1, JL_EMPLOYEES e2
where e1.Mgr = e2.Empno(+)
order by e2.Fname, e2.Lname;

/*5b*/
select
    e1.Fname || ' ' || e1.Lname as "Employee Name",
    e1.Job as "Job Title",
    e2.Fname || ' ' || e2.Lname as "Manager Name"
from JL_EMPLOYEES e1
left join JL_EMPLOYEES e2 on e1.Mgr = e2.Empno
order by e2.Fname, e2.Lname;

/*6.1a*/
select 
    Title as "Book Title",
    Name as "Publisher Name",
    Retail-Cost as "Profit Amount",
    Gift as "Promotional Gift"
from BOOKS, PUBLISHER, PROMOTION
where BOOKS.PubID = PUBLISHER.PubID
    and BOOKS.Retail >= PROMOTION.Minretail
    and BOOKS.Retail <= PROMOTION.Maxretail
order by Name;

/*6.1b*/
select 
    Title as "Book Title",
    Name as "Publisher Name",
    Retail-Cost as "Profit Amount",
    Gift as "Promotional Gift"
from BOOKS
inner join PUBLISHER on BOOKS.PubID = PUBLISHER.PubID
inner join PROMOTION 
    on BOOKS.Retail >= PROMOTION.Minretail
    and BOOKS.Retail <= PROMOTION.Maxretail
order by Name;

/*6.2a*/
select Isbn as "ISBNs That Have Not Sold"
from BOOKS
minus
select BOOKS.Isbn as "ISBN"
from BOOKS, ORDERITEMS, ORDERS
where ORDERITEMS.Isbn = BOOKS.Isbn
    and ORDERS.Order# = ORDERITEMS.Order#;

/*6.2b*/
select Isbn as "ISBNs That Have Not Sold"
from BOOKS
minus
select BOOKS.Isbn as "ISBN"
from BOOKS
inner join ORDERITEMS on ORDERITEMS.Isbn = BOOKS.Isbn
inner join ORDERS on ORDERS.Order# = ORDERITEMS.Order#;

/*6.2c Much simpler version without joins*/
select Isbn as "ISBNs That Have Not Sold"
from BOOKS
minus
select Isbn
from ORDERITEMS;