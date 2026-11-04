
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int __fastcall FUN_00605f70(int param_1)

{
  uint *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 auStack_3c [6];
  int **appiStack_24 [3];
  uint local_c;
  int *local_8;
  
  appiStack_24[0] = *(int ***)(*(int *)(param_1 + 0x90) + 0x18);
  if (appiStack_24[0] == (int **)0x0) {
    return -0x7fffbffb;
  }
  appiStack_24[2] = &local_8;
  appiStack_24[1] = (int **)&DAT_0085e5b4;
  auStack_3c[5] = 0x605fa8;
  local_c = param_1;
  iVar6 = (*(code *)**appiStack_24[0])();
  if (-1 < iVar6) {
    auStack_3c[5] = 0x605fc2;
    iVar4 = -(*(int *)(param_1 + 0x9c) + 3U & 0xfffffffc);
    puVar1 = (uint *)((int)auStack_3c + *(int *)(*(int *)(param_1 + 0x8c) + 0x74) + iVar4 + 0x2c);
    *puVar1 = (DAT_00a060d8 & 0xff0000 | DAT_00a060d8 >> 0x10) >> 8 |
              (DAT_00a060d8 << 0x10 | DAT_00a060d8 & 0xff00) << 8;
    puVar1[1] = *(uint *)(param_1 + 0x98);
    *(uint *)((int)auStack_3c + iVar4 + 0x24) =
         (DAT_00a060d0 & 0xff0000 | DAT_00a060d0 >> 0x10) >> 8 |
         (DAT_00a060d0 << 0x10 | DAT_00a060d0 & 0xff00) << 8;
    uVar8 = *(uint *)(*(int *)(param_1 + 0x8c) + 0x74);
    *(uint *)((int)auStack_3c + iVar4 + 0x28) = uVar8;
    puVar11 = *(undefined4 **)(*(int *)(param_1 + 0x8c) + 0x78);
    puVar12 = (undefined4 *)((int)auStack_3c + iVar4 + 0x2c);
    for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
    }
    for (uVar8 = uVar8 & 3; uVar7 = local_c, uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    }
    *(uint *)((int)auStack_3c + iVar4 + 0x18) =
         (DAT_00a060c8 & 0xff0000 | DAT_00a060c8 >> 0x10) >> 8 |
         (DAT_00a060c8 << 0x10 | DAT_00a060c8 & 0xff00) << 8;
    *(int *)((int)auStack_3c + iVar4 + 0x1c) = *(int *)(uVar7 + 0x98) + -8 + *(int *)(uVar7 + 0x9c);
    *(uint *)((int)appiStack_24 + iVar4 + 8) =
         (DAT_00a060c0 & 0xff0000 | DAT_00a060c0 >> 0x10) >> 8 |
         (DAT_00a060c0 << 0x10 | DAT_00a060c0 & 0xff00) << 8;
    piVar5 = local_8;
    *(undefined4 *)((int)auStack_3c + iVar4 + 0x14) = 0;
    *(undefined4 *)((int)auStack_3c + iVar4 + 0x10) = 0;
    iVar6 = *piVar5;
    *(undefined4 *)((int)auStack_3c + iVar4 + 0xc) = 0;
    *(undefined4 *)((int)auStack_3c + iVar4 + 8) = 0;
    *(int **)((int)auStack_3c + iVar4 + 4) = piVar5;
    pcVar2 = *(code **)(iVar6 + 0x14);
    puVar9 = (undefined1 *)((int)auStack_3c + iVar4);
    *(undefined4 *)((int)auStack_3c + iVar4) = 0x6060cf;
    iVar6 = (*pcVar2)();
    piVar5 = local_8;
    if (-1 < iVar6) {
      uVar3 = *(undefined4 *)(uVar7 + 0x9c);
      *(undefined4 *)(puVar9 + -4) = 0;
      *(undefined4 *)(puVar9 + -8) = uVar3;
      iVar6 = *piVar5;
      *(int *)(puVar9 + -0xc) = (int)auStack_3c + iVar4 + 0x18;
      *(int **)(puVar9 + -0x10) = piVar5;
      pcVar2 = *(code **)(iVar6 + 0x10);
      puVar10 = (undefined4 *)(puVar9 + -0x14);
      puVar9 = puVar9 + -0x14;
      *puVar10 = 0x6060e8;
      iVar6 = (*pcVar2)();
    }
    *(int **)(puVar9 + -4) = local_8;
    pcVar2 = *(code **)(*local_8 + 8);
    *(undefined4 *)(puVar9 + -8) = 0x6060f3;
    (*pcVar2)();
  }
  return iVar6;
}

