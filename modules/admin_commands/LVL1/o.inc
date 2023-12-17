CMD:o(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	new color[9], text[144];
	if(sscanf(params, "s[7]s[144]", color, text)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/o [color(RRGGBB)] [text]");
	new str[256];
	if(strlen(color) < 6 || strlen(color) > 6) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Указан неправильный цвет!");
	format(str, sizeof(str), "АДМИН %s[%d]: %s", PlayerInfo[playerid][pName], playerid, text);
	format(color, sizeof(color), "%sFF", color);
	SendClientMessageToAll(HexToInt(color), str);
	return 1;
}