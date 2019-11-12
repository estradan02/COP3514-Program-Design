//Code by Nicholas Estrada. This program is designed to take input from CSV file, gradebook.csv, calculate each student's project averages, exam averages, weighted grades, and final letter grade. The calculations are written into an output file, output.csv, in that respective order after their names.
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

int main(int argc, char *argv[])
{
  //Needed variables and contstants
  FILE *input, *output;
  char names[MAX_LEN], header_line[100], *grade;
  int p1, p2, p3, p4, p5, p6, p7, mid, final, i, j, temp;
  float avg_p, avg_exam, weighted;
  
  //Determines if user entered in the command line correctly
  if (argc != 3)
    {
      printf("Usage: ./calc_grade gradebook.csv output.csv\n");
      return 1;
    }  
  
  //Opens both the input and out files
  input = fopen(argv[1], "r");
  output = fopen(argv[2], "w");
  
  //Verifies that both files are opened correctly
  if((input == NULL) || (output == NULL))
    {
      printf("Error opening files!\n");
      return 1;
    }
   

  if(fscanf(input, "%[^\n]", header_line) == 1);
  {
  fprintf(output, "Name,Project,Exam,Weighted total,Grade letter");
  }
  
  //Checks for these errors until the end of the file
  while(!feof(input) && !ferror(input))
  {
     //Reads data from each line of the input file
     if(fscanf(input, "%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d\n", names, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &mid, &final) == 10)
      {
    
    int lowest[7] = {p1, p2, p3, p4, p5, p6, p7};
    
    //Loop sorting the lowest project grades
    for(i = 0; i < 7; i++)
    {
      for(j = i+1; j < 7; j++)
      {
        if(lowest[i] < lowest[j])
        {
          temp = lowest[i];
          lowest[i] = lowest[j];
          lowest[j] = temp;
        }      
      }
    } 
    
    //Needed calculations
    avg_p = ((float)(p1+p2+p3+p4+p5+p6+p7-lowest[6])/6.00);
    avg_exam = (((float)mid+(float)final)/2.00);
    weighted = ((0.40 * avg_p) + (0.60 * avg_exam));
    
    //Grade letter logic    
    if (weighted >= 90 && avg_p >= 70 && avg_exam >= 70) {
		      grade = "A";
        }
         else if (weighted < 90 && weighted >= 80 &&  avg_p >= 70 && avg_exam >= 70) {
          grade = "B";
        }
        else if (weighted < 80 && weighted >= 70 && avg_p >= 60 && avg_exam >= 60) {
          grade = "C";
        }
        else if ((weighted < 80 && weighted >= 70) && (avg_p < 60 || avg_exam < 60)) {
		      grade = "C-";
        }
        else if (weighted < 70 && weighted >= 60 ) {
		      grade = "D";
        }
        else if (weighted < 60) {
		      grade = "F";
        }
    
    //Output written to output file
    fprintf(output, "%s,%.2f,%.2f,%.2f,%s\n", names, avg_p, avg_exam, weighted, grade);
     }
  }
 
//Closing all open files
fclose(input);
fclose(output);     
return 0;
}