/*
Toby Hansen
March 29, 2026
SQL Programming
Chapter Twelve Textbook Assignment
*/

/*Q1 List the first name and the last name of each customer who placed 
more than the average number of orders. Along with the names, show the 
total each of the listed customers paid on all orders he or she placed.*/
select 
    c.Firstname || ' ' || c.Lastname as "Customer Name",
    c.Customer# as "Customer ID",
    count(distinct o.Order#) as "Orders Placed",
    sum(oi.Quantity*oi.Paideach) as "Total Spent"
from CUSTOMERS c
    inner join ORDERS o on c.Customer# = o.Customer#
    inner join ORDERITEMS oi on o.Order# = oi.Order#
group by c.Customer#, c.Firstname, c.Lastname
having count(distinct o.order#) > (
    select avg("orderCount") from (
        select count(*) as "orderCount"
        from ORDERS
        group by Customer#
    )
)
order by "Orders Placed" desc, c.Customer#;

/*Q2.v1 Use a CORRELATED subquery to show which authors' books have not been ordered.*/
select 
    a.Fname || ' ' || a.Lname as "Authors who have a book with no orders",
    b.Title as "Title of book with no orders",
    b.Isbn as "ISBN"
from AUTHOR a
    inner join BOOKAUTHOR ba on a.Authorid = ba.Authorid
    inner join BOOKS b on ba.Isbn = b.Isbn
where not exists (
    select *
    from ORDERITEMS oi
    where oi.Isbn = b.Isbn
)
order by a.Fname, a.Lname, b.Title;

/*Q2.v2 Use a NON-CORRELATED subquery to show which authors' books have not been ordered.*/
select 
    Fname || ' ' || Lname as "Authors who have a book with no orders",
    Title as "Title of book with no orders",
    Isbn as "ISBN"
from AUTHOR 
    inner join BOOKAUTHOR using (Authorid)
    inner join BOOKS using (Isbn)
where Isbn not in (select Isbn from ORDERITEMS)
order by Fname, Lname, Title;

/*Q3 List the customers who placed an order for the least expensive 
book, include the title and price of the book in your output.*/
select
    Firstname || ' ' || Lastname as "Customer Name",
    Title as "Title Of Book",
    Retail as "Price Of Book To Customer"
from CUSTOMERS 
    inner join ORDERS using (Customer#)
    inner join ORDERITEMS using (Order#)
    inner join BOOKS using (Isbn)
where Retail = (select min(Retail) from BOOKS)
order by "Customer Name", Title;

/*Q4 List the name of the publisher(s) that published most books.*/
select 
    Name as "Name Of The Publisher(s) Who Have Published The Most Books",
    count(*) as "Amount Of Books Published"
from PUBLISHER inner join BOOKS using (Pubid)
group by Name
having count(*) = (
    select max(count(*)) 
    from BOOKS group by Pubid
);

/*Q5 Complete Q5 from textbook page 493. Total quantities 
per ISBN (orderitems table) for your subquery. */
/*Determine which author or authors wrote the books 
most frequently purchased by customers of JustLee Books*/
select 
    Fname || ' ' || Lname as "Author Name",
    Title as "Title of Book(s) most frequently sold at JustLee",
    sum(Quantity) as "Copies Sold"
from AUTHOR 
    inner join BOOKAUTHOR using (Authorid)
    inner join BOOKS using (Isbn)
    inner join ORDERITEMS using (Isbn)
group by Fname || ' ' || Lname, Title
having sum(Quantity) = (
    select max(sum(Quantity)) 
    from ORDERITEMS 
    group by Isbn
)
order by "Copies Sold" desc, Title;

/*Q6 List titles of books in the same category as books ordered 
by Giana Tammy. Do not list the books she already ordered.*/
select 
    Title as "Books that Giana Tammy has not ordered that share a category with a book she has ordered",
    Category
from BOOKS
where Category in ( 
        select distinct Category
        from BOOKS 
            inner join ORDERITEMS using (Isbn)
            inner join ORDERS using (Order#)
            inner join CUSTOMERS using (Customer#)
        where upper(Firstname) = 'TAMMY'
            and upper(Lastname) = 'GIANA'
    ) 
    and Isbn not in (
        select distinct Isbn
        from ORDERITEMS
            inner join ORDERS using (Order#)
            inner join CUSTOMERS using (Customer#)
        where upper(Firstname) = 'TAMMY'
            and upper(Lastname) = 'GIANA'
    )
order by Category, Title;

/*Q7 It looks like someone is generating orders with stolen account numbers. The credit 
card company says they repeat orders for the same amount. JustLee knows that order 1003 is 
one of the fraudulent ones and needs to find other orders for the same amount to check on 
them, too. Show orders (calculate total order) that are for the same amount as order 1003.*/
select 
    Order#,
    sum(Quantity*Paideach) as "Order Total"
from ORDERITEMS
group by Order#
having sum(Quantity*Paideach) = (
    select sum(Quantity*Paideach)
    from ORDERITEMS
    where Order# = 1003
);

/*Q8 Create your own (original) question and write a sub-query for the report.*/
/*List the customers who placed an order for the most expensive 
book(s), include the title and price of the book(s) in your output.*/
select
    Firstname || ' ' || Lastname as "Customer Name",
    Title as "Title Of Book",
    Retail as "Price Of Book To Customer"
from CUSTOMERS 
    inner join ORDERS using (Customer#)
    inner join ORDERITEMS using (Order#)
    inner join BOOKS using (Isbn)
where Retail = (select max(Retail) from BOOKS)
order by "Customer Name", Title;