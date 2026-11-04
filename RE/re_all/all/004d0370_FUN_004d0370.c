
int __thiscall FUN_004d0370(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != param_2) {
    iVar2 = FUN_004d0530();
    if (iVar2 == 0) {
      FUN_004d0350();
    }
    else {
      uVar3 = FUN_004d0530();
      uVar4 = FUN_004d0530();
      if (uVar4 < uVar3) {
        uVar3 = FUN_004d0530();
        uVar4 = FUN_004dac90();
        if (uVar4 < uVar3) {
          if (*(int *)(param_1 + 4) != 0) {
            FUN_004dae30(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
            deallocate(*(undefined4 *)(param_1 + 4),
                       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0xa8);
          }
          uVar5 = FUN_004d0530();
          cVar1 = FUN_004dada0(uVar5);
          if (cVar1 != '\0') {
            uVar5 = DoMessageBox(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 8) = uVar5;
          }
        }
        else {
          iVar2 = FUN_004d0530();
          iVar2 = iVar2 * 0xa8 + *(int *)(param_2 + 4);
          FUN_004ed480(*(undefined4 *)(param_2 + 4),iVar2,*(undefined4 *)(param_1 + 4));
          uVar5 = DoMessageBox(iVar2,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = uVar5;
        }
      }
      else {
        uVar5 = FUN_004ed480(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        FUN_004dae30(uVar5,*(undefined4 *)(param_1 + 8));
        iVar2 = FUN_004d0530();
        *(int *)(param_1 + 8) = iVar2 * 0xa8 + *(int *)(param_1 + 4);
      }
    }
  }
  return param_1;
}

