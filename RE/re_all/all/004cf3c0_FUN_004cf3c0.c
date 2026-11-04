
int __thiscall FUN_004cf3c0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != param_2) {
    iVar2 = FUN_004cf550();
    if (iVar2 == 0) {
      FUN_004cf3a0();
    }
    else {
      uVar3 = FUN_004cf550();
      uVar4 = FUN_004cf550();
      if (uVar4 < uVar3) {
        uVar3 = FUN_004cf550();
        uVar4 = FUN_004d9630();
        if (uVar4 < uVar3) {
          if (*(int *)(param_1 + 4) != 0) {
            FUN_004d96f0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
            deallocate(*(undefined4 *)(param_1 + 4),
                       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0x4c);
          }
          uVar5 = FUN_004cf550();
          cVar1 = FUN_004d9670(uVar5);
          if (cVar1 != '\0') {
            uVar5 = DoMessageBox(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 8) = uVar5;
          }
        }
        else {
          iVar2 = FUN_004cf550();
          iVar2 = iVar2 * 0x4c + *(int *)(param_2 + 4);
          FUN_004ed230(*(undefined4 *)(param_2 + 4),iVar2,*(undefined4 *)(param_1 + 4));
          uVar5 = DoMessageBox(iVar2,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = uVar5;
        }
      }
      else {
        uVar5 = FUN_004ed230(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        FUN_004d96f0(uVar5,*(undefined4 *)(param_1 + 8));
        iVar2 = FUN_004cf550();
        *(int *)(param_1 + 8) = iVar2 * 0x4c + *(int *)(param_1 + 4);
      }
    }
  }
  return param_1;
}

