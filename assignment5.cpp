#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define SIZE 20
int checkPass = 0;
char checkLoc[SIZE];

class StoreData
{
public:
    StoreData()
    {
        FILE *data;
        data = fopen("data.txt", "r");
        if (data == NULL)
        {
            printf("File Cannot Open!");
            exit(1);
        }
        while (!feof(data))
        {
            fscanf(data, "%d%10s%10d%10d%10d%10s", &id, name, &checkPass, &amount, &age, checkLoc);
        }
        if (id != 0)
        {
            cout << "Your last id => " << id << endl;
        }
        fclose(data);
    }
    char name[SIZE];
    int id = 0;
    int amount = 0;
    int age = 0;
    void setPassword(int p)
    {
        password = p;
    }
    int getPassword()
    {
        return password;
    }
    void setLocation(char l[SIZE])
    {
        strcpy(location, l);
    }
    char *getLocation()
    {
        return location;
    }

private:
    int password = 0;
    char location[SIZE];
};

void saveData(StoreData storeObj);
void showAll(StoreData storeObj);
void searchData(StoreData storeObj);
void deleteData(StoreData storeObj, int line);
void editData(StoreData storeObj, int line);

int main()
{
    int option = 0;
    StoreData storeObj;
    int trueValue = 0;

    cout << "Press 1 to insert data,2 to search data,3 to show all datas,4 to delete,5 to edit" << endl;
    cout << "> ";
    cin >> option;

    switch (option)
    {
    case 1:
        saveData(storeObj);
        break;
    case 2:
        searchData(storeObj);
        break;
    case 3:
        showAll(storeObj);
        break;
    case 4:
        int l;
        showAll(storeObj);
        FILE *data;
        if (data == NULL)
        {
            printf("File Cannot Open!");
            exit(1);
        }
        data = fopen("data.txt", "r");
        while (!feof(data))
        {
            fscanf(data, "%d%10s%10d%10d%10d%10s", &storeObj.id, storeObj.name, &checkPass, &storeObj.amount, &storeObj.age, checkLoc);
        }
        if (storeObj.id != 0)
        {
            fclose(data);
            cout << "What line number do you want to delete? : ";
            cin >> l;
            deleteData(storeObj, l);
        }
        break;
    case 5:
        showAll(storeObj);
        if (data == NULL)
        {
            printf("File Cannot Open!");
            exit(1);
        }
        data = fopen("data.txt", "r");
        while (!feof(data))
        {
            fscanf(data, "%d%10s%10d%10d%10d%10s", &storeObj.id, storeObj.name, &checkPass, &storeObj.amount, &storeObj.age, checkLoc);
        }
        if (storeObj.id != 0)
        {
            fclose(data);
            cout << "What line number do you want to edit? : ";
            cin >> l;
            editData(storeObj, l);
        }
        break;
    default:
        cout << "Invalid input." << endl;
    }

    return 0;
}
void saveData(StoreData storeObj)
{
    FILE *data;
    if (data == NULL)
    {
        printf("File Cannot Open!");
        exit(1);
    }
    data = fopen("data.txt", "a");
    cout << "Enter id : ";
    cin >> storeObj.id;
    cout << "Enter name : ";
    cin >> storeObj.name;
    cout << "Enter password : ";
    cin >> checkPass;
    storeObj.setPassword(checkPass);
    cout << "Enter amount : ";
    cin >> storeObj.amount;
    cout << "Enter age : ";
    cin >> storeObj.age;
    cout << "Enter location : ";
    cin >> checkLoc;
    storeObj.setLocation(checkLoc);

    while (!feof(stdin))
    {
        fprintf(data, "%d%10s%10d%10d%10d%10s\n", storeObj.id, storeObj.name, storeObj.getPassword(), storeObj.amount, storeObj.age, storeObj.getLocation());
        cout << "Enter id : ";
        cin >> storeObj.id;
        cout << "Enter name : ";
        cin >> storeObj.name;
        cout << "Enter password : ";
        cin >> checkPass;
        storeObj.setPassword(checkPass);
        cout << "Enter amount : ";
        cin >> storeObj.amount;
        cout << "Enter age : ";
        cin >> storeObj.age;
        cout << "Enter location : ";
        cin >> checkLoc;
        storeObj.setLocation(checkLoc);
    }
    fclose(data);
}

void searchData(StoreData storeObj)
{
    char sName[SIZE];
    FILE *data;
    data = fopen("data.txt", "r");
    if (data == NULL)
    {
        printf("File Cannot Open!");
        exit(1);
    }
    cout << "Enter name you want to search : ";
    cin >> sName;
    while (!feof(data)){
        fscanf(data, "%d%10s%10d%10d%10d%10s", &storeObj.id, storeObj.name, &checkPass, &storeObj.amount, &storeObj.age, checkLoc);
        if (storeObj.id == 0)
        {
            cout << "Your data is empty" << endl;
        }
        else
        {
            if (strcmp(storeObj.name, sName) == 0)
            {
                printf("%d%10s%10d%10d%10d%10s\n", storeObj.id, storeObj.name, checkPass, storeObj.amount, storeObj.age, checkLoc);
                break;
            }
        }
    };

    fclose(data);
}

void showAll(StoreData storeObj)
{
    FILE *data;
    data = fopen("data.txt", "r");
    if (data == NULL)
    {
        printf("File Cannot Open!");
        exit(1);
    }
    cout << "Data are : " << endl;
    while (!feof(data))
    {
        fscanf(data, "%d%10s%10d%10d%10d%10s", &storeObj.id, storeObj.name, &checkPass, &storeObj.amount, &storeObj.age, checkLoc);
        storeObj.setLocation(checkLoc);
        storeObj.setPassword(checkPass);
        if (storeObj.id == 0)
        {
            cout << "Your data is empty" << endl;
        }
        else
        {
            if (feof(data))
            {
                break;
            }
            printf("%d%10s%10d%10d%10d%10s\n", storeObj.id, storeObj.name, storeObj.getPassword(), storeObj.amount, storeObj.age, storeObj.getLocation());
        }
    }
    fclose(data);
}
void deleteData(StoreData storeObj, int line)
{
    FILE *data;
    FILE *temp;
    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "w");
    if (data == NULL)
    {
        printf("File Cannot Open!");
        exit(1);
    }
    int count = 1;
    char buffer[1000];
    while ((fgets(buffer, sizeof(buffer), data)) != NULL)
    {
        if (line != count)
        {
            fputs(buffer, temp);
        }
        count++;
    }
    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    cout << "Data is deleted successfully." << endl;
    showAll(storeObj);
}

void editData(StoreData storeObj, int line)
{
    FILE *data;
    FILE *temp;
    char buffer[1000];
    int count = 1;

    data = fopen("data.txt", "r");
    temp = fopen("temp.txt", "w");
    if (data == NULL)
    {
        printf("File Cannot Open!");
        exit(1);
    }

    cout << "Enter new id : ";
    cin >> storeObj.id;
    cout << "Enter new name : ";
    cin >> storeObj.name;
    cout << "Enter new password : ";
    cin >> checkPass;
    storeObj.setPassword(checkPass);
    cout << "Enter new amount : ";
    cin >> storeObj.amount;
    cout << "Enter new age : ";
    cin >> storeObj.age;
    cout << "Enter new location : ";
    cin >> checkLoc;
    storeObj.setLocation(checkLoc);
    cout << "Data is updated successfully." << endl;
    while (fgets(buffer, sizeof(buffer), data))
    {
        if (line != count)
        {
            fputs(buffer, temp);
        }
        else
        {
            fprintf(temp, "%d%10s%10d%10d%10d%10s\n", storeObj.id, storeObj.name, storeObj.getPassword(), storeObj.amount, storeObj.age, storeObj.getLocation());
        }
        count++;
    }
    fclose(data);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    showAll(storeObj);
}
