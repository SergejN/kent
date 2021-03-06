# pairedTagAlign.sql was originally generated by the autoSql program, which also 
# generated pairedTagAlign.c and pairedTagAlign.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Peaks format (BED 6+)
CREATE TABLE pairedTagAlign (
    chrom varchar(255) not null,	# Reference sequence chromosome or scaffold
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    name varchar(255) not null,	# Name of item
    score int unsigned not null,	# Score from 0-1000
    strand char(1) not null,	# + or -
    seq1 varchar(255) not null,	# Sequence of first read
    seq2 varchar(255) not null,	# Sequence of second read
              #Indices
    INDEX chromStart (chrom(8), chromStart)
)
AVG_ROW_LENGTH = 100
MAX_ROWS = 10000000000
;
