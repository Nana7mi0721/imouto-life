
undefined4 FUN_005b8890(int param_1,int param_2,undefined4 *param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (*(char *)(param_1 + 8) == '\0') {
    if ((((param_2 == 1) || (param_2 == 2)) || (param_2 == 3)) || ((param_2 == 4 || (param_2 == 5)))
       ) {
      uVar1 = 1;
    }
    if ((param_4 < 0) ||
       (((param_4 != 1 && (param_4 != 2)) && ((param_4 != 3 && ((param_4 != 4 && (param_4 != 5))))))
       )) goto LAB_005b8987;
  }
  else {
    if (param_2 == 1) {
      if (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) == 0x47) goto LAB_005b88f2;
LAB_005b88ed:
      uVar1 = 1;
    }
    else {
      if (param_2 == 2) goto LAB_005b88ed;
      if (param_2 == 3) {
        if (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) != 0x4a) goto LAB_005b88ed;
      }
      else if ((param_2 == 4) ||
              ((param_2 == 5 && (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) != 0x4d))))
      goto LAB_005b88ed;
    }
LAB_005b88f2:
    if (param_4 < 0) goto LAB_005b8987;
    if (param_4 == 1) {
      if (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) == 0x47) goto LAB_005b8987;
    }
    else if (param_4 != 2) {
      if (param_4 == 3) {
        if (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) == 0x4a) goto LAB_005b8987;
      }
      else if ((param_4 != 4) &&
              ((param_4 != 5 || (*(int *)(&DAT_00ee9a58 + *(int *)(param_1 + 4) * 4) == 0x4d))))
      goto LAB_005b8987;
    }
  }
  uVar2 = 1;
LAB_005b8987:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar1;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = uVar2;
  }
  return 0;
}

