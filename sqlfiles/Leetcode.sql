select s.score as Score,
(select count(distinct b.Score) from Scores b where b.Score >= a.Score) as Rank
from Scores s
order by s.score desc;