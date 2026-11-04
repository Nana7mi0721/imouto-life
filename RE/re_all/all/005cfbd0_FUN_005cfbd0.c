
undefined4
FUN_005cfbd0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int param_11,
            int param_12,int param_13)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_470;
  int local_46c;
  int local_468;
  int local_464;
  int local_460;
  int local_45c;
  int local_458;
  int local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined1 local_440 [1064];
  undefined4 local_18;
  undefined4 local_14;
  
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (*(char *)(*(int *)(param_1 + 0x4c) + 0xb) == '\0') {
    local_470 = param_8;
    local_468 = param_10;
    local_46c = param_9;
    local_464 = param_11;
    iVar2 = FUN_005229c0(&local_470,local_440,param_3,param_4,param_5,1,0);
    if (iVar2 < 0) {
      return 0xffffffff;
    }
    local_448 = local_18;
    local_444 = local_14;
    local_450 = 0;
    local_44c = 0;
    FUN_00518620(&local_450,param_12,param_13,*(undefined4 *)(param_1 + 4),local_440,0,0,0,0,0);
    FUN_00517420();
    return 0;
  }
  if (param_2 == 0) {
    if (DAT_00ef1b58 == 0) {
      uVar3 = DAT_00ee9bc0;
      iVar2 = DAT_00ee9b90;
    }
    else {
      uVar3 = DAT_00ef1b60;
      iVar2 = DAT_00ef1b58;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_2 + 0x4c) + 0x3c);
    uVar3 = *(undefined4 *)(iVar2 + 8);
    iVar2 = *(int *)(iVar2 + 4);
  }
  local_470 = param_8;
  local_468 = param_10;
  local_46c = param_9;
  local_458 = (param_10 - param_8) + param_12;
  local_454 = (param_11 - param_9) + param_13;
  local_464 = param_11;
  iVar1 = *(int *)(*(int *)(param_1 + 0x4c) + 0x3c);
  local_460 = param_12;
  local_45c = param_13;
  FUN_005caf30(iVar2,uVar3,&local_470,*(undefined4 *)(iVar1 + 4),**(undefined4 **)(iVar1 + 0xc),
               &local_460,0,0,0,0,0,0,0,0);
  return 0;
}

