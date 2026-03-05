/*
Toby Hansen
March 4, 2026
SQL Programming
Chapter Ten Textbook Assignment
*/

/*Q1*/
select
    Category as "Category Name",
    count(*) as "Category Amount"
from BOOKS
where lower(Category) = 'computer'
group by Category;

/*Q2*/
select
    Fname || ' ' || Lname as "Author",
    count(Isbn) as "Books Written"
from AUTHOR 
inner join BOOKAUTHOR using (AuthorID)
group by Lname, Fname
order by Lname, Fname;

/*Q3*/
select sum(Paideach*Quantity) as "Total Paid For Order 1009"
from ORDERITEMS
where Order# = 1009;

/*Q4*/
select
    Category as "Category",
    avg(Retail) as "Average Retail Price"
from BOOKS
where lower(Category) = 'children' 
    or lower(Category) = 'business'
group by Category;

/*Q5*/
select
    Firstname || ' ' || Lastname as "Customer Name",
    Order# as "Order#",
    sum(Paideach*Quantity) as "Order Total"
from ORDERITEMS
inner join ORDERS using (Order#)
inner join CUSTOMERS using (Customer#)
where State = 'NJ' 
    or State = 'FL'
group by Order#, Firstname, Lastname
having sum(Paideach*Quantity) > 30
order by Order#;
/*In case having isn't allowed, and nesting was expected:*/
select * 
from (
    select
        Firstname || ' ' || Lastname as "Customer Name",
        Order# as "Order#",
        sum(Paideach*Quantity) as "Order Total"
    from ORDERITEMS
    inner join ORDERS using (Order#)
    inner join CUSTOMERS using (Customer#)
    where State = 'NJ' 
        or State = 'FL'
    group by Order#, Firstname, Lastname
    order by Order#
) 
where "Order Total" > 30;

/*Q6*/
select avg("Order Total") as "Average Of All Orders"
from (
    select sum(Paideach*Quantity) as "Order Total"
    from ORDERITEMS
    group by Order#
);

/*Q7*/
select max(Retail) as "Retail Price Of The Most Expensive Book Bought By A Georgian"
from BOOKS
inner join ORDERITEMS using (Isbn)
inner join ORDERS using (Order#)
inner join CUSTOMERS using (Customer#)
where State = 'GA';