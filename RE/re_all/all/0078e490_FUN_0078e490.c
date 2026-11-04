
void __thiscall FUN_0078e490(int param_1,int *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar7 = *(int *)(param_1 + 0x1c);
  if ((iVar7 < 1) && (iVar7 < 0)) {
    FUN_0078e010(0);
    iVar7 = iVar7 * 4;
    do {
      puVar4 = (undefined4 *)(iVar7 + *(int *)(param_1 + 0x24));
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = 0;
      }
      iVar7 = iVar7 + 4;
    } while (iVar7 < 0);
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_00791170();
  iVar7 = *(int *)(param_1 + 8);
  iVar10 = 0;
  if (0 < iVar7) {
    do {
      iVar9 = *(int *)(param_1 + 0x10);
      iVar11 = iVar10 + 1;
      iVar6 = *(int *)(iVar9 + iVar10 * 8);
      if (iVar11 < iVar7) {
        piVar5 = (int *)(iVar9 + iVar11 * 8);
        do {
          if (*piVar5 != iVar6) break;
          iVar11 = iVar11 + 1;
          piVar5 = piVar5 + 2;
        } while (iVar11 < iVar7);
      }
      bVar2 = true;
      if (iVar10 < iVar11) {
        piVar5 = (int *)(iVar9 + 4 + iVar10 * 8);
        iVar9 = iVar11 - iVar10;
        do {
          iVar1 = *(int *)(*(int *)(param_3 + 0x10) + *piVar5 * 4);
          if (*(int *)(iVar1 + 0xcc) == iVar6) {
            iVar1 = *(int *)(iVar1 + 0xd4);
            if (iVar1 == 1) {
              bVar2 = false;
            }
            if (iVar1 == 4) {
              bVar2 = false;
            }
          }
          piVar5 = piVar5 + 2;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (bVar2) goto joined_r0x0078e571;
        do {
          iVar9 = *(int *)(*(int *)(param_3 + 0x10) +
                          *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar10 * 8) * 4);
          if ((*(int *)(iVar9 + 0xcc) == iVar6) && (*(int *)(iVar9 + 0xd4) == 2)) {
            FUN_006105d0(3);
            *(undefined4 *)(iVar9 + 0xd8) = 0;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar11);
      }
      else {
joined_r0x0078e571:
        for (; iVar10 < iVar11; iVar10 = iVar10 + 1) {
          if (*(int *)(*(int *)(*(int *)(param_3 + 0x10) +
                               *(int *)(*(int *)(param_1 + 0x10) + 4 + iVar10 * 8) * 4) + 0xcc) ==
              iVar6) {
            FUN_006105d0(2);
          }
        }
      }
      iVar10 = iVar11;
    } while (iVar11 < iVar7);
  }
  iVar7 = (**(code **)(*param_2 + 0x20))();
  param_3 = 0;
  if (0 < iVar7) {
    do {
      iVar9 = (**(code **)(*param_2 + 0x24))(param_3);
      iVar10 = *(int *)(iVar9 + 0x294);
      iVar11 = *(int *)(iVar9 + 0x298);
      if (((iVar10 != 0) && (*(int *)(iVar10 + 0xd4) != 2)) ||
         ((iVar11 != 0 && (*(int *)(iVar11 + 0xd4) != 2)))) {
        if (((*(uint *)(iVar10 + 200) >> 1 & 1) != 0) && (*(int *)(iVar10 + 0xd4) != 2)) {
          FUN_00610600(0);
        }
        if (((*(uint *)(iVar11 + 200) >> 1 & 1) != 0) && (*(int *)(iVar11 + 0xd4) != 2)) {
          FUN_00610600(0);
        }
        if ((*(char *)(param_1 + 0x40) != '\0') &&
           (cVar3 = (**(code **)(*param_2 + 0x18))(iVar10,iVar11), cVar3 != '\0')) {
          iVar10 = *(int *)(param_1 + 0x1c);
          if (iVar10 == *(int *)(param_1 + 0x20)) {
            iVar11 = iVar10 * 2;
            if (iVar10 == 0) {
              iVar11 = 1;
            }
            if (*(int *)(param_1 + 0x20) < iVar11) {
              if (iVar11 == 0) {
                puVar4 = (undefined4 *)0x0;
              }
              else {
                puVar4 = (undefined4 *)FUN_00646b30(iVar11 * 4,0x10);
              }
              iVar10 = *(int *)(param_1 + 0x1c);
              iVar6 = 0;
              if (0 < iVar10) {
                puVar8 = puVar4;
                do {
                  if (puVar8 != (undefined4 *)0x0) {
                    *puVar8 = *(undefined4 *)(*(int *)(param_1 + 0x24) + iVar6 * 4);
                  }
                  iVar6 = iVar6 + 1;
                  puVar8 = puVar8 + 1;
                } while (iVar6 < iVar10);
              }
              if (*(int *)(param_1 + 0x24) != 0) {
                if (*(char *)(param_1 + 0x28) != '\0') {
                  FUN_00646b80(*(int *)(param_1 + 0x24));
                }
                *(undefined4 *)(param_1 + 0x24) = 0;
              }
              *(undefined1 *)(param_1 + 0x28) = 1;
              *(undefined4 **)(param_1 + 0x24) = puVar4;
              *(int *)(param_1 + 0x20) = iVar11;
            }
          }
          piVar5 = (int *)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x1c) * 4);
          if (piVar5 != (int *)0x0) {
            *piVar5 = iVar9;
          }
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        }
      }
      param_3 = param_3 + 1;
    } while (param_3 < iVar7);
  }
  return;
}

