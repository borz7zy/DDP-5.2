CMD:offban(playerid, params[])
{
	if(AI[playerid][aLevel] < 5) return 1;
	
	new idd[24];
	new days;
	new prichina[144];
	new unbandate2;
	new str[512];

	if(sscanf(params,"s[24]is[144]",idd,days,prichina)) return SendClientMessage(playerid, COLOR_VIOLET, "USE: /offban [Nickname] [���(3-30)] [�������]");
	if(days > 30 || days < 3) return SendClientMessage(playerid, COLOR_RED, "������! ���� �� 3 �� 30!");
	unbandate2 = gettime() + days*86400;

	mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `bans` (`NameBan`, `UnbanDate`, `BanDate`, `Who`, `Reason`) VALUES ('%e', '%d', '%d', '%s', '%s')",idd,unbandate2,gettime(),PlayerInfo[playerid][pName],prichina);
	mysql_tquery(ServerDB, str, "", "");

	foreach(Player, i){
		if(strcmp(PlayerInfo[i][pName], idd, true) == 0){
			Kick(i);
		}
	}

	format(str, sizeof(str), ""NS" {FFFFFF}����� {CCFF00}%s {FFFFFF}������� ������ {CCFF00}%s {FFFFFF}�� {CCFF00}%d {FFFFFF}����. �������:{CCFF00} %s",PlayerInfo[playerid][pName],idd,days,prichina);
	SendClientMessageToAll(COLOR_VIOLET, str);
	return 1;
}