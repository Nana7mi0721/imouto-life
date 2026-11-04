
void __fastcall FUN_00791170(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = 0;
  iVar2 = *(int *)(param_1 + 4);
  if (0 < iVar2) {
    do {
      iVar6 = *(int *)(param_1 + 0xc);
      iVar11 = iVar10 * 8;
      iVar7 = *(int *)(iVar11 + iVar6);
      puVar8 = (undefined4 *)(iVar11 + iVar6);
      iVar9 = iVar10;
      if (iVar10 != iVar7) {
        do {
          *puVar8 = *(undefined4 *)(iVar6 + iVar7 * 8);
          iVar6 = *(int *)(param_1 + 0xc);
          iVar9 = *(int *)(iVar6 + iVar11);
          iVar11 = iVar9 * 8;
          iVar7 = *(int *)(iVar6 + iVar11);
          puVar8 = (undefined4 *)(iVar6 + iVar11);
        } while (iVar9 != iVar7);
      }
      *(int *)(*(int *)(param_1 + 0xc) + iVar10 * 8) = iVar9;
      *(int *)(*(int *)(param_1 + 0xc) + 4 + iVar10 * 8) = iVar10;
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar2);
  }
  if (1 < *(int *)(param_1 + 4)) {
    iVar6 = *(int *)(param_1 + 4) + -1;
    iVar10 = 0;
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + (iVar6 / 2) * 8);
    iVar11 = iVar6;
    do {
      iVar9 = *(int *)(param_1 + 0xc);
      iVar7 = iVar9 + iVar10 * 8;
      iVar3 = *(int *)(iVar9 + iVar10 * 8);
      while (iVar3 < iVar2) {
        piVar1 = (int *)(iVar7 + 8);
        iVar7 = iVar7 + 8;
        iVar10 = iVar10 + 1;
        iVar3 = *piVar1;
      }
      iVar7 = iVar9 + iVar11 * 8;
      iVar3 = *(int *)(iVar9 + iVar11 * 8);
      while (iVar2 < iVar3) {
        piVar1 = (int *)(iVar7 + -8);
        iVar7 = iVar7 + -8;
        iVar11 = iVar11 + -1;
        iVar3 = *piVar1;
      }
      if (iVar11 < iVar10) break;
      uVar4 = *(undefined4 *)(iVar9 + iVar10 * 8);
      uVar5 = *(undefined4 *)(iVar9 + 4 + iVar10 * 8);
      iVar7 = iVar11 * 8;
      *(undefined4 *)(iVar9 + iVar10 * 8) = *(undefined4 *)(iVar7 + iVar9);
      *(undefined4 *)(iVar9 + 4 + iVar10 * 8) = *(undefined4 *)(iVar7 + 4 + iVar9);
      puVar8 = (undefined4 *)(iVar7 + *(int *)(param_1 + 0xc));
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + -1;
      *puVar8 = uVar4;
      puVar8[1] = uVar5;
    } while (iVar10 <= iVar11);
    if (0 < iVar11) {
      FUN_007912b0(iVar6,0,iVar11);
    }
    if (iVar10 < iVar6) {
      FUN_007912b0(iVar6,iVar10,iVar6);
    }
  }
  return;
}

