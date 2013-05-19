/* src/hist.c Copyright (C) 2013 James Smith */

#include <stdio.h>
#include <stdlib.h>

#include "hist.h"

/* Initialize a new histogram */
int histCreate(struct histogram *a, int size, enum HIST_ORIEN orientation)
{
	a = malloc(sizeof(*a));
	a->data = calloc(size, sizeof(a->data));

	a->orientation = orientation;

	return (1);
}

int histPrint(struct histogram *a)
{
	return (1);
}

int histDestroy(struct histogram *a)
{
	free(a->data);
	free(a);
	a = NULL; /* Destroy dangling pointer */

	return (1);
}
