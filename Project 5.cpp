//Bismillah-AbubakarQ
//---------------------------------------------------
// Purpose: Implement simple spreadsheet program.
// Author:  John Gauch and S. Abubakar Qasim
//---------------------------------------------------

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 26;
const int COLS = 26;

//---------------------------------------------------
// Read read index of the form A4 and calculate
// the corresponding row=3 col=0 values.
//---------------------------------------------------
void read_index(int &row, int &col)
{
   char letter = ' ';
   int number = 0;
   cin >> letter >> number;

   if (letter >= 'A' && letter <= 'Z')
      col = letter - 'A';
   else
      cout << "Error: invalid column\n";

   if (number >= 1 && number <= 26)
      row = number - 1;
   else
      cout << "Error: invalid row\n";
}

//---------------------------------------------------
// Print range of values in spreadsheet array
//---------------------------------------------------
void print(float data[ROWS][COLS], int r1, int c1, int r2, int c2)
{
   for (int row = r1; row <= r2; row++)
   {
      for (int col = c1; col <= c2; col++)
         cout << data[row][col] << "\t";
      cout << endl;
   }
}


// ADD FUNCTIONS TO DO ARRAY OPERATIONS HERE

// Command List
void Commandlist()
{
   cout << "Operations List: \t*Invalid operation will terminate system*\n";
   cout << "      Store\t\t - 'STORE' \n";
   cout << "      Random\t\t - 'RANDOMIZE' \n";
   cout << "      Find Minimum\t - 'MIN'\n";
   cout << "      Find Maximum\t - 'MAX'\n";
   cout << "      Summation\t\t - 'SUM'\n";
   cout << "      Find Average\t - 'AVE'\n";
   cout << "      Find Varience\t - 'VAR'\n";
   cout << "      Standard Deviation - 'STD'\n";
   cout << "      Print Values\t - 'PRINT'\n";
   cout << "      Quit System\t - 'QUIT'\n";
   cout << "      Command List\t - 'CMDList'\n";
   cout << endl;
}

// Random Value Function 
void RANDOM_value(float data[ROWS][COLS], int Max, int Min, int r1, int c1, int r2, int c2)
{
   int range = Max - Min + 1;
   for (int row = r1; row <= r2; row++)
   {
      for (int col = c1; col <= c2; col++)
      {
         data[row][col] = random() % range + Min; //switch 10 and 1 with min max functions from user.
      }
   }
}

// Function Summation   
void sum(float data[ROWS][COLS], int r1, int c1, int r2, int c2, int r3, int c3) 
{  
   float sum = 0;
               read_index(r1, c1);
               read_index(r2, c2);
               read_index(r3, c3);

  for (int row = r1; row <= r2; row++)
   {
      for (int col = c1; col <= c2; col++)
      {
         sum = sum + data[row][col];

      }
   }
   data[r3][c3] = sum;
}

// Min Value Function 
void MinValue(float data[ROWS][COLS], int r1, int c1, int r2, int c2, int r3, int c3) 
{
         float tempMIN = data[r1][c1];
               read_index(r1, c1);
               read_index(r2, c2);
               read_index(r3, c3);

         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
            if (tempMIN > data[row][col])
               tempMIN = data[row][col];
            }
         }
   data[r3][c3] = tempMIN;
}

// Max Value Function 
void MaxValue(float data[ROWS][COLS], int r1, int c1, int r2, int c2, int r3, int c3) 
{
         float tempMAX = data[r1][c1];
               read_index(r1, c1);
               read_index(r2, c2);
               read_index(r3, c3);

         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
            if (tempMAX < data[row][col])
               tempMAX = data[row][col];
            }
         }
   data[r3][c3] = tempMAX;
}

// Average Value Function 
void AverageFunction(float data[ROWS][COLS], int r1, int c1, int r2, int c2, int r3, int c3) 
{
         float sumVal = 0.0;
         float intVal = 0.0;
         float avgVal = data[r1][c1];
               read_index(r1, c1);
               read_index(r2, c2);
               read_index(r3, c3);

         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
               intVal ++;
               sumVal += data[row][col];
            }
         }
   avgVal = sumVal / intVal;
   data[r3][c3] = avgVal;
}

// Variance Value Function 
void VarFunction(float data[ROWS][COLS], int r1, int c1, int r2, int c2, int r3, int c3) 
{
         float sumVal = 0.0;
         float intVal = 0.0;
         float avgVal = data[r1][c1];
         float varVal = 0.0; 
               read_index(r1, c1);
               read_index(r2, c2);
               read_index(r3, c3);

         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
               intVal ++;
               sumVal += data[row][col];
               //cout << sumVal << endl;
            }
         }
      avgVal = sumVal / intVal;
      float preVar = 0.0; 
      float avgVariance = 0.0;
      float Sum_MeanMinusAvg = 0.0;
      float MeanMinusAvg = 0.0;
         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
               MeanMinusAvg = data[row][col] - avgVal; // Pre Squared 
               preVar = MeanMinusAvg * MeanMinusAvg; // Squared Function 
               avgVariance += preVar; // Average of Variance Squared 
               //cout << avgVariance;
               //cout << endl;

               //cout << MeanMinusAvg << endl;
               //cout << endl;

               Sum_MeanMinusAvg += MeanMinusAvg; // Test to see if equals 0
               //cout << Sum_MeanMinusAvg << endl;

            }
         }

   varVal = avgVariance / (intVal - 1);
   data[r3][c3] = varVal;
}

// Standard Deviation Value Function - Very simlilar to above function for Variance
void STDFunction(float data[ROWS][COLS], int r1, int c1, int r2, int c2, int r3, int c3) 
{
         float sumVal = 0.0;
         float intVal = 0.0;
         float avgVal = data[r1][c1];
         float varVal = 0.0;
         float STDVal = 0.0; 
               read_index(r1, c1);
               read_index(r2, c2);
               read_index(r3, c3);

         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
               intVal ++;
               sumVal += data[row][col];
               //cout << sumVal << endl;
            }
         }
      avgVal = sumVal / intVal;
      float preVar = 0.0; 
      float avgVariance = 0.0;
      float Sum_MeanMinusAvg = 0.0;
      float MeanMinusAvg = 0.0;
         for (int row = r1; row <= r2; row++)
         {
            for (int col = c1; col <= c2; col++)
            {
               MeanMinusAvg = data[row][col] - avgVal; // Pre Squared 
               preVar = MeanMinusAvg * MeanMinusAvg; // Squared Function 
               avgVariance += preVar; // Average of Variance Squared 
               //cout << avgVariance;
               //cout << endl;

               //cout << MeanMinusAvg << endl;
               //cout << endl;

               Sum_MeanMinusAvg += MeanMinusAvg; // Test to see if equals 0
               //cout << Sum_MeanMinusAvg << endl;

            }
         }

   varVal = avgVariance / (intVal - 1);
   STDVal = sqrt(varVal);
   data[r3][c3] = STDVal;
}

//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{
   cout << endl;
   // Initialize spreadsheet
   float data[ROWS][COLS];
   for (int row = 0; row < ROWS; row++)
      for (int col = 0; col < COLS; col++)
         data[row][col] = 0;

   //// ADD CODE TO HANDLE COMMANDS HERE ////
   string option;
   cout << "Operations List: \t*Invalid operation will terminate system*\n";
   cout << "      Store\t\t - 'STORE' \n"; // Done --- 
   cout << "      Random\t\t - 'RANDOMIZE' \n"; // Done ---
   cout << "      Find Minimum\t - 'MIN'\n"; //Done ---
   cout << "      Find Maximum\t - 'MAX'\n"; //Done ---
   cout << "      Summation\t\t - 'SUM'\n"; // Done ---
   cout << "      Find Average\t - 'AVE'\n"; //Done ---
   cout << "      Find Varience\t - 'VAR'\n"; //Done ---
   cout << "      Standard Deviation - 'STD'\n"; //Done ---
   cout << "      Print Values\t - 'PRINT'\n"; //Done ---
   cout << "      Quit System\t - 'QUIT'\n"; // Done --- 
   cout << "      Command List\t - 'CMDList'\n";
   cout << endl;
      while (option != "QUIT")
      {
         cout << "Enter desired operation: ";
         cin >> option;
         if (option == "STORE")
            {
               float store_val = 0.0;
               cin >> store_val;
               int row = 0;
               int col = 0;
               read_index(row, col);
               data[row][col] = store_val;
            }
         
         else if (option == "PRINT")
            {
               int printC1=0, printR1=0;
               read_index(printR1, printC1);
               
               int printC2=0, printR2=0;
               read_index(printR2, printC2);

               print(data, printR1, printC1, printR2, printC2);
            }
         
         else if (option == "RANDOMIZE")
            {
               // Range for random numbers with user input
               int randMax=0, randMin = 0;
               cin >> randMin >> randMax;

               // First Variable e.g. A1
               int randC1=0, randR1=0;
               read_index(randR1, randC1);

               // Second Variable e.g. B10
               int randC2=0, randR2=0;
               read_index(randR2, randC2);

               RANDOM_value(data, randMax, randMin, randR1, randC1, randR2, randC2);
            }

         else if (option == "SUM")
            {
               int sumR1=0, sumC1=0, sumR2=0, sumC2=0, sumR3=0, sumC3=0;
               sum(data, sumR1, sumC1, sumR2, sumC2, sumR3, sumC3);

            }

         else if (option == "MIN") //////////////////// FIX ///////////////////////
            {
               int minR1=0, minC1=0, minR2=0, minC2=0, minR3=0, minC3=0;
               MinValue(data, minR1, minC1, minR2, minC2, minR3, minC3);
            }

         else if (option == "MAX")
            {
               int maxR1=0, maxC1=0, maxR2=0, maxC2=0, maxR3=0, maxC3=0;
               MaxValue(data, maxR1, maxC1, maxR2, maxC2, maxR3, maxC3);
            }

         else if (option == "AVE")
            {
               int avgR1=0, avgC1=0, avgR2=0, avgC2=0, avgR3=0, avgC3=0;
               AverageFunction(data, avgR1, avgC1, avgR2, avgC2, avgR3, avgC3);
            }

         else if (option == "VAR")
            {
               int varR1=0, varC1=0, varR2=0, varC2=0, varR3=0, varC3=0;
               VarFunction(data, varR1, varC1, varR2, varC2, varR3, varC3);
            }

         else if (option == "STD")
            {
               int stdR1=0, stdC1=0, stdR2=0, stdC2=0, stdR3=0, stdC3=0;
               STDFunction(data, stdR1, stdC1, stdR2, stdC2, stdR3, stdC3);
            }

         else if (option == "CMDList")
            {
               Commandlist();
            }

         else if (option == "QUIT")
            {
               option = "QUIT";
            }

         else 
            {
               cout << "Invalid Statement: System Terminating\n";
               cout << endl;
               return 0;
            }
      }
   cout << endl;
   cout << "Thank you for using SABQ Excel. Have a nice day!\n";
   cout << endl;
   return 0;
}