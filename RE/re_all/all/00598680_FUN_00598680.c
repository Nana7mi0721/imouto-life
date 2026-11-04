
undefined4 FUN_00598680(int param_1,int param_2,undefined4 *param_3,int param_4,undefined4 *param_5)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  if (*(char *)(param_1 + 8) == '\0') {
    if ((((param_2 == 1) || (param_2 == 2)) || (param_2 == 3)) || ((param_2 == 4 || (param_2 == 5)))
       ) {
      local_8 = 1;
    }
    if ((-1 < param_4) &&
       (((param_4 == 1 || (param_4 == 2)) || ((param_4 == 3 || ((param_4 == 4 || (param_4 == 5))))))
       )) {
      local_4 = 1;
    }
    goto LAB_005987e3;
  }
  if (param_2 == 1) {
    if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) != 0x31545844) goto LAB_0059870f;
  }
  else if (param_2 == 2) {
    if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) != 0x32545844) goto LAB_0059870f;
  }
  else if (param_2 == 3) {
    if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) != 0x33545844) goto LAB_0059870f;
  }
  else if (param_2 == 4) {
    if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) != 0x34545844) {
LAB_0059870f:
      local_8 = 1;
    }
  }
  else if ((param_2 == 5) && (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) != 0x35545844))
  goto LAB_0059870f;
  if (-1 < param_4) {
    if (param_4 == 1) {
      if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x31545844) goto LAB_005987e3;
    }
    else if (param_4 == 2) {
      if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x32545844) goto LAB_005987e3;
    }
    else if (param_4 == 3) {
      if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x33545844) goto LAB_005987e3;
    }
    else if (param_4 == 4) {
      if (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x34545844) goto LAB_005987e3;
    }
    else if ((param_4 != 5) || (*(int *)(&DAT_00ddb4d4 + *(int *)(param_1 + 4) * 4) == 0x35545844))
    goto LAB_005987e3;
    local_4 = 1;
  }
LAB_005987e3:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_8;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_4;
  }
  return 0;
}

