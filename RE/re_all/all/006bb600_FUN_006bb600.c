
void FUN_006bb600(int param_1,int param_2,undefined4 *param_3,byte *param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int local_10;
  uint local_c;
  
  puVar8 = (uint *)(param_2 + (int)param_4 * 0x10);
  iVar11 = (int)param_3 + (int)param_4 * 0x10;
  uVar7 = *(uint *)((int)param_4 * 0x20 + 0x48 + param_1);
  iVar5 = (int)param_4 * 0x20 + 0x48 + param_1;
  iVar1 = uVar7 * param_5 + *(int *)(iVar5 + 8);
  iVar3 = *(int *)(param_1 + 0xd31c) + iVar1 * 4;
  param_4 = (byte *)(*(int *)(param_1 + 0xd318) + iVar1);
  uVar2 = (uint)(0 < param_5);
  uVar9 = (uint)(param_6 < *(int *)(iVar5 + 4));
  puVar10 = (undefined4 *)(iVar3 + (-uVar2 & uVar7) * 4);
  for (uVar4 = (((uVar9 - uVar2) - param_5) + param_6) * uVar7 & 0x3fffffff; uVar4 != 0;
      uVar4 = uVar4 - 1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar10 = 0;
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  iVar5 = uVar2 + param_5 * 2;
  iVar1 = *(int *)(iVar11 + 8);
  uVar2 = puVar8[2];
  param_2 = iVar5 * 4;
  puVar10 = (undefined4 *)(uVar2 * param_2 + puVar8[3]);
  puVar12 = (undefined4 *)(iVar1 * param_2 + *(int *)(iVar11 + 0xc));
  uVar4 = *puVar8;
  param_3 = puVar12;
  if (param_2 < 4) {
    param_3 = (undefined4 *)(iVar5 * -4 + 4);
    param_2 = param_2 + (int)param_3;
    do {
      puVar13 = puVar12;
      puVar14 = puVar10;
      for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar14 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar14 = puVar14 + 1;
      }
      puVar12 = (undefined4 *)((int)puVar12 + iVar1);
      for (uVar6 = uVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined1 *)puVar14 = *(undefined1 *)puVar13;
        puVar13 = (undefined4 *)((int)puVar13 + 1);
        puVar14 = (undefined4 *)((int)puVar14 + 1);
      }
      puVar10 = (undefined4 *)((int)puVar10 + uVar2);
      param_3 = (undefined4 *)((int)param_3 + -1);
    } while (param_3 != (undefined4 *)0x0);
    param_3 = puVar12;
  }
  iVar5 = (param_6 - (uint)(uVar9 == 0)) * 8;
  param_5 = iVar3;
  if (param_2 < iVar5) {
    local_c = (iVar5 - param_2) + 7U >> 3;
    param_2 = param_2 + local_c * 8;
    do {
      iVar3 = *(int *)(param_1 + 0xd118 + (uint)*param_4 * 4);
      FUN_006bb970(puVar10,uVar2,(int)param_3 - iVar1,iVar1,iVar3,iVar3 * 3 >> 2,param_5,
                   param_5 + uVar7 * 4);
      iVar3 = param_5 + 4;
      iVar5 = 8;
      param_4 = param_4 + 1;
      if (8 < (int)uVar4) {
        local_10 = param_5;
        param_6 = iVar3 + uVar7 * 4;
        param_5 = iVar3;
        do {
          iVar3 = *(int *)(param_1 + 0xd118 + (uint)*param_4 * 4);
          iVar11 = iVar3 * 3 >> 2;
          FUN_006bb970((undefined1 *)(iVar5 + (int)puVar10),uVar2,
                       (undefined1 *)((iVar5 - iVar1) + (int)param_3),iVar1,iVar3,iVar11,param_5,
                       param_6);
          FUN_006bbb80((undefined1 *)(iVar5 + uVar2 * -4 + -4 + (int)puVar10),uVar2,iVar3,iVar11,
                       local_10);
          param_5 = param_5 + 4;
          param_6 = param_6 + 4;
          local_10 = local_10 + 4;
          iVar5 = iVar5 + 8;
          param_4 = param_4 + 1;
        } while (iVar5 < (int)uVar4);
        iVar3 = param_5;
      }
      param_5 = iVar3;
      param_3 = param_3 + iVar1 * 2;
      puVar10 = puVar10 + uVar2 * 2;
      local_c = local_c - 1;
    } while (local_c != 0);
  }
  if (uVar9 == 0) {
    if (param_2 < (int)puVar8[1]) {
      param_2 = puVar8[1] - param_2;
      do {
        puVar12 = param_3;
        puVar13 = puVar10;
        for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        for (uVar7 = uVar4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
          puVar12 = (undefined4 *)((int)puVar12 + 1);
          puVar13 = (undefined4 *)((int)puVar13 + 1);
        }
        puVar10 = (undefined4 *)((int)puVar10 + uVar2);
        param_3 = (undefined4 *)((int)param_3 + iVar1);
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    iVar3 = 8;
    if (8 < (int)uVar4) {
      do {
        param_4 = param_4 + 1;
        iVar5 = *(int *)(param_1 + 0xd118 + (uint)*param_4 * 4);
        FUN_006bbb80((undefined1 *)(iVar3 + uVar2 * -8 + -4 + (int)puVar10),uVar2,iVar5,
                     iVar5 * 3 >> 2,param_5);
        iVar3 = iVar3 + 8;
        param_5 = param_5 + 4;
      } while (iVar3 < (int)uVar4);
    }
  }
  return;
}

