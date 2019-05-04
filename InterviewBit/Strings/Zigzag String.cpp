/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.*/

string Solution::convert(string A, int B) {
    
    if(B==1)
    return A;
    int row=0;
    bool down=true;
    int i;
    string s[B],res="";
    for(i=0;i<A.length();++i)
    {
        s[row].push_back(A[i]);
        if(row==B-1)
          down=false;
        else if(row==0)
            down=true;
        if(down)
            row++;
        else
            row--;
    
    }
    for(i=0;i<B;++i)
    res=res+s[row];
    return res;
}
