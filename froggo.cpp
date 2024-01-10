
// Library includes and name space for std library
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

   // Initiating variables that will be used in the program
   int d, s, k, c, a, er;
   double m, id, dt;
   bool ch;
   char cho;

   // Starting the loop that will have the main program
   do
   {
      // reseting the variables after each loop
      dt = 0;
      c = 1, a = 1, er = 0;
      ch = true;

      // this part is a welcome screen that has a lot of information about the program
      cout << "                                Welcome to the Frog Jump Challenge!";
      cout << R"(
                                            .--._.--.
                                           ( O     O )
                                           /   . .   \
                                          .`._______.'.
                                         /(           )\
                                       _/  \  \   /  /  \_
                                    .~   `  \  \ /  /  '   ~.
                                   {    -.   \  V  /   .-    }
                                 _ _`.    \  |  |  |  /    .'_ _
                                 >_       _} |  |  | {_       _<
                                  /. - ~ ,_-'  .^.  `-_, ~ - .\
                                          '-'|/   \|`-`      
)" << '\n';
      cout << R"(Welcome to the Frog Jump Challenge! This program checks if a frog can hop a certain distance.
The user needs to enter three positive integers : 
D : the total distance to calculate.
S : the initial jump distance.
K : the limit before the frog rests. 
After every 5 jumps, the frog gets tired and jumps less far. 
When the jumps get too short, the frog takes a break. 
Let's see if our froggy friend can make it to cover the specified distance!)"
           << endl;

      /* This is the part where the user inputs all the necessary values(3 tries incase of error),
       after that it asks if it wants to rerun the program,
       I used taht if and continue to avoid using goto*/
      cout << "Please enter the value of D (in m) : ";
      cin >> d;
      while (d < 0 && er < 3)
      {
         er++;
         cout << "The value of D needs to be a postivie integer !!" << endl
              << "Please enter the value of D (in m) : ";
         cin >> d;
      }
      if (er == 3 && d < 0)
      {
         cout << "You have entered an unacceptable value more than 3 times !!" << endl;
         cout << "Do you want to continue? (y/n): ";
         cin >> cho;
         system("cls");
         continue;
      }
      // i reset the value of er to give each value 3 tries each
      er = 0;
      cout << "Please enter the value of S (in cm) : ";
      cin >> s;
      while (s < 0 && er < 3)
      {
         er++;
         cout << "The value of S needs to be a postivie integer !!" << endl
              << "Please enter the value of S (in cm) : ";
         cin >> s;
      }
      if (er == 3 && s < 0)
      {
         cout << "You have entered an unacceptable value more than 3 times !!" << endl;
         cout << "Do you want to continue? (y/n): ";
         cin >> cho;
         system("cls");
         continue;
      }
      er = 0;
      cout << "Please enter the value of K (in cm) : ";
      cin >> k;
      while (k < 0 && er < 3)
      {

         cout << "The value of K needs to be a postivie integer !!" << endl
              << "Please enter the value of K (in cm) : ";
         cin >> k;
      }
      if (er == 3 && k < 0)
      {
         cout << "You have entered an unacceptable value more than 3 times !!" << endl;
         cout << "Do you want to continue? (y/n): ";
         cin >> cho;
         system("cls");
         continue;
      }
      
      /*converting the distance from meters to centimeters,
       and converting the values to double for the calculations to be precise */
      m = (double)s;
      id = (double)d * 100;

      // I added this to avoid the calculations if the initial jump distance is smaller than the limit.
      if (k > s)
      {
         cout << "The value of the limit K cannot be bigger than the initial jump S !!" << endl;
         cout << "Do you wish to restart? (y/n): ";
         cin >> cho;
         system("cls");
         continue;
      }
      while (dt < id)
      {
         if (m < k)
         {
            ch = false;
            break;
         }
         dt += m;
         if (c % 5 == 0 && c != 0)
         {
            /*instead of using the m = m*a/a+1 formula, i used the m =  m = s / a + 1 formula
            because it's simpler and it doesn't change the initial s*/
            m = s / ((double)a + 1);
            a++;
         }
         c++;
      }
      if (ch == true)
      {
         cout << "The Froggy has been succesful !! it traveled the distance of " << d << " Meters in " << c - 1 << " steps" << endl;
      }
      else
      {
         cout << "Unfortunately, The Froggy has been unsuccesful !! it only had " << id - dt << " cm left to the finish line." << endl;
      }

      cout << "Do you want to continue? (y/n): ";
      cin >> cho;
      /*used this to make the command clear itself when the user wants a restart.
       also to keep the instructions visible at every start of the program*/
      system("cls");
   } while (cho == 'y' || cho == 'Y');
   return 0;
}