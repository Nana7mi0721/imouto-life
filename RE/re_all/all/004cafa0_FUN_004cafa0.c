
int __thiscall FUN_004cafa0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  uint local_10;
  
  iVar1 = (int)*DAT_00a1671c / DAT_0084b264 + 0x1e;
  while( true ) {
    if (*(int *)(param_1 + 0x38) < (iVar1 * DAT_0084b264) / *(int *)(param_1 + 0x74)) {
      local_20 = *(int *)(param_1 + 0x38);
    }
    else {
      local_20 = (iVar1 * DAT_0084b264) / *(int *)(param_1 + 0x74);
    }
    if ((local_20 < *(int *)(param_1 + 0x30)) && (1 < *(int *)(param_1 + 0x3c))) {
      return -1;
    }
    if (*(int *)(param_1 + 0x38) < (iVar1 * DAT_0084b264) / *(int *)(param_1 + 0x74)) {
      local_24 = *(int *)(param_1 + 0x38);
    }
    else {
      local_24 = (iVar1 * DAT_0084b264) / *(int *)(param_1 + 0x74);
    }
    if ((local_24 < *(int *)(param_1 + 0x30)) && (*(int *)(param_1 + 0x3c) < 2)) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    piVar2 = (int *)FUN_004ce990(*(undefined4 *)(param_1 + 0x30));
    if (*(int *)(param_1 + 0x34) < *piVar2) break;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    *(undefined4 *)(param_1 + 0x34) = 0;
    if (*(int *)(param_1 + 0x38) < (iVar1 * DAT_0084b264) / *(int *)(param_1 + 0x74)) {
      local_28 = *(int *)(param_1 + 0x38);
    }
    else {
      local_28 = (iVar1 * DAT_0084b264) / *(int *)(param_1 + 0x74);
    }
    if (*(int *)(param_1 + 0x30) <= local_28) {
      local_10 = 0;
      local_14 = 0;
      if (-1 < param_2) {
        if (DAT_0084b264 / 2 < param_2 % DAT_0084b264) {
          local_14 = DAT_0084b264 - param_2 % DAT_0084b264;
          local_10 = (uint)(param_2 % (DAT_0084b264 / 2) == 0);
          if ((DAT_0084b264 == 0x20) && (0x18 < param_2 % 0x20)) {
            local_14 = local_14 + 0x20;
            local_10 = 2;
          }
          if ((DAT_0084b264 == 0x28) && (0x1e < param_2 % 0x28)) {
            local_14 = local_14 + 0x28;
            local_10 = 2;
          }
        }
        else {
          local_14 = -(param_2 % DAT_0084b264);
          if (param_2 % DAT_0084b264 == 0) {
            if (DAT_0084b264 == 0x20) {
              local_14 = local_14 + 0x20;
              local_10 = 2;
            }
            else if (DAT_0084b264 == 0x28) {
              local_14 = local_14 + 0x28;
              local_10 = 2;
            }
          }
          else {
            local_14 = local_14 + DAT_0084b264;
            local_10 = 1;
          }
        }
      }
      if (param_2 < 0) {
        iVar3 = -param_2;
        if (iVar3 % DAT_0084b264 < DAT_0084b264 / 2) {
          local_14 = iVar3 % DAT_0084b264;
          if (iVar3 % DAT_0084b264 != 0) {
            local_10 = 0;
          }
          if (DAT_0084b264 == 0x20) {
            local_14 = local_14 + 0x20;
            local_10 = 2;
            if (0x20 / (*(int *)(param_1 + 0x74) / 2) <= iVar3 % 0x20) {
              local_10 = 3;
            }
          }
          if (DAT_0084b264 == 0x28) {
            local_14 = local_14 + 0x28;
            local_10 = 2;
            if (0x28 / (*(int *)(param_1 + 0x74) / 2) <= iVar3 % 0x28) {
              local_10 = 3;
            }
          }
        }
        else {
          local_14 = iVar3 % DAT_0084b264;
          local_10 = 1;
        }
      }
      if ((*(int *)(param_1 + 0x3c) == 1) &&
         (*(int *)(param_1 + 0x30) % ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74)) == local_10)) {
        return (-((param_2 + local_14) / DAT_0084b264) -
               *(int *)(param_1 + 0x30) / ((int)*DAT_00a16674 / *(int *)(param_1 + 0x74))) + -0x3e6;
      }
    }
  }
  *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
  iVar1 = *(int *)(param_1 + 0x34) + -1;
  FUN_004cde80(*(undefined4 *)(param_1 + 0x30));
  piVar2 = (int *)FUN_004ce990(iVar1);
  return *piVar2;
}

