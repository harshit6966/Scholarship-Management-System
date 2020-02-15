#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void calc();
class feedetails
{
private:
    unsigned long long int fee;
public:
    void choice()
    {
     int n;
     lab:
     cout<<"Choose Your Stream:\n";
     cout<<"1.Engineering"<<endl;
     cout<<"2.MBA"<<endl;
     cout<<"3.Agriculture"<<endl;
     cout<<"4.MCA"<<endl;
     cin>>n;
     fflush(stdin);
     if(n!=1)
     {
         cout<<"\tData Not Available For This Stream"<<endl;
          goto lab;
     }
     if(n==1)
     {
         int s;

        l1 :
        cout<<"Choose your stream"<<endl;
         cout<<"1.BTech"<<endl;
         cout<<"2.BTech Integrated"<<endl;
         cin>>s;
         fflush(stdin);

         if(s==1 ||s==2)
         {
             getdata(s);
         }
         else
         {

         cout<<"\tERROR! Please Enter Right Choice"<<endl;
             goto l1;
         }
     }
    }
    void getdata(int k)
    {
    if(k==1)
       {
           fee=94500;
       }
    if(k==2)
        {
            fee=104500;
        }
    }
    void display()
    {
         cout<<"Applicable Fee(Per Semester)is:"<<fee<<endl;
    }
    void details()
  {
    int j;
    cout<<"Enter 1 For Scholarship Details:\n";
    cin>>j;
    fflush(stdin);
if(j=1)
{   int press;
    int n;
    detail:
    cout<<"Scholarship On The Basis Of:\n";
    cout<<"1). LPUNEST Marks"<<endl;
    cout<<"2). 12th Marks"<<endl;
    cout<<"3). JEE-MAINS Marks"<<endl;
    cout<<"4). EXIT"<<endl;
    cout<<"Enter Your Choice:\n";
    cin>>n;
    fflush(stdin);


    if(n==1)
    {
        cout<<"Performance in LPUNEST "<<"\t\t\t\t"<<"Scholarship Amount"<<endl;
        cout<<"-----------------------"<<"\t\t\t\t"<<"------------------"<<endl;
        cout<<"1.Top 10% Applicants"     <<"\t\t\t\t"<<"1 Lac per Annum."<<endl;
        cout<<"2.Next 10%(i.e. 11%-20%) applicants"<<"\t\t"<<"80,000 Per Annum."<<endl;
        cout<<"3.Next 10%(i.e. 21%-30%) applicants"<<"\t\t"<<"60,000 Per Annum."<<endl;

    }
    if(n==2)
    {
        cout<<"Scholarship Criteria        "<<"\t\t\t\t"<<"Scholarship Amount"<<endl;
        cout<<"----------------------------"<<"\t\t\t\t"<<"------------------"<<endl;
        cout<<"1.98% or Above Aggreate Marks "<<"\t\t\t\t"<<"75,000 rs. Per Semester"<<endl;
        cout<<"2.90%-97.99%%  Aggreate Marks "<<"\t\t\t\t"<<"50,000 rs. Per Semester"<<endl;
        cout<<"3.80%-89.99%  Aggreate Marks "<<"\t\t\t\t"<<"40,000 rs. Per Semester"<<endl;
        cout<<"4.70%-79.99%  Aggreate Marks "<<"\t\t\t\t"<<"30,000 rs. Per Semester"<<endl;
    }
 if(n==3)
    {
        cout<<"Scholarship Criteria           "<<"\t\t\t\t "<<"Scholarship Amount"<<endl;
        cout<<"-------------------------------"<<"\t\t\t\t "<<"------------------"<<endl;
        cout<<"1.More than or equal to 325 Marks"<<"\t\t\t\t"<<"75,000 rs. Per Semester"<<endl;
        cout<<"2.Score from 275 to 324 Marks     "<<"\t\t\t\t"<<"50,000 rs. Per Semester"<<endl;
        cout<<"3.Score from 225 to 274 Marks     "<<"\t\t\t\t"<<"40,000 rs. Per Semester"<<endl;
        cout<<"4.Score from 175 to 274 Marks     "<<"\t\t\t\t"<<"30,000 rs. Per Semester"<<endl;
    }
   cout<<"If you want to check scholarship details again press '1' or else press '0' "<<endl;
   cin>>press;
   fflush(stdin);
   if(press==1)
   {

       goto detail;
   }
   if(press==0)
   {
    calc();
   }

}

}
};
int fee=0;
int marks=0;
int percentage=0;
int rank=0;

class student
{
private:
    char name[100];
    char city[100];
    unsigned long long int mobile_no;
    unsigned long long int fee;
    unsigned long long int amount;

public:
  void getdata();
   void showdata();

    void choice();

    void calculate(int k);

    int storestudent();
    void viewstudent();
    void searchstudent(char *);
    //void deletestudent(char*);
};
int student::storestudent()
{
    if(mobile_no==0 && strlen(name)==0)
    {
        cout<<"Student Data Not Initialized:";
        return(0);
    }
    else
    {
    ofstream fout;
    fout.open("scholar.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return(1);
    }
}
   void student::viewstudent()
    {
        ifstream fin;
        fin.open("scholar.txt",ios::out|ios::binary);
        if(!fin)
           cout<<"file not found";
        else
        {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
         showdata();
         fin.read((char*)this,sizeof(*this));

        }
         fin.close();
        }

    }

   void student::searchstudent(char *t)
    {
        int count=0;
        ifstream fin;
        fin.open("scholar.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"file not found:";
        }
        else
        {

        while(!fin.eof())
        {
            fin.read((char*)this,sizeof(*this));
            if(!strcmp(t,name))
            {
                showdata();
                count++;
            }
             fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        if(count==0)
            cout<<"record not found";
        }
    };

    /*void book::deletebook(char*c)
    {
        ifstream fin;
        ofstream fout;
        fin.open("ajeet.txt",ios::in|ios::binary);
        if(!fin)
        {
            cout<<"file not found";
        }
        else
        {
            fout.open("ajeet1.txt",ios::out|ios::binary);
              fin.read((char*)this,sizeof(*this));
              while(!fin.eof())
              {
                  if(strcmp(c,title))
                  {
                      fout.write((char*)this,sizeof(*this));
                       fin.read((char*)this,sizeof(*this));
                  }
              }
            fin.close();
            fout.close();
            remove("ajeet1.txt");
            rename("ajeet1.txt","ajeet.txt");
        }*/



int main()
{
    cout<<"\t\t\t\tWELCOME TO SCHOLARSHIP CALCULATOR FOR LPU\t\t\t\t\n";

     feedetails f1;
     f1.choice();
     f1.display();
     f1.details();

    return 0;
}
void calc()
{
     int key;
     student s1;
     s1.getdata();
     s1.choice();
     s1.storestudent();
     s1.showdata();
     cout<<"For Checking The Record press '0' Otherwise Press'1'"<<endl;
     fflush(stdin);
     cin>>key;
     if(key==0)
     {
    int i;
    cout<<"Select Your Option:"<<endl;
    cout<<"1.VIEW RECORDS"<<endl;
    cout<<"2.SEARCH RECORDS"<<endl;
    cout<<"3.EXIT "<<endl;
    fflush(stdin);
    cin>>i;
    if(i==1)
    {
     s1.viewstudent();
    }
    if(i==2)
    {
        char temp[100];
        cout<<"Enter Student's Name:"<<endl;
        fflush(stdin);
        cin.getline(temp,50);
     s1.searchstudent(temp);
    }
    if(i==3)
    {
        exit(0);
    }

     }

}
void student::getdata()
    {
        cout<<"Enter Your Name: "<<endl;
        fflush(stdin);
        cin.getline(name,30);

        cout<<"Enter Your City: ";
        fflush(stdin);
        cin.getline(city,30);

        cout<<"Contact Number: ";
        fflush(stdin);
        cin>>mobile_no;
    }

    void student::choice()
    {
    int n;
    cout<<"\n\n\t\t////////////////////////////////////////////////////////////////////////"<<endl;
    cout<<"\n\t\t\t\t\t\tOn Which Do You Want To Get Scholarship\t\t\t\t\t\n";
    cout<<"\n\t\t\n";
    cout<<"1.LPUNEST Marks"<<endl;
    cout<<"2.JEE-MAINS Marks"<<endl;
    cout<<"3.12th Marks"<<endl;
    cin>>n;
    fflush(stdin);
    calculate(n);
    }
    void student::calculate(int k)
     {
          if(k==1)
      {
      cout<<"Enter Your Rank Or Percentile In LPUNEST Exam:\n";
      cin>>rank;
      fflush(stdin);
          if(rank<10 && rank>0)
             {
               fee=(2*24500);
               amount=(4*fee);
             }
         if(rank<20 && rank>10)
            {
              fee=(2*54500);
              amount=(4*fee);
            }
        if(rank<30 && rank>20)
          {
           fee=(2*64500);
           amount=(4*fee);
          }
      }
    if(k==2)
    {

        cout<<"Enter Your JEE-MAINS Marks:\n";
        cin>>marks;
        fflush(stdin);
        if(marks>325)
         {
      fee=(2*19500);
      amount=(4*fee);
         }
        if(marks<325 && marks>275)
            {
      fee=(2*45500);
      amount=(4*fee);
            }
            if(marks<275 && marks>225)
                {
      fee=(2*54500);
      amount=(4*fee);
                }
          if(marks<225 && marks>175)
            {
      fee=(2*64500);
      amount=(4*fee);
            }

    }
    }
   void student::showdata()

{
        cout<<"\t\t......STUDENT DETAILS...........\n";
        cout<<"Name: "<<name<<endl<<"City: "<<city<<endl<<"Mobile Number: ="<<mobile_no<<endl;
        cout<<"\t\t\tStudent fee details are below after applying scholarship*****\n";
        cout<<"Fee per annum:       \t\t\t\t\tComplete Tution fee of 4 Year: "<<endl;
        cout<<"\t\t\n"<<(amount)/4  <<"\t\t\n"<<amount<<endl;

        cout<<"\n\t3. NOTICE*-Examination Fee Of Rs 2,000/- Will Be Charged Per Semester:"<<endl;
    }
