CMD:skin(playerid, params[]){
	if(job[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала увольтесь с работы{FF0000}!");
	if(dmzone[playerid] != 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Для начала уйдите с дм зоны! {CCFF00}( /dmexit )");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/skin [id(0-299)]");
	if(params[0] < 0 || params[0] > 299) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}ID скина от 0 до 299{FF0000}!");
	static const femaleskinsone[]={9,10,11,12,13,31,38,39,40,41,53,54,55,56,63,64,65,69,
	75,76,77,85,87,88,89,90,91,92,93,129,130,131,138,139,140,141,145,148,150,151,152,
	157,169,172,178,190,191,192,193,194,195,196,197,198,199,201,205,207,211,214,215,
	216,218,219,224,225,226,231,232,233,237,238,243,244,245,246,251,256,257,263,298,
	306,307,308,309};
	if(SearchValueInElemetsArray(femaleskinsone, params[0]) != -1 && PlayerInfo[playerid][pSex] == 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы ввели женский скин{FF0000}!");
	if(SearchValueInElemetsArray(femaleskinsone, params[0]) == -1 && PlayerInfo[playerid][pSex] == 2) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы ввели мужской скин{FF0000}!");
	PlayerInfo[playerid][pSkin] = params[0];
	SetPlayerSkin(playerid, PlayerInfo[playerid][pSkin]);
	SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Скин изменён{CCFF00}!");
	return 1;
}
