#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "exearv.h"

int main(){
    Family * bisavo = create("Oscar", create_empty(), create_empty());
	Family * vo1 = create("Amelia", create_empty(), bisavo);
	Family * vo2 = create("Caio", create_empty(), create_empty());
	Family * vo3 = create("Tamares", create_empty(), create_empty());
	Family * vo4 = create("Jose", create_empty(), create_empty());
	Family * pai = create("Pedro", vo2, vo1);
	Family * mae = create("Carolina", vo4, vo3);
	Family * maria = create("Maria", pai, mae);

	print_family(maria, 10);
	int kin = 0;
	char member[51] = "Tamares";
	find(maria, member, kin);
}
