
undefined4 FUN_00597060(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    return 0xffffffff;
  }
  if (param_1[0x113] != 0) {
    FUN_0056e1d0(param_1[0x113]);
    param_1[0x113] = 0;
  }
  iVar1 = param_1[2];
  if (iVar1 == 0) {
    if (*(int *)((int)param_1 + 0x4a) != 0) {
      FUN_0056e1d0(*(int *)((int)param_1 + 0x4a));
      *(undefined4 *)((int)param_1 + 0x4a) = 0;
    }
    *param_1 = 0;
    return 0;
  }
  if (iVar1 == 1) {
    FUN_005f8e60(param_1);
    *param_1 = 0;
    return 0;
  }
  if (iVar1 == 2) {
    FUN_005fa3d0();
    *param_1 = 0;
    return 0;
  }
  FUN_005dd320();
  *param_1 = 0;
  return 0;
}

