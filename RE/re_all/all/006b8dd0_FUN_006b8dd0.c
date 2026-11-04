
int FUN_006b8dd0(uint param_1,uint param_2)

{
  void *pvVar1;
  uint uVar2;
  
  if ((((param_2 - 1 < 0x100) && ((param_2 & param_2 - 1) == 0)) && (param_1 <= -param_2 - 1)) &&
     (pvVar1 = _malloc(param_1 + param_2), pvVar1 != (void *)0x0)) {
    uVar2 = (int)pvVar1 - 1U & param_2 - 1;
    *(char *)(uVar2 + (int)pvVar1) = (char)uVar2;
    return uVar2 + 1 + (int)pvVar1;
  }
  return 0;
}

