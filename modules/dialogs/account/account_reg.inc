//4884

fpub:dialog_register(pid, dialogid, response, listitem, string:inputtext[]){
    if (!response)
    {
        Kick(pid);
        return 1;
    }
    if (PassControl(inputtext) == 0)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ����� ������������ ������ ���������");
        dialog_register_show(pid);
        return 1;
    }
    if (strlen(inputtext) < 6)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}�������� � ������ ������ ���� �� ������ 6!");
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}�������: �� a �� z , �� A �� Z , � ����� �� 0 �� 9 !");
        dialog_register_show(pid);
        return 1;
    }
    new hashed_pass[65];
    new salt[17];
    for (new i; i < 16; ++i)
    {
        switch(random(3)){
            case 0: salt[i] = random_range_int(48, 57);
            case 1: salt[i] = random_range_int(65, 90);
            case 2: salt[i] = random_range_int(97, 122);
        }
    }
    SHA256_Hash(inputtext, salt, hashed_pass, 65);
    new query[512];
    mysql_format(ServerDB, query, sizeof(query), "INSERT INTO `players` (`PlayerName`, `Pass`, `HASH`, `Money`, `Kills`, `Deaths`, `TDReg`, `Combo`, `IPAdr`, `Skin`) VALUES ('%e','%s','%e','50000','0','0','%d','1','%e','-1')", PlayerInfo[pid][pName], hashed_pass, salt, gettime(), PlayerInfo[pid][pIPAdr]);
    mysql_tquery(ServerDB, query, "OnPlayerRegistered", "is", pid, inputtext);
    PlayerInfo[pid][pTDReg] = gettime();
    return 1;
}

stock dialog_register_show(playerid)
{
    new strr[2048];
    format(strr, sizeof(strr), "{FF0000}������� ������� �������:\
    \n- {8F30E4}��������� ������������ ���� ������ ������� ��� �������������.\
    \n- {8F30E4}��������� ���������� ������ ������� � ������ �� ������.\
    \n- {8F30E4}��������� ������� �������.\
    \n- {8F30E4}��������� ������������� ����������� �����/�������.");
    format(strr, sizeof(strr), "%s\
    \n- {8F30E4}��������� ������� ������� ������������ ��������� (��).\
    \n- {8F30E4}��������� ��������� � ������� � ���.\
    \n- {8F30E4}��������� ������������ ����� ����, � ����������� �����������!\
    \n- {8F30E4}��������� ������� ���� ����, �� �������� ������.\
    \n\n{FF0000}��������� FAQ �� �������:", strr);
    format(strr, sizeof(strr), "%s\
    \n- {8F30E4}��� ������ ������ ������� ����������� /cmd.\
    \n- {8F30E4}�� ������� ������������ ������� ���� (ALT - ������, ������ 2 - � ������)\
    \n\n{FF0000}���������� ������� ������, ����� �������� ������ ������ ��������.\
    \n{FF0000}������������� {00FFAA}DDP ������� {FF0000}- �� ���� ��������������� �� ��������� ��������.\
    \n\n{FF0000}��� ���: {8F30E4}%s", strr, PlayerInfo[playerid][pName]);
    // ShowPlayerDialog(playerid, 0, DIALOG_STYLE_INPUT, ">>[����������� �� DREAMS]<<", strr, "�����", "������");
    Dialog_ShowCallback(playerid, using public dialog_register<iiiis>, DIALOG_STYLE_INPUT, "{8F30E4}>>[����������� �� DREAMS]<<", strr, "�����", "������");
}