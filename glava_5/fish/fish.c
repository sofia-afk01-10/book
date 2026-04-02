#include <stdio.h>
struct exercise{
    const char *description;
    float duration;
};
struct meal{
    const char *integredients;
    float weight;
};
struct preferences{
    struct meal food;
    struct exercise exercise;
};

struct fish{
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

/* Выводим запись, содержащуюся в каталоге */
void catalog(struct fish f)
{
    printf("%s - это %s с %i зубами. Ему %i года\n", 
           f.name, f.species, f.teeth, f.age);
}

/* Выводим ярлык для аквариума */
void label(struct fish a)
{
    printf("Кличка:%s\nРазновидность:%s\n%i года, %i зубов\n", 
           a.name, a.species, a.teeth, a.age);
    printf("Давать %2.2f кг %s и разрешать %s на протяжении %2.2f часов\n", 
            a.care.food.weight, a.care.food.integredients, a.care.exercise.description, a.care.exercise.duration);
}

int main()
{
    struct fish snappy = {"Зубастик","пиранья", 69, 4, {"Мясо", 7.5, "купаться в джакузи", 7.5}};
    catalog(snappy);
    printf("Зубастик любит кушать %s ", snappy.care.food);
    printf("\nЗубастик любит заниматься %f часов\n", snappy.care.exercise.duration);
    label(snappy);
    return 0;
}