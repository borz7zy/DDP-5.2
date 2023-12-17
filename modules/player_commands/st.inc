CMD:st(playerid, params[]){
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "USE: {FFFFFF}/st [час(0-23)]");
	if(params[0]<0 || params[0]>23) return SendClientMessage(playerid, COLOR_RED, "USE: {FFFFFF}/st [час(0-23)]");
	SetPlayerTime(playerid, params[0], 0);
	new str[144];
	format(str, sizeof(str), ""NS" {FFFFFF}Установлено %02d:00 часов!", params[0]);
	SendClientMessage(playerid, COLOR_VIOLET, str);
	strdel(str, 0, sizeof(str));
	return 1;
}