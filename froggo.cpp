#include <iostream>

using namespace std;

int main()
{
   int d, s, k, c = 1, a = 1;
   double m, id, dt = 0;
   bool ch = true;
   char cho;
   do
   {
      cout << "                           Welcome to the Frog Jump Challenge!";
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

      cout << "Please enter the value of D (in m) : ";
      cin >> d;
      while (d < 0)
      {
         cout << "The value of D needs to be a postivie integer !!" << endl
              << "Please enter the value of D (in m) : ";
         cin >> d;
      }

      cout << "Please enter the value of S (in cm) : ";
      cin >> s;
      while (s < 0)
      {
         cout << "The value of S needs to be a postivie integer !!" << endl
              << "Please enter the value of S (in cm) : ";
         cin >> s;
      }
      cout << "Please enter the value of K (in cm) : ";
      cin >> k;
      while (k < 0)
      {
         cout << "The value of K needs to be a postivie integer !!" << endl
              << "Please enter the value of K (in cm) : ";
         cin >> k;
      }
      m = (double)s;
      id = (double)d * 100;
      while (dt < id)
      {
         if (m < k )
         {
            ch = false;
            c = c-1;
            break;
         }
         dt += m;
         cout<<"Steps : "<<c<<" / Distance traveled : "<<dt<<endl;
         if (c % 5 == 0 && c!=0)
         {
            m = s / ((double)a + 1);
            a++;
            cout << "New step is :" << m << endl;
         }
         c = c + 1;
      }
      if (ch == true)
      {
         cout << "The Froggy has been succesful !! it traveled the distance in " << c << " steps" << endl;
      }
      else
      {
         cout << "Unfortunately, The Froggy has been unsuccesful !! it only had " << id - dt << " cm left to the finish line./steps : " << c << endl;
      }

      cout << "Do you want to continue? (y/n): ";
      cin >> cho;
      system("cls");
   } while (cho == 'y' || cho == 'Y');
   return 0;
}