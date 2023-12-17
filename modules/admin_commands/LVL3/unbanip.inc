CMD:unbanip(playerid, params[])
{
	if(AI[playerid][aLevel] < 3) return 1;
	new str[128],nick[17];
	if(sscanf(params,"s[17]",nick)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: /unbanip [IP]");
	mysql_format(ServerDB, str, sizeof(str), "SELECT * FROM `ipbans` WHERE `NameBan` = '%e' LIMIT 1", nick);
	mysql_tquery(ServerDB, str, "CheckBannedIP", "ds", playerid, nick);
	return 1;
}

fpub:CheckBannedIP(playerid, const nick[])
{
	new string[256];
	if(cache_num_rows() > 0)
	{
		mysql_format(ServerDB, string, sizeof(string), "DELETE FROM `ipbans` WHERE `IP`='%s' LIMIT 1", nick);
		mysql_tquery(ServerDB, string, "", "");
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {00FF00}Разнанен!");
	}
	else
	{
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFF00}IP не забанен!");
	}
	return 1;
}