
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0079d230(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int aiStack_50 [12];
  undefined4 uStack_20;
  
  iVar5 = (int)param_1;
  iVar7 = *(int *)((int)param_1 + 0x114);
  iVar6 = *(int *)((int)param_1 + 0x10c) + iVar7;
  uStack_20 = 0x79d257;
  piVar12 = (int *)((int)param_1 + 0x18);
  piVar10 = piVar12;
  piVar11 = aiStack_50 + (0xd - iVar6);
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar11 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar11 = piVar11 + 1;
  }
  iVar7 = *(int *)((int)param_1 + 0x128);
  uVar1 = *(undefined4 *)((int)param_1 + 0x110);
  while( true ) {
    param_1 = aiStack_50 + (0xd - iVar6);
    iVar9 = param_4;
    if (*(int *)(iVar5 + 0x10c) <= param_4) {
      iVar9 = *(int *)(iVar5 + 0x10c);
    }
    uVar2 = *(undefined4 *)(iVar5 + 0x128);
    aiStack_50[0xc - iVar6] = iVar9;
    aiStack_50[0xb - iVar6] = uVar2;
    iVar3 = *(int *)(iVar5 + 0x114);
    aiStack_50[10 - iVar6] = param_3;
    aiStack_50[9 - iVar6] = (int)(aiStack_50 + ((iVar3 + 0xd) - iVar6));
    aiStack_50[8 - iVar6] = iVar5;
    aiStack_50[7 - iVar6] = 0x79d2a8;
    FUN_0079f980();
    uVar2 = *(undefined4 *)(iVar5 + 0x118);
    aiStack_50[7 - iVar6] = uVar1;
    uVar4 = *(undefined4 *)(iVar5 + 0x114);
    aiStack_50[6 - iVar6] = iVar9 << 0x10;
    aiStack_50[5 - iVar6] = uVar2;
    aiStack_50[4 - iVar6] = uVar4;
    aiStack_50[3 - iVar6] = iVar7 + 4;
    aiStack_50[2 - iVar6] = (int)param_1;
    aiStack_50[1 - iVar6] = param_2;
    aiStack_50[-iVar6] = 0x79d2ce;
    param_2 = FUN_0079d330();
    param_3 = param_3 + iVar9 * 2;
    param_4 = param_4 - iVar9;
    if (param_4 < 2) break;
    piVar10 = param_1 + iVar9;
    for (uVar8 = *(uint *)(iVar5 + 0x114) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
      *param_1 = *piVar10;
      piVar10 = piVar10 + 1;
      param_1 = param_1 + 1;
    }
    for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
      *(char *)param_1 = (char)*piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
      param_1 = (int *)((int)param_1 + 1);
    }
  }
  piVar10 = param_1 + iVar9;
  for (uVar8 = *(uint *)(iVar5 + 0x114) & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
    *piVar12 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar12 = piVar12 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(char *)piVar12 = (char)*piVar10;
    piVar10 = (int *)((int)piVar10 + 1);
    piVar12 = (int *)((int)piVar12 + 1);
  }
  return;
}

