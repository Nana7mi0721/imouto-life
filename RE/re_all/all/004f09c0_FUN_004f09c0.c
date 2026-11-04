
int __thiscall FUN_004f09c0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != param_2) {
    iVar2 = FUN_004ce080();
    if (iVar2 == 0) {
      FUN_004ce950();
    }
    else {
      uVar3 = FUN_004ce080();
      uVar4 = FUN_004ce080();
      if (uVar4 < uVar3) {
        uVar3 = FUN_004ce080();
        uVar4 = FUN_004ea8d0();
        if (uVar4 < uVar3) {
          if (*(int *)(param_1 + 4) != 0) {
            FUN_004e4160(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
            deallocate(*(undefined4 *)(param_1 + 4),
                       *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 2);
          }
          uVar5 = FUN_004ce080();
          cVar1 = FUN_004d88b0(uVar5);
          if (cVar1 != '\0') {
            uVar5 = DoMessageBox(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 8) = uVar5;
          }
        }
        else {
          iVar2 = FUN_004ce080();
          iVar2 = *(int *)(param_2 + 4) + iVar2 * 4;
          FUN_004ece40(*(undefined4 *)(param_2 + 4),iVar2,*(undefined4 *)(param_1 + 4));
          uVar5 = DoMessageBox(iVar2,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = uVar5;
        }
      }
      else {
        uVar5 = FUN_004ece40(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        FUN_004e4160(uVar5,*(undefined4 *)(param_1 + 8));
        iVar2 = FUN_004ce080();
        *(int *)(param_1 + 8) = *(int *)(param_1 + 4) + iVar2 * 4;
      }
    }
  }
  return param_1;
}

