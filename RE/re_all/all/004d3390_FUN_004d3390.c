
int __thiscall FUN_004d3390(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_1 != param_2) {
    iVar2 = FUN_004dd250();
    if (iVar2 == 0) {
      FUN_004d3520();
    }
    else {
      uVar3 = FUN_004dd250();
      uVar4 = FUN_004dd250();
      if (uVar4 < uVar3) {
        uVar3 = FUN_004dd250();
        uVar4 = FUN_004dd210();
        if (uVar4 < uVar3) {
          if (*(int *)(param_1 + 4) != 0) {
            FUN_004dd320(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
            deallocate(*(undefined4 *)(param_1 + 4),
                       (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0x2740);
          }
          uVar5 = FUN_004dd250();
          cVar1 = FUN_004dd290(uVar5);
          if (cVar1 != '\0') {
            uVar5 = DoMessageBox(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                                 *(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 8) = uVar5;
          }
        }
        else {
          iVar2 = FUN_004dd250();
          iVar2 = iVar2 * 0x2740 + *(int *)(param_2 + 4);
          FUN_004ed990(*(undefined4 *)(param_2 + 4),iVar2,*(undefined4 *)(param_1 + 4));
          uVar5 = DoMessageBox(iVar2,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 8) = uVar5;
        }
      }
      else {
        uVar5 = FUN_004ed990(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        FUN_004dd320(uVar5,*(undefined4 *)(param_1 + 8));
        iVar2 = FUN_004dd250();
        *(int *)(param_1 + 8) = iVar2 * 0x2740 + *(int *)(param_1 + 4);
      }
    }
  }
  return param_1;
}

