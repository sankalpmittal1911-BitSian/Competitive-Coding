/*Grid is given with dimensions N X N (5 <= N <= 20). In that grid there can be 5 different kind of blocks placed at some locations. Blocks are numbered like this:


  1   2   3      4              5

We need to roll a marble in this grid. Once a marble hits a block, it rebounds based on below diagram.

 

  


If marble hits boundary, it will wrap around as shown in figure below. Same will be applicable for vertical roll or marble as well.
      

      

      
      
      




Each block has some health value H associated with it (0 <= H <= 5). Each time a marble hits block, its health gets reduced by 1. When health value becomes 0, block will disappear.
Each grid cell will have either value 0 or two digit number. If value is 0, no block is present. Otherwise, 1st digit represents type of block as shown above and second digit represents health of block.
We can start rolling marble from any cell which does not have Block. Also we can start rolling marble to any direction. Once we roll marble, it will roll on its own by hitting any block in between with changing direction and reducing health of block.
There will come a point when marble will come to same cell without changing any direction. I.e. looping through boundary and coming back to same cell. At that point we need to count maximum number of blocks which got disappeared with current marble roll.
Problem is to find maximum number of blocks which we can disappear for a given grid. (By selecting start cell and direction)
Sample input matrix:
0 0 31  0 0
51  31  0 0 0
0 0 42  31  32
0 0 21  0 0
0 11  0 0 32



Sample Output: 6


*/


#include<iostream>
#include<stdio.h>
#include<math.h>

int n, **arr, **backup, gr,gc, ans, gdir;

int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}
int game(int r, int c, int dir, int bl)
{
    int right=-999,left=-999,up=-999,down=-999;

	if(r==-1 && dir==4) r=n-1;
	else if(r==n && dir==2) r=0;
	else if(c==-1 && dir==3) c=n-1;
	else if(c==n && dir==1) c=0;



	if(arr[r][c]==0 && gr==r && gc==c && gdir==dir)
	{
		return bl;
	}
	else if(arr[r][c]==0)
	{
		if(dir==1) right= game(r, c+1, dir, bl);
		else if(dir==2) down =  game(r+1, c, dir, bl);
		else if(dir==3) left= game(r, c-1, dir, bl);
		else if(dir==4) up= game(r-1, c, dir, bl);
	}
	else
	{
		gr=r;
		gc=c;
		int h=arr[r][c]%10;
		int t=arr[r][c]/10;
		h--;
		if(h==0)
		{
			arr[r][c]=0;
			bl++;
			//printf("%d %d\n", bl, arr[r][c]);
		}
		else
		{
			arr[r][c]--;
		}
		if(t==1)
		{
			if(dir==1)
			{
				gdir=3; dir=3;
				left= game(r, c-1, dir, bl);
			}
			else if(dir==4)
			{
				gdir=2; dir=2;
				down= game(r+1, c, dir, bl);
			}
			else if(dir==2)
			{
				gdir=1; dir=1;
				right= game(r, c+1, dir, bl);
			}
			else if(dir==3)
			{
				gdir=4; dir=4;
				up= game(r-1, c, dir, bl);
			}
		}
		else if(t==2)
		{
			if(dir==1)
			{
				gdir=3; dir=3;
				left= game(r, c-1, dir, bl);
			}
			else if(dir==4)
			{
				gdir=1; dir=1;
				right= game(r, c+1, dir, bl);
			}
			else if(dir==2)
			{
				gdir=4; dir=4;
				up= game(r-1, c, dir, bl);
			}
			else if(dir==3)
			{
				gdir=2; dir=2;
				down= game(r+1, c, dir, bl);
			}
		}
		else if(t==3)
		{
			if(dir==1)
			{
				gdir=2; dir=2;
				down= game(r+1, c, dir, bl);
			}
			else if(dir==4)
			{
				gdir=3; dir=3;
				left= game(r, c-1, dir, bl);
			}
			else if(dir==2)
			{
				gdir=4; dir=4;
				up= game(r-1, c, dir, bl);
			}
			else if(dir==3)
			{
				gdir=1; dir=1;
				right= game(r, c+1, dir, bl);
			}
		}
		else if(t==4)
		{
			if(dir==1)
			{
				gdir=4; dir=4;
				up= game(r-1, c, dir, bl);
			}
			else if(dir==4)
			{
				gdir=2; dir=2;
				down= game(r+1, c, dir, bl);
			}
			else if(dir==2)
			{
				gdir=3; dir=3;
				left= game(r, c-1, dir, bl);
			}
			else if(dir==3)
			{
				gdir=1; dir=1;
				right= game(r, c+1, dir, bl);
			}
		}
		else if(t==5)
		{
			if(dir==1)
			{
				gdir=3; dir=3;
				left= game(r, c-1, dir, bl);
			}
			else if(dir==4)
			{
				gdir=2; dir=2;
				down= game(r+1, c, dir, bl);
			}
			else if(dir==2)
			{
				gdir=4; dir=4;
				up= game(r-1, c, dir, bl);
			}
			else if(dir==3)
			{
				gdir=1; dir=1;
				right= game(r, c+1, dir, bl);
			}
		}

	}

    return max(max(max(right,left),up),down);

}




void refresh()
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]=backup[i][j];
		}
	}
}

int main()
{
    int right=0,left=0,up=0,down=0;
	scanf("%d",&n);
	int i, j;
	arr= new int*[n];
	backup= new int*[n];
	for(i=0;i<n;i++)
	{
		arr[i]=new int[n];
		backup[i]=new int[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			backup[i][j]=arr[i][j];
		}
	}
	ans=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//printf("%d ",arr[i][j]);
			if(arr[i][j]==0)
			{
				gr=i;gc=j;gdir=1;
				right=game(i, j+1, 1, 0); refresh();

				gr=i;gc=j;gdir=2;
				down=game(i+1, j, 2, 0); refresh();

				gr=i;gc=j;gdir=3;
				left=game(i, j-1, 3, 0); refresh();

				gr=i;gc=j;gdir=4;
				up=game(i-1, j, 4, 0); refresh();

				ans=max(max(max(max(ans,left),right),up),down);
			}
		}
		//printf("\n");
	}

	printf("%d",ans);
	return 0;
}

