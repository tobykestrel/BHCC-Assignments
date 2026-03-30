/*
Toby Hansen
March 25, 2026
SQL Programming
Discussion Board 7
*/

/*
To perform this activity, refer to the tables in the JustLee Books database.
Currently, JustLee Books bills customers for orders by enclosing an invoice with each order
when it’s shipped. A customer then has 10 days to send in the payment. Of course, this practice
has resulted in the company having to list some debts as “uncollectible.” By contrast, most other
online booksellers receive payment through a customer’s credit card at the time of purchase.
With this method, although payment would be deposited within 24 hours into JustLee’s bank
account, there’s a downside. When a merchant accepts credit cards for payment, the company
processing the credit card sales (usually called a “credit card clearinghouse”) deducts a 1.5%
processing fee from the total amount of the credit card sale.
The management of JustLee Books is trying to determine whether the surcharge for credit
card processing is more than the amount usually deemed uncollectible when customers are
sent an invoice. Historically, the average amount that JustLee Books has lost is about 4% of the
total amount due from orders with a higher-than-average amount due. In other words, usually
customers who have an order with a larger-than-average invoice total default on payments.
To determine how much money would be lost or gained by accepting credit card payments,
management has requested that you do the following:
1. Determine how much the surcharge would be for all recently placed orders if payment had
been made by a credit card.
2. Determine the total amount that can be expected to be written off as uncollectible based on
recently placed orders with an invoice total more than the average of all recently placed orders.
Based on the results of these two calculations, you should determine whether the company
will lose money by accepting payments via credit card. State your findings in a memo to
management. Include the SQL statements for calculating the expected surcharge and the
expected amount of uncollectible payments.
*/

select
    (select sum(Quantity*Paideach)*.015 from ORDERITEMS
    ) as "Amount lost to 1.5% credit card surcharge",
    (select sum(sum(Quantity*PaidEach))*.04 
        from ORDERITEMS inner join ORDERS using (Order#)
        group by Order#
        having sum(Quantity*Paideach) > (
            select avg("OrderTotal") from (
                select sum(Quantity*Paideach) as "OrderTotal"
                from ORDERITEMS
                group by Order#
            )
        )
    ) as "Amount lost to defaulted large orders" 
from DUAL;
