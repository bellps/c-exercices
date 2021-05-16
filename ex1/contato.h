typedef struct contact Contact;

typedef struct list List;

List * create_contact_list();

List * insert_contact(Contact * c, List *l);

void print_list(List *l);
