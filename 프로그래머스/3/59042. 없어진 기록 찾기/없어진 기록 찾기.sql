SELECT o.ANIMAL_ID, o.NAME
FROM ANIMAL_OUTS o
WHERE o.ANIMAL_ID NOT IN (
    SELECT i.ANIMAL_ID FROM ANIMAL_INS i
);