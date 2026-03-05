/*
Toby Hansen
March 4, 2026
SQL Programming
Chapter Ten Textbook Assignment
*/

/*Q1 How many books are there in the Computer category? Use column alias for a column 
with the number of books, show category and the number of books in your report.*/
select
    Category as "Category Name",
    count(*) as "Category Amount"
from BOOKS
where lower(Category) = 'computer'
group by Category;

/*Q2 Find out how many books each author wrote. Display the author’s first and 
last name and how many books (s)he wrote. Sort by last name, then first name.*/
select
    Fname || ' ' || Lname as "Author",
    count(Isbn) as "Books Written"
from AUTHOR 
inner join BOOKAUTHOR using (AuthorID)
group by Lname, Fname
order by Lname, Fname;

/*Q3 Calculate the total paid for the order 1009. Consider quantity 
in calculations, some books may be purchased in multiple copies.*/
select sum(Paideach*Quantity) as "Total Paid For Order 1009"
from ORDERITEMS
where Order# = 1009;

/*Q4 Find the average retail price of books in each of the Children 
and Business categories, use a single query to show the average 
for Children and Business books (two records in the results).*/
select
    Category as "Category",
    avg(Retail) as "Average Retail Price"
from BOOKS
where lower(Category) = 'children' 
    or lower(Category) = 'business'
group by Category;

/*Q5 List customers from New Jersey and Florida who placed 
orders totaling over $30. Aggregate PER order, PER customer.*/
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

/*Q6 Determine the average of ALL orders. Find the total per each order 
before calculating the average for all orders. Hint: Use nesting.*/
select avg("Order Total") as "Average Of All Orders"
from (
    select sum(Paideach*Quantity) as "Order Total"
    from ORDERITEMS
    group by Order#
);

/*Q7 Show the retail price of the most expensive book a customer from Georgia has 
bought. Assign a clear header to this column. Show just one column in the report!*/
select max(Retail) as "Retail Price Of The Most Expensive Book Bought By A Georgian"
from BOOKS
inner join ORDERITEMS using (Isbn)
inner join ORDERS using (Order#)
inner join CUSTOMERS using (Customer#)
where State = 'GA';