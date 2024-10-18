SELECT 
    id,
    COUNT(id) AS num
FROM
(SELECT 
    requester_id as id
FROM RequestAccepted
UNION ALL
SELECT 
    accepter_id as id
FROM RequestAccepted
) m
GROUP BY id
ORDER BY num DESC
LIMIT 1;