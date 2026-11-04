
void FUN_006bd820(int param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  sbyte sVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  if ((param_3 == (undefined4 *)0x0) || ((*(byte *)(param_1 + 0x30) & 1) != 0)) {
    sVar6 = 0;
  }
  else {
    sVar6 = 1;
  }
  iVar10 = 0x10 >> sVar6;
  if ((param_3 == (undefined4 *)0x0) || ((*(byte *)(param_1 + 0x30) & 2) != 0)) {
    sVar6 = 0;
  }
  else {
    sVar6 = 1;
  }
  iVar4 = ((int)param_3 + param_2 * 3) * 0x10;
  iVar3 = *(int *)(iVar4 + 0xf8 + param_1);
  piVar2 = (int *)(iVar4 + 0xec + param_1);
  iVar4 = piVar2[2];
  uVar1 = *piVar2 + iVar10 * 2;
  puVar9 = (undefined4 *)(iVar3 - iVar10);
  param_3 = (undefined4 *)(((piVar2[1] + -1) * iVar4 - iVar10) + iVar3);
  puVar8 = (undefined4 *)((int)puVar9 - (0x10 >> sVar6) * iVar4);
  if (puVar9 != puVar8) {
    puVar5 = param_3;
    do {
      param_3 = (undefined4 *)((int)param_3 + iVar4);
      puVar11 = (undefined4 *)((int)puVar9 - iVar4);
      puVar12 = puVar11;
      for (uVar7 = uVar1 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar12 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar7 = uVar1 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      puVar9 = puVar5;
      puVar12 = param_3;
      for (uVar7 = uVar1 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar12 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar7 = uVar1 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      puVar5 = (undefined4 *)((int)puVar5 + iVar4);
      puVar9 = puVar11;
    } while (puVar11 != puVar8);
  }
  return;
}

