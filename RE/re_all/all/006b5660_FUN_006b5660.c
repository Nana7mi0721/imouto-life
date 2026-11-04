
int FUN_006b5660(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int local_5c;
  int local_48;
  int local_40 [16];
  
  iVar1 = param_1[0xd];
  iVar7 = *param_1;
  iVar8 = param_1[0xc];
  iVar2 = param_1[0xb];
  iVar9 = iVar2 >> 1;
  local_5c = 0;
  local_40[8] = 0;
  local_40[9] = 0;
  local_40[10] = 0;
  local_40[0xb] = 0;
  local_40[0xc] = 0;
  local_40[0xd] = 0;
  local_40[0xe] = 0;
  local_40[0xf] = 0;
  local_48 = iVar7;
  if (iVar1 == 1) {
    if (0 < iVar7) {
      piVar6 = local_40 + iVar7 + 8;
      do {
        piVar10 = (int *)((int)piVar6 + (int)param_2 + (-4 - (int)(local_40 + 8)));
        piVar6 = piVar6 + -1;
        iVar3 = *piVar10 - iVar8;
        if (iVar3 < iVar9) {
          iVar5 = (iVar9 - iVar3) * 2 + -1;
        }
        else {
          iVar5 = (iVar3 - iVar9) * 2;
        }
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        else if (iVar2 <= iVar5) {
          iVar5 = iVar2 + -1;
        }
        *piVar6 = iVar3 + iVar8;
        local_5c = local_5c * iVar2 + iVar5;
        local_48 = local_48 + -1;
      } while (local_48 != 0);
    }
  }
  else if (0 < iVar7) {
    piVar6 = local_40 + iVar7 + 8;
    do {
      piVar10 = (int *)((int)param_2 + (-4 - (int)(local_40 + 8)) + (int)piVar6);
      piVar6 = piVar6 + -1;
      iVar3 = ((*piVar10 - iVar8) + (iVar1 >> 1)) / iVar1;
      if (iVar3 < iVar9) {
        iVar5 = (iVar9 - iVar3) * 2 + -1;
      }
      else {
        iVar5 = (iVar3 - iVar9) * 2;
      }
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      else if (iVar2 <= iVar5) {
        iVar5 = iVar2 + -1;
      }
      *piVar6 = iVar3 * iVar1 + iVar8;
      local_5c = local_5c * iVar2 + iVar5;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
  }
  piVar6 = param_1 + 3;
  if (*(char *)(*(int *)(*piVar6 + 8) + local_5c) < '\x01') {
    iVar3 = -1;
    iVar9 = param_1[1];
    iVar8 = (iVar2 + -1) * iVar1 + iVar8;
    local_48 = -1;
    local_40[0] = 0;
    local_40[1] = 0;
    local_40[2] = 0;
    local_40[3] = 0;
    local_40[4] = 0;
    local_40[5] = 0;
    local_40[6] = 0;
    local_40[7] = 0;
    param_1 = (int *)0x0;
    if (0 < iVar9) {
      iVar2 = *(int *)(*piVar6 + 8);
      do {
        if ('\0' < *(char *)(iVar2 + (int)param_1)) {
          iVar5 = 0;
          if (0 < iVar7) {
            piVar6 = param_2;
            iVar3 = iVar7;
            do {
              iVar4 = *(int *)(((int)local_40 - (int)param_2) + (int)piVar6) - *piVar6;
              piVar6 = piVar6 + 1;
              iVar5 = iVar5 + iVar4 * iVar4;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
            iVar3 = local_48;
          }
          if (iVar3 != -1) {
            if (iVar3 <= iVar5) goto LAB_006b588c;
          }
          piVar6 = local_40;
          piVar10 = local_40 + 8;
          for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
            *piVar10 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar10 = piVar10 + 1;
          }
          local_5c = (int)param_1;
          iVar3 = iVar5;
          local_48 = iVar5;
        }
LAB_006b588c:
        iVar5 = 0;
        if (iVar8 <= local_40[0]) {
          piVar6 = local_40;
          do {
            piVar10 = piVar6 + 1;
            *piVar6 = 0;
            iVar5 = iVar5 + 1;
            piVar6 = piVar10;
          } while (iVar8 <= *piVar10);
        }
        piVar6 = local_40 + iVar5;
        if (-1 < local_40[iVar5]) {
          *piVar6 = local_40[iVar5] + iVar1;
        }
        *piVar6 = -*piVar6;
        param_1 = (int *)((int)param_1 + 1);
      } while ((int)param_1 < iVar9);
    }
  }
  if ((-1 < local_5c) && (0 < iVar7)) {
    piVar6 = local_40 + 8;
    do {
      iVar1 = *piVar6;
      piVar6 = piVar6 + 1;
      iVar7 = iVar7 + -1;
      *param_2 = *param_2 - iVar1;
      param_2 = param_2 + 1;
    } while (iVar7 != 0);
  }
  return local_5c;
}

