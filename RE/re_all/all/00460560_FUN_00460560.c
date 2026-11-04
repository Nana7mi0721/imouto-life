
int FUN_00460560(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  undefined1 local_5;
  
  local_8 = param_1[4];
  local_7 = param_1[1];
  local_6 = param_1[3];
  local_5 = *param_1;
  iVar1 = FUN_004604b0(&local_8);
  local_7 = param_1[1];
  local_6 = param_1[5];
  local_5 = param_1[2];
  iVar2 = FUN_004604b0(&local_8);
  local_7 = param_1[7];
  local_6 = param_1[3];
  local_5 = param_1[6];
  iVar3 = FUN_004604b0(&local_8);
  local_7 = param_1[7];
  local_6 = param_1[5];
  local_5 = param_1[8];
  iVar4 = FUN_004604b0(&local_8);
  return iVar1 * 1000 + iVar2 * 100 + iVar4 + iVar3 * 10;
}

