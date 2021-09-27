#include<bits/stdc++.h>
using namespace std;
class InputGrades  //base class
{
protected:
    string grade[100];
    string subjects[100];
    int NumofSubjects;
    int cred[100];
public:
    void input();
    void display();
};

void InputGrades::input()        //Function to input number of subjects,grades and credits
{
    cout<<"Enter Number of Subjects"<<endl;
    cin>>NumofSubjects;
    cout<<endl;
    for(int i=0;i<NumofSubjects;i++)
    {
        cout<<"Enter subject Name"<<endl;
        cin>>subjects[i];
        cout<<"Enter Grades obtained"<<endl;
        cin>>grade[i];
        cout<<"Enter Credits for the subjects"<<endl;;
        cin>>cred[i];
    }
}
void InputGrades::display()      //Function to display the inputted parameters
{
    cout<<setw(8)<<"Subjects"<<setw(10)<<"||"<<setw(8)<<"Grades"<<"    "<<setw(7)<<"||"<<setw(9)<<"Credits"<<endl;
     cout<<"------------------------------------------------------------------------------";
    cout<<endl;
    for(int i=0;i<NumofSubjects;i++)
    {
        cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<setw(3)<<"|| "<<setw(8)<<cred[i];
        cout<<endl;
    }
    cout<<endl;
}
class Cgpi:public InputGrades   //derived class
{
public:
    void displaygrades();
    int compute();
    void pointerPercentage();
};
void Cgpi::displaygrades()  //functon to convert inputted grades to marks
{
    cout<<setw(8)<<"Subjects"<<setw(10)<<"||"<<setw(8)<<"Grades"<<setw(11)<<"||"<<setw(8)<<"Marks"<<setw(7)<<"||"<<setw(8)<<"Credits"<<endl;
    cout<<"-----------------------------------------------------------------------------------";
    cout<<endl;
    for(int i=0;i<NumofSubjects;i++)
    {
        if(grade[i]=="AA")
        {
              cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<10<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
        else if(grade[i]=="AB")
        {
               cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<9<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
        else if(grade[i]=="BB")
        {

            cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<8<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
        else if(grade[i]=="BC")
        {

                cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<7<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
        else if(grade[i]=="CC")
        {

               cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<6<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
        else if(grade[i]=="CD")
        {

           cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<5<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
        else{

                cout<<setw(8)<<subjects[i]<<"        "<<"||"<<" "<<setw(8)<<grade[i]<<"        "<<"||"<<setw(8)<<"Fail"<<"     "<<"|| "<<setw(8)<<cred[i]<<endl;
        }
    }

}

int Cgpi::compute()    //function to store marks in map and  compute accordingly
{
    unordered_map<string,int>mp;
    for(int i=0;i<NumofSubjects;i++)
    {
        if(grade[i]=="AA")
        {
            mp[grade[i]]=10;
        }
        else if(grade[i]=="AB")
        {
            mp[grade[i]]=9;
        }
        else if(grade[i]=="BB")
        {
            mp[grade[i]]=8;
        }
        else if(grade[i]=="BC")
        {
            mp[grade[i]]=7;
        }
        else if(grade[i]=="CC")
        {
            mp[grade[i]]=6;
        }
        else if(grade[i]=="CD")
        {
            mp[grade[i]]=5;
        }
        else{
            mp[grade[i]]=0;
        }
    }

    int sum=0;
    for(int i=0;i<NumofSubjects;i++)
    {
        if(mp.find(grade[i])!=mp.end())
        {
            sum+=(mp[grade[i]]*cred[i]);
        }
    }
    return sum;
}
void Cgpi::pointerPercentage()  //function to convert sum to pointer and percentage
{
    int tot=0;
    for(int i=0;i<NumofSubjects;i++)
    {
        tot+=cred[i];
    }
    cout<<setprecision(3);
    cout<<endl;
    cout<<"The pointer computed is: "<< (double)compute()/tot<<endl;
    cout<<"The computed percentage is:"<<(10.00*((double)compute()/tot))-7.50;

}
int main()   //main function
{
    Cgpi c;   //object creation of derived class
    c.input();
    c.display();
    c.displaygrades();
    c.pointerPercentage();
    return 0;
}
