#ifndef FASTAESMODULE_DEFINITIONS_H
#define FASTAESMODULE_DEFINITIONS_H

typedef enum {
    BAD_PARAMETERS, SUCCESS
} status;

typedef struct {
    int srcLen;
    int dstLen;
} srcDstLength;

#define CHECK_PTR_RET(ptr) if ((ptr) == NULL) return BAD_PARAMETERS
#define CHECK_MULTIPLICITY_BY(number, divisor) if ((number) % (divisor)) return BAD_PARAMETERS

#endif //FASTAESMODULE_DEFINITIONS_H
