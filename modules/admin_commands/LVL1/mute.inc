CMD:mute(playerid, params[]){
	new str[256];
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "dds[144]", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/mute [id] [минуты] [причина]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы ввели ID оффлайн игрока!");
	if(params[1] < 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Минут не может быть меньше 1!");
	if(gPlayerLogged[params[0]] == 0 || gPlayerSpawned[params[0]] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не залогинился/заспавнился!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	mysql_format(ServerDB, str, sizeof(str), "SELECT `IDDB` FROM `mutedlist` WHERE `IDDB` = '%d' LIMIT 1", PlayerInfo[params[0]][pMID]);
	mysql_tquery(ServerDB, str, "MutePlayer", "ddds", params[0], params[1], playerid, params[2]);
	return 1;
}

fpub:MutePlayer(playerid, time, adminid, const reason[]){
	new str[256];
	if(cache_num_rows() > 0){
		mysql_format(ServerDB, str, sizeof(str), "DELETE FROM `mutedlist` WHERE `IDDB`='%d' LIMIT 1", PlayerInfo[playerid][pMID]);
		mysql_tquery(ServerDB, str, "", "");
		
		Muted[playerid] = gettime() + (60*time);
		new timemute = gettime() + (60*time);
		
		format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}перезаткнул игрока {CCFF00}%s (%d мин){FFFFFF}. Причина: {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName], time, reason);
		SendClientMessageToAll(COLOR_VIOLET, str);
		mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `mutedlist` (`IDDB`, `getmute`, `endmute`, `admin`, `reason`, `leavetime`) VALUES ('%d','%d','%d','%e','%s','0')", PlayerInfo[playerid][pMID], gettime(), timemute, PlayerInfo[adminid][pName], reason);
		mysql_tquery(ServerDB, str, "", "");
	}else{
		Muted[playerid] = gettime() + (60*time);
		new timemute = gettime() + (60*time);
		
		format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}заткнул игрока {CCFF00}%s (%d мин){FFFFFF}. Причина: {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName], time, reason);
		SendClientMessageToAll(COLOR_VIOLET, str);
		mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `mutedlist` (`IDDB`, `getmute`, `endmute`, `admin`, `reason`, `leavetime`) VALUES ('%d','%d','%d','%e','%s','0')", PlayerInfo[playerid][pMID], gettime(), timemute, PlayerInfo[adminid][pName], reason);
		mysql_tquery(ServerDB, str, "", "");
	}
	return 1;
}