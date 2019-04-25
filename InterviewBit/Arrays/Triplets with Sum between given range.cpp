/*Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.*/

bool compare(double a1,double b1)
{
return a1>b1;
}
bool compare2(double a1,double b1)
{
return a1<b1;
}

double min_element(vector A) //return minimum element { double min=A[0]; for(int i=0;i<A.size();i++) { if(A[i]<min) { min=A[i]; }

{
return min; } vector<double> getmin(vector<double> a,int n) {     vector<double> b;
for(int i=0;i<n;i++)
    b.push_back(a[i]);
for(int i=n;i<a.size();i++)
{    b.push_back(a[i]);
    sort(b.begin(),b.end(),compare2);//Here n is either 2 or 3. sorting is done in such a way that it take O(n) time complexity i.e.sorting two element at a time
                                     //O(2*log(2)*n)=O(n)
    b.pop_back();
}
//Time complexity=O(3lg3 * n)=O(n)
return b; }
vector getmax(vector a,int n) { vector b; for(int i=0;i<n;i++) b.push_back(a[i]); for(int i=n;i<a.size();i++) { b.push_back(a[i]); sort(b.begin(),b.end(),compare); //Here n is either 2 or 3. sorting is done in such a way that it take O(n) time complexity i.e.sorting two element at a time=>O(2*n) //O(2*log(2)*n)=O(n) b.pop_back(); } return b; }

int Solution::solve(vector &a) { vector A,B,C;

for(int i=0;i<a.size();i++)
{ char b[20];
for(int j=0;j<a[i].length();j++)
{
b[j]=a[i][j];
}
if(0.0<atof(b)&&atof(b)<((double)2.0/(double)3.0)) // atof converts string to double
{
A.push_back(atof(b));

}
else if((double)2.0/(double)3.0<=atof(b)&&atof(b)<=1.0)
{
B.push_back(atof(b));

}
else if(1.0<atof(b)&&atof(b)<2.0)
{
C.push_back(atof(b));

}

}

//1
int res=0;

if(A.size()>=3)
{
vector b3; b3=getmax(A,3); // used to get max 3 elements in O(n) time double m=0; for(int i=0;i<b3.size();i++) m+=b3[i];

if(m>1.0)
{
res=1;
return res;
}

}
//2
if(A.size()>=2&&B.size()>=1)
{
vector b4; b4=getmax(A,2); // used to get max 2 elements in O(logn) time

double m1=0;
for(int i=0;i<b4.size();i++)
m1+=b4[i];

for(int i=0;i<B.size();i++)
{
if(1-m1<B[i]&&B[i]<2-m1)
{
res=1;
return res;
}

}

}

//3
if(A.size()>=2&&C.size()>=1)
{
vector b1; b1=getmin(A,2); //used to get min 2 elements in O(n) time

double m2=0;
for(int i=0;i<b1.size();i++)
m2+=b1[i];

double min=min_element(C);

if(m2+min<2.0)
{
res=1;
return res;
}

}

//4
if(B.size()>=2&&A.size()>=1)
{
vector b2; b2=getmin(B,2); //used to get min 2 elements in O(n) time double m3=0; for(int i=0;i<b2.size();i++) m3+=b2[i];

for(int i=0;i<A.size();i++)
{
if(A[i]<2-m3)
{
res=1;
return res;
}

}

}

//5
if(A.size()>=1&&B.size()>=1&&C.size()>=1)
{
int res3=0;
double min1=min_element(A);
double min2=min_element(B);
double min3=min_element(C);
if(min1+min2+min3<2&&min1+min2+min3>1)
{
res=1;
return res;
}

}

return res;
// Time complexity =O(logn)+O(n)
//hence,Time complexity=O(n)

}
