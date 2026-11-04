
undefined4
FUN_006b5920(undefined4 param_1,int *param_2,int param_3,int param_4,int *param_5,code *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *local_430;
  int local_42c;
  int local_428;
  int local_41c;
  int local_414;
  int local_400 [128];
  int local_200 [128];
  
  piVar1 = (int *)*param_2;
  iVar2 = piVar1[3];
  iVar3 = *(int *)param_2[4];
  iVar4 = piVar1[2];
  iVar5 = (piVar1[1] - *piVar1) / iVar4;
  piVar9 = local_200;
  for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  piVar9 = local_400;
  for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  local_42c = 0;
  if (param_2[2] < 1) {
    return 0;
  }
  do {
    iVar7 = 0;
    local_41c = 0;
    if (0 < iVar5) {
      do {
        if ((local_42c == 0) && (0 < param_4)) {
          local_428 = param_4;
          local_430 = param_5;
          do {
            iVar8 = 1;
            iVar6 = *(int *)(*local_430 + iVar7 * 4);
            if (1 < iVar3) {
              piVar9 = (int *)(*local_430 + 4 + iVar7 * 4);
              do {
                iVar6 = iVar6 * iVar2;
                if (iVar8 + iVar7 < iVar5) {
                  iVar6 = iVar6 + *piVar9;
                }
                iVar8 = iVar8 + 1;
                piVar9 = piVar9 + 1;
              } while (iVar8 < iVar3);
            }
            if (iVar6 < *(int *)(param_2[4] + 4)) {
              iVar6 = FUN_006b0940(param_2[4],iVar6,param_1);
              param_2[9] = param_2[9] + iVar6;
            }
            local_430 = local_430 + 1;
            local_428 = local_428 + -1;
          } while (local_428 != 0);
        }
        local_430 = (int *)0x0;
        if (0 < iVar3) {
          iVar6 = iVar7 * 4;
          local_414 = iVar7 * iVar4;
          do {
            if (iVar5 <= iVar7) goto LAB_006b5b79;
            iVar8 = *piVar1;
            if (0 < param_4) {
              local_428 = param_4;
              piVar9 = param_5;
              do {
                if (local_42c == 0) {
                  local_400[*(int *)(iVar6 + *piVar9)] =
                       local_400[*(int *)(iVar6 + *piVar9)] + iVar4;
                }
                if (((piVar1[*(int *)(*piVar9 + iVar6) + 6] & 1 << ((byte)local_42c & 0x1f)) != 0)
                   && (iVar7 = *(int *)(*(int *)(param_2[5] + *(int *)(*piVar9 + iVar6) * 4) +
                                       local_42c * 4), iVar7 != 0)) {
                  iVar7 = (*param_6)(param_1,*(int *)((param_3 - (int)param_5) + (int)piVar9) +
                                             (local_414 + iVar8) * 4,iVar4,iVar7);
                  param_2[8] = param_2[8] + iVar7;
                  local_200[*(int *)(iVar6 + *piVar9)] =
                       local_200[*(int *)(iVar6 + *piVar9)] + iVar7;
                }
                piVar9 = piVar9 + 1;
                local_428 = local_428 + -1;
              } while (local_428 != 0);
              iVar7 = local_41c;
            }
            local_430 = (int *)((int)local_430 + 1);
            iVar7 = iVar7 + 1;
            local_414 = local_414 + iVar4;
            iVar6 = iVar6 + 4;
            local_41c = iVar7;
          } while ((int)local_430 < iVar3);
        }
      } while (iVar7 < iVar5);
    }
LAB_006b5b79:
    local_42c = local_42c + 1;
    if (param_2[2] <= local_42c) {
      return 0;
    }
  } while( true );
}

