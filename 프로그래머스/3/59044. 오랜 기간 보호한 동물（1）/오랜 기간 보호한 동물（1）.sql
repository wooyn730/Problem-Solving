SELECT I.NAME, I.DATETIME FROM ANIMAL_INS AS I LEFT JOIN ANIMAL_OUTS AS O ON I.ANIMAL_ID = O.ANIMAL_ID WHERE O.DATETIME IS NULL ORDER BY I.DATETIME ASC LIMIT 3;