#include <stdio.h>
#include <stdlib.h>

typedef struct student {
  int grade;
  int studentID;
  char *name;
} student;

int compareFunc(const void *voidA, const void *voidB) {
  int a = (*(student *)voidA).grade;
  int b = (*(student *)voidB).grade;
  if (a < b) {
    return -1;
  } else if (a > b) {
    return +1;
  } else {
    return 0;
  }
}

int main() {
  struct student studentArray[] = {
      {87, 10001, "Fred"},     {28, 10002, "Tom"},   {100, 10003, "Alistair"},
      {75, 10004, "Sasha"},    {84, 10005, "Erin"},  {98, 10006, "Belinda"},
      {75, 10007, "Leslie"},   {70, 10008, "Candy"}, {81, 10009, "Aretha"},
      {68, 10010, "Veronica"},
  };

  int w = sizeof(struct student);

  int size = sizeof(studentArray) / sizeof(studentArray[0]);
  qsort(studentArray, 10, w, compareFunc);
  for (int i = 0; i < size; i++) {
    printf("%d ", studentArray[i].grade);
  }
  printf("\n");
  return 0;
}