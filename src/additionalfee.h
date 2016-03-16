#include "util.h"
#include "main.h"

class AdditionalFee
{
public:
    static int64_t GetAdditionalFeeFromTable(int64_t additionalFeeValue, bool Exchange); //keesdewit
	static bool IsInFeeExcemptionList(CTxDestination destination); //keesdewit
};
