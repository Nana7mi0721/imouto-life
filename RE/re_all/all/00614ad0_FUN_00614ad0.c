
void __thiscall FUN_00614ad0(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  float fVar2;
  undefined4 *puVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    iVar8 = *(int *)(param_1 + 0x18);
    local_28 = 0x7c;
    if ((iVar8 < 0x81) && (iVar8 < 0x80)) {
      FUN_00621d20(0x80);
      iVar8 = iVar8 << 3;
      do {
        puVar3 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x20));
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = 0x7c;
          puVar3[1] = local_24;
        }
        iVar8 = iVar8 + 8;
      } while (iVar8 < 0x400);
    }
    *(undefined4 *)(param_1 + 0x18) = 0x80;
    piVar1 = *(int **)(param_1 + 0x20);
    *piVar1 = param_2;
    piVar1[1] = param_3;
    iVar8 = 1;
    iVar10 = 8;
    do {
      iVar9 = iVar10 + -8;
      iVar7 = iVar8 + -1;
      puVar3 = (undefined4 *)(iVar9 + *(int *)(param_1 + 0x20));
      pfVar11 = (float *)*puVar3;
      pfVar4 = (float *)puVar3[1];
      if (local_28 < iVar7) {
        iVar6 = *(int *)(param_1 + 0x18);
        local_28 = *(int *)(param_1 + 0x18) * 2;
        if (iVar6 <= local_28) {
          if (iVar6 < local_28) {
            FUN_00621d20(local_28);
          }
          for (; iVar6 < local_28; iVar6 = iVar6 + 1) {
            puVar3 = (undefined4 *)(*(int *)(param_1 + 0x20) + iVar6 * 8);
            if (puVar3 != (undefined4 *)0x0) {
              *puVar3 = local_20;
              puVar3[1] = pfVar4;
            }
          }
        }
        *(int *)(param_1 + 0x18) = local_28;
        local_28 = local_28 + -4;
      }
      if (pfVar11 == pfVar4) {
        if (pfVar11[10] != 0.0) {
          fVar2 = pfVar11[9];
          pfVar4 = (float *)(iVar9 + *(int *)(param_1 + 0x20));
          *pfVar4 = fVar2;
          pfVar4[1] = fVar2;
          fVar2 = pfVar11[10];
          pfVar4 = (float *)(iVar10 + *(int *)(param_1 + 0x20));
          iVar7 = iVar8 + 2;
          *pfVar4 = fVar2;
          pfVar4[1] = fVar2;
          fVar2 = pfVar11[10];
          iVar9 = iVar10 + 0x10;
          pfVar4 = (float *)(iVar10 + 8 + *(int *)(param_1 + 0x20));
          *pfVar4 = pfVar11[9];
          pfVar4[1] = fVar2;
        }
      }
      else if ((((*pfVar11 <= pfVar4[4]) && (*pfVar4 <= pfVar11[4])) && (pfVar11[1] <= pfVar4[5]))
              && (((pfVar4[1] <= pfVar11[5] && (pfVar11[2] <= pfVar4[6])) &&
                  (pfVar4[2] <= pfVar11[6])))) {
        if (pfVar11[10] == 0.0) {
          if (pfVar4[10] != 0.0) {
            fVar2 = pfVar4[9];
            puVar3 = (undefined4 *)(iVar9 + *(int *)(param_1 + 0x20));
            *puVar3 = pfVar11;
            puVar3[1] = fVar2;
            goto LAB_00614cfe;
          }
          (**(code **)(*param_4 + 0xc))(pfVar11,pfVar4);
        }
        else {
          if (pfVar4[10] == 0.0) {
            pfVar5 = (float *)(iVar9 + *(int *)(param_1 + 0x20));
            *pfVar5 = pfVar11[9];
            pfVar5[1] = (float)pfVar4;
            pfVar11 = (float *)pfVar11[10];
          }
          else {
            fVar2 = pfVar4[9];
            pfVar5 = (float *)(iVar9 + *(int *)(param_1 + 0x20));
            *pfVar5 = pfVar11[9];
            pfVar5[1] = fVar2;
            fVar2 = pfVar4[9];
            iVar7 = iVar10 + 8;
            pfVar5 = (float *)(iVar10 + *(int *)(param_1 + 0x20));
            iVar8 = iVar8 + 2;
            *pfVar5 = pfVar11[10];
            pfVar5[1] = fVar2;
            fVar2 = pfVar4[10];
            iVar10 = iVar10 + 0x10;
            pfVar5 = (float *)(iVar7 + *(int *)(param_1 + 0x20));
            *pfVar5 = pfVar11[9];
            pfVar5[1] = fVar2;
            pfVar11 = (float *)pfVar11[10];
LAB_00614cfe:
            pfVar4 = (float *)pfVar4[10];
          }
          iVar7 = iVar8 + 1;
          iVar9 = iVar10 + 8;
          puVar3 = (undefined4 *)(iVar10 + *(int *)(param_1 + 0x20));
          *puVar3 = pfVar11;
          puVar3[1] = pfVar4;
        }
      }
      iVar8 = iVar7;
      iVar10 = iVar9;
    } while (iVar9 != 0);
  }
  return;
}

