
fpub:TopMoney(playerid){
	if(cache_num_rows() > 0)
	{
		new fulldialog[3000], str[3000];
		fulldialog = "{FFFF55}���\t{CCFF00}�����\n\n";
		for(new i = 0; i < cache_num_rows(); i++)
		{
			new name[MAX_PLAYER_NAME];
			cache_get_value_name(i, "PlayerName", name, MAX_PLAYER_NAME);
			new money;
			cache_get_value_int(i, "Money", money);
			if(money>0){
				format(str, sizeof str, "{FFFF55}%s\t{CCFF00}$%d\n", name, money);
				strcat(fulldialog, str);
			}
		}
		ShowPlayerDialog(playerid, 9999, DIALOG_STYLE_TABLIST_HEADERS, ">>[��� �� �������]<<", fulldialog, "��", "");
	}
	return 1;
}

fpub:TopScore(playerid){
	if(cache_num_rows() > 0)
	{
		new fulldialog[3000], str[3000];
		fulldialog = "{FFFF55}���\t{CCFF00}SCORE\n\n";
		for(new i = 0; i < cache_num_rows(); i++)
		{
			new name[MAX_PLAYER_NAME];
			cache_get_value_name(i, "PlayerName", name, MAX_PLAYER_NAME);
			new money;
			cache_get_value_int(i, "DriftExp", money);
			if(money>0){
				format(str, sizeof str, "{FFFF55}%s\t{CCFF00}%d\n", name, money);
				strcat(fulldialog, str);
			}
		}
		ShowPlayerDialog(playerid, 9999, DIALOG_STYLE_TABLIST_HEADERS, ">>[��� �� �����]<<", fulldialog, "��", "");
	}
	return 1;
}

fpub:TopDeaths(playerid){
	if(cache_num_rows() > 0)
	{
		new fulldialog[3000], str[3000];
		fulldialog = "{FFFF55}���\t{CCFF00}�������\n\n";
		for(new i = 0; i < cache_num_rows(); i++)
		{
			new name[MAX_PLAYER_NAME];
			cache_get_value_name(i, "PlayerName", name, MAX_PLAYER_NAME);
			new money;
			cache_get_value_int(i, "Deaths", money);
			if(money>0){
				format(str, sizeof str, "{FFFF55}%s\t{CCFF00}%d\n", name, money);
				strcat(fulldialog, str);
			}
		}
		ShowPlayerDialog(playerid, 9999, DIALOG_STYLE_TABLIST_HEADERS, ">>[��� �� �������]<<", fulldialog, "��", "");
	}
	return 1;
}

fpub:TopKills(playerid){
	if(cache_num_rows() > 0)
	{
		new fulldialog[3000], str[3000];
		fulldialog = "{FFFF55}���\t{CCFF00}�������\n\n";
		for(new i = 0; i < cache_num_rows(); i++)
		{
			new name[MAX_PLAYER_NAME];
			cache_get_value_name(i, "PlayerName", name, MAX_PLAYER_NAME);
			new money;
			cache_get_value_int(i, "Kills", money);
			if(money>0){
				format(str, sizeof str, "{FFFF55}%s\t{CCFF00}%d\n", name, money);
				strcat(fulldialog, str);
			}
		}
		ShowPlayerDialog(playerid, 9999, DIALOG_STYLE_TABLIST_HEADERS, ">>[��� �� ���������]<<", fulldialog, "��", "");
	}
	return 1;
}

fpub:TopMinuteOnline(playerid){
	if(cache_num_rows() > 0)
	{
		new fulldialog[3000], str[3000];
		fulldialog = "{FFFF55}���\t{CCFF00}�����\n\n";
		for(new i = 0; i < cache_num_rows(); i++)
		{
			new name[MAX_PLAYER_NAME];
			cache_get_value_name(i, "PlayerName", name, MAX_PLAYER_NAME);
			new money;
			cache_get_value_int(i, "MinLog", money);
			if(money>0){
				format(str, sizeof str, "{FFFF55}%s\t{CCFF00}%d\n", name, money);
				strcat(fulldialog, str);
			}
		}
		ShowPlayerDialog(playerid, 9999, DIALOG_STYLE_TABLIST_HEADERS, ">>[��� �� �������]<<", fulldialog, "��", "");
	}
	return 1;
}

fpub:TopRecordDrift(playerid){
	if(cache_num_rows() > 0)
	{
		new fulldialog[3000], str[3000];
		fulldialog = "{FFFF55}���\t{CCFF00}����� �� �����\n\n";
		for(new i = 0; i < cache_num_rows(); i++)
		{
			new name[MAX_PLAYER_NAME];
			cache_get_value_name(i, "PlayerName", name, MAX_PLAYER_NAME);
			new money;
			cache_get_value_int(i, "ExpRecord", money);
			if(money>0){
				format(str, sizeof str, "{FFFF55}%s\t{CCFF00}%d\n", name, money);
				strcat(fulldialog, str);
			}
		}
		ShowPlayerDialog(playerid, 9999, DIALOG_STYLE_TABLIST_HEADERS, ">>[��� �� ����� ����� �� �����]<<", fulldialog, "��", "");
	}
	return 1;
}