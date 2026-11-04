
undefined4 * __thiscall FUN_00791360(undefined4 *param_1,int *param_2)

{
  char cVar1;
  
  FUN_00797500();
  *param_1 = &PTR_FUN_008374d0;
  param_1[0xc] = param_2;
  param_1[1] = 0x15;
  cVar1 = (**(code **)(*param_2 + 0x24))();
  if (cVar1 == '\0') {
    FUN_00791690();
    return param_1;
  }
  (**(code **)(*param_2 + 0x2c))(param_1 + 4,param_1 + 8);
  return param_1;
}

