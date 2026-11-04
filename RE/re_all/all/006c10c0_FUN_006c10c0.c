
void FUN_006c10c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1;
  if (3 < *(int *)(param_1 + 0x5c)) {
    iVar4 = *(int *)(param_1 + 0x2208);
    if (*(int *)(param_1 + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x60);
    }
    iVar3 = iVar3 * 0x160 + *(int *)(param_1 + 0x1c);
    iVar1 = *(int *)(param_1 + 0x2204);
    if (iVar1 == 0) {
      iVar4 = iVar4 + *(int *)(iVar3 + 0x3c);
    }
    else if (iVar1 == 0xbbf) {
      param_1 = 0;
      FUN_006c4d60(iVar3 + 0x14c,&param_1);
      iVar4 = iVar4 + *(int *)(iVar3 + 0x3c) + param_1;
    }
    else if (iVar1 == 0xbc0) {
      param_1 = 0;
      FUN_006c4e20(iVar3 + 0x14c,&param_1);
      iVar4 = iVar4 + *(int *)(iVar3 + 0x3c) + param_1;
    }
    if (iVar4 < 0x7fff) {
      if (iVar4 < -0x8000) {
        iVar4 = -0x8000;
      }
    }
    else {
      iVar4 = 0x7fff;
    }
    FUN_00797f60(*(undefined4 *)(iVar2 + 0x21d8),0xfc2,iVar4);
  }
  return;
}

