/*
Toby Hansen
March 29, 2026
SQL Programming
Chapter Twelve Textbook Assignment
*/

/*Q1*/
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

/*Q2.v1 (Correlated Subquery)*/
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

/*Q2.v2 (Non-Correlated Subquery)*/
select 
    Fname || ' ' || Lname as "Authors who have a book with no orders",
    Title as "Title of book with no orders",
    Isbn as "ISBN"
from AUTHOR 
    inner join BOOKAUTHOR using (Authorid)
    inner join BOOKS using (Isbn)
where Isbn not in (select Isbn from ORDERITEMS)
order by Fname, Lname, Title;

/*Q3*/
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

/*Q4*/
select 
    Name as "Name Of The Publisher(s) Who Have Published The Most Books",
    count(*) as "Amount Of Books Published"
from PUBLISHER inner join BOOKS using (Pubid)
group by Name
having count(*) = (
    select max(count(*)) 
    from BOOKS group by Pubid
);

/*Q5*/
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

/*Q6*/
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

/*Q7*/
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

/*Q8{Custom} List the customers who placed an order for the most expensive 
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