
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ea580(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  uint uVar3;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = in_EAX[2];
  local_44 = *(undefined4 *)(iVar1 + 0x180);
  iVar2 = *in_EAX;
  local_40 = *(undefined4 *)(iVar1 + 0x184);
  local_3c = *(undefined4 *)(iVar1 + 0x188);
  local_38 = 0x3f800000;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_4 = 0;
  local_10 = 0;
  local_30 = 0;
  local_8 = 0;
  local_28 = 0;
  local_14 = 0;
  local_c = 0;
  local_34 = 0;
  local_2c = 0;
  DAT_00a38de4 = 1;
  DAT_00ef72cc = 1;
  FUN_005b9a40(&local_44);
  FUN_005bb490(param_1);
  FUN_005b9d00(2);
  local_58 = in_EAX[0x2d];
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_4c = 0x3f800000;
  if (local_58 == -1) {
    local_58 = *(int *)(iVar1 + 0x1a0);
  }
  local_48 = ((float)in_EAX[0x28] * (float)local_58) / (float)_DAT_0081ec30;
  FUN_005bb3f0(&local_54);
  if (DAT_00a3810c == 0) {
    uVar3 = in_EAX[0x2c];
    if (uVar3 == 0xffffffff) {
      uVar3 = *(uint *)(iVar1 + 0x19c);
    }
    if (0xe < uVar3) goto switchD_005ea6ab_caseD_4;
  }
  else {
    uVar3 = 0;
  }
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((&DAT_005ea70c)[uVar3]) {
  case 0:
    break;
  case 1:
    if (*(char *)(*(int *)(iVar2 + 8) + 0x24e) == '\0') {
      uVar3 = 1;
    }
    else {
      uVar3 = 0x11;
    }
    break;
  case 2:
    if (*(char *)(*(int *)(iVar2 + 8) + 0x24e) == '\0') {
      uVar3 = 2;
    }
    else {
      uVar3 = 0x12;
    }
    break;
  case 3:
    uVar3 = 0x10;
    break;
  case 4:
    goto switchD_005ea6ab_caseD_4;
  }
  FUN_005bb510(uVar3);
switchD_005ea6ab_caseD_4:
  FUN_005b9b80(0);
  return;
}

