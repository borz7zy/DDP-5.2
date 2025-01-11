CMD:cmdscan(playerid){
	if(AI[playerid][aLevel] < 4) return 1;
	switch(AI[playerid][aReadCMD]){
		case false:{
			AI[playerid][aReadCMD]=true;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы включили сканирование команд{CCFF00}!");
		}
		case true:{
			AI[playerid][aReadCMD]=false;
			SendClientMessage(playerid, COLOR_VIOLET, ""NS" {FFFFFF}Вы отключили сканирование команд{CCFF00}!");
		}
	}
	return 1;
}