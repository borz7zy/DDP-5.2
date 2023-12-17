CMD:ban(playerid, params[]){
	if(AI[playerid][aLevel] < 2) return 1;
	new str[512];
	new id, day, reason[144];
	if(sscanf(params, "dds[144]",id, day, reason))return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/ban [id] [дни(3-30)] [причина]");
	if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} Вы ввели ID игрока, которого нет на сервере!");
	if(playerid == id) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} Невозможно забанить самого себя!");
	if(day > 30 || day < 3) return SendClientMessage(playerid, COLOR_RED, "Ошибка! Дней от 3 до 30!");
	if(AI[id][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	new unbandate=gettime() + day*86400;// текущая дата + дни бана умноженные на 86400 = день разбана
	mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `bans` (`NameBan`, `UnbanDate`, `BanDate`, `Who`, `Reason`, `IP`) VALUES ('%e','%d','%d','%e','%s','%s')", PlayerInfo[id][pName], unbandate, gettime(), PlayerInfo[playerid][pName], reason, PlayerInfo[id][pIPAdr]);
	mysql_tquery(ServerDB, str, "", "");
	
	format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}забанил {FF0000}%s{FFFFFF} на {CCFF00}%d{FFFFFF}дней.", PlayerInfo[playerid][pName], PlayerInfo[id][pName], day);
	SendClientMessageToAll(COLOR_VIOLET, str);
	format(str, sizeof(str), ""NS" {FFFFFF}Причина бана:{FF0000}%s", reason);
	SendClientMessageToAll(COLOR_VIOLET, str);

 	format(str, sizeof(str),"{FF0000}ВЫ БЫЛИ ЗАБАНЕНЫ!!!\n{FFFFFF}Дата бана: %s\nДата разбана: %s\nЗабанил: %s\nПричина: %s\n\n{FFFFFF}Вы можете подать заявление по разбану в обсуждениях группы\n{CCFF00}"VK_G"", date("%dd/%mm/%yyyy в %hh:%ii:%ss",gettime()), date("%dd/%mm/%yyyy в %hh:%ii:%ss",unbandate), PlayerInfo[playerid][pName], reason);
	ShowPlayerDialog(id,2,0,"{CCFF00}>>[ВЫ ЗАБАНЕНЫ!]<<",str,"Ok","");

	Kick(id);
	return 1;
}