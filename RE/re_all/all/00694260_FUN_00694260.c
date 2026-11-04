
void FUN_00694260(int *param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = param_4 - param_3;
  if ((0 < (int)uVar4) && (0 < param_2)) {
    param_4 = param_2;
    do {
      iVar2 = *param_1;
      param_1 = param_1 + 1;
      uVar1 = *(undefined1 *)(param_3 + iVar2 + -1);
      puVar5 = (undefined4 *)(param_3 + iVar2);
      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
        puVar5 = puVar5 + 1;
      }
      for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = uVar1;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

