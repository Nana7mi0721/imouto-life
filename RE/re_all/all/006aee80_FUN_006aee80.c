
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006aee80(float *param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  int *piVar7;
  int iStack_2c;
  undefined4 uStack_28;
  int local_14;
  int local_10;
  int *local_c;
  float *local_8;
  
  uStack_28 = 0x6aee9f;
  iVar2 = param_3 * -4;
  (&uStack_28)[-param_3] = 0x6aeead;
  pfVar6 = (float *)((int)register0x00000010 + param_3 * -8 + -0x24);
  iVar4 = 0;
  iVar3 = 0;
  local_14 = 0;
  if (0 < param_3) {
    local_8 = param_1;
    do {
      if (1 < iVar3) {
        local_c = &iStack_2c + (iVar3 - param_3);
        for (pfVar5 = (float *)(&uStack_28 + param_3 * -2 + iVar3); *pfVar5 <= *local_8;
            pfVar5 = pfVar5 + -1) {
          if ((((*(int *)((int)register0x00000010 + ((iVar2 + -0x24) - (int)pfVar6) + (int)pfVar5) +
                 param_2 <= iVar4) || (iVar3 < 2)) || (pfVar5[-1] < *pfVar5)) ||
             (*local_c + param_2 <= iVar4)) {
            *(int *)((int)register0x00000010 + iVar3 * 4 + iVar2 + -0x24) = iVar4;
            fVar1 = *local_8;
            goto LAB_006aef3e;
          }
          iVar3 = iVar3 + -1;
          local_c = local_c + -1;
        }
      }
      *(int *)((int)register0x00000010 + iVar3 * 4 + iVar2 + -0x24) = iVar4;
      fVar1 = *local_8;
LAB_006aef3e:
      pfVar6[iVar3] = fVar1;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 1;
      local_8 = local_8 + 1;
    } while (iVar4 < param_3);
  }
  local_10 = 0;
  if (0 < iVar3) {
    piVar7 = (int *)((int)register0x00000010 + iVar2 + -0x20);
    iVar2 = (int)pfVar6 - ((int)register0x00000010 + iVar2 + -0x24);
    do {
      if ((iVar3 + -1 <= local_10) || (*(float *)(iVar2 + (int)piVar7) <= *pfVar6)) {
        iVar4 = piVar7[-1] + 1 + param_2;
      }
      else {
        iVar4 = *piVar7;
      }
      if (param_3 < iVar4) {
        iVar4 = param_3;
      }
      if (local_14 < iVar4) {
        iVar4 = iVar4 - local_14;
        pfVar5 = param_1 + local_14;
        local_14 = local_14 + iVar4;
        do {
          *pfVar5 = *pfVar6;
          pfVar5 = pfVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      local_10 = local_10 + 1;
      piVar7 = piVar7 + 1;
      pfVar6 = pfVar6 + 1;
    } while (local_10 < iVar3);
  }
  return;
}

