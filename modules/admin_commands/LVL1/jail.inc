CMD:jail(playerid, params[]){
    if(AI[playerid][aLevel] < 1) return 1;
    if(sscanf(params, "dds[144]", params[0], params[1], params[2])) 
        return SendClientMessage(playerid, COLOR_VIOLET, "USE: {FFFFFF}/jail [id] [срок] [причина]");
    
    if(!IsPlayerConnected(params[0])) 
        return SendClientMessage(playerid, COLOR_VIOLET, "Игрок не подключен!");

    if(!gPlayerLogged[params[0]] || !gPlayerSpawned[params[0]]) 
        return SendClientMessage(playerid, COLOR_VIOLET, "Игрок не готов!");

    if(params[1] < 1) 
        return SendClientMessage(playerid, COLOR_VIOLET, "Срок не может быть меньше 1!");

    if(AI[params[0]][aLevel] > AI[playerid][aLevel]) 
        return SendClientMessage(playerid, COLOR_VIOLET, "Уровень игрока выше вашего!");

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
        
        format(str, sizeof(str), "{FFFFFF}%s {CCFF00}%s {FFFFFF}получил срок {CCFF00}%d{FFFFFF} минут: {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName], time, reason);
        SendClientMessageToAll(COLOR_VIOLET, str);
        
        mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `prisonlist` (`IDDB`, `getprison`, `endprison`, `admin`, `reason`, `leavetime`) VALUES ('%d','%d','%d','%s','%s','0')", PlayerInfo[playerid][pMID], gettime(), timemute, PlayerInfo[adminid][pName], reason);
        mysql_tquery(ServerDB, str, "", "");
    } else {
        Prison[playerid] = gettime() + (60*time);
        new timemute = gettime() + (60*time);
        
        format(str, sizeof(str), "{FFFFFF}%s {CCFF00}%s {FFFFFF}получил срок {CCFF00}%d{FFFFFF} минут: {CCFF00}%s", PlayerInfo[adminid][pName], PlayerInfo[playerid][pName], time, reason);
        SendClientMessageToAll(COLOR_VIOLET, str);
        
        mysql_format(ServerDB, str, sizeof(str), "INSERT INTO `prisonlist` (`IDDB`, `getprison`, `endprison`, `admin`, `reason`, `leavetime`) VALUES ('%d','%d','%d','%s','%s','0')", PlayerInfo[playerid][pMID], gettime(), timemute, PlayerInfo[adminid][pName], reason);
        mysql_tquery(ServerDB, str, "", "");
    }
    Teleport(playerid, 1104.6355, 1098.7548, 1098.0000, 0, 0, false, 88.7659);
    prisontimer[playerid] = SetTimerEx("CheckPrison", 5000, false, "i", playerid);
    ResetPlayerWeapons(playerid);
    return 1;
}

fpub:CheckPrison(playerid){
    if(prisoncheck[playerid] != true && Prison[playerid] > gettime()){
        new str[256];
        format(str, sizeof(str), "{FFFFFF}%s {CCFF00}в тюрьме", PlayerInfo[playerid][pName]);
        SendClientMessageToAll(COLOR_VIOLET, str);
        Kick(playerid);
        KillTimer(prisontimer[playerid]);
        prisontimer[playerid]=0;
    }
    return 1;
}