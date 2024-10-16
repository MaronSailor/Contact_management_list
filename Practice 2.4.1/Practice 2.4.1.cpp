// List of ukrainian contacts. It is an old programm, I've written in college. Sadly, I couldn't improve myself more
// Randomly generates list of contacts and then User can find any contact from the list by it's Name, Surname or Phone
// It also shows the most active contact from the list

#include <iostream>
#include <string>
#include <Windows.h>

#define out(OutPut) std::cout << OutPut // It was much more comfortable for me to create some shortcuts to shorten the code
#define in(InPut) std::cin >> InPut
#define end std::cout << std::endl
#define loop(IntVariable, MaxInt) for (int IntVariable = 0; IntVariable < MaxInt; IntVariable++)
#define eut(OutPut) std::cout << OutPut << std::endl
#define iut(OutPut, InPut)   \
    std::cout << OutPut; \
    std::cin >> InPut

int Contacts_Amounts = 10, Years = 2005; // Contancts_Amount is free to change
std::string Search_Get;
bool Search_Completed = false;

struct Examples // Those are some examples where random information will be taken from 
{
    std::string Operator_Code[6] =
    { "63", "73", "93", "67", "97", "98" };
    std::string Device_Type[6] =
    { "Foldable Phone", "Smartphone", "Keyboard Phone", "Personal Computer", "Laptop", "Tablet" };
    std::string Place_of_residence[6] =
    { "Kyiv", "Lviv", "Donetsk", "Sumy", "Chernihiv", "Kharkiv" };
    std::string Group[6] =
    { "Work", "College", "Home", "Friend", "School", "Special" };
    std::string Name[6] =
    { "Serhii", "Artem", "Oleksii", "Oleksandr", "Vitalii", "Vlad" };
    std::string Surname[6] =
    { "Filatov", "Marchenkov", "Nikolaenko", "Volodin", "Yasinskii", "Chornovil" };
} Out;

struct Phone // Variables for Phone
{
    std::string Phone_Number;
    std::string Device_Type;
    std::string Name;
    std::string Surname;
    std::string Group;
    std::string Birthday_Day;
    std::string Place_of_residence;
    int Rating;
    int CallIn;
    int CallOut;
};
Phone* Contacts = new Phone[Contacts_Amounts];

int Generate_Int(int MIN_RAND, int MAX_RAND) // Needed to generate random number but let stay as an int
{
    return MIN_RAND + rand() % (MAX_RAND - MIN_RAND);
}

std::string Generate_String_Numbers(int MAX_LOOP, int MIN_RAND, int MAX_RAND) // Needed to generate random numbers and transform them to string
{
    std::string Generated_Result;
    loop(i, MAX_LOOP)
    {
        Generated_Result += std::to_string(MIN_RAND + rand() % (MAX_RAND - MIN_RAND));
    }
    return Generated_Result;
}

std::string Generate_from_Struct(std::string x[]) // randomly chooses features from Examples sctructure
{
    int j = Generate_Int(0, 5);
    switch (j)
    {
    case 0:
        return x[j];
        break;
    case 1:
        return x[j];
        break;
    case 2:
        return x[j];
        break;
    case 3:
        return x[j];
        break;
    case 4:
        return x[j];
        break;
    case 5:
        return x[j];
        break;
    default:
        eut("Something went wrong!");
        break;
    }
    return 0;
}

void Amount_Input() // Can be used to change Contacts_Amount
{
    iut("Enter amount of contacts => ", Contacts_Amounts);
}

void Input() // Creates a list of Contacts_Amount
{
    loop(i, Contacts_Amounts)
    {
        Contacts[i].Phone_Number = Generate_from_Struct(Out.Operator_Code) + "-" + Generate_String_Numbers(4, 0, 9);
        Contacts[i].Phone_Number += "-" + Generate_String_Numbers(2, 0, 9) + "-" + Generate_String_Numbers(2, 0, 9);
        Contacts[i].Device_Type = Generate_from_Struct(Out.Device_Type);
        Contacts[i].Name = Generate_from_Struct(Out.Name);
        Contacts[i].Surname = Generate_from_Struct(Out.Surname);
        Contacts[i].Group = Generate_from_Struct(Out.Group);
        Contacts[i].Birthday_Day = Generate_String_Numbers(1, 1, 30) + "-" + Generate_String_Numbers(1, 1, 12) + "-" + Generate_String_Numbers(1, 1950, Years);
        Contacts[i].Place_of_residence = Generate_from_Struct(Out.Place_of_residence);
        Contacts[i].Rating = Generate_Int(1, 5);
        Contacts[i].CallIn = Generate_Int(1, 100);
        Contacts[i].CallOut = Generate_Int(1, 100);
        Sleep(150);
    }
    end;
}

int Find_Most_CallIn() // One of the contacts has the most "Entering calls"
{
    int Saver;
    loop(i, Contacts_Amounts)
    {
        loop(j, Contacts_Amounts)
        {
            if (Contacts[j].CallIn > Contacts[i].CallIn)
            {
                Saver = j;
            }
        }
    }
    return Saver;
}

void Output(int i) // Function to output detailed data of contact
{
    eut("Contact phone - " << Contacts[i].Phone_Number);
    eut("Device type - " << Contacts[i].Device_Type);
    eut("Name - " << Contacts[i].Name);
    eut("Surname - " << Contacts[i].Surname);
    eut("Group - " << Contacts[i].Group);
    eut("Birthday - " << Contacts[i].Birthday_Day);
    eut("Place of residence - " << Contacts[i].Place_of_residence);
    eut("Entering calls from this contact - " << Contacts[i].CallIn);
    eut("Opening calls to this contact - " << Contacts[i].CallOut);
    eut("Rating - " << Contacts[i].Rating);
}

void Search() // Function for search feature
{
    iut("Enter contact Number/Name/Surname to search. Multiple can appear - ", Search_Get);
    end;
    loop(i, Contacts_Amounts)
    {
        if (Contacts[i].Name == Search_Get || Contacts[i].Surname == Search_Get || Contacts[i].Phone_Number == Search_Get)
        {
            eut("**********************************************");
            Search_Completed = true;
            Output(i);
            eut("**********************************************");
        }
    }
    end;
    if (Search_Completed == false)
        eut("Contact with " << Search_Get << " data was not found");
}

void CallIn_Output()
{
    eut("----------------------------------------------");
    eut("Most entering calls are from - " << Contacts[Find_Most_CallIn()].Name);
    Output(Find_Most_CallIn());
    eut("----------------------------------------------");
}

int main()
{
    eut("Halle");
    srand(time(0));
    // Amount_Input();
    Input();
    loop(i, Contacts_Amounts)
        eut(i + 1 << "  -  " << Contacts[i].Phone_Number << "  -  " << Contacts[i].Name << " " << Contacts[i].Surname);
    CallIn_Output();
    end;
    Search();
}