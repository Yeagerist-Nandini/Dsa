#include<bits/stdc++.h>
using namespace std;

const int r=5,c=5;

void display(char mat[][c])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void floodFill(char mat[][c],int i,int j,char ch,char color)
{
    if(i<0 || j<0 || i>=r || j>=c)
    return;

    // if(vis[i][j])
    // return ;

    if(mat[i][j]!=ch)
    return;

    mat[i][j]=color;

    floodFill(mat,i-1,j,ch,color);
    floodFill(mat,i,j-1,ch,color);
    floodFill(mat,i+1,j,ch,color);
    floodFill(mat,i,j+1,ch,color);
}

int main()
{
    // cin>>r>>c;
    char mat[r][c];

    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    mat[i][j]='.';      
   
   for(int i=0;i<r;i++)
   mat[i][0]='#';
   for(int i=0;i<c;i++)
   mat[0][i]='#';
   for(int i=r-1;i>=0;i--)
   {
       mat[i][4]='#';
       mat[4][i]='#';
   }

    floodFill(mat,3,3,'.','R');
    display(mat);

    return 0;
}