/* ncbiRefLink.h was originally generated by the autoSql program, which also 
 * generated ncbiRefLink.c and ncbiRefLink.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef NCBIREFLINK_H
#define NCBIREFLINK_H

#define NCBIREFLINK_NUM_COLS 5

extern char *ncbiRefLinkCommaSepFieldNames;

struct ncbiRefLink
/* Metadata for NCBI RefSeq Genes */
    {
    struct ncbiRefLink *next;  /* Next in singly linked list. */
    char *id;	/* transcript id */
    char *gbKey;	/* molecule type */
    char *gene;	/* gene name */
    char *dbXref;	/* database cross reference */
    char *product;	/* product */
    };

void ncbiRefLinkStaticLoad(char **row, struct ncbiRefLink *ret);
/* Load a row from ncbiRefLink table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct ncbiRefLink *ncbiRefLinkLoad(char **row);
/* Load a ncbiRefLink from row fetched with select * from ncbiRefLink
 * from database.  Dispose of this with ncbiRefLinkFree(). */

struct ncbiRefLink *ncbiRefLinkLoadAll(char *fileName);
/* Load all ncbiRefLink from whitespace-separated file.
 * Dispose of this with ncbiRefLinkFreeList(). */

struct ncbiRefLink *ncbiRefLinkLoadAllByChar(char *fileName, char chopper);
/* Load all ncbiRefLink from chopper separated file.
 * Dispose of this with ncbiRefLinkFreeList(). */

#define ncbiRefLinkLoadAllByTab(a) ncbiRefLinkLoadAllByChar(a, '\t');
/* Load all ncbiRefLink from tab separated file.
 * Dispose of this with ncbiRefLinkFreeList(). */

struct ncbiRefLink *ncbiRefLinkCommaIn(char **pS, struct ncbiRefLink *ret);
/* Create a ncbiRefLink out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new ncbiRefLink */

void ncbiRefLinkFree(struct ncbiRefLink **pEl);
/* Free a single dynamically allocated ncbiRefLink such as created
 * with ncbiRefLinkLoad(). */

void ncbiRefLinkFreeList(struct ncbiRefLink **pList);
/* Free a list of dynamically allocated ncbiRefLink's */

void ncbiRefLinkOutput(struct ncbiRefLink *el, FILE *f, char sep, char lastSep);
/* Print out ncbiRefLink.  Separate fields with sep. Follow last field with lastSep. */

#define ncbiRefLinkTabOut(el,f) ncbiRefLinkOutput(el,f,'\t','\n');
/* Print out ncbiRefLink as a line in a tab-separated file. */

#define ncbiRefLinkCommaOut(el,f) ncbiRefLinkOutput(el,f,',',',');
/* Print out ncbiRefLink as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* NCBIREFLINK_H */

