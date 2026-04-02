#include <stdio.h>

typedef struct {
    const char *name;
    const char *species;
    int age;
} turtle;

void happy_birthday(turtle *t)
{
    (*t).age = (*t).age + 1;
    printf("С днем рождения, %s! Теперь тебе %i лет!\n", (*t).name, (*t).age);
}

int main()
{
    turtle myrtle = {"Тортилла", "Кожистая черепаха", 99};
    happy_birthday(&myrtle);
    printf("%s прожила %i лет\n", myrtle.name, myrtle.age);
    return 0;
}
