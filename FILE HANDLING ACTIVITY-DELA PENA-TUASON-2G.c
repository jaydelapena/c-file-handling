//DELA PENA, JAY ASLEY A. - TUASON, JETHRO B. COMP ENG'G. TECHNOLOGY
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include<dirent.h>
#include<sys/stat.h>

struct Book {
	char title[50]; //A character array to store the title of the book.
	char author[50]; //A character array to store the author of the book.
	int publicationYear; //An integer to store the year of publication.
	float price;
} book1;
		
void writeToFile(const char* fileName, struct Book* book); //Writes book information to a file.
void readFromFile(const char* fileName); //Reads and displays the contents of a file.
void appendToFile(const char* fileName, struct Book* book); //Appends book information to an existing file.
void deleteFile(const char* fileName); //Deletes a specified file.
void renameFile(const char* oldFileName, const char* newFileName); //Renames a file.
bool checkFileExistence(const char* fileName); //Checks if a file exists.
void displayBookList(); //Displays a list of books by reading ang parsing info from multiple files.
void readBook(const char* bookName); //Reads and displays the contents of a specific book file.


int main() {
	while(1) {
	
		char fileName[100];
		char oldFileName[100];
		char newFileName[100];
		char bookName[100];
		
		int choice;

        printf("\n========================================================================================\n");
		printf("                               Choose the file handling operation:\n\n");
		printf("                                [1] WRITE TO FILE\n\n");
		printf("                                [2] READ FROM FILE\n\n");
		printf("                                [3] APPEND TO FILE\n\n");
		printf("                                [4] DELETE FILE\n\n");
		printf("                                [5] RENAME FILE\n\n");
		printf("                                [6] CHECK FILE EXISTENCE\n\n");
		printf("                                [7] DISPLAY A BOOK FROM THE LIST\n\n");
		printf("                                [8] READ A BOOK FROM THE LIST\n\n");
		printf("\n=========================================================================================\n ");
		printf("                                Enter your choice: ");
		scanf("%d", &choice);
		getchar();
		system("cls");

				switch (choice) {
						case 1:
							printf("Enter Book Title: ");
							fgets(book1.title, 50, stdin);
							book1.title[strcspn(book1.title, "\n")] = '\0';
							system("cls");

							printf("Enter Book Author: ");
							fgets(book1.author, 50, stdin);
							book1.author[strcspn(book1.author, "\n")] = '\0';
							system("cls");

							printf("Enter Year of Publication: ");
							scanf("%d", &book1.publicationYear);
							system("cls");

							printf("Enter the Price: ");
							scanf("%f", &book1.price);
							system("cls");

							printf("The Title is: %s\n", book1.title);
							printf("The Author is: %s\n", book1.author);
							printf("Publication Year: %d\n", book1.publicationYear);
							printf("Price: Php %.2f\n", book1.price);

							strcpy(fileName, book1.title);
							strcat(fileName, "-");
							strcat(fileName, book1.author);
							strcat(fileName, ".txt");

        					writeToFile(fileName, &book1);
						break;

						case 2:
							printf("Enter the Name of File you want to Read: ");
							fgets(fileName, sizeof(fileName), stdin);
							fileName[strcspn(fileName, "\n")] = '\0';

							readFromFile(fileName);
						break;

						case 3:
							printf("Enter the Name of File you want to Append: ");
							fgets(fileName, sizeof(fileName), stdin);
							fileName[strcspn(fileName, "\n")] = '\0';

							printf("Enter Book Title: ");
							fgets(book1.title, sizeof(book1.title), stdin);
							book1.title[strcspn(book1.title, "\n")] = '\0';

							printf("Enter Book Author: ");
							fgets(book1.author, sizeof(book1.author), stdin);
							book1.author[strcspn(book1.author, "\n")] = '\0';

							printf("Enter Year of Publication: ");
							scanf("%d", &book1.publicationYear);

							printf("Enter the Price: ");
							scanf("%f", &book1.price);

							printf("The Title is: %s\n", book1.title);
							printf("The Author is: %s\n", book1.author);
							printf("Publication Year: %d\n", book1.publicationYear);
							printf("Price: Php %.2f\n", book1.price);

							strcpy(fileName, book1.title);
							strcat(fileName, "-");
							strcat(fileName, book1.author);
							strcat(fileName, ".txt");

							appendToFile(fileName, &book1);
						break;

						case 4:
							printf("Enter the Name of File you want to Delete: ");
							fgets(fileName, sizeof(fileName), stdin);
							fileName[strcspn(fileName, "\n")] = '\0';

							deleteFile(fileName);
						break;

						case 5:
							printf("Enter the current Name of File you want to Rename: ");
							fgets(oldFileName, sizeof(oldFileName), stdin);
							oldFileName[strcspn(oldFileName, "\n")] = '\0';
							system("cls");

							printf("Enter the New Name of File:");
							fgets(newFileName, sizeof(newFileName), stdin);
							newFileName[strcspn(newFileName, "\n")] = '\0';
							system("cls");

							renameFile(oldFileName, newFileName);
						break;

						case 6:
       					    printf("Enter the Name of File you want to Check Existence: ");
							fgets(fileName, sizeof(fileName), stdin);
						    fileName[strcspn(fileName, "\n")] = '\0';
							system("cls");

								if (checkFileExistence(fileName)) {
									printf("File exists.\n");	
								} else {
									printf("File does not exist.\n");
								}
						break;

						case 7:
							displayBookList();
							printf("Invalid choice.\n");
						break;

						case 8:
  							printf("Enter the name of the bok you want to read: ");
  							fgets(bookName, sizeof(bookName), stdin);
  							bookName[strcspn(bookName, "\n")] = '\0';
  							system("cls");
   
  							readBook(bookName);
  						break;
		
						default:
						
							break;
					}
		}

	return 0;
}

/*This function takes a filename and a pointer to a 'struct book' as input and writes the book information
  to the file in a specific format.
*/
void writeToFile(const char* fileName, struct Book* book) {
		FILE* file = fopen(fileName, "w");

			fprintf(file, "The Title is: %s\n", book->title);
			fprintf(file, "The Author is: %s\n", book->author);
			fprintf(file, "Publication Year: %d\n", book->publicationYear);
			fprintf(file, "Price: Php %.2f\n", book->price);

			fclose(file);
			printf("Data written to the file successfully.\n");
		}

/* This function reads and displays the content of the 
file specified by the given filename.
*/
void readFromFile(const char* fileName) {
		FILE* file = fopen(fileName, "r");

			if (file == NULL) {
				printf("File does not exist or error opening the file.\n\n");
			return;
	}

			char line[100];
				while (fgets(line, sizeof(line), file)) {
					printf("%s", line);
				}

				fclose(file);	
	}

/*This function takes a filename and a pointer to a 'struct book' as inout and appends the book information to
  the file.
*/
void appendToFile(const char* fileName, struct Book* book) {
		FILE* file = fopen(fileName, "a");

			if (file == NULL) {
				printf("File does not exist or error opening the file.\n");
			return;
		}

				fprintf(file, "The Title is: %s\n", book->title);
				fprintf(file, "The Author is: %s\n", book->author);
				fprintf(file, "Publication Year: %d\n", book->publicationYear);
				fprintf(file, "Price: Php %.2f\n", book->price);

				fclose(file);
				printf("Data appended to the file successfully.\n");
		}

//This function deletes the file specified by the given filename.
void deleteFile(const char* fileName) {
	
			if (remove(fileName) == 0) {
				printf("File deleted successfully.\n");	
			} else {
				printf("File does not exist or error deleting the file.\n");
		}
}

//This function renames a file from the old filename to the new filename.
void renameFile(const char* oldFileName, const char* newFileName) {

			if (access(oldFileName, F_OK) == 0) {
				if (rename(oldFileName, newFileName) == 0) {
					printf("File renamed successfully!\n\n");
				} else {
					printf("Error renaming the File.\n\n");
				}
			} else {
				printf("File does not exist.\n");
	}
}

//This function checks whether the file specified by the given filename exists or not.
bool checkFileExistence(const char* fileName) {
			FILE* file = fopen(fileName, "r");

				if (file != NULL) {
					fclose(file);
				return true;
				} else {
				return false;
				}
			}

//This function lists all the books in the current directory that have a .txt extension
void displayBookList() {
			DIR* directory = opendir(".");
				
				if (directory == NULL) {
					printf("Error opening the current directory.\n");
				return;
			}

			struct dirent* entry;
			struct stat fileInfo;
			FILE* file;

				printf("List of Books:\n");

					while ((entry = readdir(directory)) != NULL) {
						if (stat(entry->d_name, &fileInfo) == -1) {
							printf("Error getting file information.\n");
							closedir(directory);
						return;
			}

			if (S_ISREG(fileInfo.st_mode) && strstr(entry->d_name, ".txt") != NULL) {
				file = fopen(entry->d_name, "r");
				if (file == NULL) {
					printf("Error opening file: %s\n", entry->d_name);
				continue;	
				}

			char line[100];

			if (fgets(line, sizeof(line), file) != NULL) {
			// Extract the title and author from the line
				char* titleStart = strstr(line, "The Title is: ");
			if (titleStart != NULL) {
				titleStart += strlen("The Title is: ");
				char* titleEnd = strchr(titleStart, '\n');
				
					if(titleEnd != NULL) {
						*titleEnd = '\0';
       					printf("%s", titleStart);
			}
}

			if (fgets(line, sizeof(line), file) != NULL) {
				char* authorStart = strstr(line, "The Author is: ");
				
					if (authorStart != NULL) {
						authorStart += strlen("The Author is: ");
						char* authorEnd = strchr(authorStart, '\n');

						if (authorEnd != NULL) {
							*authorEnd = '\0';
							printf(" by %s\n", authorStart);
					}
				}
		}
}

	fclose(file);
	}
}

	closedir(directory);
}

//This function takes the name of a book as input and reads and displays its content from a file with the same name.
void readBook(const char* bookName){
		FILE* file = fopen(bookName, "r");

			if(file == NULL) {
				printf("File does not exist or error opening the file.\n");
return ;
}

		char line[100];
		
			while (fgets(line, sizeof(line), file)) {
			printf("%s", line);
		}

fclose(file);
}
