#include <stdio.h>
#include "hist.h"

int main(int argc, char **argv)
{
	int error_code 	= 0;
	int print_code 	= 0;
	int finale_code = 0;

	/*Testing*/

	/*	1. 	Create a histogram
		2. 	Enter values
		3.  Return output
	*/

	struct histogram *new_hist;

	printf("========TEST ONE=======\n");

	error_code  = histCreate(&new_hist, 10, HISTOGRAM_VERTICAL);

	print_code  = histPrint(new_hist);

	finale_code = histDestroy(new_hist);

	printf("Test 1, codes are [ %d %d %d ] \n", error_code, print_code, finale_code);

	
	/*Histogram info*/

	runHistInfo(new_hist, LITE);	
	printf("=======================\n");

	int i;

	/*Testing data sets*/

	struct histogram *datagram;

	struct field *dataset = malloc(sizeof(struct field) * 12);

	histCreate(&datagram, 12, HISTOGRAM_VERTICAL);

	char *months[12] = {"January", "February", "March", "April", "May",
					  	"June","July", "August", "September", "October",
					  	"November", "December"};

	int  stats[12] 	 = { 10, 12, 9, 5, 3, 11, 5, 7, 2, 1, 12, 22 }; 

	char *colors[12] = {"Blue", "Red", "Green", "Yellow", "Orange",
						"Magenta", "Cyan", "Purple", "Brown","White",
						"Pink","Default"};

	for(i = 0; i < 12; i++) {
			dataset[i].name = months[i];
			dataset[i].freq = stats[i];
			dataset[i].cv   = colors[i];
	}

	histAdd(&datagram, dataset);

	printf("\n");
	printf("=======HISTOGRAM VERTICAL=========\n");

	/*Display info*/
	runHistInfo(datagram, FULL);

	/*Test setting axis compared to Vertical histogram*/

	histPrint(datagram);

	printf("=================================\n");


	printf("\n");
	printf("/*Let's try changing layout*/\n");
	printf("run : changeOrientation(&datagram, HISTOGRAM_HORIZONTAL);\n");

	changeOrientation(&datagram, HISTOGRAM_HORIZONTAL);


	printf("\n");
	printf("======HISTOGRAM HORIZONTAL========\n");
	runHistInfo(datagram, LITE);
	
	histPrint(datagram);

	printf("=================================\n");

	histDestroy(datagram);
}
