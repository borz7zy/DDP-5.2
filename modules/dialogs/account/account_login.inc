fpub:dialog_login(pid, dialogid, response, listitem, string:inputtext[]){
    if (!response)
    {
        Kick(pid);
        return 1;
    }
    if (PassControl(inputtext) == 0)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}� ������ ����� ������������ ������ ���������");
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}�������: �� a �� z , �� A �� Z , � ����� �� 0 �� 9 !");
        DialogLoginShow(pid);
        return 1;
    }
    if (strlen(inputtext) < 6) return DialogLoginShow(pid);
    new hashed_pass[65];
    SHA256_Hash(inputtext, PlayerInfo[pid][pHASH], hashed_pass, 65);
    if (strcmp(PlayerInfo[pid][pKey], hashed_pass) == 0)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS"{FFFFFF} �� ������� ����������������!");
        new query[256];
        mysql_format(ServerDB, query, sizeof(query), "SELECT * FROM `players` WHERE `PlayerName`='%s' LIMIT 1", PlayerInfo[pid][pName]);
        mysql_tquery(ServerDB, query, "OnPlayerLogin", "i", pid);
    }
    else
    {
        PlayerInfo[pid][pPodbor]++;
        if (5 - PlayerInfo[pid][pPodbor] == 0)
        {
            SendClientMessage(pid, COLOR_VIOLET, ""NS"{FFFFFF} �� ���� ������� �� ������ ������!");
            Kick(pid);
            return 1;
        }
        DialogLoginShow(pid);
        SendClientMessage(pid, COLOR_VIOLET, ""NS"{FFFFFF}�� ����� �������� ������!");
        new string[144];
        format(string, 64, "%s{FFFFFF} � ��� �������� %d �������!", NS, 5 - PlayerInfo[pid][pPodbor]);
        SendClientMessage(pid, COLOR_VIOLET, string);
    }
    return 1;
}

stock DialogLoginShow(playerid)
{
    new string[1024];
    format(string, sizeof(string), "{FFFFFF}���������� ������ ������� ��������� �������!\
	\n{FFFFFF}�� ������� ������� ����������, �� ������� ���� ������ �� ������ ��������!\
	\n{FFFFFF}������������� {8F30E4}DDP ������� {FFFFFF}- �� ���� ��������������� �� ��������� ��������.\
	\n\n{FFFFFF}��� ���: {8F30E4}%s.\
	\n{FFFFFF}������� ���� ������ � ���� ����:", PlayerInfo[playerid][pName]);
    
    Dialog_ShowCallback(playerid, using public dialog_login<iiiis>, DIALOG_STYLE_INPUT, "{8F30E4}>>[����������� �� DREAMS]<<", string, "�����", "������");

    // ShowPlayerDialog(playerid, 1, DIALOG_STYLE_INPUT, "{8F30E4}>>[����������� �� DREAMS]<<", string, "�����", "������");
    return 1;
}