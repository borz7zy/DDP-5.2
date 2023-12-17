CMD:unban(playerid, params[])
{
	if(AI[playerid][aLevel] < 3) return 1;
	new str[128],nick[MAX_PLAYER_NAME];
	if(sscanf(params,"s[24]",nick)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: /unban [Nickname]");
	mysql_format(ServerDB, str, sizeof(str), "SELECT * FROM `bans` WHERE `NameBan` = '%e' LIMIT 1", nick);
	mysql_tquery(ServerDB, str, "CheckBanned", "ds", playerid, nick);
	return 1;
}

fpub:CheckBanned(playerid, const nick[])
{
	new string[256];
	if(cache_num_rows() > 0)
	{
		mysql_format(ServerDB, string, sizeof(string), "DELETE FROM `bans` WHERE `NameBan`='%s' LIMIT 1", nick);
		mysql_tquery(ServerDB, string, "", "");
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {00FF00}Разнанен!");
	}
	else
	{
		SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFF00}Аккаунт не забанен!");
	}
	return 1;
}