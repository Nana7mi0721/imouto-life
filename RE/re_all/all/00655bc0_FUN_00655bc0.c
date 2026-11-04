
void FUN_00655bc0(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x294);
  iVar5 = -1;
  while( true ) {
    if (iVar5 + 1 == iVar4) {
      *param_3 = -1;
      return;
    }
    iVar2 = (iVar4 + iVar5) / 2;
    uVar1 = **(uint **)(*(int *)(param_1 + 0x290) + iVar2 * 4);
    if (uVar1 == (param_2 & 0xffff)) break;
    if (uVar1 < (param_2 & 0xffff)) {
      iVar5 = iVar2;
    }
    else {
      iVar4 = iVar2;
    }
  }
  for (puVar3 = (undefined4 *)(*(int *)(param_1 + 0x290) + -4 + iVar2 * 4);
      (iVar2 != 0 && (*(uint *)*puVar3 == (param_2 & 0xffff))); puVar3 = puVar3 + -1) {
    iVar2 = iVar2 + -1;
  }
  *param_3 = iVar2;
  return;
}

