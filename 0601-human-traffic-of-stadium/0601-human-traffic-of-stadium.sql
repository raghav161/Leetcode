# Write your MySQL query statement below
select distinct s1.id, s1.visit_date, s1.people
from stadium s1, stadium s2, stadium s3
where s1.people>=100 and s2.people>=100 and s3.people>=100 
and 
    ((s2.id=s1.id+1 and s3.id=s1.id+2)
    or (s2.id=s1.id-1 and s3.id=s1.id+1)
    or (s2.id=s1.id-1 and s3.id=s1.id-2))
order by id