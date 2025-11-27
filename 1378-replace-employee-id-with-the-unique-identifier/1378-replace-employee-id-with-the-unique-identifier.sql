# Write your MySQL query statement below
# why left join -> because we want all rwos of employyes table if we used inner join the alice and bob is removed..
select 
   EmployeeUNI.unique_id ,
   Employees.name 
   from Employees
   left join EmployeeUNI 
   ON Employees.id = EmployeeUNI.id;