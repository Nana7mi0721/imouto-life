
undefined4 FUN_00650070(char *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *param_1;
  if (cVar1 != 'a') {
    if (cVar1 == 'r') {
      if (param_1[1] == '+') {
        return 2;
      }
      return 0;
    }
    if (cVar1 != 'w') {
      FUN_006512e0(0,param_2,s___s___Bad_mode_00a069f4,param_1);
      return 0xffffffff;
    }
  }
  uVar2 = 0x102;
  if (cVar1 == 'w') {
    uVar2 = 0x302;
  }
  return uVar2;
}

