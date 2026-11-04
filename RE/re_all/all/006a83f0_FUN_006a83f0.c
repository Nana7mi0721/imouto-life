
undefined4 FUN_006a83f0(int *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    piVar3 = param_1;
    for (iVar2 = 0x5a; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    param_1[1] = 0x4000;
    param_1[6] = 0x400;
    pvVar1 = _malloc(0x4000);
    *param_1 = (int)pvVar1;
    pvVar1 = _malloc(param_1[6] << 2);
    param_1[4] = (int)pvVar1;
    pvVar1 = _malloc(param_1[6] << 3);
    param_1[5] = (int)pvVar1;
    if (((*param_1 != 0) && (param_1[4] != 0)) && (pvVar1 != (void *)0x0)) {
      param_1[0x54] = param_2;
      return 0;
    }
    FUN_006a8490(param_1);
  }
  return 0xffffffff;
}

