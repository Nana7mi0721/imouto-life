
void __thiscall FUN_0078e770(int param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int local_18;
  int local_10;
  
  FUN_0078e490(param_2,param_3);
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(param_1 + 0x40) == '\0') {
    uVar6 = (**(code **)(*param_2 + 0x28))();
    uVar7 = (**(code **)(*param_2 + 0x20))();
    (**(code **)(*param_4 + 4))
              (*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 8),uVar6,uVar7,0xffffffff);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  if (1 < *(int *)(param_1 + 0x1c)) {
    FUN_0078ea80(param_3,0,*(int *)(param_1 + 0x1c) + -1);
  }
  iVar8 = 0;
  local_18 = 1;
  local_10 = 0;
  if (0 < iVar1) {
    do {
      bVar5 = false;
      iVar11 = *(int *)(*(int *)(param_1 + 0x10) + iVar8 * 8);
      for (; (iVar8 < iVar1 &&
             (piVar13 = (int *)(*(int *)(param_1 + 0x10) + iVar8 * 8), *piVar13 == iVar11));
          iVar8 = iVar8 + 1) {
        iVar9 = *(int *)(*(int *)(param_3 + 0x10) + piVar13[1] * 4);
        iVar14 = *(int *)(param_1 + 0x30);
        if (iVar14 == *(int *)(param_1 + 0x34)) {
          if (iVar14 == 0) {
            iVar14 = 1;
          }
          else {
            iVar14 = iVar14 * 2;
          }
          FUN_0078e010(iVar14);
        }
        piVar13 = (int *)(*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x30) * 4);
        if (piVar13 != (int *)0x0) {
          *piVar13 = iVar9;
        }
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
        iVar9 = *(int *)(iVar9 + 0xd4);
        if ((iVar9 == 2) || (iVar9 == 5)) {
          bVar5 = true;
        }
      }
      iVar14 = 0;
      iVar9 = 0;
      if (local_10 < iVar2) {
        iVar3 = *(int *)(param_1 + 0x24);
        iVar4 = *(int *)(iVar3 + local_10 * 4);
        iVar12 = *(int *)(*(int *)(iVar4 + 0x294) + 0xcc);
        if (iVar12 < 0) {
          iVar12 = *(int *)(*(int *)(iVar4 + 0x298) + 0xcc);
        }
        if (iVar12 == iVar11) {
          local_18 = local_10 + 1;
          if (local_18 < iVar2) {
            piVar13 = (int *)(iVar3 + local_18 * 4);
            do {
              iVar9 = *(int *)(*(int *)(*piVar13 + 0x294) + 0xcc);
              if (iVar9 < 0) {
                iVar9 = *(int *)(*(int *)(*piVar13 + 0x298) + 0xcc);
              }
              if (iVar11 != iVar9) break;
              local_18 = local_18 + 1;
              piVar13 = piVar13 + 1;
            } while (local_18 < iVar2);
          }
          iVar14 = local_18 - local_10;
          iVar9 = iVar3 + local_10 * 4;
        }
      }
      if (!bVar5) {
        (**(code **)(*param_4 + 4))
                  (*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x30),iVar9,iVar14,
                   iVar11);
      }
      if (iVar14 != 0) {
        local_10 = local_18;
      }
      iVar11 = *(int *)(param_1 + 0x30);
      if (iVar11 < 1) {
        if ((iVar11 < 0) && (*(int *)(param_1 + 0x34) < 0)) {
          iVar9 = 0;
          if (0 < iVar11) {
            do {
              if (iVar9 != 0) {
                *(undefined4 *)(iVar9 * 4) = *(undefined4 *)(*(int *)(param_1 + 0x38) + iVar9 * 4);
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < iVar11);
          }
          if (*(int *)(param_1 + 0x38) != 0) {
            if (*(char *)(param_1 + 0x3c) != '\0') {
              FUN_00646b80(*(int *)(param_1 + 0x38));
            }
            *(undefined4 *)(param_1 + 0x38) = 0;
          }
          *(undefined1 *)(param_1 + 0x3c) = 1;
          *(undefined4 *)(param_1 + 0x38) = 0;
          *(undefined4 *)(param_1 + 0x34) = 0;
        }
        if (iVar11 < 0) {
          iVar11 = iVar11 * 4;
          do {
            puVar10 = (undefined4 *)(iVar11 + *(int *)(param_1 + 0x38));
            if (puVar10 != (undefined4 *)0x0) {
              *puVar10 = 0;
            }
            iVar11 = iVar11 + 4;
          } while (iVar11 < 0);
        }
      }
      *(undefined4 *)(param_1 + 0x30) = 0;
    } while (iVar8 < iVar1);
  }
  return;
}

