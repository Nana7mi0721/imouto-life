
undefined4 FUN_00519720(uint param_1,int param_2,int *param_3)

{
  int *piVar1;
  int local_40;
  int local_3c;
  
  if ((int)param_1 < 1) {
    piVar1 = (int *)0x0;
    DAT_00a380d4 = 0xffffffff;
  }
  else {
    if (((((DAT_00cc47d0 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc47f8))
        || ((DAT_00cc4800 <= (int)(param_1 & 0xffff) ||
            (piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar1 == (int *)0x0)))) ||
       ((*piVar1 * 0x10000 != (param_1 & 0x3ff0000) || (piVar1[4] != 0)))) {
      return 0xffffffff;
    }
    DAT_00a380d4 = param_1;
  }
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  if (piVar1 != (int *)0x0) {
    if (param_2 == 0) {
      local_40 = *param_3;
      if (local_40 < 0x100) {
        if (local_40 < 0) {
          local_40 = 0;
        }
      }
      else {
        local_40 = 0xff;
      }
    }
    else if (param_2 == 1) {
      DAT_00a380d8 = *param_3;
      DAT_00a380dc = param_3[1];
      if (DAT_00a380dc < 0x100) {
        if (DAT_00a380dc < 0) {
          DAT_00a380dc = 0;
        }
      }
      else {
        DAT_00a380dc = 0xff;
      }
      if (DAT_00a380d8 < 0x100) {
        if (DAT_00a380d8 < 0) {
          DAT_00a380d8 = 0;
        }
      }
      else {
        DAT_00a380d8 = 0xff;
      }
      local_40 = DAT_00a380d8;
      local_3c = DAT_00a380dc;
      if (DAT_00a37d78 != 0) goto LAB_0051985e;
      FUN_00581210(DAT_00a380d8,DAT_00a380dc);
    }
  }
  if (DAT_00a37d78 == 0) {
    if ((int)DAT_00a380d4 < 1) {
      DAT_00a37e5c = 0;
      return 0;
    }
    DAT_00a37e5c = piVar1[0x13] + 0x34;
    return 0;
  }
LAB_0051985e:
  FUN_00567bb0(piVar1,param_2,&local_40);
  return 0;
}

