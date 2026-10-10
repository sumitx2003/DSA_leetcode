# Write your MySQL query statement below
select Employee.name,
       Bonus.bonus
from Employee
left  join Bonus
on Employee.empID=Bonus.empId
having Bonus.bonus is NULL or Bonus.bonus<1000;