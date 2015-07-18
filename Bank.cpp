#include<iostream.h>
#include<math.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
void skylinebank();           //DISPLAY "SKYLINE BANK"
void welcome();               //DISPLAY WELCOME SCREEN
void welcomespace(char A[30]);
void pwdenter(char pin[6]);
void delay(long);             //DELAYS DISPLAY
void clear(long);             //CLEARS AND DELAYS DISPLAY
void design();                //DISPLAYS DESIGN
void option1();               //ENCOUNTERS OPTION 1
void option2();               //ENCOUNTERS OPTION 2
void option3();               //ENCOUTNERS OPTION 3
void apcheck(long,char[6]);   /*COMPARE ACCOUNT NUMBER
				AND PASSWORD*/
int q=1;

class account
{
 char name[100];
 long accno;
 char pincode[6];
 double balance;
 public:
 void pinenter();              //ENTER ACCOUNT NUMBER
 void accenter(long numb);     //ENTER ACCOUNT NUMBER
 void nameenter();             //ENTER NAME
 int acccheck(long p);         //CHECKS ACCOUNT NUMBER
 int pincheck(char q[6]);      //CHECKS PINCODE
 void accdisplay();            //DISPLAYS ACCOUNT
 void namedisplay();           //DISPLAYS NAME
 void accstat();               //DISPLAYS ACCOUNT STATUS
 void depenter();              //ENTERS DEPOSIT AMOUNT
 void depositamt(double dep);  //DEPOSIT AMOUNT
 void withdrawamt(double wid); // WITHDRAW AMOUNT
 void transfer(long k);        //TRANSFER AMOUNT
 double depbal();
 long accreturn();             //RETURNS ACCOUNT NUMBER
 char* pinreturn();  //RETURNS PIN
 char* namereturn();           //RETURNS NAME
 double balreturn();           //RETURNS BALANCE
}u,t,v,temp,tem,ch;

 void feature(account u,long pos);
 void fopt1(account u,long pos);
 void fopt2(account u,long pos);
 void fopt3(account u,long pos);
 void fopt4(account u,long pos);
 void fopt5(account u,long pos);
 void fopt6();

 void writefile(account ch,account u)
 {
  ifstream fin("csproj.dat",ios::in|ios::binary);
  ofstream fint("temp.dat",ios::out|ios::binary|ios::app);
  while(fin.read((char*)&ch,sizeof(ch)))
   if(u.acccheck(ch.accreturn())!=0)
   fint.write((char*)&ch,sizeof(ch));
   fint.close();
   fin.close();
 }

 void tempwrite(account u)
 {
  ofstream foutt("temp.dat",ios::out|ios::binary|ios::app);
  writefile(ch,u);
  foutt.write((char*)&u,sizeof(u));
  foutt.close();
  remove("csproj.dat");
  rename("temp.dat","csproj.dat");
 }

 void pattern(int x,int y,char z,char p)
 {
  if(p=='h')
  for(int i=0;i<=80;i++,x++)
   {
    gotoxy(x,y);
    cout<<z;
   }
  else
  for(int i=0;i<=24;i++,y++)
   {
   gotoxy(x,y);
   cout<<z;
   }
 }
 void design()
 {
  pattern(0,0,'$','h');
  pattern(0,24,'$','h');
  pattern(0,0,'$','v');
  pattern(80,0,'$','v');
 }
 void load()
 {
  clrscr();design();
  for(int i=0;i<5;i++)
  {
   gotoxy(24,10);
   cout<<"PROCESSING REQUEST";
   for(int j=0;j<5;j++)
   {
    cout<<".";
    delay(20000000);}
    cout<<"\b\b\b\b\b";
   }
 }
 void write(account);
 void designslow()
 {
  int x1=40,x=40,y=0;
  while(x1<=80)
  {
   gotoxy(x,0);
   cout<<"$";
   gotoxy(x1,0);
   cout<<"$";
   x--;
   x1++;
   delay(3000000);
  }
  while(y<=24)
  {
  gotoxy(0,y);
  cout<<"$";
  gotoxy(80,y);
  cout<<"$";
  delay(3000000);
  y++;
  }
  x=0;
  x1=80;
  while(x<=40)
  {
   gotoxy(x,24);
   cout<<"$";
   gotoxy(x1,24);
   cout<<"$";
   delay(3000000);
   x++;
   x1--;
  }
 }
 void delay(long x)
 {
  for(long l=0;l<=x;l++)
  {}
 }
 void clear(long x)
 {
  for(long i=0;i<=x;i++)
  clrscr();
 }
 void start()
 {skylinebank();
  welcome();
 }
 void skylinebank()
 {
  for(int i=0;i<=5;i++)
  {
   gotoxy(5,5);
   cout<<"* * * *    *     *     *     *     *       * *** *   *       *     * * * *"<<endl;
   gotoxy(4,6);
   cout<<"*           *    *      *     *     *          *      **      *    *      "<<endl;
   gotoxy(4,7);
   cout<<"*           *   *       *     *     *          *      * *     *    *      "<<endl;
   gotoxy(4,8);
   cout<<"*           *  *        *     *     *          *      *  *    *    *      "<<endl;
   gotoxy(4,9);
   cout<<" * * * *    * *         * * * *     *          *      *   *   *    * * * *"<<endl;
   gotoxy(4,10);
   cout<<"       *    *  *           *        *          *      *    *  *    *      "<<endl;
   gotoxy(4,11);
   cout<<"       *    *   *          *        *          *      *     * *    *      "<<endl;
   gotoxy(4,12);
   cout<<"       *    *    *         *        *          *      *	**    *      "<<endl;
   gotoxy(4,13);
   cout<<"* * * *     *     *        *        * * *   * *** *   *       *    * * * *"<<endl;
   gotoxy(20,15);cout<<"* *         *        *       *      *     * "<<endl;
   gotoxy(20,16);cout<<"*  *       * *       **      *      *    *  "<<endl;
   gotoxy(20,17);cout<<"*   *     *   *      * *     *      *   *   "<<endl;
   gotoxy(20,18);cout<<"*  *     *     *     *  *    *      *  *    "<<endl;
   gotoxy(20,19);cout<<"* *     * * * * *    *   *   *      * *     "<<endl;
   gotoxy(20,20);cout<<"*  *    *       *    *    *  *      *  *    "<<endl;
   gotoxy(20,21);cout<<"*   *   *       *    *     * *      *   *   "<<endl;
   gotoxy(20,22);cout<<"*  *    *       *    *      **      *    *  "<<endl;
   gotoxy(20,23);cout<<"* *     *       *    *       *      *     * "<<endl;
   delay(70000000);
   clear(500);
  }
 }
 void welcomespace(char A[30])
 {
  gotoxy(29,6);
  for(int i=0;i<23;i++)
  {
   delay(15000000);
   cout<<A[i];
  }
 }
 void welcome()
 {
  clrscr();
  designslow();
  char A[30];
  int o;
  strcpy(A,"WELCOME TO SKYLINE BANK");
  gotoxy(25,4);
  cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
  gotoxy(22,5);
  cout<<"$$$                               $$$";
  gotoxy(22,6);
  cout<<"$$$";
  gotoxy(56,6);
  cout<<"$$$";
  gotoxy(22,7);
  cout<<"$$$                               $$$";
  gotoxy(25,8);
  cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
  welcomespace(A);
  gotoxy(25,10);
  cout<<" 1. CREATE A BANK ACCOUNT";
  gotoxy(25,12);
  cout<<" 2. ACCESS A BANK ACCOUNT";
  gotoxy(25,14);
  cout<<" 3. EXIT";
  gotoxy(27,16);
  cout<<"Select Option <1-3>";
  gotoxy(27,18);
  while(q>=0)
  {
   cin>>o;
   gotoxy(27,17);
   delay(7500000);
   if(o==1 || o==2 || o==3)
   {
    if(o==1)option1();
    if(o==2)option2();
    if(o==3)option3();
   }
  }
 }
 void option1()
 {
  load();
  long pos;
  int r;char opt,x;
  char pwd[6],pwdtemp[6];
  long num;
  ifstream fin("csproj.dat",ios::in);
  ofstream fout("csproj.dat",ios::out|ios::binary|ios::app);
  clrscr();
  design();
  gotoxy(25,4);
  cout<<"ENTER NAME";
  gotoxy(25,5);
  u.nameenter();
  clrscr();design();
  gotoxy(25,5);
  cout<<"Enter Initial Deposit Amount";
  gotoxy(3,6);
  cout<<"Note that a minimum of Rs 100 or maximum of Rs 5,00,000 must be deposited";
  gotoxy(30,7);
  u.depenter();
  delay(7500000);
  clrscr();
  design();
  gotoxy(18,6);
  cout<<"CONGRATULATIONS !!!";
  gotoxy(18,7);
  fin.seekg(-18,ios::end);
  if(!fin.read((char*)&num,sizeof(num)))
  {
   num=15000;
   }
   pos=fin.tellg();
   cout<<"YOUR ACCOUNT NUMBER IS "<<++num;
   u.accenter(num);
   gotoxy(18,8);
   cout<<"PLEASE ENTER A 6-DIGIT PIN CODE. ";
   gotoxy(18,9);
   u.pinenter();
   delay(7500000);
   gotoxy(18,10);
   cout<<"PLEASE RE-ENTER PIN CODE FOR CONFIRMATION";
   gotoxy(18,11);
   pwdenter(pwdtemp);
   strcpy(pwd,pwdtemp);
   r=u.pincheck(pwd);
   if(r==0)
   {
    write(u);
    clrscr();
    design();
    gotoxy(17,6);
    cout<<"YOU HAVE SUCCESSFULLY CREATED AN ACCOUNT WITH SKYLINE BANK";
    delay(70000000);
    gotoxy(17,8);
    cout<<"Do you want to view your account? Enter Y/N !! "<<endl;
    gotoxy(17,10);
    cin>>opt;
    delay(7500000);
    if(opt=='y' || opt=='Y')
    {
     feature(u,pos);
    }
    else
    {
     clrscr();
     design();
     fin.close();
     fout.close();
     welcome();
    }
   }
   else
   {
    int r;
    clrscr();
    design();
    do
    {
     gotoxy(15,4);
     cout<<"PIN ENTERED WAS INCORRECT !! ENTER 6-DIGIT PIN CODE ONCE AGAIN";
     gotoxy(25,5);
     u.pinenter();
     gotoxy(25,6);
     cout<<"PLEASE RE-ENTER PIN CODE FOR CONFIRMATION";
     gotoxy(25,7);
     pwdenter(pwdtemp);
     strcpy(pwd,pwdtemp);
     r=u.pincheck(pwd);
     clrscr();
     design();
    }while(r!=0);
    gotoxy(17,6);
    cout<<"YOU HAVE SUCCESSFULLY CREATED AN ACCOUNT WITH SKYLINE BANK";
    delay(75000000);
    write(u);
    fout.close();
    gotoxy(17,8);
    cout<<"Do you want to view your account? Enter Y/N !! "<<endl;
    cin>>opt;
    clrscr();
    design();
    delay(7500000);
    if(opt=='y' || opt=='Y')
    {
     feature(u,pos);
    }
    else
    {
     clrscr();
     design();
     fin.close();
     welcome();
    }
   }
  }
 void option2()
 {
  long accnum;
  char pwdtemp[6],pwd[6];
  load();
  clrscr();
  design();
  gotoxy(25,4);
  cout<<"*=*=*=*=*=*=*=*=*=*"<<endl;
  gotoxy(25,5);
  cout<<"    USER LOGIN     "<<endl;
  gotoxy(25,6);
  cout<<"*=*=*=*=*=*=*=*=*=*"<<endl;
  gotoxy(15,7);
  cout<<"PLEASE ENTER ACCOUNT NUMBER AND 6-DIGIT CODE.";
  gotoxy(25,8);
  cout<<"ACCOUNT NUMBER: ";
  cin>>accnum;
  gotoxy(25,10);
  cout<<"PIN CODE: ";
  pwdenter(pwdtemp);
  strcpy(pwd,pwdtemp);
  apcheck(accnum,pwd);
 }
 void option3()
 {exit(0);}
 void write(account u)
 {
 ofstream fout("csproj.dat",ios::out|ios::app|ios::binary);
 fout.write((char*)&u,sizeof(u));
 fout.close();
 }
 void pwdenter(char pin[6])
 {
  char x;
  int n=0,c=0,y=0,d=0 ;
  for(int i=0,j=0,k=0;i>=-2;i++)
  {
   n=0;
   d=0;
   while(k==6)
   {
    y=getch();
    if(y==8)
    {
     d=1;
     k=6;
     x=8;
     break;
    }
    if(y=='\r')
    {
     c=1;
     break;
    }
   }
    if(c==1)
    break;
    if(d==0)
    x=getch();
  if(!(k==0 && x==8 || x=='\r'))
  {
   if(x==8 && i!=0)
   {
    if(k>=0)
    {
     cout<<"\b";
     j--;
     k--;
     n=1;
    }
    else
    cout<<"";
   }
   if(x!=8 && x!='\r' && j!=0)
   if(k<=6)
    {j++;n=1;k++;pin[k-1]=x;}

   if( x!=8 && x!='\r' && k<=6 )
   {
   cout<<"*";
   }
   if(j==0 && x!=8)
   {
   pin[k]=x;
   }
   if(x!=8 && j==0 && n==0 && x!='\r')
  {
  k++;
  }
   }
   }
  while(c==1)
 {

  if(y=='\r')
  c=0;}

 }
 void apcheck(long accnum,char pwd[6])
 {
  int h=0;
  long pos;
  ifstream fin("csproj.dat",ios::in|ios::binary);
  fin.seekg(0);
  while(fin.read((char*)&u,sizeof(u)))
  {
   if(u.acccheck(accnum)==0 && u.pincheck(pwd)==0)
   {
    pos=(fin.tellg()-sizeof(u));
    h=1;
    break;
    }
    else h=0;
   }
  fin.close();
  if(h==1)
  feature(u,pos);
  else
  if(h==0)
  {
   clrscr();
   design();
   gotoxy(25,6);
   cout<<"USERNAME and/or PASSWORD INCORRECT !!!!";
   delay(200000000);
   welcome();}
  }
 void feature(account u,long pos)
 {
  int fopt;
  clrscr();
  design();
  u.accstat();
  gotoxy(18,8);
  cout<<"BANK BALANCE : Rs "<<u.depbal();
  gotoxy(18,10);
  cout<<"1. DEPOSIT AMOUNT";
  gotoxy(18,12);
  cout<<"2. WITHDRAW AMOUNT";
  gotoxy(18,14);
  cout<<"3. BANK BALANCE";
  gotoxy(18,16);
  cout<<"4. PIN CHANGE";
  gotoxy(18,18);
  cout<<"5. TRANSFER MONEY";
  gotoxy(18,20);
  cout<<"6. EXIT";
  gotoxy(18,22);
  cout<<"Select Your Option <1-6> ";
  cin>>fopt;
  switch(fopt)
  {
   case 1 :fopt1(u,pos);
   break;
   case 2 :fopt2(u,pos);
   break;
   case 3 :fopt3(u,pos);
   break;
   case 4 :fopt4(u,pos);
   break;
   case 5 :fopt5(u,pos);
   break;
   case 6 :fopt6();
   break;
  }
 }
 void fopt1(account u,long pos)
 { load();
  clrscr();
  design();
  double dep;
  int e;
  char x;
  ofstream foutt("temp.dat",ios::out|ios::binary|ios::app);
	gotoxy(15,4);
	do
	{clrscr();
	 design();
	 gotoxy(15,4);
	 cout<<"Enter amount to be deposited. ";
	 gotoxy(15,6);
	 cout<<"PLEASE NOTE:- A maximum of Rs 5,00,000 can only be deposited";
	 gotoxy(15,8);
	 cin>>dep;
	 if(dep<=500000 && dep>=0)
	 {writefile(ch,u);
	  e=1;
	  u.depositamt(dep);
	  foutt.write((char*)&u,sizeof(u));
	  foutt.close();
	  remove("csproj.dat");
	  rename("temp.dat","csproj.dat");
	  gotoxy(18,10);
	  cout<<"ACCOUNT UPDATED!!";
	  gotoxy(18,12);
	  cout<<"Press any key to continue..";
	  gotoxy(18,14);
	  x=getch();
	  x++;
	  feature(u,pos);
	  break;}
	  else
	 {clrscr();
	  design();
	  gotoxy(18,9);
	  cout<<"ERROR!!";
	  delay(75000000);
	  e=0;
	 }
	}while(e==0);
 }
 void fopt2(account u,long pos)
{
 clrscr();
 design();
 double wid;
 int n;
 char x;
 load();
 ofstream foutt("temp.dat",ios::out|ios::binary|ios::app);
	gotoxy(18,4);
	do
	{
	 gotoxy(18,4);
	 clrscr();
	 design();
	 gotoxy(18,4);
	 cout<<"Enter amount to be withdrawn";
	 gotoxy(18,6);
	 cout<<"PLEASE NOTE:- A maximum of Rs 5,00,000 can only be withdrawn";
	 gotoxy(18,8);
	 cin>>wid;
	 if(wid<=u.depbal() && wid <=500000 && wid>=0)
	 {
	  writefile(ch,u);
	  u.withdrawamt(wid);
	  n=0;
	  foutt.write((char*)&u,sizeof(u));
	  foutt.close();
	  remove("csproj.dat");
	  rename("temp.dat","csproj.dat");
	  gotoxy(18,12);
	  cout<<"ACCOUNT UPDATED!!";
	  gotoxy(18,14);
	  cout<<"Press any key to continue..";
	  gotoxy(18,16);
	  x=getch();
	  x++;
	  feature(u,pos);
	 }
	 else
	 {clrscr();
	  design();
	  gotoxy(18,10);
	  cout<<"ERROR!!";
	  n=1;
	  delay(75000000);
	 }
	}while(n!=0);
      }
 void fopt3(account u,long pos)
{
	clrscr();
	design();
	char x;
	load();
	clrscr();
	design();
	gotoxy(18,4);
	cout<<"BANK BALANCE : Rs "<<u.depbal();
	delay(75000000);
	gotoxy(18,6);
	cout<<"Press any key to continue..";
	gotoxy(18,8);
	x=getch();x++;feature(u,pos);
       }
void fopt4(account u,long pos)
{
 clrscr();
 design();
 char pwdtemp[6],pwd[6];
 int r;
 char x;
 load();
 ofstream foutt("temp.dat",ios::out|ios::binary|ios::app);
	gotoxy(18,4);
	do
	{clrscr();
	 design();
	 char g;
	 gotoxy(8,6);cout<<"Do you want to change your pin ? Enter Y/N !! ";
	 cin>>g;
	 if(g!='Y' && g!='y')
	 feature(u,pos);
	 if(g=='Y' || g=='y')
	 {clrscr();
	  design();
	  gotoxy(18,4);
	  cout<<"Enter new 6 DIGIT PIN CODE";
	  gotoxy(18,6);
	  u.pinenter();
	  gotoxy(18,8);
	  cout<<"Re-enter 6 DIGIT PIN CODE ";
	  pwdenter(pwdtemp);
	  strcpy(pwd,pwdtemp);
	  r=u.pincheck(pwd);
	  if(r==0)
	  {gotoxy(18,12);
	  writefile(ch,u);
	  foutt.write((char*)&u,sizeof(u));
	  foutt.close();
	  remove("csproj.dat");
	  rename("temp.dat","csproj.dat");
	  cout<<"CONGRATULATIONS!! PIN CHANGED";
	  gotoxy(18,14);
	  cout<<"Press any key to continue..";
	  getch();
	  feature(u,pos);
	 }
	  else
	   {clrscr();
	    design();
	    gotoxy(18,10);
	    cout<<"ERROR!! WRONG PIN ENTERED";
	    delay(75000000);
	    r=1;
	   }

	 }
	}while (r!=0);

}
 void transfer(account u,long k,long pos)
 {ifstream fin("csproj.dat",ios::in|ios::binary);
  long postemp;
  int tp=3;
 double am;
 char x;
 account v;
  while(fin.read((char*)&v,sizeof(v)))
	  {
	   if(v.acccheck(k)==0)
	   {postemp=(fin.tellg()-sizeof(v));
	    gotoxy(18,12);
	    cout<<"Enter Amount to be Transferred";
	    gotoxy(18,14);
	    cin>>am;
	    if(am<0)
	    {
	     tp=1;
	     clrscr();
	     gotoxy(18,16);
	     design();
	     cout<<"INVALID";
	     delay(75000000);
	     fin.close();
	     feature(u,pos);}
	    else
	    if(am>=u.depbal())
	    {
	     tp=0;
	     gotoxy(18,16);
	     cout<<"Transfer amount exceeding bank balance";
	     fin.close();
	     delay(75000000);
	     feature(u,pos);
	     break;
	    }
	    else
	    {tp=2;
	     u.withdrawamt(am);
	     v.depositamt(am);
	     fin.close();
	     break;
	    }}}
	    if(tp==2)
	    {gotoxy(18,16);
	    ofstream foutt("temp.dat",ios::out|ios::binary|ios::app);
	    cout<<"AMOUNT WAS SUCCESSFULLY TRANSFERRED TO ";

	    writefile(ch,v);
	  foutt.write((char*)&v,sizeof(v));
	  foutt.close();
	  remove("csproj.dat");
	  rename("temp.dat","csproj.dat");

	    gotoxy(18,18);
	    tempwrite(u);

	    cout<<"ACCOUNT NUMBER :- ";
	    v.accdisplay();
	    gotoxy(18,20);
	    cout<<"NAME :- ";
	    v.namedisplay();
	    gotoxy(18,22);
	    cout<<"Press any key to continue";
	    gotoxy(18,24);
	    gotoxy(24,24);
	    x=getch();
	    x++;
	    feature(u,pos);

	   }

	   if(tp==3)
	   {
	    clrscr();
	    design();
	    gotoxy(18,10);
	    cout<<"INVALID ";
	    delay(150000000);
	    fin.close();
	    feature(u,pos);}
  }
 void fopt5(account u,long pos)
 {
  char a;
  long k;
  load();
  clrscr();
  design();
	 gotoxy(18,4);
	 cout<<"DO YOU WANT TO TRANSFER MONEY ? ENTER Y/N ? ";
	 cin>>a;
	 if(a=='Y' || a=='y')
	 {
	  gotoxy(18,6);
	  cout<<"MONEY TRANSFER";
	  gotoxy(18,8);
	  cout<<"ENTER RECEPIENT BANK ACCOUNT NUMBER";
	  gotoxy(18,10);
	  cin>>k;
	  transfer(u,k,pos);
	 }else feature(u,pos);
}

void fopt6()
{load();
 clrscr();
 design();
 gotoxy(24,10);
 cout<<"YOU HAVE SUCCESSFULLY SIGNED OUT ";
 delay(100000000);
 welcome();
}

char* account::namereturn()
{return(name);}

double account :: balreturn()
{return balance;}


 void account::nameenter()
 {
  gets(name);
  }


 void account::accenter(long numb)
 {
  accno=numb;
  }
 int account::pincheck(char q[6])
 {int r=0;
  for(int i=0;i<6;i++)
  if(pincode[i]!=q[i])
  {r=1;
   break;}
  return(r);
  }
 int account::acccheck(long p)
 {
  int r=0;
  if(p!=accno)
  r=1;
  return(r);
 }
 void account::accdisplay()
 {cout<<accno;}

 void account::namedisplay()
 {cout<<name;}

 void account::accstat()
 {
  gotoxy(18,2);
  cout<<"====ACCOUNT STATUS====";
  gotoxy(18,4);
  cout<<"ACCOUNT NUMBER : ";
  cout<<accno;
  gotoxy(18,6);
  cout<<"ACCOUNT HOLDER : ";
  cout<<name;
  }
 void account::depenter()
{double x,R;
 int i=8;
 do
 {gotoxy(35,i);
  cin>>x;
  if(x>=100 && x<=500000)
   {balance=x;
    R=1;}
  else
 { gotoxy(5,i);
  cout<<"ERROR!!A Minimum of Rs 100 or a Maximum of Rs 5,00,000 must be deposited";
  R=0;}
  i+=2;
  }while(R==0);
}
void account::depositamt(double dep)
 {balance=balance+dep;}
double account::depbal()
 {return(balance);}
void account::withdrawamt(double wid)
{ balance=balance-wid;}
long account::accreturn()
{
 return(accno);
}
char* account::pinreturn()
{return(pincode);}

void account::pinenter()
 {
  char x,pin[6];
  int n=0,c=0,y=0,d=0;
  for(int i=0,j=0,k=0;i>=-2;i++)
  {n=0;
   d=0;

   while(k==6)
    {
     y=getch();
     if(y==8)
     {d=1;k=6;x=8;break;}
     if(y=='\r')
     {c=1;break;}}
     if(c==1)
     break;
    if(d==0)
    x=getch();

   if(!(k==0 && x==8 || x=='\r'))
    {
    if(x==8 && i!=0)
    {
     if(k>=0)
     {cout<<"\b";
      j--;
      k--;
      n=1;}
     else
     cout<<"";
    }
     if(x!=8 && x!='\r' && j!=0)
      if(k<=6)
       {j++;
	n=1;
	k++;
	pincode[k-1]=x;
       }

     if( x!=8 && x!='\r' && k<=6 ){cout<<"*";}
      if(j==0 && x!=8)
      {pincode[k]=x;}
      if(x!=8 && j==0 && n==0 && x!='\r')
     {k++;}
   }
  }
 while(c==1)
 {
  if(y=='\r')
  c=0;
 }
}
void main()
{start();}


