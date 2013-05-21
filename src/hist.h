/* src/hist.h Copyright (C) 2013 James Smith */

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Wordplay humour */
enum HIST_ORIEN { HISTOGRAM_VERTICAL = 0, HISTOGRAM_HORIZONTAL};

struct field {
	char *name;
	int freq;
	char *cv;		/*Color-value*/
};


struct histogram {
	int fields; /* Number of e.g. names in the histogram. */
	enum HIST_ORIEN orientation;
	struct field *data;
};

/* Create a new 'object' and return an error code.
 * @arg (histogram) pointer to histogram
 * @arg (int) number of elements to initialize in the histogram
 * @return (int) non-zero on success
 */
int histCreate(struct histogram **a, int size, enum HIST_ORIEN);

/* Add to histogram datafield values
*  @ For now, just pass in the dataset and place it in struct
*  @ return -1 on failure, 1 on success
*/   

int histAdd(struct histogram **a,struct field *data_s);

/* Print histogram in memory to stdout
 * @arg (histogram) pointer to table to print
 * @return (int) non-zero on success
 */

int histPrint(struct histogram *a);

/* Destroy the table in memory, freeing all memory back to system
 * @arg (histogram) pointer to table to be freed
 * @return (int) non-zero on success
 */
int histDestroy(struct histogram *a);

int getLimit(struct histogram *a);

int *getEnumWidth(int max);

int *getEnumWhoriz(int max);

#endif /* HISTOGRAM_H */
