CMD:live(playerid){
	if(AI[playerid][aLevel] < 2) return 1;
	new string[144];
	if (AI[playerid][aGod] == 1)
	{
		AI[playerid][aGod] = 0;
		format(string,sizeof(string),""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}выключил собственное бессмертие.", PlayerInfo[playerid][pName]);
		SendAdminMessage(COLOR_VIOLET, string);
	}
	else
	{
		AI[playerid][aGod] = 1;
		format(string,sizeof(string),""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}включил собственное бессмертие.", PlayerInfo[playerid][pName]);
		SendAdminMessage(COLOR_VIOLET, string);
	}
	return 1;
}
