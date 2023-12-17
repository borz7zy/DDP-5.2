CMD:offban(playerid, params[])
{
	if(PlayerInfo[playerid][aLevel] < 5) return 1;
	new idd[24],days,prichina[144],unbandate2,str[512];
	if(sscanf(params,"s[24]is[144]",idd,days,prichina)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: /offban [Nickname] [дни(3-30)] [причина]");
	if(days > 30 || days < 3) return SendClientMessage(playerid, COLOR_RED, "Ошибка! Дней от 3 до 30!");
	unbandate2 = gettime() + days*86400; // текущая дата + дни бана умноженные на 86400 = день разбана

	mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `bans` (`NameBan`, `UnbanDate`, `BanDate`, `Who`, `Reason`) VALUES ('%e', '%d', '%d', '%s', '%s')",idd,unbandate2,gettime(),PlayerInfo[playerid][pName],prichina);
	mysql_tquery(ServerDB, str, "", "");

	foreach(Player, i){
		if(strcmp(PlayerInfo[i][pName], idd, true) == 0){
			Kick(i);
		}
	}

	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}забанил аккаунт {CCFF00}%s {FFFFFF}на {CCFF00}%d {FFFFFF}дней. Причина:{CCFF00} %s",PlayerInfo[playerid][pName],idd,days,prichina);
	SendClientMessageToAll(COLOR_VIOLET, str);
	return 1;
}