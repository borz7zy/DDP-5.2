CMD:unmute(playerid, params[]){
	new str[256];
	if(AI[playerid][aLevel] < 1) return 1;
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/unmute [id]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы ввели ID оффлайн игрока!");
	if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не залогинился/заспавнился!");
	if(AI[params[0]][aLevel] > AI[playerid][aLevel]) return SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Админ стоит на уровень выше вас{FF0000}! {FFFFFF}Невозможно{FF0000}!");
	mysql_format(ServerDB, str, sizeof(str), "SELECT `IDDB` FROM `mutedlist` WHERE `IDDB` = '%d' LIMIT 1", PlayerInfo[params[0]][pMID]);
	mysql_tquery(ServerDB, str, "UnmutePlayer", "dd", params[0], playerid);
	return 1;
}

fpub:UnmutePlayer(playerid, adminid){
	new str[256];
	if(cache_num_rows() > 0){
		mysql_format(ServerDB, str, sizeof(str), "DELETE FROM `mutedlist` WHERE `IDDB`='%d' LIMIT 1", PlayerInfo[playerid][pMID]);
		mysql_tquery(ServerDB, str, "", "");
		
		Muted[playerid] = 0;
		format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}размутил игрока {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName]);
		SendClientMessageToAll(COLOR_VIOLET, str);
	}else{
		if(Muted[playerid] > gettime()){
			Muted[playerid] = 0;
			format(str, sizeof(str), ""NS" {FFFFFF}Админ {CCFF00}%s {FFFFFF}размутил игрока {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName]);
			SendClientMessageToAll(COLOR_VIOLET, str);
		}else SendClientMessage(adminid, COLOR_VIOLET, ""NS" {FFFFFF}Игрок не был заткнут!");
	}
	return 1;
}