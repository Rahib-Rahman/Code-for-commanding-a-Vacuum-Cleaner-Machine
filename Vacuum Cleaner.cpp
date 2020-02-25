#include<bits/stdc++.h>
#define mxn 1005

/*
 * @author Sheikh Md. Rahibur Rahman
*/

using namespace std;

int row, col;
char grid[mxn][mxn];
void vacuumCleaner(int,int);
string arr[] = {"UP\n\n", "DOWN\n\n", "LEFT\n\n", "RIGHT\n\n"};

void PrintGrid()
{
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
}

void printAction(int action)
{
    cout<<arr[action-1];
}

void update(int action, int x,int y)
{
    if(action==1)
    {
        x--;
    }
    else if(action==2)
    {
        x++;
    }
    else if(action==3)
    {
        y--;
    }
    else if(action==4)
    {
        y++;
    }
    vacuumCleaner(x,y);
}

int isActionValid(int action,int x,int y)
{
    if(action==1)
    {
        x--;
    }
    else if(action==2)
    {
        x++;
    }
    else if(action==3)
    {
        y--;
    }
    else if(action==4)
    {
        y++;
    }

    if(x>0 && x<=row && y>0 && y<=col)
        return 1;
    return 0;
}

int totalclean()
{
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            if(grid[i][j]=='#')
                return 0;
        }
    }
    return 1;
}

void Actuator(int dirt ,int x,int y)
{
    if(dirt)
    {
        printf("Perception : Dirt  |  Action : Suck\n\n");
        grid[x][y] = '.';
        vacuumCleaner(x,y);

    }
    else
    {
        printf("Perception : Clean  |  Action : ");
        int action = rand()%4+1;

        while(!isActionValid(action,x,y))
        {
            action = rand()%4+1;
        }
        printAction(action);

        if(!totalclean())
           update(action,x,y);
    }
}

int Sensor(int x,int y)
{
    if(grid[x][y]=='#')return 1;
    return 0;
}

void vacuumCleaner(int x,int y)
{
    int dirt = Sensor(x,y);
    PrintGrid();
    printf("Vacuum Cleaner Position : x=%d y=%d\n",x,y);
    Actuator(dirt,x,y);
}



void gridInitializer()
{
    srand(time(NULL));
    printf("\n. = clean \n# = Dirt \nV = Vacuum Cleaner \n\n");
    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            grid[i][j] = '.';
        }
    }
    int dirtpositions = (row*col)/4;

    while(dirtpositions--)
    {
        int x,y;
        x=rand()%row+1;
        y=rand()%col+1;
        grid[x][y] = '#';
    }
}

int main()
{
    int x,y;
    printf("Enter number of Rows : ");
    scanf("%d",&row);
    printf("Enter number of Column : ");
    scanf("%d",&col);
    gridInitializer();
    PrintGrid();
    printf("\nEnter the Coordinates where to place the vacuum cleaner : ");
    scanf("%d %d",&x,&y);
    vacuumCleaner(x,y);
}
