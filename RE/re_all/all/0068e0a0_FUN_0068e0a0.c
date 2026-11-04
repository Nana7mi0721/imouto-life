
void FUN_0068e0a0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int local_42c;
  int *local_428;
  int local_424;
  int local_400 [256];
  
  iVar1 = *(int *)(param_1 + 0x70);
  local_424 = 0x7fffffff;
  iVar6 = param_3 + 0x1c;
  local_42c = 0;
  if (0 < iVar1) {
    piVar12 = *(int **)(param_1 + 0x74);
    local_428 = local_400;
    iVar10 = *piVar12;
    iVar2 = piVar12[1];
    iVar3 = piVar12[2];
    do {
      uVar4 = (uint)*(byte *)(iVar10 + local_42c);
      if ((int)uVar4 < param_2) {
        iVar11 = (uVar4 - param_2) * 2;
        iVar11 = iVar11 * iVar11;
        iVar8 = param_2 + 0x18;
LAB_0068e152:
        iVar5 = iVar8;
      }
      else {
        iVar5 = param_2 + 0x18;
        iVar8 = param_2;
        if (iVar5 < (int)uVar4) {
          iVar11 = (uVar4 - iVar5) * 2;
          iVar11 = iVar11 * iVar11;
          goto LAB_0068e152;
        }
        iVar11 = 0;
        if (param_2 * 2 + 0x18 >> 1 < (int)uVar4) goto LAB_0068e152;
      }
      uVar7 = (uint)*(byte *)(iVar2 + local_42c);
      iVar5 = (uVar4 - iVar5) * 2;
      if ((int)uVar7 < param_3) {
        iVar8 = (uVar7 - param_3) * 3;
        iVar11 = iVar11 + iVar8 * iVar8;
        iVar8 = uVar7 - iVar6;
      }
      else {
        if (iVar6 < (int)uVar7) {
          iVar8 = (uVar7 - iVar6) * 3;
          iVar11 = iVar11 + iVar8 * iVar8;
        }
        else if ((int)uVar7 <= param_3 + iVar6 >> 1) {
          iVar8 = uVar7 - iVar6;
          goto LAB_0068e1ac;
        }
        iVar8 = uVar7 - param_3;
      }
LAB_0068e1ac:
      uVar4 = (uint)*(byte *)(iVar3 + local_42c);
      if ((int)uVar4 < param_4) {
        iVar11 = iVar11 + (uVar4 - param_4) * (uVar4 - param_4);
        iVar9 = uVar4 - (param_4 + 0x18);
      }
      else {
        iVar9 = param_4 + 0x18;
        if (iVar9 < (int)uVar4) {
          iVar11 = iVar11 + (uVar4 - iVar9) * (uVar4 - iVar9);
          iVar9 = uVar4 - param_4;
        }
        else if (param_4 * 2 + 0x18 >> 1 < (int)uVar4) {
          iVar9 = uVar4 - param_4;
        }
        else {
          iVar9 = uVar4 - iVar9;
        }
      }
      iVar5 = iVar5 * iVar5 + iVar8 * 3 * iVar8 * 3 + iVar9 * iVar9;
      *local_428 = iVar11;
      if (iVar5 < local_424) {
        local_424 = iVar5;
      }
      local_42c = local_42c + 1;
      local_428 = local_428 + 1;
    } while (local_42c < iVar1);
  }
  iVar6 = 0;
  iVar10 = 0;
  if (0 < iVar1) {
    piVar12 = local_400;
    do {
      if (*piVar12 <= local_424) {
        *(char *)(iVar6 + param_5) = (char)iVar10;
        iVar6 = iVar6 + 1;
      }
      iVar10 = iVar10 + 1;
      piVar12 = piVar12 + 1;
    } while (iVar10 < iVar1);
  }
  return;
}

