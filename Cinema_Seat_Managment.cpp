#include <bits\stdc++.h>
#include <conio.h>
using namespace std;
class Universal_Cinema
{
    string moive_name;
    string movie_time;
    float ticket_price;
    int seat_limit;

    string customer_name;
    string book_movie_name;
    int customer_age;
    public:
    void setdata();
    void showdata();
    void admin_add_movie();
    void admin_remove_movie();
    void show_all_movies();
    void updat_movie_details();
    void book_ticket();
    void setdata_customer();
    void cancel_seat();
};

void Universal_Cinema::setdata(){
    cout<<"\nENTER MOVIE NAME : ";cin>>moive_name;
    cout<<"ENTER MOVIE TIMING : ";cin>>movie_time;
    cout<<"ENTER TICKET PRICE : ";cin>>ticket_price; 
    cout<<"ENTER SEATS LIMIT : ";cin>>seat_limit;
}
void Universal_Cinema::showdata(){
    cout<<"\nMOVIE NAME IS : "<<moive_name<<endl;
    cout<<"MOVIE TIMINIG IS : "<<movie_time<<endl;
    cout<<"TICKET PRICE IS : "<<ticket_price<<endl;
    cout<<"TOTAL SEATS IN CINEMA : "<<seat_limit<<endl;
}
void Universal_Cinema::admin_add_movie(){
    int choice;
    fstream movie;
    movie.open("movie.csv",ios::out|ios::binary);
    if(!movie){
        cout<<"\nFILE NOT OCCUR....ERROR"<<endl;
        return;
    }
    do{
        setdata();
        movie.write((char*)(this),sizeof(*this));
        cout<<"\nDO YOU WANT TO ADD MORE MOVIE ?"<<endl;
        cout<<"PRESS 1 TO ADD AND 0 TO EXIT : ";cin>>choice;
    }while(choice==1);
    movie.close();
}
void Universal_Cinema::admin_remove_movie(){
    string movie_name2;
    fstream movie,movie1;
    movie.open("movie.csv",ios::in|ios::binary);
    movie1.open("movie1.csv",ios::out|ios::binary);
    if(!movie){
        cout<<"\nFILE NOT OCCUR....ERROR"<<endl;
        return; 
    }
    cout<<"\nENTER MOVIE NAME TO DELETE : ";cin>>movie_name2;
    movie.read((char*)this,sizeof(*this));
        while (!movie.eof())
        {  if(movie_name2!=moive_name){
            movie1.write((char*)this,sizeof(*this));
            movie.read((char*)(this),sizeof(*this));
            }
            else{
                cout<<"\nMOVIE NOT FOUND"<<endl;
            }
        }
        movie.close();
        movie1.close();
        remove("movie.csv");
        rename("movie1.csv","movie.csv");
        
    }
void Universal_Cinema::show_all_movies(){
    fstream movie;
    movie.open("movie.csv",ios::in|ios::binary);
    if(!movie){
        cout<<"\nFILE NOT OCCUR....ERROR"<<endl;
        return; 
    }
    movie.read((char*)this,sizeof(*this));
    while (!movie.eof())
    {
        showdata();
        movie.read((char*)this,sizeof(*this));
    }
    movie.close();
}
void Universal_Cinema::updat_movie_details(){
    string moive_name2;
    fstream movie;
    movie.open("movie.csv",ios::in|ios::out|ios::ate|ios::binary);
    if(!movie){
        cout<<"\nFILE NOT OCCUR....ERROR"<<endl;
        return; 
    }
    movie.seekg(0);
    movie.read((char*)this,sizeof(*this));
    cout<<"\nENTER MOVIE NAME TO EDIT DETAILS : ";cin>>moive_name2;
    while (!movie.eof())
    {
        if(moive_name2== moive_name){
        setdata();
        int a=movie.tellp();
        movie.seekp((a)-(sizeof(*this)));
        movie.write((char*)(this),sizeof(*this));
        }
        else{
            cout<<"\nMOVIE NOT FOUND"<<endl;
        }
        movie.read((char*)(this),sizeof(*this));
    }
    movie.close();
}
void Universal_Cinema::setdata_customer(){
    

}
void Universal_Cinema::book_ticket(){
    string customer_name1,moive_name1,customer_age1;
    int choice;
   fstream movie;
   movie.open("movie.csv",ios::out|ios::binary);
    if(!movie){
        cout<<"\nFILE NOT OCCUR....ERROR"<<endl;
        return; 
    }
        show_all_movies();
        cout<<"\n\nENTER CUSTOMER NAME : ";cin>>customer_name1;
        cout<<"ENTER CUSTOMER AGE : ";cin>>customer_age1;
        cout<<"ENTER MOVIE NAME : ";cin>>moive_name1;
        movie.read((char*)this,sizeof(*this));
        while (!movie.eof())
        {
            if(moive_name1!=moive_name){
                movie.write((char*)this,sizeof(*this));
                cout<<"MOVIE SEAT SUCESSFULLY BOOKED"<<endl;
                return;
            }
            else{
                cout<<"\nMOVIE NOT FOUND"<<endl;
            }
            movie.read((char*)this,sizeof(*this));
        }
             
      
   
    movie.close();
}
void Universal_Cinema::cancel_seat(){
    string customer_name1;
    fstream movie,movie1;
    movie.open("movie.csv",ios::in|ios::binary);
     if(!movie){
        cout<<"\nFILE NOT OCCUR....ERROR"<<endl;
        return; 
    }
    movie1.open("movie1.csv",ios::out|ios::binary);
    cout<<"\nENTER CUSTOMER NAME TO CANCEL SEAT : ";cin>>customer_name1;
    movie.read((char*)this,sizeof(*this));
    while (!movie.eof())
    {
        if(customer_name1!=customer_name){
            movie1.write((char*)this,sizeof(*this));
            movie.read((char*)this,sizeof(*this));
        }
        else{
            cout<<"\nMOVIE NOT FOUND"<<endl;
        }
    }
    movie.close();
    movie1.close();
    remove("movie.csv");
    rename("movie1.csv","movie.csv");
}
int main()
{
    Universal_Cinema admin;
    Universal_Cinema customer;
    int choice;
    string admin_password;
    string user_id;
    cout << "\n---------WELCOME TO UNIVERSAL CINEMA---------" << endl;
    cout << "\n1 => ADMIN" << endl;
    cout << "2 => CUSTOMER" << endl;
    cout << "3 => EXIT" << endl;
    cout << "\nENTER YOUR CHOICE : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\n-----WELCOME TO ADMIN PANEL-----" << endl;
        cout << "\nENTER USER ID : ";
        cin >> user_id;
        if (user_id == "HAIDER456")
            
        {
            cout << "\nENTER PASSWORD : ";
            cin >> admin_password;

            if (admin_password == "12345")
                
            {
                fh:
                cout << "\n1 => ADD MOVIE" << endl;
                cout << "2 => REMOVE MOVIE" << endl;
                cout << "3 => MODIFY MOVIE DETAILS" << endl;
                cout << "4 => SHOW ALL MOVIES" <<endl;
                cout << "5 => EXIT" << endl;
                cout << "\nENTER YOUR CHOICE : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                admin.admin_add_movie();
                goto fh;
                    break;
                case 2:
                admin.admin_remove_movie();
                goto fh;
                    break;
                case 3:
                admin.updat_movie_details();
                    break;
                case 4:
                admin.show_all_movies();
                getch();
                goto fh;
                    break;
                case 5:
                 exit(0);
                    break;
                default:
                cout<<"\nINVALID CHOICE.....TRY AGAIN "<<endl;
                    break;
                }
            }
            else {
            cout << "\nINCORRECT PASSWORD .....TRY AGAIN"<<endl;
            break;
        }

        }
        else {
            cout << "\nINCORRECT USER ID .....TRY AGAIN"<<endl;
            break;
        }

        break;
    case 2:
        hf:
        cout << "\n-----WELCOME TO CUSTOMER PANEL-----" << endl;
        cout << "\n1 => BOOK SEAT" << endl;
        cout << "2 => CANCEL SEAT" << endl;
        cout << "3 => SHOW ALL MOVIES" << endl;
        cout << "4 => EXIT" << endl;
        cout << "\nENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        customer.book_ticket();
        goto hf;
            break;
        case 2:
        customer.cancel_seat();
        goto hf;
            break;
        case 3:
        admin.show_all_movies();
        getch();
        goto hf;
            break;
        case 4:
        exit(0);
            break;
        default:
        cout<<"\nINVALID CHOICE.....TRY AGAIN "<<endl;
            break;
        }
        break;
    default:
    cout<<"\nINVALID CHOICE.....TRY AGAIN "<<endl;
        break;
    }
    return 0;
}