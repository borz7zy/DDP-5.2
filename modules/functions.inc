stock SendForSpawned(color, const message[]){
	foreach(Player,i) if(gPlayerSpawned[i] == 1 && IsPlayerConnected(i))SendClientMessage(i, color, message);
	return 1;
}

stock SendAdminMessage(color, const string[])
{
	foreach(Player,i) if(IsPlayerConnected(i) && AI[i][aLevel] > 0)SendClientMessage(i, color, string);
	return 1;
}

stock CheckFlood(playerid, const acheeto[], time){
	if(GetPVarInt(playerid, acheeto) > gettime()){
		return 0;
	}else{
		SetPVarInt(playerid, acheeto, gettime()+time);
		return 1;
	}
}

/*
*
* Перенос строки реализуется таким образом: считаем колличество символов перед сообщением (в том числе символы цветов)
* далее - мы знаем лимит сообщений в строке: 144 символов. Узнаём колличество символов в входной строке.
* Если колличество символов в входной строке + колличество символов до строки (название банды + ник + айди + цвета) > 144 -
* - то создаём перенос.
*
* Извлекаем доступное колличество символов для отправки и режем строку, далее - режем строку и переносим остаток строки на новую строку.
*
*/

stock SendLocalChat(playerid, const pText[]){
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	new str[256], onetext[144], twotext[144];
	foreach(Player, i)
	{
		if(PlayerToPoint(50.0, playerid, X, Y, Z)){
			if(PlayerInfo[playerid][pGang] == 0){
				if(PlayerToPoint(50.0, i, X, Y, Z)){
					if(strlen(pText)+1+1+strlen(PlayerInfo[playerid][pName])+2+3+1+16 > 144){//режем сообщение так как оно не попадает в рамки
						
						strmid(onetext, pText, 0, strlen(pText)-(1+1+strlen(PlayerInfo[playerid][pName])+2+3+1+16));
						format(str, sizeof(str), ""MNS" %s: {8E8E8E}( {FFFFFF}%s {8E8E8E})", PlayerInfo[playerid][pName], onetext);
						SendClientMessage(i, GetPlayerColor(playerid), str);
						
						strmid(twotext,pText,strlen(onetext), strlen(pText));
						format(str, sizeof(str), ""MNS" %s: {8E8E8E}( {FFFFFF}%s {8E8E8E})", PlayerInfo[playerid][pName], twotext);
						SendClientMessage(i, GetPlayerColor(playerid), str);
						
					}else{//ну либо шлём как есть, все равно влезет
						format(str, sizeof(str), ""MNS" %s: {8E8E8E}( {FFFFFF}%s {8E8E8E})", PlayerInfo[playerid][pName], pText);
						SendClientMessage(i, GetPlayerColor(playerid), str);
					}
					SetPlayerChatBubble(playerid, pText, GetPlayerColor(playerid), 15.0, 5000);
				}
			}else{
				if(PlayerToPoint(50.0, i, X, Y, Z)){
					if(strlen(pText)+strlen(GangInfo[PlayerInfo[playerid][pGang]][gName])+1+strlen(PlayerInfo[playerid][pName])+2+3+1+16 > 144){
						
						strmid(onetext, pText, 0, strlen(pText)-(strlen(GangInfo[PlayerInfo[playerid][pGang]][gName])+1+strlen(PlayerInfo[playerid][pName])+2+3+1+16));
						format(str, sizeof(str), "%s %s[%d] шепчет: {FFFFFF}%s", GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pName], onetext);
						SendClientMessage(i, GetPlayerColor(playerid), str);
						
						strmid(twotext,pText,strlen(onetext), strlen(pText));
						format(str, sizeof(str), "%s %s[%d] шепчет: {FFFFFF}%s", GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pName], twotext);
						SendClientMessage(i, GetPlayerColor(playerid), str);
						
					}else{
						format(str, sizeof(str), "%s %s: {8E8E8E}( {FFFFFF}%s {8E8E8E})", GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pName], pText);
						SendClientMessage(i, GetPlayerColor(playerid), str);
					}
					SetPlayerChatBubble(playerid, pText, GetPlayerColor(playerid), 15.0, 5000);
				}
			}
		}
	}
	return 0;
}

stock SendPingPlayerMessage(playerid, const pText[], pingplayerid){
	new str[256], onetext[144], twotext[144];
	if(PlayerInfo[playerid][pGang] == 0){
		if(strlen(pText)+1+1+24+2+3+1+8+24+1+1+8 > 144){
			strmid(onetext, pText, 0, strlen(pText)-(1+1+24+2+3+1+8+24+1+1+8));
			format(str, sizeof(str), ""MNS" %s[%d]:{CCFF00}%s, {FFFFFF}%s", PlayerInfo[playerid][pName], playerid, PlayerInfo[pingplayerid][pName], onetext);
			SendClientMessageToAll(GetPlayerColor(playerid), str);
			
			strmid(twotext,pText,strlen(onetext), strlen(pText));
			format(str, sizeof(str), ""MNS" %s[%d]: {CCFF00}%s, {FFFFFF}%s", PlayerInfo[playerid][pName], playerid, PlayerInfo[pingplayerid][pName], twotext);
			SendClientMessageToAll(GetPlayerColor(playerid), str);
		}else{
			format(str, sizeof(str), ""MNS" %s[%d]: {CCFF00}%s, {FFFFFF}%s", PlayerInfo[playerid][pName], playerid, PlayerInfo[pingplayerid][pName], pText);
			SendClientMessageToAll(GetPlayerColor(playerid), str);
			SetPlayerChatBubble(playerid, pText, GetPlayerColor(playerid), 15.0, 5000);
		}
	}else{
		if(strlen(pText)+strlen(GangInfo[PlayerInfo[playerid][pGang]][gName])+1+24+2+3+1+8+24+1+1+8 > 144){
			strmid(onetext, pText, 0, strlen(pText)-(strlen(GangInfo[PlayerInfo[playerid][pGang]][gName])+1+24+2+3+1+8+24+1+1+8));
			format(str, sizeof(str), ""MNS" %s[%d]:{CCFF00}%s, {FFFFFF}%s", PlayerInfo[playerid][pName], playerid, PlayerInfo[pingplayerid][pName], onetext);
			SendClientMessageToAll(GetPlayerColor(playerid), str);
			
			strmid(twotext,pText,strlen(onetext), strlen(pText));
			format(str, sizeof(str), ""MNS" %s[%d]: {CCFF00}%s, {FFFFFF}%s", PlayerInfo[playerid][pName], playerid, PlayerInfo[pingplayerid][pName], twotext);
			SendClientMessageToAll(GetPlayerColor(playerid), str);
		}else{
			format(str, sizeof(str), ""MNS" %s[%d]: {CCFF00}%s, {FFFFFF}%s", PlayerInfo[playerid][pName], playerid, PlayerInfo[pingplayerid][pName], pText);
			SendClientMessageToAll(GetPlayerColor(playerid), str);
			SetPlayerChatBubble(playerid, pText, GetPlayerColor(playerid), 15.0, 5000);
		}
	}
	PlayerPlaySound(pingplayerid, 1085,0,0,0);
	return 0;
}