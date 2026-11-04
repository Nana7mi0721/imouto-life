
int FUN_006bea30(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 local_200 [512];
  
  iVar4 = 0;
  do {
    iVar1 = FUN_006be910(param_1,local_200);
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar2 = FUN_006beae0(0,local_200,iVar1);
    if (0x7fff < uVar2) {
      return -0x17;
    }
    pvVar3 = _malloc(uVar2 * 2);
    if (pvVar3 == (void *)0x0) {
      return -1;
    }
    FUN_006beae0(pvVar3,local_200,iVar1);
    *param_2 = pvVar3;
    iVar4 = iVar4 + 1;
    param_2 = param_2 + 1;
  } while (iVar4 < 0x50);
  return 0;
}

