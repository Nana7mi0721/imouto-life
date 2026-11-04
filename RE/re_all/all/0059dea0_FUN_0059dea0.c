
undefined4
FUN_0059dea0(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8,int param_9,int param_10,int param_11,
            int param_12,int param_13)

{
  int iVar1;
  int local_474;
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
  iVar1 = FUN_005d35f0();
  if ((iVar1 != 0) && (DAT_00e79688 != 0)) {
    FUN_005d3950();
    DAT_00e79688 = 0;
  }
  if (*(char *)(*(int *)(param_1 + 0x4c) + 0xb) == '\0') {
    local_474 = param_8;
    local_46c = param_10;
    local_470 = param_9;
    local_468 = param_11;
    iVar1 = FUN_005229c0(&local_474,local_440,param_3,param_4,param_5,1,0);
    if (iVar1 < 0) {
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
    iVar1 = DAT_00ddb5c4;
    if (DAT_00ddb5c4 == 0) {
      iVar1 = DAT_00ddb5b4;
    }
  }
  else {
    local_464 = *(int *)(*(int *)(param_2 + 0x4c) + 0x3c);
    iVar1 = *(int *)(local_464 + 0x1c);
    if (*(int *)(local_464 + 0x1c) == 0) {
      iVar1 = *(int *)(local_464 + 4 + param_4 * 4);
    }
  }
  local_474 = param_8;
  local_470 = param_9;
  local_46c = param_10;
  local_458 = (param_10 - param_8) + param_12;
  local_454 = (param_11 - param_9) + param_13;
  local_468 = param_11;
  local_460 = param_12;
  local_45c = param_13;
  FUN_005d3850(iVar1,&local_474,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x4c) + 0x3c) + 4),
               &local_460,0);
  return 0;
}

