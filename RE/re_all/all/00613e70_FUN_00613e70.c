
void __thiscall FUN_00613e70(int param_1,undefined4 param_2)

{
  float *pfVar1;
  float *pfVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  cVar4 = (**(code **)(**(int **)(param_1 + 0x60) + 0x34))();
  if (cVar4 != '\0') {
    iVar5 = (**(code **)(**(int **)(param_1 + 0x60) + 0x18))();
    if (1 < *(int *)(iVar5 + 4)) {
      FUN_0060d8f0(param_2,0,*(int *)(iVar5 + 4) + -1);
    }
    iVar9 = 0;
    iVar6 = 0;
    iStack_20 = 0;
    iStack_1c = 0;
    if (0 < *(int *)(iVar5 + 4)) {
      iStack_18 = 0;
      do {
        piVar10 = (int *)(iStack_18 + *(int *)(iVar5 + 0xc));
        if ((*piVar10 == iVar9) && (piVar10[1] == iVar6)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        iVar9 = *piVar10;
        iVar6 = piVar10[1];
        if (bVar3) {
LAB_00613f5d:
          (**(code **)(**(int **)(param_1 + 0x60) + 0x1c))(piVar10,param_2);
          iStack_20 = iStack_20 + 1;
          *piVar10 = 0;
          piVar10[1] = 0;
        }
        else {
          pfVar1 = *(float **)(*piVar10 + 0x30);
          pfVar2 = *(float **)(piVar10[1] + 0x30);
          if (((((pfVar2[4] < *pfVar1) || (pfVar1[4] < *pfVar2)) || (pfVar2[5] < pfVar1[1])) ||
              ((pfVar1[5] < pfVar2[1] || (pfVar2[6] < pfVar1[2])))) || (pfVar1[6] < pfVar2[2]))
          goto LAB_00613f5d;
        }
        iStack_1c = iStack_1c + 1;
        iStack_18 = iStack_18 + 0x10;
      } while (iStack_1c < *(int *)(iVar5 + 4));
    }
    uVar7 = 0;
    if (1 < *(int *)(iVar5 + 4)) {
      FUN_0060d8f0(param_2,0,*(int *)(iVar5 + 4) + -1);
    }
    iVar9 = *(int *)(iVar5 + 4);
    iStack_20 = iVar9 - iStack_20;
    if (iVar9 <= iStack_20) {
      if ((iVar9 < iStack_20) && (*(int *)(iVar5 + 8) < iStack_20)) {
        if (iStack_20 != 0) {
          uVar7 = FUN_00646b30(iStack_20 * 0x10,0x10);
        }
        FUN_0060d240(0,*(undefined4 *)(iVar5 + 4),uVar7);
        FUN_007932e0();
        *(undefined4 *)(iVar5 + 0xc) = uVar7;
        *(undefined1 *)(iVar5 + 0x10) = 1;
        *(int *)(iVar5 + 8) = iStack_20;
      }
      if (iVar9 < iStack_20) {
        iVar6 = iVar9 << 4;
        iVar9 = iStack_20 - iVar9;
        do {
          puVar8 = (undefined4 *)(iVar6 + *(int *)(iVar5 + 0xc));
          if (puVar8 != (undefined4 *)0x0) {
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            puVar8[3] = 0;
          }
          iVar6 = iVar6 + 0x10;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
    }
    *(int *)(iVar5 + 4) = iStack_20;
  }
  return;
}

