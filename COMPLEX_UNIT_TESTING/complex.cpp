#include "complex.h"
#include <ostream>
#include <iostream>
#include <math.h>
#include <string>

namespace csis3700
{
    complex::complex()
    {
        real=0;
        imaginary=0;
    }
    complex::complex(double r, double i)
    {
        real=r;
        imaginary=i;
    }
   double complex::get_real()  const
   {
       return real;
   }
   double complex::get_imaginary() const
   {
       return imaginary;
   }
   double complex::magnitude() const
   {
       return sqrt(pow(real,2)+pow(imaginary,2));
   }
   double complex::norm() const
   {
       return (pow(real,2) + pow(imaginary,2));
   }
   complex complex::conjugate() const
   {
        return complex(real,-imaginary);
   }
   complex complex::negate() const
   {
       return complex(-real,-imaginary);
   }
   complex complex::reciprocal() const
   {
      return complex(real/(real*real+imaginary*imaginary),-imaginary/(real*real+imaginary*imaginary));
   }
   std::ostream& operator << (std::ostream& out,const complex& c)
   {
     
        if (c.get_imaginary() == 0)
        {
            out << c.get_real();
            return out;
        }
        if (c.get_real() == 0)
        {
            out << c.get_imaginary() << "i";
            return out;
        }
        if (c.get_imaginary() < 0)
        {
            out << c.get_real() << " - " << (abs(c.get_imaginary()))  << "i";
            return out;
        }
        out << c.get_real() << " + " << c.get_imaginary() << "i";
        return out;
    
   }
   bool operator == (const complex& c, const complex& d)
   {
       
       if
       ((c.get_real() == d.get_real()) && (c.get_imaginary() == d.get_imaginary()))
       { 
         return true;
       }
       else
       {
        return false;
       }
      //return (abs(c.get_real()- d.get_real()) < .001 && abs(c.get_imaginary()-d.get_imaginary()) < .001);
   }
   bool operator != (const complex&c, const complex& d)
   {
      return !(c == d);
   }
   complex operator + (const complex&c, const complex& d)
   {
      double r;
      double i;
      r = c.get_real() + d.get_real();;
      i = c.get_imaginary() + d.get_imaginary();
      return complex(r,i);
   }
   complex operator - (const complex&c, const complex& d)
    {
        double r;
        double i;
        r = c.get_real() - d.get_real();
        i = c.get_imaginary() - d.get_imaginary();
        return complex(r,i);
    }
     complex operator * (const complex& c, const complex& d)
    {
        double r;
        double i;
        r = c.get_real()*d.get_real() - c.get_imaginary()*d.get_imaginary();
        i = c.get_real()*d.get_imaginary() + d.get_real()*c.get_imaginary();
        return complex(r,i);
    }
     complex operator / (const complex&c, const complex& d)
    {
        return c*d.reciprocal();
    }
   void demo()
   {
     using namespace std;
     double r1,r2,i1,i2;
     string op1;
     cout << "You will need to enter two complex  numbers " << endl;
     cout << "Enter real part of your first complex number" << endl;
     cout << "followed by a space enter your imaginary part but no need to include 'i' " << endl;
     cout << "Now type the operator which you want to use for two complex numbers " << endl;
     cout << " use operator  +, -, *, / " <<endl;
     cout << "Now Enter the second complex number in the same format and on the same line" <<endl;
     cout << " don't press enter until you have typed all of them" << endl;
     cout << "for example, \"4 2 / 2 4\" will" << endl;
     cout << "be taken as entering \"(4 + 2i)/(2 + 4i)\"" << endl;
     cout << "you can press enter after every number or wait" << endl;
     cout << "until you have typed all the numbers." << endl;
     cout << "Here it's important to make sure :: " << endl;
     cout << "if you want to enter a complex number that does not have" << endl;
     cout << "either an imaginary or real part, enter 0 for that part." << endl;
     cout << "for example, \"4\" must be entered as \"4  0\"" << endl;
     cout << "and \"6i\" must be entered as \"0 6 \"" << endl;
     cout << "Enter a complex number as given instructions: " << endl;
     cin>>r1>>r2>>op1>>i1>>i2;
               while(op1 != "/" && op1 != "*" && op1 != "+" && op1 != "-")
               {
               cout << "One of these are only allowed +,-,*,/ " << endl;
               cout << "Enter valid operator: " << endl;
               cin>>op1;
               }
               complex complex1(r1,i1);
               complex complex2(r2,i2);
               if (op1 == "/")
               {
               cout << "(" << complex1 << ") / (" << complex2 << ") = " << (complex1/complex2) <<  endl;;
               }
               if (op1 == "*")
               {
               cout << "(" << complex1 << ") * (" << complex2 << ") = " <<(complex1*complex2) << endl;
               }
               if (op1 == "+")
               {
               cout << "(" << complex1 << ") + (" << complex2 << ") = " << (complex1 + complex2) << endl;
               }
               if (op1 == "-")
               {
               cout << "(" << complex1 << ") - (" << complex2 << ") = " << (complex1 - complex2) << endl;
               }
               string once_more;
               cout<<"Want to go again?? Y for YES and N For NO" <<endl;
               cin>>once_more;
               while(once_more != "N" && once_more != "Y")
                {
                    cout<<"Enter Y or N" << endl;
                    cin>>once_more;
                }
                while(once_more == "Y")
                {
                    cout<<"Enter your complex number as you did before " << endl;
                    cin>>r1>>r2>>op1>>i1>>i2;   
                    while(op1 != "/" && op1 != "*" && op1 != "+" && op1 != "-")
                    {
                    cout << "One of these are only allowed +,-,*,/ " << endl;
                    cout << "Enter valid operator: " << endl;
                    cin>>op1;
                    }
                    complex complex1(r1,i1);
                    complex complex2(r2,i2);
                    if (op1 == "/")
                    {
                    cout << "(" << complex1 << ") / (" << complex2 << ") = " << (complex1/complex2) <<  endl;;
                    }
                    if (op1 == "*")
                    {
                    cout << "(" << complex1 << ") * (" << complex2 << ") = " <<(complex1*complex2) << endl;
                    }
                    if (op1 == "+")
                    {
                    cout << "(" << complex1 << ") + (" << complex2 << ") = " << (complex1 + complex2) << endl;
                    }
                    if (op1 == "-")
                    {
                    cout << "(" << complex1 << ") - (" << complex2 << ") = " << (complex1 - complex2) << endl;
                    }
                    cout<<"Want to go again?? Y for YES and N For NO" <<endl;
                    cin>>once_more;
                    
                    while(once_more != "N" && once_more != "Y")
                    {
                    cout<<"Enter Y or N";
                    cin>>once_more;
                    }
              }  
        }              
           
           
 }
