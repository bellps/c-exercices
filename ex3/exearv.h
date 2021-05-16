typedef struct family Family;

Family * create_empty();

Family * create(char * name, Family * left, Family * right);

int empty(Family * f);

void print_member(char * name, int spaces);

void print_family(Family * f, int spaces);

Family * free_family(Family * f);

void find(Family * f, char * member, int kin);

void get_kin(int kin);