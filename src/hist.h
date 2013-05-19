/* src/hist.h Copyright (C) 2013 James Smith */

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

/* Wordplay humour */
enum HIST_ORIEN { HISTOGRAM_VERTICAL = 0, HISTOGRAM_HORIZONTAL};

struct field {
	char *name;
	int freq;
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
int histCreate(struct histogram *, int, enum HIST_ORIEN);

/* Print histogram in memory to stdout
 * @arg (histogram) pointer to table to print
 * @return (int) non-zero on success
 */
int histPrint(struct histogram *);

/* Destroy the table in memory, freeing all memory back to system
 * @arg (histogram) pointer to table to be freed
 * @return (int) non-zero on success
 */
int histDestroy(struct histogram *);

#endif /* HISTOGRAM_H */
