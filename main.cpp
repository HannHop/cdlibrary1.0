// application.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//
#include <iostream>
#include <stdio.h>
#include <string.h>

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

char* trim (char *str) {
    size_t ln = strlen(str) - 1;
    if (*str && str[ln] == '\n')
    str[ln] = '\0';

    return str;
}

int main()
{
	int size = 0;
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
		// chuj

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

	print_list(head);
}

