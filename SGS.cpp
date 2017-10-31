// The Source Code for Smart Garbage System
#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//Class Administrator contains fine() totalpincode(int f) maxmin() add_New() add_Existing() total() search() del() functions
class Administrator{
public:
void fine()
{
    ifstream fin;
    ofstream f1;
    fin.open("penalty.csv");
    f1.open("temp1.csv");
    char c[30],p[30],d[30];
    string b,l;
    int x=0,f,j,n;
    cout<<"Enter UIDAI of the user :"<<endl;
    cin>>c;
    string s;
    int a;
    while(fin)
    {
        getline(fin,s);
        istringstream in(s);
        in.getline(d,16,',');
        if(strcmp(c,d)==0){
            x=1;
            break;}
    }
    if(x==1)
    {
            fin.seekg(0,ios::beg);
        while(fin){
          getline(fin,s);
          if(s=="")
            continue;
       istringstream is(s);
       is.getline(d,16,',');
       if(strcmp(d,c)!=0)
       f1<<s<<endl;
        else
        {
            f1<<d<<",";
          for(int i=1;i<6;i++)
              {
                  is.getline(p,19,',');
                  if(i==4)
                {
                  f=atoi(p);
                  cout<<"The present fine is : "<<f<<endl;
              cout<<"Press 1 to add more fine"<<endl;
              cout<<"Press 2 to deduce the fine"<<endl;
              cout<<"Enter your choice "<<endl;
              cin>>j;
              if(j==1)
              {
                  cout<<"Enter the amount "<<endl;
                  cin>>n;
                  f=f+n;
              }
              else if(j==2)
              {
                  int z=f;
                 do
                 {
                     cout<<"Enter the amount "<<endl;
                  cin>>n;
                  if(n>z)
                  {
                      cout<<"Deducted amount cannot be bigger than the fine"<<endl;
                  }
                  else
                  {
                      f=f-n;
                  }
                 }
                 while(z<n);
              }
                 else
                    cout<<"Wrong choice.No changes has been made"<<endl;

              f1<<f<<",";

                  }
                  else
                    f1<<p<<",";

              }
              f1<<","<<endl;

        }
    }
    fin.close();
    f1.close();
    remove("penalty.csv");
    rename("temp1.csv","penalty.csv");
    }
    else
    {
        cout<<"Profile not present"<<endl;
        fin.close();}
}
    int totalpincode(int f)
{

	ifstream fin,fin1;
	fin.open("penalty.csv");
	fin1.open("pincode.csv");
	string b;
	const int d=f;
	int s=0,a,p;
	char c[20];
	string x[6];
	while(fin1)
    {
        getline(fin1,b);
        istringstream is(b);
        is.getline(c,10,',');
        p=atoi(c);
        if(p==d){
            a=1;
            break;}
    }
    if(a==1){
	while(fin)
	{
		getline(fin,b);
		istringstream in(b);
		for(int i=0;i<6;i++)
		{
			in.getline(c,19,',');
			x[i]=c;
		}
		int pincode = atoi(x[5].c_str());
		int fine = atoi(x[4].c_str());
		if(d==pincode)
			s+=fine;
	}
}
	else{
        cout<<"Pincode not present"<<endl;
        s=-1;

}
return s;
}
void maxmin()
{
    ifstream fin;
    fin.open("pincode.csv");
    string b;
    char c[15];
    int s[30];
    int j=0;
    string str[100];
    while(fin)
    {
        getline(fin,b);
		istringstream in(b);
        in.getline(c,16,',');
        s[j]=totalpincode(atoi(c));
        in.getline(c,16,',');
        str[j]=c;
        j++;
    }
    int temp;
    string temp1;
    int k;
    for(k=0; k<j-1; k++)
    {
     for(int m=0;m<=10-k;m++)
     {
     if(s[m]>s[m+1])
     {
     temp=s[m];
     s[m]=s[m+1];
     s[m+1]=temp;
     temp1=str[m];
     str[m]=str[m+1];
     str[m+1]=temp1;
     }
     }
     }
    cout<<"Highest fine collected = "<<s[k-1]<< " of area " << str[k-1]<<endl;
    cout<<"Lowest fine collected = "<<s[0]<< " of area " << str[0]<<endl;
}
   virtual void add_New()
{
    ofstream fout1,fout2;
    ifstream fin;
    fin.open("password.csv");
    fout2.open("penalty.csv",ios::app);
    fout1.open("password.csv",ios::app);
    char p[20],d[20];
    long long int x,y;
    int f=0;
    string b,a;
    cout<<"Welcome new user"<<endl;
    cout<<"Enter your 12 digit UIDAI number"<<endl;
    cin>>x;
    stringstream in;
         in<<x;
         b=in.str();
       if(b.length()!=12)
       {
           cout<<"You have entered wrong number"<<endl;
       }
       else
        {
    while(fin)
        {
    getline(fin,a);
        istringstream is(a);
        is.getline(d,16,',');
        y=atoll(d);
    if(x==y)
    {
        cout<<"User already registered"<<endl;
    fin.close();
        exit(0);
    }}
         fout1<<b<<",";
       cout<<"Enter your password"<<endl;
       cin>>p;
       fout1<<p<<","<<endl;
       fout2<<b<<",";
       cout<<"Enter your first name"<<endl;
       cin>>d;
       fout2<<d<<",";
       cout<<"Enter your last name"<<endl;
       cin>>d;
       fout2<<d<<",";
       cout<<"Enter your bank account"<<endl;
       cin>>d;
       fout2<<d<<",";
       cout<<"Enter the fine"<<endl;
       cin>>d;
       fout2<<d<<",";
       cout<<"Enter the pin code"<<endl;
       cin>>d;
       fout2<<d<<",,"<<endl;
       fout1.close();
       fout2.close();
    }}
    void add_Existing()
    {
        ifstream fin;
        fin.open("temp.csv");
        ofstream fout1,fout2,fout3;
        fout1.open("password.csv",ios::app);
        fout2.open("penalty.csv",ios::app);
        string a;
        char d[20];
        int x=0,j;
        while(fin)
        {
            getline(fin,a);
            x++;
        }
        x--;
        fin.close();
        if(x>0)
        {
            fin.open("temp.csv");
            for(int i=1;i<=x;i++)
            {
                getline(fin,a);
                istringstream is(a);
                is.getline(d,20,',');
                cout<<"UIDAI Number : "<<d<<endl;
                is.getline(d,20,',');
                cout<<"Password : "<<d<<endl;
                is.getline(d,20,',');
                cout<<"First name : "<<d<<endl;
                is.getline(d,20,',');
                cout<<"Last Name : "<<d<<endl;
                is.getline(d,20,',');
                cout<<"Bank Account : "<<d<<endl;
                is.getline(d,20,',');
                is.getline(d,20,',');
                cout<<"Pin Code : "<<d<<endl;
                cout<<"Press 1 to add this to main database\nPress 0 to discard this data\nEnter your choice"<<endl;
                cin>>j;
                if(j==1)
                {
                    istringstream in(a);
                    in.getline(d,20,',');
                    fout1<<d<<",";
                    fout2<<d<<",";
                    in.getline(d,20,',');
                    fout1<<d<<","<<endl;
                    for(int y=0;y<5;y++)
                    {
                        in.getline(d,20,',');
                        fout2<<d<<",";
                    }
                    fout2<<","<<endl;
                }
                else if(j==0)
                {
                    continue;
                }
            }
            fin.close();
            fout1.close();
            fout2.close();
            fout3.open("temp.csv",ios::trunc);
            fout3.close();
        }
        else
            cout<<"There is no data to be entered"<<endl;

    }
    void total()
{
    ifstream fin;
    fin.open("penalty.csv");
    string b;
    int s=0;
    char c[15];
    while(fin)
    {
    getline(fin,b);
    istringstream in(b);
    for(int i=0;i<5;i++)
    in.getline(c,16,',');
    s+=atoi(c);
    }
    cout<<"Total Fine = Rs. "<<s;
}
virtual void edit()
{

}
virtual void search()
    {
        ifstream fin;
        fin.open("penalty.csv");
        string b,l[6];
        int f=0;
        cout<<"Enter the UIDAI number: "<<endl;
        char c[16],d[16];
        cin>>c;
        while(fin)
        {
        getline(fin,b);
        istringstream is(b);
        is.getline(d,16,',');
        if(strcmp(c,d)==0)
        {
            l[0]=d;
       for(int i=1;i<6;i++)
       {
           is.getline(d,16,',');
           l[i]=d;
       }
       f=1;
       break;
        }
    }
    if(f==1)
    {
       cout<<"The details of the citizen are :"<<endl;
       cout<<"UIDAI number: "<<l[0]<<endl;
       cout<<"First name: "<<l[1]<<endl;
       cout<<"Last name: "<<l[2]<<endl;
       cout<<"Bank Account no: "<<l[3]<<endl;
       cout<<"Fine: Rs."<<l[4]<<endl;
       cout<<"Area: "<<l[5]<<endl;
    }
    else
        cout<<"You have entered wrong UIDAI number.\nPlease check again and try later"<<endl;
        fin.close();
    }
    void del()
{
    ifstream fin;
    ifstream f3;
    ofstream  f1;
    ofstream f2;
    fin.open("password.csv");
    char c[30],p[30],d[30];
    string b,l;
    int x=0;
    cout<<"Enter UIDAI of the user that you want to delete"<<endl;
    cin>>c;
    string s;
    while(fin)
    {
         getline(fin,s);
       istringstream is(s);
       is.getline(d,16,',');
       if(strcmp(c,d)==0)
        {
            x=1;
            fin.seekg(0,ios::beg);
            break;
        }
    }
    if(x==1){
    f1.open("temp1.csv");
    f2.open("temp2.csv");
    f3.open("penalty.csv");
    while(fin)
    {
        getline(fin,s);
        if(s=="")
            continue;
       istringstream is(s);
       is.getline(d,16,',');
    if(strcmp(c,d)!=0)
    {
        f1<<s<<endl;
    }
         if(fin.eof())
    break;
    }
    while(f3)
    {

       getline(f3,s);
if(s=="")
    continue;
istringstream in(s);
       in.getline(p,16,',');
    if(strcmp(c,p)!=0)
    {
        f2<<s<<endl;
    }
        if(f3.eof())
    break;
    else
        continue;
    }
    cout<<"Profile deleted"<<endl;
    }
    else{
        cout<<"Profile Not Present"<<endl;
        exit(0);}
    fin.close();
    f1.close();
    f3.close();
    f2.close();
    remove("penalty.csv");
    remove("password.csv");
    rename("temp1.csv","password.csv");
    rename("temp2.csv","penalty.csv");
}
};
//User Class contains login() edit() new_user() functions.
class User:public Administrator
{
    public:
    void edit()
{
    ifstream fin;
    ifstream f3;
    ofstream f1;
    ofstream f2;
    fin.open("password.csv");
    f1.open("temp1.csv");
    char c[30],p[30],d[30];
    string b,l;
    int x=0;
    cout<<"Enter UIDAI of the user"<<endl;
    cin>>c;
    string s;
    int a;
    while(fin)
    {
        getline(fin,s);
        istringstream in(s);
        in.getline(d,16,',');
        if(strcmp(c,d)==0){
            x=1;
            break;}
    }
    if(x==1){
            fin.seekg(0,ios::beg);
        while(fin){
          getline(fin,s);
          if(s=="")
            continue;
       istringstream is(s);
       is.getline(d,16,',');
       if(strcmp(d,c)!=0)
        f1<<s<<endl;
        else
        {
                f1<<d<<",";
                is.getline(d,16,',');
                cout<<"Enter the old password"<<endl;
                cin>>p;
                if(strcmp(d,p)!=0){
                        cout<<"Wrong password"<<endl;
                        f1.close();
                        remove("temp1.csv");
                    break;
                    }
                else
                {
                    cout<<"Enter the new password"<<endl;
                    cin>>p;
                    f1<<p<<","<<endl;
                }
            }
            if(fin.eof())
                break;
        }
        fin.close();
        f1.close();
        remove("password.csv");
        rename("temp1.csv","password.csv");
    }
    else
    {
        cout<<"ID not present"<<endl;
        fin.close();
    }
    }
void search()
{
    ifstream fin,fin1;
    fin.open("password.csv");
    char c[20],p[19],d[19],t[19],e[20];
    string b,l[6],a,pass="";
    char ch;
    int f=0,f1=0;
    cout<<"Enter the UIDAI number"<<endl;
    cin>>c;
    while(fin)
    {
        getline(fin,b);
        istringstream is(b);
        is.getline(d,16,',');
    if(strcmp(c,d)==0)
    {
      f=1;
      is.getline(t,16,',');
      break;
    }
   else
    f=0;
    }
    if(f==1)
    {
       cout<<"Enter the password"<<endl;
          ch = _getch();
   while(ch != 13){
        pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
cout<<"\n";
strcpy(p, pass.c_str());
       if(strcmp(t,p)==0)
        {
           f1=1;
           fin1.open("penalty.csv");
          while(fin1)
          {
           getline(fin1,a);
           istringstream in(a);
           in.getline(e,19,',');
           if(strcmp(e,c)==0)
           {
              l[0]=c;
              for(int x=1;x<6;x++)
              {
                  in.getline(e,19,',');
                  l[x]=e;
              }
           }

       }
        }
       else{
            pass="";
        cout<<"Wrong password"<<endl;}
    }
    else
        cout<<"Wrong id"<<endl;
if(f1==1)
{
    cout<<"The details of user ID "<<c<<" are :-"<<endl;
   cout<<"UIDAI number: "<<l[0]<<endl;
   cout<<"First name: "<<l[1]<<endl;
   cout<<"Last name: "<<l[2]<<endl;
   cout<<"Bank Account no: "<<l[3]<<endl;
   cout<<"Fine: Rs. "<<l[4]<<endl;
   cout<<"Area: "<<l[5]<<endl;
}
    fin.close();
    fin1.close();
}
void add_New()
{
    ofstream fout1,fout2;
    ifstream fin;
    fin.open("password.csv");
    fout2.open("temp.csv",ios::app);
    char p[20],d[20];
    long long int x,y;
    int f=0;
    string b,a;
    cout<<"Welcome new user"<<endl;
    cout<<"Enter your 12 digit UIDAI number"<<endl;
    cin>>x;
    stringstream in;
         in<<x;
         b=in.str();
       if(b.length()!=12)
       {
           cout<<"You have entered wrong number"<<endl;
       }
       else
        {
    while(fin)
        {
    getline(fin,a);
        istringstream is(a);
        is.getline(d,16,',');
        y=atoll(d);
    if(x==y)
    {
        cout<<"User already registered"<<endl;
    fin.close();
        exit(0);
    }}
         fout2<<b<<",";
       cout<<"Enter your Password"<<endl;
       cin>>p;
       fout2<<p<<",";
       cout<<"Enter your First name"<<endl;
       cin>>d;
       fout2<<d<<",";
       cout<<"Enter your Last name"<<endl;
       cin>>d;
       fout2<<d<<",";
       cout<<"Enter your Bank Account"<<endl;
       cin>>d;
       fout2<<d<<","<<"0,";
       cout<<"Enter the Pin Code"<<endl;
       cin>>d;
       fout2<<d<<",,"<<endl;
       fout2.close();
       cout<<"thanks, Your data has been stored and will be added upon verification by the Administrator"<<endl;
    }}};
//start of main()
int main()
{
    User us;
    Administrator ad;
    Administrator *obj;
    int c,b,e,f,x;
    string a="",d="admin1234";
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"\n *** Welcome to Smart Waste Disposal System *** \n"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Press 1 for Citizen's Interface "<<endl;
    cout<<"Press 2 for Administrator's Interface "<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>c;
    do
    {
    if(c==1)
        {
            obj=&us;
            cout<<"---------------------------------------------------------------------------------------"<<endl;
            cout<<"Welcome Citizen"<<endl;
            cout<<"---------------------------------------------------------------------------------------"<<endl;cout<<"Press 1 for Existing User Interface"<<endl;
            cout<<"Press 2 to Sign up as New User Interface"<<endl;
            cout<<"Press 0 to exit"<<endl;
            cout<<"Enter your choice"<<endl;
            cin>>b;
            if(b==1)
            {
                cout<<"---------------------------------------------------------------------------------------"<<endl;
                cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
                cout<<"Press 1 to view the Profile Details"<<endl;
                cout<<"Press 2 to change the Password"<<endl;
                cout<<"Enter your choice"<<endl;
                cout<<"---------------------------------------------------------------------------------------"<<endl;
                cin>>x;
                if(x==1)
                    {    system("cls");
                        obj->search();
                    }
                else if(x==2)
                {
                    system("cls");
                    obj->edit();
                }
                else
                    cout<<"Wrong choice"<<endl;
            }
            else if(b==2)
            {
                system("cls");
                obj->add_New();
            }
            else if(b==0)
                exit(0);
            else
                cout<<"You have Entered Wrong Choice"<<endl;
        }
    else if(c==2)
        {
            obj=&ad;
            system("cls");
            cout<<"Enter password"<<endl;
            char ch;
            ch = _getch();
         while(ch !=13){//character 13 is enter
      a.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<endl;
            if(a==d)
            {
                cout<<"---------------------------------------------------------------------------------------"<<endl;
                cout<<"Welcome Administrator"<<endl;
                cout<<"---------------------------------------------------------------------------------------"<<endl;

               do
               {
                   cout<<"\nPress 1 to Search the database by UIDAI number"<<endl;
                   cout<<"Press 2 to Create a new account"<<endl;
                   cout<<"Press 3 to Check the total fine"<<endl;
                   cout<<"Press 4 to Search for fine by pin-code"<<endl;
                   cout<<"Press 5 to Display areas with the highest and lowest penalties"<<endl;
                   cout<<"Press 6 to Delete a profile"<<endl;
                   cout<<"Press 7 to Modify the fine of a citizen"<<endl;
                   cout<<"Press 0 to exit"<<endl;
                   cout<<"Enter your choice"<<endl;
                   cout<<"---------------------------------------------------------------------------------------"<<endl;
                   cin>>e;
                   switch(e)
                   {
                   case 1:
                       {
                    system("cls");
                    obj->search();
                     }
                    break;
                   case 2:
                    cout<<"Press 1 to Add a new account"<<endl;
                    cout<<"Press 2 to Verify the Temporary accounts"<<endl;
                    cout<<"Enter your Choice"<<endl;
                    cin>>f;
                    if(f==1)
                    {
                        system("cls");
                        obj->add_New();
                    }
                    else if(f=2)
                    {    system("cls");
                        obj->add_Existing();
                    }
                    else
                        cout<<"You have entered wrong choice"<<endl;
                        break;
                   case 3:
                       {
                    system("cls");
                    obj->total();
                       }
                    break;
                    case 4:
                    int f,s;
                    cout<<"Enter the pin-code to show total fine for:"<<endl;
                    cin>>f;
                    system("cls");
                    s=obj->totalpincode(f);
                    if(s>0)
                    cout<<"Total fine for pin-code "<< f <<" is: "<<s<<endl;
                    break;
                   case 5:
                    system("cls");
                    obj->maxmin();
                    break;
                   case 6:
                    system("cls");
                    obj->del();
                    break;
                   case 7:
                    system("cls");
                    obj->fine();
                    break;
                   case 0:
                       exit(0);
                    break;
                   default:
                    cout<<"You have entered wrong choice"<<endl;
                   }
               }
               while(e!=0);
            }
            else{
                    a="";
                cout<<"You have entered wrong password"<<endl;
        }}
    else
    cout<<"You have Entered an invalid choice!"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Press 1 for Citizen's Interface"<<endl;
    cout<<"Press 2 for Administrator's Interface"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Press 0 to Exit"<<endl;
    cout<<"Enter your Choice"<<endl;
    cin>>c;
    }
    while(c!=0);
}
