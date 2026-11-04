
void FUN_006950b0(int param_1,undefined4 *param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  iVar1 = *(int *)(param_1 + 0x24);
  uVar2 = *(uint *)(param_1 + 0x1c);
  if (-1 < param_5 + -1) {
    param_4 = param_4 * 4;
    param_1 = param_5;
    do {
      puVar5 = (undefined1 *)*param_2;
      param_2 = param_2 + 1;
      param_4 = param_4 + 4;
      iVar3 = *(int *)(*param_3 + -4 + param_4);
      uVar4 = 0;
      if (uVar2 != 0) {
        do {
          *(undefined1 *)(uVar4 + iVar3) = *puVar5;
          puVar5 = puVar5 + iVar1;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar2);
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

