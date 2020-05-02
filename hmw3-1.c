#include <stdio.h>
#include <string.h>
#include <math.h>


int process(const char *input_filename, const char *output_filename) {
  /* Open the files input for read and output for write */
  FILE* inputPtr = fopen(input_filename, "r");
  FILE* outputPtr = fopen(output_filename, "w");

  int count = 0;

  double first;
  char operator;
  double second;

  while(fscanf(inputPtr, "%lf %c %lf", &first, &operator , &second) != EOF) {
    if(operator == '*') {
      fprintf(outputPtr,"%lf\n", first * second);
      count = count + 1;
    }
    else if(operator == '+'){
      fprintf(outputPtr, "%lf\n", first + second);
      count = count + 1;
    }
    else if(operator == '-'){
      fprintf(outputPtr, "%lf\n", first - second);
      count = count + 1;
    }
    else if(operator == '/'){
      fprintf(outputPtr, "%lf\n", first / second);
      count = count + 1;
    }
    else if(operator == '^'){
      double out = pow(first, second);
      fprintf(outputPtr,"%lf\n",out);
      /*fprintf(outputPtr, "%lf\n", pow(first,second));*/
      count = count + 1;
    }
    else{
      fprintf(outputPtr,"Non valid operator");
    }
  }
  fclose(outputPtr);
  fclose(inputPtr);
/* return the amount of calculations */
  return count;
}

int main(){
  char inputFileName[] = "inputFile";
  char outputFileName[] = "outputFile";
  process(inputFileName, outputFileName);
}
