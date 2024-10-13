# Write your MySQL query statement below
SELECT Request_at as Day,
ROUND(COUNT(IF(Status != 'completed', TRUE, NULL))/COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips
WHERE (Request_at BETWEEN '2013-10-01' AND '2013-10-03')
AND Client_id IN (SELECT Users_Id FROM Users WHERE Banned='No')
AND Driver_Id IN (Select Users_Id from Users where Banned='No')
GROUP BY Request_at;