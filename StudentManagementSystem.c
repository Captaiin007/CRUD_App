#include<stdio.h>
#include<string.h>
struct Student{
 int rollNo;
 char name[21];
};
struct Student s[100];
int numberOfStudentsAdded;
void addStudent();
void deleteStudent();
void searchStudent();
void editStudent();
void displayStudent();
int main()
{
 int ch;
 numberOfStudentsAdded=0;
 printf("*Program to store data of 100 students*\n");
 while(1)
 {
  printf("1. Add student\n");
  printf("2. Delete student\n");
  printf("3. Edit student\n");
  printf("4. Search student\n");
  printf("5. Display student\n");
  printf("6. Exit\n");
  printf("Please enter your choice(1-6) : ");
  scanf("%d",&ch);
  if(ch<=0 || ch>6)
  {
   printf("Invalid input! Please select (1-6)\n");
   continue;
  }
  if(numberOfStudentsAdded==100 && ch==1)
  {
   printf("You cannot add more than 100 students\n");
   continue;
  }
  if(numberOfStudentsAdded==0 && ch>=2 && ch<=5)
  {
   printf("You have not added any student yet\n");
  }
  if(ch==1) addStudent();
  if(ch==2) deleteStudent();
  if(ch==3) editStudent();
  if(ch==4) searchStudent();
  if(ch==5) displayStudent();
  if(ch==6) break;
 }
 return 0;
}
void addStudent()
{
 int e,vRollNo;
 char m,vName[22];
 printf("Student (Add Module)\n");
 printf("Enter roll number : ");
 scanf("%d",&vRollNo);
 fflush(stdin);
 if(vRollNo<=0)
 {
  printf("Invalid roll no!\n");
  return;
 }
 e=0;
 while(e<numberOfStudentsAdded)
 {
  if(vRollNo==s[e].rollNo)
  {
   printf("Entered roll no is alloted to %s\n",s[e].name);
   return;
  }
  e++;
 }
 printf("Enter name : ");
 fgets(vName,22,stdin);
 fflush(stdin);
 vName[strlen(vName)-1] = '\0';
 printf("Save (y/n) : ");
 m = getchar();
 fflush(stdin);
 if(m!='y' && m!='Y')
 {
  printf("Student not added\n");
  return;
 }
 s[numberOfStudentsAdded].rollNo = vRollNo;
 strcpy(s[numberOfStudentsAdded].name,vName);
 numberOfStudentsAdded++;
 printf("Student added, press enter to continue.....");
 getchar();
 fflush(stdin);
}

void deleteStudent()
{
 int vRollNo;
 int e,ep,found;
 char m;
 printf("Student (Delete Module)\n");
 printf("Enter roll no of the student to delete : ");
 scanf("%d",&vRollNo);
 fflush(stdin);
 if(vRollNo<=0)
 {
  printf("Invalid roll no!\n");
  return;
 }
 found=0;
 e=0;
 while(e<numberOfStudentsAdded)
 {
  if(vRollNo==s[e].rollNo)
  {
   found=1;
   break;
  }
  e++;
 }
 if(found==0)
 {
  printf("Roll number not found\n");
  return;
 }
 printf("Student's name : %s\n",s[e].name);
 printf("Delete (y/n) : ");
 m = getchar();
 fflush(stdin);
 if(m!='y' && m!='Y')
 {
  printf("Student not deleted\n");
  return;
 }
 ep = numberOfStudentsAdded-1;
 while(e<=ep)
 {
  s[e].rollNo = s[e+1].rollNo;
  strcpy(s[e].name,s[e+1].name);
  e++;
 }
 numberOfStudentsAdded--;
 printf("Student deleted, press enter to continue.....");
 getchar();
 fflush(stdin);
}

void editStudent()
{
 int e,found,vRollNo;
 char m,vName[22];
 printf("Student (Edit Module)\n");
 printf("Enter roll no of the student to edit : ");
 scanf("%d",&vRollNo);
 fflush(stdin);
 if(vRollNo<=0)
 {
  printf("Invalid roll no!\n");
  return;
 }
 found=0;
 e=0;
 while(e<numberOfStudentsAdded)
 {
  if(vRollNo==s[e].rollNo)
  {
   found=1;
   break;
  }
  e++;
 }
 if(found==0)
 {
  printf("Roll number not found\n");
  return;
 }
 printf("Student's name : %s\n",s[e].name);
 printf("Edit (y/n) : ");
 m = getchar();
 fflush(stdin);
 if(m!='y' && m!='Y')
 {
  printf("Student not edited\n");
  return;
 }
 printf("Enter new name : ");
 fgets(vName,22,stdin);
 fflush(stdin);
 vName[strlen(vName)-1] = '\0';
 printf("Update (y/n) : ");
 m = getchar();
 fflush(stdin);
 if(m!='y' && m!='Y')
 {
  printf("Student not updated\n");
  return;
 }
 strcpy(s[e].name,vName);
 printf("Student updated, press enter to continue.....");
 getchar();
 fflush(stdin);
}

void searchStudent()
{
 int e,found,vRollNo;
 printf("Student (Search Module)\n");
 printf("Enter roll no to search : ");
 scanf("%d",&vRollNo);
 fflush(stdin);
 if(vRollNo<=0)
 {
  printf("invalid roll no!\n");
  return;
 }
 found=0; 
 e=0;
 while(e<numberOfStudentsAdded)
 {
  if(vRollNo==s[e].rollNo)
  {
   found=1;
   break;
  }
  e++;
 }
 if(found==0)
 {
  printf("Student not found\n");
  return;
 }
 printf("Student's name : %s\n",s[e].name);
 printf("Press enter to continue.....");
 getchar();
 fflush(stdin);
}

void displayStudent()
{
 int f;
 printf("Student (List Module)\n");
 f=0;
 while(f<numberOfStudentsAdded)
 {
  printf("Roll no : %d, Name : %s\n",s[f].rollNo,s[f].name);
  f++;
 }
 printf("Press enter to continue.....\n");
 getchar();
 fflush(stdin);
}