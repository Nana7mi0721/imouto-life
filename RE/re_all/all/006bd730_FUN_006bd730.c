
void FUN_006bd730(undefined4 *param_1,int param_2,undefined1 *param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  sbyte sVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  
  if ((param_3 == (undefined1 *)0x0) || (sVar5 = 1, (*(byte *)((int)param_1 + 0x30) & 1) != 0)) {
    sVar5 = 0;
  }
  uVar7 = 0x10 >> sVar5;
  iVar4 = ((int)param_3 + param_2 * 3) * 0x10;
  iVar3 = *(int *)(iVar4 + 0xf4 + (int)param_1);
  piVar1 = (int *)(iVar4 + 0xec + (int)param_1);
  iVar4 = piVar1[3];
  puVar9 = (undefined1 *)(iVar3 * param_4 + iVar4);
  puVar8 = (undefined1 *)(iVar3 * param_5 + iVar4);
  param_3 = puVar9 + *piVar1 + -1;
  if (puVar9 != puVar8) {
    param_1 = (undefined4 *)(param_3 + 1);
    do {
      uVar2 = *puVar9;
      puVar10 = (undefined4 *)(puVar9 + -uVar7);
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar10 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
        puVar10 = puVar10 + 1;
      }
      for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar10 = uVar2;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      uVar2 = *param_3;
      puVar10 = param_1;
      for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar10 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
        puVar10 = puVar10 + 1;
      }
      for (uVar6 = uVar7 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar10 = uVar2;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      puVar9 = puVar9 + iVar3;
      param_3 = param_3 + iVar3;
      param_1 = (undefined4 *)((int)param_1 + iVar3);
    } while (puVar9 != puVar8);
  }
  return;
}

