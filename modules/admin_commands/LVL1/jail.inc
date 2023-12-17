CMD:jail(playerid, params[]){
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "dds[144]", params[0], params[1], params[2])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/jail [id] [минуты] [причина]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрока нет на сервере!");
	if(gPlayerLogged[params[0]] == 0 || gPlayerSpawned[params[0]] == 0) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не заспавнился/авторизовался!");
	if(params[1] < 1) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Минут не меньше 1!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	new str[256];
	mysql_format(ServerDB, str, sizeof(str), "SELECT `IDDB` FROM `prisonlist` WHERE `IDDB` = '%d' LIMIT 1", PlayerInfo[params[0]][pMID]);
	mysql_tquery(ServerDB, str, "JailPlayer", "ddds", params[0], params[1], playerid, params[2]);
	return 1;
}

fpub:JailPlayer(playerid, time, adminid, const reason[]){
	new str[256];
	if(cache_num_rows() > 0){
		mysql_format(ServerDB, str, sizeof(str), "DELETE FROM `prisonlist` WHERE `IDDB`='%d' LIMIT 1", PlayerInfo[playerid][pMID]);
		mysql_tquery(ServerDB, str, "", "");
		
		Prison[playerid] = gettime() + (60*time);
		new timemute = gettime() + (60*time);
		
		format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}посадил игрока {CCFF00}%s (%d мин){FFFFFF}. Причина: {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName], time, reason);
		SendClientMessageToAll(COLOR_VIOLET, str);
		mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `prisonlist` (`IDDB`, `getprison`, `endprison`, `admin`, `reason`, `leavetime`) VALUES ('%d','%d','%d','%e','%s','0')", PlayerInfo[playerid][pMID], gettime(), timemute, PlayerInfo[adminid][pName], reason);
		mysql_tquery(ServerDB, str, "", "");
	}else{
		Prison[playerid] = gettime() + (60*time);
		new timemute = gettime() + (60*time);
		
		format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}посадил игрока {CCFF00}%s (%d мин){FFFFFF}. Причина: {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName], time, reason);
		SendClientMessageToAll(COLOR_VIOLET, str);
		mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `prisonlist` (`IDDB`, `getprison`, `endprison`, `admin`, `reason`, `leavetime`) VALUES ('%d','%d','%d','%e','%s','0')", PlayerInfo[playerid][pMID], gettime(), timemute, PlayerInfo[adminid][pName], reason);
		mysql_tquery(ServerDB, str, "", "");
	}
	Teleport(playerid, 1104.6355, 1098.7548, 1098.0000, 0, 0, 0, 88.7659);
	prisontimer[playerid] = SetTimerEx("CheckPrison", 5000, false, "i", playerid);
	ResetPlayerWeapons(playerid);
	return 1;
}

fpub:CheckPrison(playerid){
	if(prisoncheck[playerid] != true && Prison[playerid] > gettime()){
		new str[256];
		format(str, sizeof(str), ""NS" {FFFFFF}Игрок {CCFF00}%s {FFFFFF}попытался отказаться от тюрьмы и был кикнут!", PlayerInfo[playerid][pName]);
		SendClientMessageToAll(COLOR_VIOLET, str);
		Kick(playerid);
		KillTimer(prisontimer[playerid]);
		prisontimer[playerid]=0;
	}
	return 1;
}