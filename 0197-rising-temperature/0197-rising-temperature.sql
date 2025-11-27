# Write your MySQL query statement below 
# self jjoin is used 
 select 
    w2.id
    from Weather as w1 
    join Weather as w2 
    on w2.recordDate = Date_add(w1.recordDate , INTERVAL 1 DAY) 
    AND w2.temperature > w1.temperature