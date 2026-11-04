
void __thiscall FUN_00621040(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = FUN_00620e10(param_1,param_2);
  if (iVar2 != 0) {
    iVar3 = param_1[2];
    if (iVar3 < 0) {
      iVar2 = *param_1;
    }
    else {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          iVar1 = *(int *)(iVar2 + 0x20);
          if (iVar1 == 0) break;
          iVar4 = iVar4 + 1;
          iVar2 = iVar1;
        } while (iVar4 < iVar3);
      }
    }
  }
  puVar5 = param_2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_00620c20(param_1,iVar2,param_2);
  return;
}

