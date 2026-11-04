
void FUN_006c3de0(int param_1,undefined4 param_2,undefined4 param_3,code *param_4,undefined4 param_5
                 )

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_006c3e60(param_1,0,0,param_5);
  if ((-1 < iVar1) && (3 < *(int *)(param_1 + 0x5c))) {
    iVar1 = *(int *)(param_1 + 0x21fc);
    iVar2 = *(int *)(param_1 + 0x2200) - iVar1;
    if (0 < iVar2) {
      if (*(int *)(param_1 + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x60);
      }
      iVar3 = *(int *)(iVar3 * 0x160 + 0x30 + *(int *)(param_1 + 0x1c));
      iVar2 = (*param_4)(param_1,param_2,param_3,*(int *)(param_1 + 0x21f8) + iVar3 * iVar1 * 4,
                         iVar2,iVar3);
      *(int *)(param_1 + 0x21fc) = iVar1 + iVar2;
    }
  }
  return;
}

