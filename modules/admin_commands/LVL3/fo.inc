CMD:fo(playerid, params[]){
	if(AI[playerid][aLevel] < 3) return 1;
	new color[9], text[144];
	if(sscanf(params, "s[7]s[144]", color, text)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/fo [color(RRGGBB)] [text]");
	new str[256];
	if(strlen(color) < 6 || strlen(color) > 6) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}”казан неправильный цвет!");
	format(str, sizeof(str), "%s", text);
	format(color, sizeof(color), "%sFF", color);
	SendClientMessageToAll(HexToInt(color), str);
	format(str, sizeof(str), ""NS" {FFFFFF}јдмин {CCFF00}%s[%d] {FFFFFF}написал в чат от имени админа",PlayerInfo[playerid][pName],playerid);
	SendAdminMessage(COLOR_VIOLET, str);
	return 1;
}