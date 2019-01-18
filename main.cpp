#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <map>

using namespace std;

struct disc {
	char artist[40];
	char album_name[40];
	int year;
	char genre[15];
};

struct List {
	disc cd_data;
	List *next;
};

List* append(List *&head, disc cd) {
    List* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    List* new_element = new List();
    new_element->cd_data = cd;
    new_element->next = nullptr;

    current->next = new_element;

    return current;
}

void print_list(List *head){
    List *current = head;
    while(current != nullptr){
        cout<<current->cd_data.artist<<endl;
        cout<<current->cd_data.album_name<<endl;
        cout<<current->cd_data.year<<endl;
        cout<<current->cd_data.genre<<endl;
        cout<<"...................."<<endl;
        current = current->next;
    }
}

map<const char*, int> category = {
    { "artist", 1 },
    { "album", 2 },
    { "year", 3 },
    { "genre", 4 }
};

map<const char*, int> menu_keyword = {
    { "help", 1 },
    { "add", 2 },
    { "byebye", 3},
    { "correct", 4},
    { "list", 5},
    { "remove", 6},
    { "search", 7},
    { "save", 8}
};

void print_specific(List *head, const char *what, char *searched){
    int how_many=0;
    int searchCriteriaIndex;
        for (auto s: category) {
            if (strcmp(s.first, what) == 0) {
                searchCriteriaIndex = s.second;
            }
        }
    cout << searchCriteriaIndex << endl;
    switch (searchCriteriaIndex){
        case 1: {
                List *current = head;
                while (current != nullptr){
                    if(strstr(current->cd_data.artist, searched)) {
                        cout<<current->cd_data.artist<<endl;
                        cout<<current->cd_data.album_name<<endl;
                        cout<<current->cd_data.year<<endl;
                        cout<<current->cd_data.genre<<endl;
                        cout<<"...................."<<endl;

                        how_many++;
                    }
                    current = current->next;
                }
                break;
        }
        case 2: {
                List *current = head;
                while (current != nullptr){
                    if(strstr(current->cd_data.album_name, searched)) {
                        cout<<current->cd_data.artist<<endl;
                        cout<<current->cd_data.album_name<<endl;
                        cout<<current->cd_data.year<<endl;
                        cout<<current->cd_data.genre<<endl;
                        cout<<"...................."<<endl;

                        how_many++;
                    }
                    current = current->next;
                }
                break;
        }
        case 3: {
                List *current = head;
                while (current != nullptr){
                    char* year;
                    sprintf(year, "%d", current->cd_data.year);
                    if(strstr(year, searched)) {
                        cout<<current->cd_data.artist<<endl;
                        cout<<current->cd_data.album_name<<endl;
                        cout<<current->cd_data.year<<endl;
                        cout<<current->cd_data.genre<<endl;
                        cout<<"...................."<<endl;

                        how_many++;
                    }
                    current = current->next;
                }
                break;
        }
        case 4: {
                List *current = head;
                while (current != nullptr){
                    if(strstr(current->cd_data.genre, searched)) {
                        cout<<current->cd_data.artist<<endl;
                        cout<<current->cd_data.album_name<<endl;
                        cout<<current->cd_data.year<<endl;
                        cout<<current->cd_data.genre<<endl;
                        cout<<"...................."<<endl;

                        how_many++;
                    }
                    current = current->next;
                }
                break;
        }
    }
    if (how_many > 1) {
        cout<<"There are "<<how_many<<" entries for searched term"<<endl;
    }else if (how_many == 1){
        cout<<"There is "<<how_many<<" entry for searched term"<<endl;
    }else cout<<"There is no entries for searched term"<<endl;
}

char* trim (char *str) {
    size_t ln = strlen(str) - 1;
    if (*str && str[ln] == '\n')
    str[ln] = '\0';

    return str;
}
    void add(List *head){
        char c[6];
        char a[40];
        char b[40];
        char d[15];

        disc add;
        fgets(a, sizeof(a),stdin);
        fgets(b, sizeof(b),stdin);
        fgets(c, sizeof(c),stdin);
        fgets(d, sizeof(d),stdin);

        strcpy(add.artist, trim(a));
        strcpy(add.album_name, trim(b));
        add.year = atoi((trim(c)));
        strcpy(add.genre, trim(d));
        append(head, add);
	}

void help(){
    cout<<"\nadd - allows to add next album to the collection"<<endl;
    cout<<"byebye - closes program WITHOUT SAVING"<<endl;
    cout<<"correct - allows to change information about album"<<endl;
    cout<<"list - lists all albums with all details"<<endl;
    cout<<"search - searches for every occurence of album containing phrase\n\tpossible switches: album, name, year, genre"<<endl;
    cout<<"save - saves current state of collection into new file"<<endl<<endl;
    cout<<"Some functionalities require phrase added afterwards (user will be asked about it in next step)."<<endl;
}

int main()
{
	int size = 0;
	char searched[40];
	char what[10];
	char keyword[10];
	FILE *f;
	f = fopen("../folder/file.csv", "r");
	List *head = new List();
	char artist[40];
	char album_name[40];
	char gatunek[15];
	int rok;

	//c = getc(f);
	fscanf(f, "%*s \n");
	while (!feof(f)) {
		 //getline(f, artist);
		fscanf(f, "%[^,], %[^,], %d, %s \n", artist, album_name, &rok, gatunek);

		/*cout << "Artist: " << artist << endl;
        cout << "Album: " << album_name << endl;
		cout << "Rok: " << rok << endl;
		cout << "Gatunek: " << gatunek << endl;*/


		disc cd;
		strcpy(cd.artist, artist);
		strcpy(cd.album_name, album_name);
		cd.year = rok;
		strcpy(cd.genre, gatunek);

		size++;
		if (size == 1) {
            head->cd_data = cd;
            head->next = nullptr;
		}else{
            append(head, cd);
		}


	}

	cout << "Size: " << size << endl;

	//add(head);


	//print_list(head);

	/*cout<<"wykonawca jakiego szukasz to: "<<endl;
	fgets(searched, sizeof(searched), stdin);
	strcpy(searched, trim(searched));
    cout<<"searched: "<<searched<<endl;
	print_specific(head, what, searched);*/

    cout<<"Welcome to CD library 1.0"<<endl;

	while(true){

        cout<<"______________________________________\n\tWhat would you like to do?\n(help for list of possible commands)\n______________________________________\n"<<endl;
        fgets(keyword, sizeof(keyword), stdin);
        strcpy(keyword, trim(keyword));
        // cout << menu_keyword.at("help") << menu_keyword[keyword] << endl;

        int selectedIndex;
        for (auto s: menu_keyword) {
            if (strcmp(s.first, keyword) == 0) {
                selectedIndex = s.second;
            }
        }
        //cout<<strcpy(keyword, trim(keyword));
        // int entered_keyword = menu_keyword[keyword];
        switch (selectedIndex){
            case 1: { //help
                cout<<"help";
                help();
            }break;

            case 2: { // add
                cout<<"Enter new entry\n\tartist\nalbum\nyear\ngenre"<<endl;
                add(head);
            }break;

            case 3: { //byebye
                exit(0);
            }break;

            case 4: { //correct

            }break;

            case 5: { //list
                print_list(head);
            }break;

            case 6: { //remove
            }break;

            case 7: { //search
                cout<<"In which category would you like to search?"<<endl;
                fgets(what, sizeof(what), stdin);
                strcpy(what, trim(what));
                cout<<"Enter phrase"<<endl;
                fgets(searched, sizeof(searched), stdin);
                strcpy(searched, trim(searched));
                print_specific(head, what, searched);
            }break;

            case 8: { //save
            }break;
        }
	}

}

//Trzeba dodac cos przeciw wyciekowi pamieci, tzn usuwac liste przy wylaczaniu programu

