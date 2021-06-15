#include<iostream>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<fstream>
using namespace std;
string currentuser;
class employee{                                             // TO CREATE BASIC DATA AND FUNCTIONS OF EMPLOYEE WHICH IS COMMON TO ALL THE CLASSES

protected:

    string emp_name;
    int emp_id;
    string emp_pwd;
    string desig;
    float exp;


    public:

    employee(){
        emp_name="";
        emp_id=0;
        emp_pwd="";
        desig="";
    }

    void getemp_data(){                                         // TO GET EMPLOYEE DATA FOR NEW USER
         system("cls");

        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER EMPLOYEE NAME: ";
        cin.ignore();
        getline(cin,emp_name);
              cout<<"\n\t\t\t\t\t\t\t\t\tENTER DESIGNATION: ";
      //  cin.ignore();
        getline(cin,desig);
        cout<<"\n\t\t\t\t\t\t\t\t\tENTER EMPLOYEE ID: ";
        cin>>emp_id;

        cout<<"\n\t\t\t\t\t\t\t\t\tENTER PASSWORD: ";
        cin.ignore();
        getline(cin,emp_pwd);
        cout<<"\n\t\t\t\t\t\t\t\t\tEXPERIENCE";
        cin>>exp;
         currentuser=emp_name+emp_pwd;                                                    // CURRENT USER WHO IS USING THE PROGRAM ,HIS DATA WILL SAVE AS EMP+PWD FILE
        currentuser+=".txt";
        fstream out(currentuser,ios::out|ios::app);
        fstream out2("list.txt",ios::out|ios::app);                                       // TO STORE COMMUNICATION DETAILS OF AN EMPLOYEE

        out<<"name: "<<emp_name<<endl;
        out<<"designation: "<<desig<<endl;
        out<<"id: "<<emp_id<<endl;
        out<<"emp_pwd: "<<emp_pwd<<endl;
        out<<"exp: "<<exp<<endl;
        //out2<<emp_name<<endl;
        out2<<"--------------------------------------------------------------\n";
        out2<<"name: "<<emp_name<<endl;
        out2<<"designation: "<<desig<<endl;
        out2<<"id: "<<emp_id<<endl;
        out2<<"exp: "<<exp<<endl;
        out2.close();                                                                      // CLOSING OF CURRENT USER FILE
        out.close();                                                                       // CLOSING OF LIST FILE

    }

};

class health_dep: virtual public employee{                                               // TO DEAL WITH THE HEALTH DEPARTMENT OF COMPANY
    protected:
       char well;
       float temp;
       string symptom;
       float weight;
       float height;
       string apphos;

    public:
       health_dep(){
           temp=0.0;
           symptom="";
           weight=0.0;
           height=0.0;
           apphos="You have no appointments";
        }

       void appointment(){                                                                    //TO BOOK APPOINTMENT IF USER WANT TO

           char ap;
         cout<<"\n\t\t\t\t\t\t\t\t  DO YOU WANT TO FIX AN APPOINTEMNT(Y/N)";
         cin>>ap;

        if(ap=='Y')
         {
            system("cls");
             int c;
             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tHOSPITALS IN YOUR COMANY PANEL ARE:\n ";
             cout<<"\n\t\t\t\t\t\t\t\t1.x\n\t\t\t\t\t\t\t\t2.y\n\t\t\t\t\t\t\t\t3.z";
             cout<<"\n\n\t\t\t\t\t\t\t\tSELECT HOSPITAL FOR APPOINTMENT ";
             cin>>c;
               switch(c)
                  {   case 1: apphos="\t\t\t\t\t\t\t\tYou have appointment at x between 10-12\n";

                          break;
                      case 2: apphos="\t\t\t\t\t\t\t\tYou have appointment at y between 10-12\n";

                          break;
                          case 3: apphos="\t\t\t\t\t\t\t\tYou have appointment at z between 10-12\n";

                          break;

                  }

            cout<<apphos;
            getch();

         }
         else{
             cout<<"\n\t\t\t\t\t\t\t\t\tTHANKS FOR CONTACTING US";  getch();
         }

       }

       void healthcondtion()                                                                               // TO TAKE THE HEALTH CONDTION OF USERS WETHER HE/SHE IS FELLING GOOD OR NOT
       {   char cp;
           cout<<"\n\t\t\t\t\t\t\t\t\tARE YOU FELLING WELL(Y/N)";
            cin>>cp;
            if(cp=='N')
            {
                appointment();
            }
       else{
       cout<<"\n\t\t\t\t\t\t\t\t\tYOU ARE FIT THATS GOOD";
         Sleep(500);
          }
       }

       void gethealthdata(){                                                                                    //TO GET BSIC HEALTH INFORMATION OF AN EMPLOYEE
           system("cls");

           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   ENTER TEMP.(F):";
           cin>>temp;

           cout<<"\n\t\t\t\t\t\t\t\t\t   ENTER WEIGHT: ";
           cin>>weight;

           cout<<"\n\t\t\t\t\t\t\t\t\t   ENTER HEIGHT: ";
           cin>>height;

           cout<<"\n\t\t\t\t\t\t\t\t\t   ENTER SYMPTOMS: ";
           cin>>symptom;

           healthcondtion();

       }

};
class finance_dep:virtual public employee{                                                          //TO DEAL WITH PROBLEMS RELATED TO FINANCE
     protected:
     float sal;
     int  maxloan;
     long walletbal;
     public:
        void assignsal()                                                                           // IT WILL ASSIGN THE SALARY ARE PER USER DESIGNATION AND PRINT IT IN THE CURRENT USER FILE
        {   fstream out(currentuser,ios::out|ios::app);
            if(desig=="manager"){
                    sal=10000;
                    out<<"salary : "<<sal<<endl;
            }
            else if(desig=="ceo"){
                sal=150000;
                out<<"salary : "<<sal<<endl;
            }
            else if(desig=="assistant manager"){
                sal=50000;
                out<<"salary : "<<sal<<endl;
            }
            else if(desig=="receptionist"){
                sal=1000;
                out<<"salary : "<<sal<<endl;
            }
            else if(desig=="head of security"){
                sal=5000;
                out<<"salary : "<<sal<<endl;
            }
            else if(desig=="security department"){
                sal=10000;
                out<<"salary : "<<sal<<endl;
            }
            else if(desig=="head developer"){
                sal=120000;
                out<<"salary : "<<sal<<endl;
            }
             else if(desig=="developer"){
                sal=10000;
                out<<"salary : "<<sal<<endl;
            }
              out.close();                                                                         //CLOSING OF FILE
          }

            void salary()                                                                          // TO SHOW SALARY STATUS OF CURRENT USER
            {     system("cls");
                fstream out(currentuser.c_str(),ios::out|ios::app|ios::in);
                   string sal_string;
                   while (out >> sal_string)                                                       // LOOP TO SEARCH SALARY OF CURRENT USER FRONT THE FILE
                        {
                            if(sal_string=="salary")
                          {
                               out.seekp(1,ios::cur);
                                out >> sal_string;

                            break;
                        }
                        }
                   int sal_int = stoi(sal_string);                                                 // CONVERTING THE SALARY  STRING TYPE OF CURRENT USER TO INTERGER TYPE
                   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR CURRENT SALARY IS: "<<sal_int;
                          cout<<"\n\t\t\t\t\t\t\t\tYOUR SALARY WILL UPDATE AT 27 OF THIS MONTH  ";
                          cout<<"\n\t\t\t\t\t\t\t\tIF FACING ISSUES REGARDING SALARY CONTACT ADMIN  ";
                              getch();
                             system("cls");
                             out.close();                                                           // CLOSING OF CURRENT USER FILE

            }
            void applyforloan(int y)                                                                //TO ISSUE LOAN TO THE CURRENT USER 1 FOR HEALTH LOAN AND 2 FOR PERSONAL LOAN
            {  int youramt,amt_hamt,your_hamt;
              system("cls");
                   fstream out(currentuser.c_str(),ios::out|ios::app|ios::in);
                   string sal_string;
                   while (out >> sal_string)                                                        //TO SEARCH SALARY OF USER FROM THE FILE
                        {
                            if(sal_string=="salary")
                          {
                               out.seekp(1,ios::cur);
                                out >> sal_string;

                            break;
                        }
                        }
                   int sal_int = stoi(sal_string);                                                  //CONVERTING SALARY FROM STRING TYPE TO INT TYPE
                   out.seekg(0);                                                                    //MOVING FILE POINTER TO BEGINING OF THE FILE
                   string exp_string;
                   while (out >>exp_string)                                                        //TO SEARCH EXPERIENCE FROM THE USER FILE
                        {
                            if(exp_string=="exp:")
                          {
                                out >>exp_string;

                            break;
                        }
                        }
                   int exp_int = stoi(exp_string);                                                    // CONERTING EXPERINCE FROM STRING TYPE TO INT TYPE


               if(y==2)
              {

                if((exp_int>1 and (exp_int<2))){                                                    //ASSIGNING LOAN ON THE BASIS OF EXPERIENCE AND SALARY OF USER
                    maxloan=2*sal_int;
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR MAXINUM PERSONAL LOAN LIMIT IS: "<<maxloan;
                }
                else if( exp_int>2 and exp_int<3){
                    maxloan=3*sal_int;
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR MAXINUM PERSONAL LOAN LIMIT IS: "<<maxloan;
                }
                else if(exp_int>3 and exp_int<4  ){
                    maxloan=4*sal_int;
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR MAXINUM PERSONAL LOAN LIMIT IS: "<<maxloan;
                }
                else if(exp_int>=5){
                    maxloan=6*sal_int;
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR MAXINUM PERSONAL LOAN LIMIT IS: "<<maxloan;
                }
                else{
                    maxloan=0;
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR MAXINUM PERSONAL LOAN LIMIT IS: "<<maxloan;
                }
                 cout<<"\n\n\t\t\t\t\t\t\t\tAMOUNT DO YOU WANT TO TAKE IT AS LOAN:  ";
                cin>>youramt;

                if(youramt>maxloan){                                                                                       // IF THE AMOUNT HE/SHE DEMANANED IS GRATER THAN THE MAX LOAN
                    cout<<"\n\n\t\t\t\t\t\t\t\tYOU CANNOT RECIEVE LOAN";
                    getch();
                    system("cls");
                }
                else{  char  t;
                    cout<<"\n\n\t\t\t\t\t\t\t\tYOU ARE ELIGIBLE FOR LOAN ";
                    cout<<"\n\n\t\t\t\t\t\t\t\tDO YOU WANT TO APPLY FOR LOAN";
                    cin>>t;

                    if(t=='y'){  cin.ignore();
                          cout<<"\n\n\t\t\t\t\t\t\t\tLOAN APPLIED SUSSCESFULLY ";
                                 getch();
                                 system("cls");
                    }
                    else{  cin.ignore();
                        cout<<"\n\n\t\t\t\t\t\t\t\tTHANKS FOR CONTACTING US HAVE H NICE DAY";
                        getch();
                        system("cls");
                    }
                }

              }

              if(y==1)                                                                                                                             //HEALTH SECTION LOAN PART
              {  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR MAXINUM HEALTH LOAN LIMIT IS: "<<sal_int<<endl;                       //MAX LOAN AMOUNT

                  cout<<"\n\t\t\t\t\t\t\t\tAMOUNT DO WANT AS LOAN  ";
                cin>>your_hamt;

                if(your_hamt>sal_int){                                                                                                               // IF THE AMOUNT HE/SHE DEMANANED IS GRATER THAN THE MAX LOAN
                    cout<<"\n\t\t\t\t\t\t\t\tYOU CANNOT RECIEVE LOAN";
                    getch();
                    system("cls");
                }
                 else{  char  q;
                    cout<<"\n\t\t\t\t\t\t\t\tYOU ARE ELIGIBLE FOR LOAN";
                    cout<<"\n\t\t\t\t\t\t\t\tDO YOU WANT TO APPLY FOR LOAN";
                    cin>>q;
                    cin.ignore();
                    if(q=='y'){
                          cout<<"\n\n\t\t\t\t\t\t\t\tLOAN APPLIED SUSSCESFULLY";  getch();
                          system("cls");
                    }
                    else{
                        cout<<"\n\t\t\t\t\t\t\t\tTHANKS FOR CONTACTING US HAVE H NICE DAY";  getch(); system("cls");
                    }
                }

              }
               out.close();                                                                                  // CLOSING OF CURRENT USER FILE

              }
          void mywallet()                                                                                    // TO SHO USER CURRENT WALLET DETAILS
            {   system("cls");
                fstream out(currentuser.c_str(),ios::out|ios::app|ios::in);
                   string str_mywallet;

                while (out >> str_mywallet)                                                                  // SEARCHING OF CURRENT WALLET FROM THE FILE
                        {
                            if(str_mywallet=="walletbal:")
                          {
                                out >> str_mywallet;

                            break;
                        }


                        }

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYOUR WALLET BALANCE IS : "<<str_mywallet<<endl;
                cout<<"\n\n\t\t\t\t\t\t\t\tYOUR WALLET WILL UPDATE AFTER 27 OF THIS MONTH "<<endl;
                getch();
                out.close();
                system("cls");
            }
           void assignwalletbalance()                                                                              // ASSING WALLET BALANCE TO THE USER
           {  walletbal=sal*0.1;
               fstream out(currentuser.c_str(),ios::out|ios::app|ios::in);
               out<<"walletbal: "<<walletbal<<"            ";
               out.close();

           }

        };
        class communication:virtual public employee{                                                    // TO PROVIDE FACILITIES TO THE USER TO KEEP IN TOUCH WITH OTHER EMPLOYEE

        protected:
           string  email;
           unsigned long long int phoneno;
            string add;
            string linkedin;
        public:
        void enterdata()                                                                                 // ENERING BASIC DETAILS OF THE EMPLOYEE

        {    ofstream out2("list.txt",ios::app);
            ofstream out(currentuser,ios::app);
            cout<<"\n\t\t\t\t\t\t\t\t\tENTER UR EMAIL: ";
           cin.ignore();
           getline(cin,email);
           out<<"email : "<<email<<"\n";

           cout<<"\n\t\t\t\t\t\t\t\t\tENTER PHONE NO. ";
           cin>>phoneno;
            out<<"phone no : "<<phoneno<<"\n";
           cout<<"\n\t\t\t\t\t\t\t\t\tENTER ADDRESS: ";
           cin.ignore();
           getline(cin,add);
           out<<"address : "<<add<<"\n";

           cout<<"\n\t\t\t\t\t\t\t\t\tENTER LINKED IN: ";
           cin.ignore();
           getline(cin,linkedin);
           out<<"linkedin : "<<linkedin<<"\n";
           out2<<"email : "<<email<<"\n";
           out2<<"phone no : "<<phoneno<<"\n";
           out2<<"linkedin : "<<linkedin<<"\n";
           out2<<"--------------------------------------------------------------\n";
           out2.close();


           out.close();
           system("cls");
        }

         void searchemp()                                                                                                               //SERCHING OF EMPLOYEE IN A FILE
         {    system("cls");
              string nametemp,searchname;
             int flag=-1;
              cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER EMPLOYEE NAME: ";
               cin.ignore();
               getline(cin,nametemp);

                fstream out("list.txt",ios::in|ios::out);
                 while (out >>searchname )
                        {
                            if(searchname==nametemp)
                          {   cout<<"\n\t\t\t\t\t\t\t\t\tEMPLOYEE FOUND: "<<nametemp;
                              flag=0;
                            break;
                        }


                        }
                if(flag==-1)  cout<<"\n\t\t\t\t\t\t\t\t\tEMPLOYEE NOT FOUND ";
                getch();
                system("cls");
         }
        void list()                                                                                                                 //TO SHOW THE LIST OF AND DETIALS OF OTHER COLLEAGUES
        {    system("cls");
             fstream out("list.txt",ios::in|ios::out|ios::app);
               char ch;
               string s;
               while(out)
               {  out.get(ch);
                cout<<ch;


               }
         cout<<"whom you want to contact";
                cin.ignore();
                cin>>s;
                cout<<"request send to "<<s;
                out.close();
                getch();
                system("cls");

        }



        };

        class traveldep:virtual public employee,public finance_dep{
        protected:
           int travelexp;
            public:
            void bookcab(){                                                                                                                 //TO BOOK CAB FOR THE USER
                system("cls");
                fstream out(currentuser.c_str(),ios::out|ios::in);
                string str_travelexp,str_mywallet;
                int int_travelexp,int_mywallet;
                while (out >> str_travelexp)                                                                                                //FINGING CURRENT TRAVEL EXPENSE FROM THE FILE
                        {
                            if(str_travelexp=="travelexp:")
                          {
                               out.seekp(1,ios::cur);
                                out >> str_travelexp;

                            break;
                        }


                        }

                        int_travelexp=stoi(str_travelexp);                                                                                  // CONERTING TRAVEL EXPENSES FROM STRING TYPE TO INT TYPE
                        out.seekg(0);
                        while (out >> str_mywallet)                                                                                        // FINDING CURRENT WALLET BALACE OF USER
                        {
                            if(str_mywallet=="walletbal:")
                          {
                                out >> str_mywallet;

                            break;
                        }


                        }

                        int_mywallet=stoi(str_mywallet);                                                                                   // CONERTING INTO INT
                        out.seekg(0);


                int f;
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWHICH CALSS OF CAB DO YOU WANT TO BOOK"<<endl;
                cout<<"\n\n\t\t\t\t\t\t\t\t\t1-ECONOMIC CLASS\n\n\t\t\t\t\t\t\t\t\t2-DELUXE CLASS\n\n\t\t\t\t\t\t\t\t\t3-PREMIMUM CLASS";
                cin>>f;

                if(f==1){
                    cout<<"\n\n\t\t\t\t\t\t\t YOUR CAB HAS BEEN BOOKED AND IT WILL ARRIVE IN 10-15 MINS.";
                    cout<<"\n\n\t\t\t\t\t\t\t\t 150 RUPPES HAS BEEN DEDUCTED FROM MY WALLET";
                      getch();
                          string e;
                   while (out >> e)
                        {
                            if(e=="travelexp:")
                          {
                               out.seekp(1,ios::cur);

                            break;
                        }


                        }
                        int_travelexp+=150;
                         out<<int_travelexp<<"    ";
                         out.seekp(0);

                   while (out >> e)
                        {
                            if(e=="walletbal:")
                          {
                            break;
                        }


                        }

                   int_mywallet-=150;
                   out<<int_mywallet<<"    ";
                }
                if(f==2){
                   cout<<"\n\n\t\t\t\t\t\t\t YOUR CAB HAS BEEN BOOKED AND IT WILL ARRIVE IN 10-15 MINS.";
                    cout<<"\n\n\t\t\t\t\t\t\t\t 300 RUPPES HAS BEEN DEDUCTED FROM MY WALLET";
                    getch();

                    string e;
                   while (out >> e)
                        {
                            if(e=="travelexp:")
                          {
                               out.seekp(1,ios::cur);

                            break;
                        }


                        }
                        int_travelexp+=300;
                         out<<int_travelexp<<"    ";
                         out.seekp(0);

                   while (out >> e)
                        {
                            if(e=="walletbal:")
                          {
                            break;
                        }


                        }

                   int_mywallet-=300;
                   out<<int_mywallet<<"    ";
                   system("cls");
                }
                if(f==3){
                    cout<<"\n\n\t\t\t\t\t\t\t YOUR CAB HAS BEEN BOOKED AND IT WILL ARRIVE IN 10-15 MINS.";
                    cout<<"\n\n\t\t\t\t\t\t\t\t 500 RUPPES HAS BEEN DEDUCTED FROM MY WALLET";
                    getch();

                   string e;
                   while (out >> e)
                        {
                            if(e=="travelexp:")
                          {
                               out.seekp(1,ios::cur);

                            break;
                        }


                        }
                        int_travelexp+=500;
                        out<<int_travelexp<<"    ";
                         out.seekp(0);

                   while (out >> e)
                        {
                            if(e=="walletbal:")
                          {
                            break;
                        }


                        }

                   int_mywallet-=500;
                out<<int_mywallet<<"    ";
                }

                   system("cls");
            }
            void travelexpense(){  system("cls");                                                                       // TO SHOW CURRENT TRAVEL EXPENSES OF USER

                   fstream out(currentuser.c_str(),ios::out|ios::in);
                string str_travelexp;
                int int_travelexp;
                while (out >> str_travelexp)
                        {
                            if(str_travelexp=="travelexp:")
                          {
                               out.seekp(1,ios::cur);
                                out >> str_travelexp;

                            break;
                        }


                        }

                        int_travelexp=stoi(str_travelexp);

             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tYOUR CURRENT TRAVEL EXPENSE IS: "<<int_travelexp;
                       getch();
                       out.close();
                               system("cls");
            }


            void assigtravelexpense()                                                                                  // ASSISNING CURRENT TRAVEL EXPENES TO USER
            {       fstream out(currentuser.c_str(),ios::out|ios::app|ios::in);
               out<<"\ntravelexp: 0        ";

            }

        };

        class final:public health_dep,public communication,public traveldep{
            public:
            protected:
        }f;

void login();                                                                                                          // VARIOUS MENU AND LOGIN FUNCTION USED
void mainmenu();
void health_menu();
void finance_menu();
void comms_menu();                                                                                                     // COMMINUCATION MENU
void travel_menu();

       void login(){
           system("cls");

           int t;
               do{ cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1.LOGIN ";
                cout<<"\n\n\t\t\t\t\t\t\t\t\t2.NEW USER";
                cout<<"\n\n\t\t\t\t\t\t\t\t\t0.EXIT";
                cout<<"\n\n\t\t\t\t\t\t\t\t    ENTER YOUR CHOICE: ";
                //cout<<"\n\t\t\t\t\t\t\t\t\t";
                cin>>t;
                if(t==1){   system("cls");
                        string name,pwd;
                           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER NAME :";
                            cin.ignore();
                            cin>>name;
                            cout<<"\n\t\t\t\t\t\t\t\t\tENTER PASSWORD :";
                            cin>>pwd;
                             currentuser=name+pwd;
                            currentuser+=".txt";
                          //  cout<<f;
                            fstream out(currentuser,ios::in|ios::out|ios::in);
                            if(out.fail()){  system("color 04");
                                    cout<<"\n\t\t\t\t\t\t\t\t\tINCORRECT NAME OR PASSWORD!!!!!";
                                      Sleep(1000);
                                     system("color 07");
                            getch();
                            system("cls");}
                           else{  system("color 02");
                                    cout<<"\n\t\t\t\t\t\t\t\t\tSUCESSFULLY LOGGED IN";
                                     Sleep(1000);
                                     system("color 07");

                                mainmenu();

                           }





                        }
                else if(t==2){
                    f.getemp_data();
                    f.enterdata();
                    f.assignsal();
                    f.assignwalletbalance();
                    f.assigtravelexpense();
                    break;
                }
                else if(t==0){ exit(0);}
                else{
                    cout<<"\nWrong choice enter again";
                    system("cls");
                }

                }while(t!=0);

                return;

       }

       void health_menu()
       {  system("cls");
            int t;
           do{
           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t1. HEALTH ISSUE";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t2. HEALTH LOAN";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t11. PREVIOUS";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t0. EXIT ";
             cin>>t;

          switch (t)
          {
          case 1:  f.gethealthdata();
                    break;
           case 2:  f.applyforloan(1);
                    break;
            case 0:  exit(0);
                    break;
            case 11: mainmenu();
                    break;
          default:cout<<"\nWrong choice enter again";
                system("cls");
              break;
          }
          system("cls");
       }while(t!=0);

        return;

       }

       void finance_menu()
       {   system("cls");
           int t,y;
           // f.assignsal();
           do{
           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t1. SALARY STATUS";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t2. APPLY FOR LOAN ";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t3-MY-WALLET";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t11. PREVIOUS";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t0. EXIT";
             cin>>t;
          switch (t)
          {
          case 1:  f.salary();
                    break;
           case 2:  system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1.HEALTH LOAN\n\n\t\t\t\t\t\t\t\t\t2.PERSONAL LOAN";
                    cin>>y;
                    f.applyforloan(y);
                    break;
            case 3: f.mywallet();
                    break;
            case 0:  exit(0);
                    break;
            case 11: mainmenu();
                    break;
          default:cout<<"\nWrong choice enter again";
                system("cls");
              break;
          }
       }while(t!=0);

        return;

       }

       void comms_menu()
       {   system("cls");
           int t,y;
           // f.assignsal();
           do{
           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1. SEARCH AN EMPLOYEE";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t2. CONTACT DETAILS OF COLLIGUES";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t11. PREVIOUS";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t0. EXIT";
             cin>>t;
          switch (t)
          {
          case 1:  f.searchemp();
                    break;
           case 2:  f.list();
                    break;
            case 0:  exit(0);
                    break;
            case 11: mainmenu();
                    break;
          default:cout<<"\nWrong choice enter again";
                system("cls");
              break;
          }
       }while(t!=0);

        return;

       }

       void travel_menu()
        {  system("cls");
             int t,y;
          //  f.assignsal();
           do{
           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1. BOOK A CAB";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t2. PAST TRAVEL EXPENSES";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t11. PREVIOUS";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t0. EXIT";
             cin>>t;
          switch (t)
          {
          case 1:  f.bookcab();
                    break;
           case 2:  f.travelexpense();
                    break;
            case 0:  exit(0);
                    break;
            case 11: mainmenu();
                    break;
          default:cout<<"\nWrong choice enter again";
                system("cls");
              break;
          }
       }while(t!=0);

        return;

       }

       void mainmenu()
       {    system("cls");
           int t;
            do{
               cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWHICH DEPARTMENT DO YOU WANT TO CONTACT";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t1-HEALTH DEPARTMENT";
             cout<<"\n\n\t\t\t\t\t\t\t\t\t2-FINANCE DEPARTMENT";
              cout<<"\n\n\t\t\t\t\t\t\t\t\t3-COMMUNUCATION DEPARTMENT";
               cout<<"\n\n\t\t\t\t\t\t\t\t\t4-TRAVEL DEPARTMENT";
                cout<<"\n\n\t\t\t\t\t\t\t\t\t0-EXIT";
                 cout<<"\n\n\t\t\t\t\t\t\t\t\t11-PREVIOUS MENU ";
                 cin>>t;
                 switch(t)
                 {    case 0:  exit(0);
                                break;
                     case 1:  health_menu();
                                break;
                      case 2:  finance_menu();
                                break;
                         case 3:  comms_menu();
                                break;
                         case 4:  travel_menu();
                                 break;

                    case 11: {   system("color 02");
                              cout<<"\nt\t\t\t\t\t\t\t\t\tLOGGED OUT SUCESSFULL";
                                       Sleep(1000);
                                       system("color 07");
                        login();}
                               break;
                    default:  cout<<"\nWrong choice enter again";
                              system("cls");
                 }
       }while(t!=0);


       return;

       }
       void loadingBar()                                                                        //LOADING ANIMATION IN THE STARTING OF THE SCREEN
{
	// 0 - black background,
	// 1 - blue Foreground
	system("color 01");

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t        Loading...\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t";

	// Print initial loading bar
	for (int i = 0; i < 26; i++)
		cout<< a;

	// Set the cursor again starting
	// point of loading bar
	cout<<"\r";
   cout<<"\t\t\t\t\t\t\t\t\t";

	// Print loading bar progress
	for (int i = 0; i < 26; i++) {
             cout<< b;

		// Sleep for 1 second
		Sleep(100);
	}

}


        int main(){                                                                                               //DRIVER FUNCTION
            loadingBar();
	system("color 07");                                                                                            // SETTING BACKGROUND TO  BLACK AND FONT TO WHITE
	system("cls");
            login();
            mainmenu();

            return 0;

        }

