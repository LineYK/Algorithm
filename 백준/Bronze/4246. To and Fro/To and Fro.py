"""
To and Fro 
 
시간 제한	메모리 제한
1 초	128 MB	517	379	349	74.893%
문제
Mo and Larry have devised a way of encrypting messages. They first decide secretly on the number of columns and write the message (letters only) down the columns, padding with extra random letters so as to make a rectangular array of letters. For example, if the message is “There’s no place like home on a snowy night” and there are five columns, Mo would write down

t o i o y
h p k n n
e l e a i
r a h s g
e c o n h
s e m o t
n l e w x
Note that Mo includes only letters and writes them all in lower case. In this example, Mo used the character ‘x’ to pad the message out to make a rectangle, although he could have used any letter.

Mo then sends the message to Larry by writing the letters in each row, alternating left-to-right and right-to-left. So, the above would be encrypted as

toioynnkpheleaigshareconhtomesnlewx

Your job is to recover for Larry the original message (along with any extra padding letters) from the encrypted one.

입력
There will be multiple input sets. Input for each set will consist of two lines. The first line will contain an integer in the range 2 . . . 20 indicating the number of columns used. The next line is a string of up to 200 lower case letters. The last input set is followed by a line containing a single 0, indicating end of input.

출력
Each input set should generate one line of output, giving the original plaintext message, with no spaces.

예제 입력 1 
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0
예제 출력 1 
theresnoplacelikehomeonasnowynightx
thisistheeasyoneab
"""

# Answer
while True:
    n = int(input())
    if n == 0:
        break
    s = input()
    l = len(s)
    k = l // n
    
    rows = []
    for i in range(k):
        row = s[i*n:(i+1)*n]
        if i % 2 == 1:
            row = row[::-1]
        rows.append(row)
    
    result = ''.join(rows[i][j] for j in range(n) for i in range(k))
    print(result)
