
CMD:makeadmin(playerid, params[]){
	if (AI[playerid][aLevel] >= 4 || IsPlayerAdmin(playerid)){
		new str[73];
		new id, datas, lvl, pass[32];
		if(sscanf(params, "ddds[32]",id,lvl,datas,pass))return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/makeadmin [id] [level] [day] [pass]");
		if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} Вы ввели ID игрока, которого нет на сервере!");
		if(lvl<1 || lvl>4) return SendClientMessage(playerid, COLOR_VIOLET, ""NS"{99FF99} Уровень должен быть не меньше 1 и не больше 4!");
		mysql_format(ServerDB, str, sizeof(str), "SELECT * FROM `admins` WHERE `aname` = '%e' LIMIT 1", PlayerInfo[id][pName]);
		mysql_tquery(ServerDB, str, "makeadmin", "dddds", playerid, id, datas, lvl, pass);
	}else {return 1;}

	return 1;
}
static inc_gLetterssss[26*2+10] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
fpub:makeadmin(playerid,makeid,datas,level, const pass[]){
	new datenum,query[512];
	if(datas !=0)datenum=gettime()+datas*86400;
	else datenum=0;
	if(cache_num_rows() > 0){//update
		mysql_format(ServerDB, query, sizeof(query), "UPDATE `admins` SET `setadmin`='%s', `blocklogged`='0', `dateget`='%d', `dateend`='%d', `alevel`='%d' WHERE `aname`='%e' LIMIT 1", AI[playerid][aName], gettime(), datenum, level, PlayerInfo[makeid][pName]);
		mysql_tquery(ServerDB, query, "", "");
		SendClientMessage(makeid, COLOR_VIOLET, ""NS"{FFFFFF} Вам обновили админ статус! Переавторизируйтесь через /alogin");
		SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} Админка обновлена!");
		AI[makeid][db_ID] = 0;
		AI[makeid][aHASH][0] = EOS;
		AI[makeid][aPass][0] = EOS;
		AI[makeid][aName][0] = EOS;
		AI[makeid][aDGet] = 0;
		AI[makeid][aDEnd] = 0;
		AI[makeid][aMakeAdmin][0] = EOS;
		AI[makeid][aMakeAdminEnd][0] = EOS;
		AI[makeid][aReasonEnd][0] = EOS;
		AI[makeid][aBlock] = 0;
		AI[makeid][aKickPlayers] = 0;
		AI[makeid][aBanPlayers] = 0;
		AI[makeid][aLogCount] = 0;
		AI[makeid][aLevel] = 0;
		AI[makeid][aResPlayer] = 0;
		AI[makeid][aTimeOnline] = 0;
		AI[makeid][aGod] = 0;
	}else{//insert

		new hashed_pass[65],
		salt[17];
		for(new i;i<6;i++)
		{
			salt[i] = inc_gLetterssss[random(sizeof(inc_gLetterssss))];
		}
		SHA256_PassHash(pass, salt, hashed_pass, 65);

		mysql_format(ServerDB, query, sizeof(query), "INSERT INTO `admins` (`aname`, `apass`, `hash`, `alevel`, `dateget`, `setadmin`, `dateend`, `setendadmin`, `reasonend`, `blocklogged`, `kicksplayers`, `banedplayers`, `loggedcount`) VALUES ('%e','%s','%e','%d','%d','%e','%d','%e','%s','%d','%d','%d','%d')",
		PlayerInfo[makeid][pName], hashed_pass, salt, level, gettime(), AI[playerid][aName], datenum, " ", " ", 0, 0, 0, 0);
		mysql_tquery(ServerDB, query, "", "");
		format(query, sizeof(query), "%s {FFFFFF}Вы получили админку {99FF99}%d {FFFFFF}уровня! Запишите следующий пароль на листок: {99FF99}%s", NS, level, pass);
		SendClientMessage(makeid, COLOR_VIOLET, query);
		SendClientMessage(makeid, COLOR_VIOLET, ""NS" {FFFFFF}Этот пароль пригодится Вам для авторизации в админ панели. Команда авторизации: /alogin [пароль]");
		SendClientMessage(playerid, COLOR_VIOLET, ""NS"{FFFFFF} Админка выдана!");
		format(query, sizeof(query), "Админ %s дал игроку %s админку %d уровня на %d дней!", PlayerInfo[playerid][pName], PlayerInfo[makeid][pName], datas);
		SendAdminMessage(0xCCFF00FF, query);
	}
	return 1;
}