#include "base58.h"
#include "additionalfee.h"
#include <boost/assign/list_of.hpp>

int64_t GetAdditionalFeeFromTableV2(int64_t additionalValue)
{
	double additionalValueInternal = (double)additionalValue / (double)COIN;
	
	if (additionalValueInternal <= 0)
		return 0;
	
	if (additionalValueInternal < 0.05)
		return (additionalValueInternal * 0.10) * COIN;
	
	if (additionalValueInternal >= 0.05 && additionalValueInternal < 0.10)
		return (additionalValueInternal * 0.12) * COIN;
	
	if (additionalValueInternal >= 0.10 && additionalValueInternal < 0.15)
		return (additionalValueInternal * 0.14) * COIN;	
	
	if (additionalValueInternal >= 0.15 && additionalValueInternal < 0.20)
		return (additionalValueInternal * 0.16) * COIN;		
	
	if (additionalValueInternal >= 0.20 && additionalValueInternal < 0.25)
		return (additionalValueInternal * 0.18) * COIN;		
	
	if (additionalValueInternal >= 0.25 && additionalValueInternal < 0.30)
		return (additionalValueInternal * 0.20) * COIN;		
	
	if (additionalValueInternal >= 0.30 && additionalValueInternal < 1)
		return (additionalValueInternal * 0.25) * COIN;		
	
	if (additionalValueInternal >= 1 && additionalValueInternal < 1.5)
		return (additionalValueInternal * 0.30) * COIN;		
	
	if (additionalValueInternal >= 1.5 && additionalValueInternal < 2)
		return (additionalValueInternal * 0.32) * COIN;		
	
	if (additionalValueInternal >= 2 && additionalValueInternal < 45)
		return (additionalValueInternal * 0.40) * COIN;		
	
	if (additionalValueInternal >= 45 && additionalValueInternal < 200)
		return (additionalValueInternal * 0.46) * COIN;		
	
	
	return (additionalValueInternal * 0.55) * COIN;			
}
   
int64_t AdditionalFee::GetAdditionalFeeFromTable(int64_t additionalValue, bool Exchange) //keesdewit
{
    if(Exchange == false) // this should be false when not sending to an exchange and therefore should get a lower fee like a standard coin (but not free)
    {
        return 0;
    }

	if (pindexBest->nHeight >= FORK_HEIGHT_7)
		return GetAdditionalFeeFromTableV2(additionalValue);
	
	double additionalValueInternal = (double)additionalValue / (double)COIN;
			
	if (additionalValueInternal <= 0)
		return 0;
	
	if (additionalValueInternal < 0.001)
		return 0.00001 * COIN;
	
	if (additionalValueInternal >= 0.001 && additionalValueInternal < 0.01)
		return 0.0001 * COIN;
	
	if (additionalValueInternal >= 0.01 && additionalValueInternal < 0.1)
		return 0.001 * COIN;		
	
	if (additionalValueInternal >= 0.1 && additionalValueInternal < 1)
		return 0.01 * COIN;	
	
	if (additionalValueInternal >= 1 && additionalValueInternal < 1.5)
		return 0.02 * COIN;	
	
	if (additionalValueInternal >= 1.5 && additionalValueInternal < 2)
		return 0.04 * COIN;			
	
	if (additionalValueInternal >= 2 && additionalValueInternal < 2.5)
		return 0.1 * COIN;					
	
	if (additionalValueInternal >= 2.5 && additionalValueInternal < 3)
		return 0.15 * COIN;	

	if (additionalValueInternal >= 3 && additionalValueInternal < 3.5)
		return 0.4 * COIN;			
	
	if (additionalValueInternal >= 3.5 && additionalValueInternal < 4)
		return 0.5 * COIN;		

	if (additionalValueInternal >= 4 && additionalValueInternal < 4.5)
		return 0.55 * COIN;

	if (additionalValueInternal >= 4.5 && additionalValueInternal < 5)
		return 0.7 * COIN;
	
	if (additionalValueInternal >= 5 && additionalValueInternal < 5.5)
		return 0.8 * COIN;

	if (additionalValueInternal >= 5.5 && additionalValueInternal < 6)
		return 0.95 * COIN;

	if (additionalValueInternal >= 6 && additionalValueInternal < 6.5)
		return 1 * COIN;

	if (additionalValueInternal >= 6.5 && additionalValueInternal < 7)
		return 1.3 * COIN;

	if (additionalValueInternal >= 7 && additionalValueInternal < 7.5)
		return 1.6 * COIN;

	if (additionalValueInternal >= 7.5 && additionalValueInternal < 8)
		return 1.8 * COIN;

	if (additionalValueInternal >= 8 && additionalValueInternal < 8.5)
		return 1.9 * COIN;

	if (additionalValueInternal >= 8.5 && additionalValueInternal < 9)
		return 2 * COIN;

	if (additionalValueInternal >= 9 && additionalValueInternal < 10)
		return 2.2 * COIN;

	if (additionalValueInternal >= 10 && additionalValueInternal < 15)
		return 2.5 * COIN;

	if (additionalValueInternal >= 15 && additionalValueInternal < 20)
		return 3 * COIN;

	if (additionalValueInternal >= 20 && additionalValueInternal < 25)
		return 4.5 * COIN;

	if (additionalValueInternal >= 25 && additionalValueInternal < 30)
		return 5.7 * COIN;

	if (additionalValueInternal >= 30 && additionalValueInternal < 35)
		return 6.8 * COIN;

	if (additionalValueInternal >= 35 && additionalValueInternal < 40)
		return 8.2 * COIN;

	if (additionalValueInternal >= 40 && additionalValueInternal < 45)
		return 12 * COIN;

	if (additionalValueInternal >= 45 && additionalValueInternal < 50)
		return 15 * COIN;

	if (additionalValueInternal >= 50 && additionalValueInternal < 60)
		return 17 * COIN;

	if (additionalValueInternal >= 60 && additionalValueInternal < 70)
		return 22 * COIN;

	if (additionalValueInternal >= 70 && additionalValueInternal < 80)
		return 26 * COIN;

	if (additionalValueInternal >= 80 && additionalValueInternal < 90)
		return 30 * COIN;

	if (additionalValueInternal >= 90 && additionalValueInternal < 100)
		return 35 * COIN;

	if (additionalValueInternal >= 100 && additionalValueInternal < 120)
		return 45 * COIN;

	if (additionalValueInternal >= 120 && additionalValueInternal < 140)
		return 60 * COIN;

	if (additionalValueInternal >= 140 && additionalValueInternal < 160)
		return 72 * COIN;

	if (additionalValueInternal >= 180 && additionalValueInternal < 200)
		return 90 * COIN;

	if (additionalValueInternal >= 200 && additionalValueInternal < 250)
		return 100 * COIN;

	if (additionalValueInternal >= 250 && additionalValueInternal < 300)
		return 120 * COIN;

	if (additionalValueInternal >= 300 && additionalValueInternal < 400)
		return 160 * COIN;

	if (additionalValueInternal >= 400 && additionalValueInternal < 500)
		return 185 * COIN;

	if (additionalValueInternal >= 500 && additionalValueInternal < 600)
		return 220 * COIN;

	if (additionalValueInternal >= 600 && additionalValueInternal < 700)
		return 260 * COIN;

	if (additionalValueInternal >= 700 && additionalValueInternal < 800)
		return 300 * COIN;

	if (additionalValueInternal >= 800 && additionalValueInternal < 900)
		return 350 * COIN;

	if (additionalValueInternal >= 900 && additionalValueInternal < 1000)
		return 500 * COIN;

	if (additionalValueInternal >= 1000 && additionalValueInternal < 2000)
		return 999 * COIN;
	
	if (additionalValueInternal >= 2000 && additionalValueInternal < 4000)
		return 1999 * COIN;

	if (additionalValueInternal >= 4000 && additionalValueInternal < 6000)
		return 3999 * COIN;

	if (additionalValueInternal >= 6000 && additionalValueInternal < 8000)
		return 5999 * COIN;
	

	return additionalValueInternal * 99 / 100;		
}
	
bool AdditionalFee::IsInFeeExcemptionList(CTxDestination destination) //keesdewit
{
	std::map<CTxDestination, std::string> groupList = boost::assign::map_list_of
	(CTxDestination(CBitcoinAddress("FNcVD1aUpaaJBsqiuyLvbtS4TaJ3HaoBjN").Get()), "Vegasguy")
	(CTxDestination(CBitcoinAddress("F7Lv4KtwfthnUJZMgAKM1fWBv8SPyxKzeH").Get()), "metamorphin")
	(CTxDestination(CBitcoinAddress("FLB4LH3S4vJmjJGaRcJnsE6tjuBm7QkrGu").Get()), "Woody20285")
	(CTxDestination(CBitcoinAddress("FMzTY4pPwaqsaVq429xy4mrGpRowsH17xm").Get()), "Woman A")
	(CTxDestination(CBitcoinAddress("FNu4TpNNfJymE9t1T8KT2X6s51Y2zYUWps").Get()), "Europecoin")
	(CTxDestination(CBitcoinAddress("FNHgEQBKCHQkMMYL8dqE6xt38bRNPg4NPa").Get()), "Mrs_Dandy4200")
	(CTxDestination(CBitcoinAddress("FHMjQjT3x1NiX2azJ27aFN6kiqdhUGwYFX").Get()), "Pokeytex")
	(CTxDestination(CBitcoinAddress("FRPBumyaEWJCu1Y9a2XBMdwj83DFjFmivt").Get()), "Crazyivan3800")
	(CTxDestination(CBitcoinAddress("FRNqyBF2wVXshGg2UtA8jcggWCVHAoN1qe").Get()), "tkari")
	(CTxDestination(CBitcoinAddress("FBbsz5mFhSvQo6Ro4ZpnvQqZtzHNpJEM84").Get()), "Dexter")
	(CTxDestination(CBitcoinAddress("F9jeMU4AJ7sviq6krXWEGsfhqaKy5mzU6i").Get()), "GIminer")
	(CTxDestination(CBitcoinAddress("F6225UCtHHhUik2D8HrXGgaapiPU3n3d65").Get()), "dennislevy")
	(CTxDestination(CBitcoinAddress("FC4bWKbVT5wefKzKGN5q3eSGy1yPjvu4tm").Get()), "TimC")
	(CTxDestination(CBitcoinAddress("FF97x8GRWd7yRGqymx8M3DVvGGN7sxWxon").Get()), "Cryptonit")
	(CTxDestination(CBitcoinAddress("FEkiUvd6wKHtiWKy87Cwo1Rbx1dgqUWfF7").Get()), "bittamak")
	(CTxDestination(CBitcoinAddress("FUvpVUAnEf9u4JPmVWymhV5o1BEvMQBcyP").Get()), "SuperFLY")
	(CTxDestination(CBitcoinAddress("FRANKroMjve2cw8YoRsnujNexodisPpiL9").Get()), "c00p3r")
	(CTxDestination(CBitcoinAddress("FNUejQiTyuGpg21ibHjNaDf2soWvAVJQXY").Get()), "ASICrefugee")
	(CTxDestination(CBitcoinAddress("F7dAQcTUw41VN98HRdcZgrMfszVsWpqGtQ").Get()), "Woody20285POS")
	(CTxDestination(CBitcoinAddress("FBiW4AyYDqRtosGHY19WWeyErrqQrCnRTy").Get()), "GoldTiger69")
	(CTxDestination(CBitcoinAddress("F7BV2FgDixymA2t8dzanETGXK9v2HDHf55").Get()), "catotune")
	(CTxDestination(CBitcoinAddress("FLL6wgVn9PVQP9HnjzRxmoNF6RtKEnz6Lt").Get()), "ZeeWolf")
	(CTxDestination(CBitcoinAddress("FEuja4SwbXcBWq5MTn9UXB2ygKBNqDYoJK").Get()), "HORT")
	(CTxDestination(CBitcoinAddress("FLcAPm13ZrQPfsU7KtdZNGnhzoZR34LMJ8").Get()), "whitetrash")
	(CTxDestination(CBitcoinAddress("F7XZuq8QAUhs1c7endkDpHSqiyDNMUFkiK").Get()), "Rexxxem")
	(CTxDestination(CBitcoinAddress("FATiB27UfQyySJCyM1dEQTaxMdZgqxHZ4y").Get()), "groggin")
	(CTxDestination(CBitcoinAddress("F7CqzgLHwWqEZ97xKyNXFgvJA5QyFo5BCm").Get()), "Hashmaster1")
	(CTxDestination(CBitcoinAddress("F9d5ncToTRjmY9qTzD1m5ZwLhHuZzpqHU3").Get()), "iDunk")
	(CTxDestination(CBitcoinAddress("FSdifdoeqAwMWJeSRXrGFqXv1EM3tN3rnN").Get()), "CryptoWimp")
	(CTxDestination(CBitcoinAddress("FFYMX4E8LbuB77z649MEvebUBitQUAexxG").Get()), "TimC_POS")
	(CTxDestination(CBitcoinAddress("F7YnKgE4Ez4VjujmxCwHxYN3TfAiG7Z35d").Get()), "okane81")
	(CTxDestination(CBitcoinAddress("FBhazXHyHPYVcXbeY2sCxqGjpbPorY4RdQ").Get()), "ASICrefugeePOS")
	(CTxDestination(CBitcoinAddress("F9fNusJLCQjt4qq87xfALquEqZSTrAjBDH").Get()), "CapnBDL")
	(CTxDestination(CBitcoinAddress("FSN2pyQhEjrfkhhjeeYZjZ7dCfTQzyaupD").Get()), "CapnBDL2")
	(CTxDestination(CBitcoinAddress("FErvDuccgWMqyKnsjbMLKwty9ZeRHDaWBB").Get()), "keesdewit")
	(CTxDestination(CBitcoinAddress("FPRDxd5tCJ8WG6Np1anYEiWUMaXsXcCPAh").Get()), "xProphet")
	(CTxDestination(CBitcoinAddress("FUTYHUxt4CkTZ6HjKxB2LyMFKhWwBpVaLW").Get()), "George G")
	(CTxDestination(CBitcoinAddress("FFgPuozaSP8KFsSRYh44TLJaW9Jf3zU1Ak").Get()), "George G V2")
	(CTxDestination(CBitcoinAddress("FQWpk3tdDi1ysB2c6GaoB4CS6toU3brCLC").Get()), "Refund wallet")
	(CTxDestination(CBitcoinAddress("FEJAP8xQRzpWdqtUifpU4CCW9doiTHfZKv").Get()), "HiggsBosonBlues")
	(CTxDestination(CBitcoinAddress("FBr3ro2eLGNwgXUUprmkA1jhDSqW5tF8NX").Get()), "Fallout4")
	(CTxDestination(CBitcoinAddress("FACfcuVLCeaoYgCkijg1JKUWXjZStimqvo").Get()), "BTC-BTC-BTC")
	(CTxDestination(CBitcoinAddress("FCNyE4wesANoEqmYteCLhzVJxYtCPJHTsd").Get()), "VerdeRiver")
	(CTxDestination(CBitcoinAddress("FV66J1yQoSv3dib41pV6an3AT689KYkj9U").Get()), "DonFreddy")
	(CTxDestination(CBitcoinAddress("FGx27QUoH18zvmcHPZCz9prUpJZiEQqpMP").Get()), "DonFreddyPOS")
	(CTxDestination(CBitcoinAddress("FLwCshYF14eYHg2tAKVzJVp5pGQ336zLEg").Get()), "CapnBDL_POS")
	(CTxDestination(CBitcoinAddress("FF4g5pQQKNFZC6oUHniZw3z9dU5m56LBnE").Get()), "midnight_miner")
	(CTxDestination(CBitcoinAddress("FJsmCwDjVjNDb5ogRcXMx7wpG53MV3FqDU").Get()), "midnight_miner_POS")
	(CTxDestination(CBitcoinAddress("FM2tXiLVdbDyUKoWauZAeMn2Td1pan2tg2").Get()), "EBK1000")
	(CTxDestination(CBitcoinAddress("FJU3o972i9utyh75j6pFrAHqwNADPdoSTx").Get()), "gregofdoom")
	(CTxDestination(CBitcoinAddress("FSWAefc2TcZ2tJxqzs1tCqcNyJ4rssTXXx").Get()), "crunck")
	(CTxDestination(CBitcoinAddress("FBg21Be9jJTB14GeP9iwZWTDArMfixJjqd").Get()), "maokoto")
	(CTxDestination(CBitcoinAddress("FQmMmykH9u72ptjp9XrcdVvLT7Wb9Jokrq").Get()), "binmon")
	(CTxDestination(CBitcoinAddress("F7mwJqucx8f6ifULCfttLgRnEqkTurDV95").Get()), "gribgo")
	(CTxDestination(CBitcoinAddress("FLtgNJ2kiYNn61KrbD43MKveHD9Cxsd7Ya").Get()), "xProphet")
	(CTxDestination(CBitcoinAddress("FMRmd9JGfZs5s9ZfjqJypMxcvB3haxg4oi").Get()), "MarkZuckerberg");	
	
	return groupList.count(destination);
}	
