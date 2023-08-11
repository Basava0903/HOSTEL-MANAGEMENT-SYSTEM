#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
class artgallery
{
private:
    string id,title,type,u_name,u_email,a_id,a_name,address,style,gid,gname,glocation,eid,start_date,end_date,i;
    float price;
    int year,u_id,u_phno;
public:
    void panel();
    void gallery();
    void artwork();
    void artist();
    void customer();
    void exhibition();
    void insert();
    void search();
    void update();
    void del();
    void art_display();
    void admin_check_orders();
    void remove_orders();
    void a_insert();
    void a_search();
    void a_del();
    void a_display();
    void g_insert();
    void g_search();
    void g_del();
    void g_display();
    void e_insert();
    void e_search();
    void e_del();
    void e_display();
    void display();
    void order_booking();
    void customer_check_orders();
    int ord_search(string );

};

void artgallery::panel()
{
a:
    int choice;
    string email,password;
    char ch;
    cout<<"\n********************************************************************************";
    cout<<"\n\t\t\t\t ART GALLERY MANAGEMENT ";
    cout<<"\n********************************************************************************";
    cout<<"\n\n 1.Gallery Panel";
    cout<<"\n 2.Artwork Panel";
    cout<<"\n 3.Artist Panel";
    cout<<"\n 4.Customer Panel";
    //cout<<"\n 5.Exhibition Panel";
    cout<<"\n 5.Exit";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        gallery();
        break;
    case 2:
        cout<<"\n\n---------------------------Admin Login-----------------------------";
        cout<<"\n\n Enter the User-Id : ";
        cin>>email;
        cout<<"\n\n Enter the Password : ";
        cin>>password;
        if(email == "FS" && password == "123")
            artwork();
        else
            cout<<"\n\n\n\t\t\t\tAdmin Login Failed!....";
        break;
    case 3:
        artist();
        break;
    case 4:
        customer();
        break;
    //case 5:
    //      exhibition();
    //        break;
    case 5:
        exit(0);
    default:
        cout<<"\n\n Invalid Value...Please Enter the Valid One";
    }
    getchar();
    goto a;
}
void artgallery::artwork()
{
a:
    int choice;
    cout<<"\n\n*************************************************************************************";
    cout<<"\n\t\t\t\t Artwork Panel";
    cout<<"\n**************************************************************************************";
    cout<<"\n\n\n 1.Add New Artwork ";
    cout<<"\n 2.Search Artwork";
    cout<<"\n 3.Update Artwork";
    cout<<"\n 4.Delete Artwork";
    cout<<"\n 5.Display Artwork";
    cout<<"\n 6.Check orders";
    cout<<"\n 7.Confirm orders";
    cout<<"\n 8.Go Back";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
        break;
    case 4:
        del();
        break;
    case 5:
        art_display();
        break;
    case 6:
        admin_check_orders();
        break;
    case 7:
        remove_orders();
        break;
    case 8:
        panel();
    default:
        cout<<"\n\n Invalid Value...Please Enter the Valid One";
        //exit(0);
    }
    getchar();
    goto a;
}

void artgallery::artist()
{
a:
    int choice;
    cout<<"\n\n**************************************************************************************";
    cout<<"\n\t\t\t\t Artist Panel";
    cout<<"\n**************************************************************************************";
    cout<<"\n\n\n 1.Add New Artist ";
    cout<<"\n 2.Search Artist";
    cout<<"\n 3.Delete Artist";
    cout<<"\n 4.Display Artist";
    cout<<"\n 5.Go Back";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        a_insert();
        break;
    case 2:
        a_search();
        break;
    case 3:
        a_del();
        break;
    case 4:
        a_display();
        break;
    case 5:
        panel();
    default:
        cout<<"\n\n Invalid Value...Please Enter the Valid One";
        exit(0);
    }
    getchar();
    goto a;
}

void artgallery::a_insert()
{
a:
    fstream file;
    string ai,n,i,add,s;
    cout<<"\n\n---------------------Add The Details Of New Artist-----------------------";
    cout<<"\n\n\t Artist_Id : ";
    cin>>a_id;
    cout<<"\n\t Artist_Name : ";
    cin>>a_name;
    cout<<"\n\t Artwork_Id :";
    cin>>id;
    cout<<"\n\t Birthplace : ";
    cin>>address;
    cout<<"\n\t Style : ";
    cin>>style;
    file.open("artist.txt",ios::in);
    if(!file)
    {
        file.open("artist.txt",ios::app|ios::out);
        file<<" "<<a_id<<" "<<a_name<<" "<<id<<" "<<address<<" "<<style<<"\n";
        file.close();
    }
    else
    {
        file>>ai>>n>>i>>add>>s;
        while(!file.eof())
        {
            if(ai == a_id)
            {
                file.close();
                cout<<"\n\n Artist_id already exist!.....";
                getchar();
                goto a;
            }
            file>>ai>>n>>i>>add>>s;
        }
        file.close();
        file.open("artist.txt",ios::app|ios::out);
        file<<" "<<a_id<<" "<<a_name<<" "<<id<<" "<<address<<" "<<style<<"\n";
        file.close();
    }

}

void artgallery::a_search()
{
    fstream file;
    string ai;
    int found=0;
    cout<<"\n\n---------------------------Search Artist---------------------------------";
    cout<<"\n\n\t Artist_id : ";
    cin>>ai;
    file.open("artist.txt",ios::in);
    if(!file)
        artist();
    else
    {
        file>>a_id>>a_name>>id>>address>>style;
        while(!file.eof())
        {
            if(ai == a_id)
            {
                cout<<"\n\n----------------------------Search Artist----------------------";
                cout<<"\n\n\t Artist_Id : "<<a_id;
                cout<<"\n\t Artist_Name : "<<a_name;
                cout<<"\n\t Art_Id : "<<id;
                cout<<"\n\t Address : "<<address;
                cout<<"\n\t Sytle : "<<style;
                found++;
            }
            file>>a_id>>a_name>>id>>address>>style;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Artist_Id Not Found.......";
    }

}

void artgallery::a_del()
{
    fstream file,file1;
    string ai;
    int found=0;
    cout<<"\n\n---------------------------Delete Artist---------------------------";
    cout<<"\n\n\t Artist_id : ";
    cin>>ai;
    file.open("artist.txt",ios::in);
    if(!file)
        artist();
    else
    {
        file1.open("artist1.txt",ios::app|ios::out);
        file>>a_id>>a_name>>id>>address>>style;
        while(!file.eof())
        {
            if(ai == a_id)
            {
                cout<<"\n\n Record Deleted Successfully......";
                found++;
            }
            else
                file1<<" "<<a_id<<" "<<a_name<<" "<<id<<" "<<address<<" "<<style<<"\n";
            file>>a_id>>a_name>>id>>address>>style;
        }
        file.close();
        file1.close();
        remove("artist.txt");
        rename("artist1.txt","artist.txt");
        if(found == 0)
            cout<<"\n\nArtist_id Not Found!!!...";
    }

}
void artgallery::a_display()
{
    fstream file;
    int found=0;
    cout<<"\n\n---------------------------Display Artist Details--------------------------------";
    file.open("artist.txt",ios::in);
    if(!file)
        artist();
    else
    {
        file>>a_id>>a_name>>id>>address>>style;
        while(!file.eof())
        {
            // cout<<"\n\n\n ---------------------------------";
            cout<<"\n\n\n\t Artist_Id : "<<a_id;
            cout<<"\n\t Artist_Name : "<<a_name;
            cout<<"\n\t Art_Id : "<<id;
            cout<<"\n\t Address : "<<address;
            cout<<"\n\t Sytle : "<<style;
            found++;
            file>>a_id>>a_name>>id>>address>>style;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Records Not Found....";
    }
}

void artgallery::gallery()
{
a:
    int choice;
    cout<<"\n\n***************************************************************************************";
    cout<<"\n\t\t\t\t Gallery Panel";
    cout<<"\n****************************************************************************************";
    cout<<"\n\n\n 1.Add Gallery Info ";
    cout<<"\n 2.Search Gallery Info ";
    cout<<"\n 3.Delete Gallery Info";
    cout<<"\n 4.Display Gallery Info";
    cout<<"\n 5.Go Back";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        g_insert();
        break;
    case 2:
        g_search();
        break;
    case 3:
        g_del();
        break;
    case 4:
        g_display();
        break;
    case 5:
        panel();
    default:
        cout<<"\n\n Invalid Value...Please Enter the Valid One";
        exit(0);
    }
    getchar();
    goto a;
}

void artgallery::g_insert()
{
a:
    fstream file;
    string gi,gn,gl;
    cout<<"\n\n ---------------------------Add Gallery Info------------------------------------";
    cout<<"\n\n\t Gallery_Id : ";
    cin>>gid;
    cout<<"\n\t Gallery_Name : ";
    cin>>gname;
    cout<<"\n\t Gallery Location :";
    cin>>glocation;
    file.open("gallery.txt",ios::in);
    if(!file)
    {
        file.open("gallery.txt",ios::app|ios::out);
        file<<" "<<gid<<" "<<gname<<" "<<glocation<<" "<<"\n";
        file.close();
    }
    else
    {
        file>>gi>>gn>>gl;
        while(!file.eof())
        {
            if(gi == gid)
            {
                file.close();
                cout<<"\n\n Gallery_id already exist!.....";
                getchar();
                goto a;
            }
            file>>gi>>gn>>gl;
        }
        file.close();
        file.open("gallery.txt",ios::app|ios::out);
        file<<" "<<gid<<" "<<gname<<" "<<glocation<<" "<<"\n";
        file.close();
    }
}

void artgallery::g_search()
{
    fstream file;
    string gi;
    int found=0;
    cout<<"\n\n -----------------------------Search Gallery Info----------------------------------------";
    cout<<"\n\n\t Gallery_id : ";
    cin>>gi;
    file.open("gallery.txt",ios::in);
    if(!file)
        gallery();
    else
    {
        file>>gid>>gname>>glocation;
        while(!file.eof())
        {
            if(gi == gid)
            {
                cout<<"\n\n-----------------------------Search Gallery Info-------------------------------";
                cout<<"\n\n\t Gallery_Id : "<<gid;
                cout<<"\n\t Gallery_Name : "<<gname;
                cout<<"\n\t Gallery_Location : "<<glocation;
                found++;
            }
            file>>gid>>gname>>glocation;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Gallery_Id Not Found.......";
    }
}
void artgallery::g_del()
{
    fstream file,file1;
    string gi;
    int found=0;
    cout<<"\n\n-------------------------------Delete Gallery Info----------------------------------------";
    cout<<"\n\n\t Gallery_Id : ";
    cin>>gi;
    file.open("gallery.txt",ios::in);
    if(!file)
        gallery();
    else
    {
        file1.open("gallery1.txt",ios::app|ios::out);
        file>>gid>>gname>>glocation;
        while(!file.eof())
        {
            if(gi == gid)
            {
                cout<<"\n\n Record Deleted Successfully......";
                found++;
            }
            else
                file1<<" "<<gid<<" "<<gname<<" "<<glocation<<" "<<"\n";
            file>>gid>>gname>>glocation;
        }
        file.close();
        file1.close();
        remove("gallery.txt");
        rename("gallery1.txt","gallery.txt");
        if(found == 0)
            cout<<"\n\n\n\t\t\t\tGallery_id Not Found!!!...";
    }
}

void artgallery::g_display()
{
    fstream file;
    int found=0;
    cout<<"\n\n----------------------------Display Gallery Details----------------------------";
    file.open("gallery.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file>>gid>>gname>>glocation;
        while(!file.eof())
        {
            // cout<<"\n\n\n -----------------------------------------";
            cout<<"\n\n\n\t Gallery_Id : "<<gid;
            cout<<"\n\t Gallery_Name : "<<gname;
            cout<<"\n\t Gallery_Location : "<<glocation;
            found++;
            file>>gid>>gname>>glocation;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Records Not Found....";
    }
}

void artgallery::exhibition()
{
a:
    int choice;
    cout<<"\n\n**************************************************************************************";
    cout<<"\n\t\t\t\t Exhibition Panel";
    cout<<"\n***************************************************************************************";
    cout<<"\n\n\n 1.Add Exhibition Info ";
    cout<<"\n 2.Search Exhibition Info ";
    cout<<"\n 3.Delete Exhibition Info";
    cout<<"\n 4.Display Exhibition Info";
    cout<<"\n 5.Go Back";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        e_insert();
        break;
    case 2:
        e_search();
        break;
    case 3:
        e_del();
        break;
    case 4:
        e_display();
        break;
    case 5:
        panel();
    default:
        cout<<"\n\n Invalid Value...Please Enter the Valid One";
        exit(0);
    }
    getchar();
    goto a;
}
void artgallery::e_insert()
{
a:
    fstream file;
    string e,gi,sd,ed;
    cout<<"\n\n---------------------------------- Add Exhibition Info----------------------------------";
    cout<<"\n\n\t Exhibition_Id : ";
    cin>>eid;
    cout<<"\n\t Start Date : ";
    cin>>start_date;
    cout<<"\n\t End Date : ";
    cin>>end_date;
    file.open("exhibition.txt",ios::in);
    if(!file)
    {
        file.open("exhibition.txt",ios::app|ios::out);
        file<<" "<<eid<<" "<<start_date<<" "<<end_date<<"\n";
        file.close();
    }
    else
    {
        file>>e>>sd>>ed;
        while(!file.eof())
        {
            if(e == eid)
            {
                file.close();
                cout<<"\n\n Exhibition_id already exist!.....";
                getchar();
                goto a;
            }
            file>>e>>sd>>ed;
        }
        file.close();
        file.open("exhibition.txt",ios::app|ios::out);
        file<<" "<<eid<<" "<<start_date<<" "<<end_date<<"\n";
        file.close();
    }
}

void artgallery::e_search()
{
    fstream file;
    string e;
    int found=0;
    cout<<"\n\n---------------------------------Search Exhibition Info------------------------";
    cout<<"\n\n\t Exhibition_id : ";
    cin>>e;
    file.open("exhibition.txt",ios::in);
    if(!file)
        exhibition();
    else
    {
        file>>eid>>start_date>>end_date;
        while(!file.eof())
        {
            if(e == eid)
            {
                cout<<"\n\n-------------------------Search Exhibition Info--------------------------";
                cout<<"\n\n\t Exhibition_Id : "<<eid;
                cout<<"\n\t Start Date : "<<start_date;
                cout<<"\n\t End Date : "<<end_date;
                found++;
            }
            file>>eid>>start_date>>end_date;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Exhibition_Id Not Found.......";
    }
}

void artgallery::e_del()
{
    fstream file,file1;
    string e;
    int found=0;
    cout<<"\n\n---------------------------Delete Exhibition Info---------------------------";
    cout<<"\n\n\t Exhibition_Id : ";
    cin>>e;
    file.open("exhibition.txt",ios::in);
    if(!file)
        exhibition();
    else
    {
        file1.open("exhibition1.txt",ios::app|ios::out);
        file>>eid>>start_date>>end_date;
        while(!file.eof())
        {
            if(e == eid)
            {
                cout<<"\n\n Record Deleted Successfully......";
                found++;
            }
            else
                file1<<" "<<eid<<" "<<start_date<<" "<<end_date<<"\n";
            file>>eid>>start_date>>end_date;
        }
        file.close();
        file1.close();
        remove("exhibition.txt");
        rename("exhibition1.txt","exhibition.txt");
        if(found == 0)
            cout<<"\n\n\n\t\t\t\tExhibition_id Not Found!!!...";
    }
}

void artgallery::e_display()
{
    fstream file;
    int found=0;
    cout<<"\n\n---------------------------Display Exhibition Details---------------------------";
    file.open("exhibition.txt",ios::in);
    if(!file)
        exhibition();
    else
    {
        file>>eid>>start_date>>end_date;
        while(!file.eof())
        {
            // cout<<"\n\n\n ----------------------------------------------------";
            cout<<"\n\n\n\t Exhibition_Id : "<<eid;
            cout<<"\n\t Start Date : "<<start_date;
            cout<<"\n\t End Date : "<<end_date;
            found++;
            file>>eid>>start_date>>end_date;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Records Not Found....";
    }
}




void artgallery::customer()
{
a:
    int choice;
    cout<<"\n\n**************************************************************************************";
    cout<<"\n\t\t\t\t Customer Panel";
    cout<<"\n***************************************************************************************";
    cout<<"\n\n\n 1.Display Artwork ";
    cout<<"\n 2.Order Bookings";
    cout<<"\n 3.Check Order";
    cout<<"\n 4.Go Back";
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        display();
        break;
    case 2:
        order_booking();
        break;
    case 3:
        customer_check_orders();
        break;
    case 4:
        panel();
    default:
        cout<<"\n\n Invalid Value...Please Enter the Valid One";
        exit(0);
    }
    getchar();
    goto a;
}
void artgallery::insert()
{
a:
    fstream file;
    string i,t,ty;
    float p;
    int y;
    cout<<"\n\n-------------------------------Add New Artwork------------------------------";
    cout<<"\n\n\t Art_Id : ";
    cin>>id;
    cout<<"\n\t Title : ";
    cin>>title;
    cout<<"\n\t Type_of_Art :";
    cin>>type;
    cout<<"\n\t Price : ";
    cin>>price;
    cout<<"\n\t Year : ";
    cin>>year;
    file.open("artwork.txt",ios::in);
    if(!file)
    {
        file.open("artwork.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<title<<" "<<type<<" "<<price<<" "<<year<<"\n";
        file.close();
    }
    else
    {
        file>>i>>t>>ty>>p>>y;
        while(!file.eof())
        {
            if(i == id)
            {
                file.close();
                cout<<"\n\n Art_id already exist!.....";
                getchar();
                goto a;
            }
            file>>i>>t>>ty>>p>>y;
        }
        file.close();
        file.open("artwork.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<title<<" "<<type<<" "<<price<<" "<<year<<"\n";
        file.close();
    }
}

void artgallery::search()
{
    fstream file;
    string i;
    int found=0;
    cout<<"\n\n---------------------------Search Artwork-------------------------";
    cout<<"\n\n\t Art_id : ";
    cin>>i;
    file.open("artwork.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file>>id>>title>>type>>price>>year;
        while(!file.eof())
        {
            if(i == id)
            {
                cout<<"\n\n-------------------------Search Artwork-------------------------";
                cout<<"\n\n\t Art_id : "<<id;
                cout<<"\n\t Title : "<<title;
                cout<<"\n\t Type_of_Art : "<<type;
                cout<<"\n\t Price: "<<price;
                cout<<"\n\t Year : "<<year;
                found++;
            }
            file>>id>>title>>type>>price>>year;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Art_id Not Found.......";
    }
}
int artgallery::ord_search(string i)
{
    fstream file;

    int found=0;
    // cout<<"\n\n---------------------------Search Artwork-------------------------";

    file.open("artwork.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file>>id>>title>>type>>price>>year;
        while(!file.eof())
        {
            if(i == id)
            {
                cout<<"\n\n-------------------------Selected Artwork-------------------------";
                cout<<"\n\n\t Art_id : "<<id;
                cout<<"\n\t Title : "<<title;
                cout<<"\n\t Type_of_Art : "<<type;
                cout<<"\n\t Price: "<<price;
                cout<<"\n\t Year : "<<year;
                found++;
            }
            file>>id>>title>>type>>price>>year;
        }
        file.close();
        if(found == 0)
        {
            cout<<"\n\n Art_id Not Found.......";
            return 0;
        }
        return 1;
    }
}

void artgallery::update()
{
    fstream file,file1;
    string i,t,ty;
    float p;
    int y;
    int found=0;
    cout<<"\n\n----------------------------Update Artwork------------------------------";
    cout<<"\n\n\t Art_id : ";
    cin>>i;
    file.open("artwork.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file1.open("artwork1.txt",ios::app|ios::out);
        file>>id>>title>> type>>price>>year;
        while(!file.eof())
        {
            if(i == id)
            {
                cout<<"\n\n\t Enter New title : ";
                cin>>t;
                cout<<"\n\t Enter New Art_type : ";
                cin>>ty;
                cout<<"\n\t Enter New Price : ";
                cin>>p;
                cout<<"\n\t Enter New Year : ";
                cin>>y;
                file1<<" "<<id<<" "<<t<<" "<<ty<<" "<<p<<" "<<y<<"\n";
                found++;
            }
            else
                file1<<" "<<id<<" "<<title<<" "<<type<<" "<<price<<" "<<year<<"\n";
            file>>id>>title>>type>>price>>year;
        }
        file.close();
        file1.close();
        remove("artwork.txt");
        rename("artwork1.txt","artwork.txt");
        if(found == 0)
            cout<<"\n\n\n\t\t\t\tArtwork Not Found.....";
    }
}

void artgallery::del()
{
    fstream file,file1;
    string i;
    int found=0;
    cout<<"\n\n---------------------------------Delete Artwork---------------------------------";
    cout<<"\n\n\t Art_id : ";
    cin>>i;
    file.open("artwork.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file1.open("artwork1.txt",ios::app|ios::out);
        file>>id>>title>> type>>price>>year;
        while(!file.eof())
        {
            if(i == id)
            {
                cout<<"\n\n Record Deleted Successfully......";
                found++;
            }
            else
                file1<<" "<<id<<" "<<title<<" "<<type<<" "<<price<<" "<<year<<"\n";
            file>>id>>title>>type>>price>>year;
        }
        file.close();
        file1.close();
        remove("artwork.txt");
        rename("artwork1.txt","artwork.txt");
        if(found == 0)
            cout<<"\n\n\n\t\t\t\tArtwork Not Found!!!...";
    }
}
void artgallery::art_display()
{
    fstream file;
    int found=0;
    cout<<"\n\n----------------------------Display Artworks---------------------------------";
    file.open("artwork.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file>>id>>title>>type>>price>>year;
        while(!file.eof())
        {
            //cout<<"\n\n\n ----------------------------------";
            cout<<"\n\n\n\t Art_id : "<<id;
            cout<<"\n\t Title : "<<title;
            cout<<"\n\t Art_type : "<<type;
            cout<<"\n\t Price : "<<price;
            cout<<"\n\t Year : "<<year;
            found++;
            file>>id>>title>>type>>price>>year;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Record Not Found....";
    }
}

void artgallery::admin_check_orders()
{
    fstream file;
    string i;
    int found=0;
    cout<<"\n\n--------------------------------Admin Check Orders------------------------------";
    file.open("Order.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file>>u_id>>u_name>>u_email>>u_phno>>i;
        while(!file.eof())
        {
            //cout<<"\n\n\n ----------------------------------------";
            cout<<"\n\n\n\t Order ID: "<<u_id;
            cout<<"\n\t Ordered Artwork ID :"<<i;
            cout<<"\n\t User Name: "<<u_name;
            cout<<"\n\t User email_id: "<<u_email;
            cout<<"\n\t User phno: "<<u_phno;
            found++;
            file>>u_id>>u_name>>u_email>>u_phno>>i;
        }
        file.close();
        if(found==0)
            cout<<"\n\n No order on Pending list";
    }
}

void artgallery::remove_orders()
{
    fstream file,file1;
    int found=0,id;
    cout<<"\n\n-----------------------------Confirm Order----------------------------";
    cout<<"\n\n\t Order ID: ";
    cin>>id;
    file.open("Order.txt",ios::in);
    if(!file)
        artwork();
    else
    {
        file1.open("Order1.txt",ios::app|ios::out);
        file>>u_id>>u_name>>u_email>>u_phno>>i;
        while(!file.eof())
        {
            if(id==u_id)
            {
                cout<<"\n\n Order Processed Successfully.........";
                found++;
            }
            else
                file1<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phno<<" "<<i<<"\n";
            file>>u_id>>u_name>>u_email>>u_phno>>i;
        }
        file.close();
        file1.close();
        remove("Order.txt");
        rename("Order1.txt","Order.txt");
        if(found==0)
            cout<<"\n\n Order ID Not Found.....";
    }
}

void artgallery::display()
{
    fstream file;
    int found=0;
    cout<<"\n\n---------------------------Display Artwork-------------------------";
    file.open("artwork.txt",ios::in);
    if(!file)
        customer();
    else
    {
        file>>id>>title>>type>>price>>year;
        while(!file.eof())
        {
            //cout<<"\n\n\n ----------------------------------------";
            cout<<"\n\n\n\t Art_id : "<<id;
            cout<<"\n\t Title : "<<title;
            cout<<"\n\t Art_type : "<<type;
            cout<<"\n\t Price : "<<price;
            cout<<"\n\t Year : "<<year;
            found++;
            file>>id>>title>>type>>price>>year;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Record Not Found....";
    }
}
void artgallery::order_booking()
{
    fstream file;
    int found=0,id,f;
    string n,e,p,i;
    cout<<"\n\n-------------------------- Book your Orders--------------------------";
    cout<<"\n\n\t Art_id : ";
    cin>>i;
    f=ord_search(i);
    if(f==0)
        return;

    cout<<"\n\n\n\t Name : ";
    cin>>u_name;
    cout<<"\n\t Email : ";
    cin>>u_email;
    cout<<"\n\t Phone no : ";
    cin>>u_phno;
    file.open("Order.txt",ios::in);
    if(!file)
    {
        file.open("Order.txt",ios::app|ios::out);
        u_id = 1000;
        file<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phno<<" "<<i<<"\n";
        file.close();
    }
    else
    {
        file>>id>>n>>e>>p>>i;
        while(!file.eof())
        {
            found++;
            file>>id>>n>>e>>p>>i;
        }
        file.close();
        file.open("Order.txt",ios::app|ios::out);
        /* if(found == 0)
         {
            u_id = 1000;
            file<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phno<<" "<<i<<"\n";
         }
        else
         {*/
        u_id=id + 1;
        file<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phno<<" "<<i<<"\n";
        //}
        file.close();
    }
    cout<<"\n\n\n\t\t\tYour order Id : "<<u_id;
    cout<<"\n\n\n\t\t\tOrder Booking Successful!!....";
}

void artgallery::customer_check_orders()
{
    fstream file;
    int id,found=0;
    string i;
    cout<<"\n\n-------------------------------Check your orders--------------------------";
    cout<<"\n\n\t User ID : ";
    cin>>id;
    file.open("Order.txt",ios::in);
    if(!file)
        customer();
    else
    {
        file>>u_id>>u_name>>u_email>>u_phno>>i;
        while(!file.eof())
        {
            if(id==u_id)
            {
                cout<<"\n\n Your Order is on Pending List......";
                found++;
            }
            file>>u_id>>u_name>>u_email>>u_phno>>i;
        }
        file.close();
        if(found == 0)
            cout<<"\n\n Your Order is Confirmed \n\n Will Contact you soon .....";
    }
}
main()
{
    system("color 03");
    artgallery a;
    a.panel();
}
