/* src/hist.c Copyright (C) 2013 James Smith */


#include "hist.h"


/*base x/y-axis on max element*/
int getLimit(struct histogram *a)
{
	int		i;
	int		capacity;
	int max_val;
    
	capacity = a->fields;
    max_val = a->data[0].freq;
    
	for(i = 0; i < capacity; i++) {
		if(max_val < a->data[i].freq) {
            max_val = a->data[i].freq;
		}
		
	}
    
	return max_val;
}

int *getEnumWidth(int max)
{
	int i;
	char buf[15];
	int *numericWidth = malloc(sizeof(int) * max);
	sprintf(buf, "%d", max);
	int max_len = strlen(buf);

	for(i = max; i > 0; i--) {

		sprintf(buf, "%d", i);
		numericWidth[i] = max_len - strlen(buf);
	}


	printf("Values are: [ ");
	for(i = 0; i < max; i++) {
		printf(" %d " , numericWidth[i]);
	}

		printf("]\n");

	return numericWidth;
}

int *getEnumWhoriz(int max)
{
	int i;
	char buf[15];
	char pbuf[15];
	sprintf(buf, "%d", max);
	int *horizontalSpacingWidth = malloc(sizeof(int) * max);
	int max_len = strlen(buf);
	int tmp_width;
	const sep = 3;
	
	for(i = 1; i <= max; i++) {
		
		sprintf(buf, "%d" , i);
		tmp_width = strlen(buf);

		horizontalSpacingWidth[i] = sep - tmp_width;

	}


	return horizontalSpacingWidth;


}

void
ms(int space, int symbol)
{
	while (space-- > 0)
		printf("%c", symbol);
}

/* Initialize a new histogram */
int histCreate(struct histogram **a, int size, enum HIST_ORIEN orientation)
{
	struct histogram *item = malloc(sizeof(struct histogram));
	
	if(item == NULL)
		return (-1);

	item->data = calloc(size, sizeof(struct field));
	item->fields = size;
	item->orientation = orientation;

	*a = item;

	return (1);
}

int histAdd(struct histogram **a, struct field *data_s)
{
	
	(*a)->data = data_s;
	return (1);

}

int histPrint(struct histogram *a)
{
	int 	x;
	int		y;
	int 	f;		 /*For fields*/
	int		i;
	int 	ax_max 			= getLimit(a);
	int		*enumWidth		= getEnumWidth(ax_max);
	char 	buf[15];
	int 	x_padding;
	int 	*horiz_spacing 	= getEnumWhoriz(ax_max);
	const int seperator = 2;


	/*Get space padding for x - axis
	  requires max element width of
	  y - axis*/
	sprintf(buf, "%d", ax_max);
	x_padding = strlen(buf);

	/*Vertical/Horizontal?*/
	if(a->orientation == HISTOGRAM_VERTICAL) {
        /*print y - axis*/
		for(y = ax_max; y > 0; y--) {
			ms(enumWidth[y], ' ');
			printf("%d", y);
			printf(" | ");

			for(f = 0; f < a->fields; f++) {
				if(a->data[f].freq < y)
					printf(" ");

				else	
					printf("█");

				printf("  ");
			}
			
				printf("\n");
		}
        
        /*print x - axis*/
      
		ms(x_padding+2, ' ');
		for(x = 0; x < a->fields; x++) 
			printf(" - ");

	} else {
		for(y = 0; y < a->fields;y++) {
			printf("|");
				
				for(i = 1; i <= ax_max; i++) {
					if(a->data[y].freq < i)
						printf(" ");

					else
						printf("██");

					printf(" ");
						
				}
					printf("\n");
			}
			
		for(x = ax_max; x > 0; x--)
			printf(" ─ ");
	
		printf("\n");

		
	/*Give it a little push*/
		printf(" ");
	
		for(i = 1; i <= ax_max; i++) {
			printf("%d" , i);
			ms(horiz_spacing[i], ' ');

		}

	}

		printf("\n");

	free(enumWidth);

	return (1);
}

int histDestroy(struct histogram *a)
{
	free(a->data);
	free(a);
	a = NULL; /* Destroy dangling pointer */

	return (1);
}


