SELECT ID, COALESCE(LENGTH, 0) AS LENGTH
FROM FISH_INFO
ORDER BY LENGTH DESC, ID ASC
LIMIT 10;

