/*
Project Title: Lab02 Maze Solver
Class: CNIT315
Name: Landan Perry
Email: ldperry@purdue.edu
Lab Time: Friday 7:30am - 9:30am

Description: Program that uses functions and mutual recursion to
solve maze puzzles. A 6by6 Example maze is given. S is the Start and G is the end(goal).
'+' signs mark the path to the end. 'V' marks the path tried but failed. '.' are untried paths.

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

char maze[6][6] ={        //builds array/maze

{'S','#','#','#','#','#'},
{'.','.','.','.','.','#'},
{'#','.','#','#','#','#'},
{'#','.','#','#','#','#'},
{'.','.','.','#','.','G'},
{'#','#','.','.','.','#'}

};

////////////////////////////////////////////////////////////////////////////////

 bool mazeGo (int row, int column){ //function that uses recursion to sovle the maze

        
        if(maze[row][column] == 'G'){  //check for maze completion
            return true;
        }else{

            if(maze[row][column] != '.' && maze[row][column] != 'S'){   //check if can move to space
                return false;   
            }

            maze[row][column] = 'V'; //tracks visited points that were the wrong path


       if(mazeGo(row+1,column)){ // move South
           maze[row][column] = '+';
           return true;
       } 

        if(mazeGo(row,column+1)){ // move East
           maze[row][column] = '+';
           return true;
       }
        
        if(mazeGo(row,column-1)){ // move West
           maze[row][column] = '+';
           return true;
       }

        if(mazeGo(row-1,column)){ //move North
           maze[row][column] = '+';
           return true;
       }

        

       return false; // if hits this point must not be part of solution
        
    }
    
    
}

//////////////////////////////////////////////////////////////////////////////

int main(){ //main function

printf("---Unsolved Maze-------\n"); //maze title

int colNum = sizeof(maze[0]); //num of columns in maze
int rowNum = sizeof(maze)/sizeof(maze[0]); //num of rows in maze

//printf("%d",rowNum);
//printf("%d",colNum);

int colStart; //column start location
int rowStart; //row start location

for(int ctr = 0; ctr < rowNum; ctr++){          //finds the start location for the maze
    for(int count = 0; count < colNum; count++){
        if(maze[ctr][count] == 'S'){
            colStart = count;
            rowStart = ctr;
        }
    }
}



for(int ctr = 0; ctr < rowNum; ctr++){        //displays unsolved maze
    for(int count = 0; count < colNum; count++){
        printf(" %c", maze[ctr][count]);
    }
    printf("\n");
}

printf("\n");
printf("---Solved Maze-------\n"); //maze title


   if(mazeGo(rowStart,colStart)){  // calls/runs mazeGo

   maze[rowStart][colStart] = 'S'; //resets S to display where the start was after solving the maze


for(int ctr = 0; ctr < rowNum; ctr++){        //displays the solved maze
    for(int count = 0; count < colNum; count++){
        printf(" %c", maze[ctr][count]);
    }
    printf("\n");

}

   }else{
       printf("Maze Unsolvable"); //prints maze is unsolvable if it can't be solved
   }




return 0; //end of program

}


 



