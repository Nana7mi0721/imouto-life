
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_007a3900(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 auStack_21c [128];
  int local_8;
  
  iVar3 = (int)param_2;
  puVar8 = param_1;
  uVar2 = (int)param_2 * param_3;
  puVar4 = auStack_21c + (0x80 - uVar2);
  if (param_4 == (undefined4 *)0x0) {
    if (0 < param_3) {
      param_2 = param_1;
      local_8 = param_3;
      param_4 = auStack_21c + (0x80 - uVar2);
      do {
        if (0 < iVar3) {
          puVar4 = param_2;
          puVar5 = param_4;
          iVar7 = iVar3;
          do {
            uVar1 = *puVar4;
            puVar4 = puVar4 + 1;
            *puVar5 = uVar1;
            puVar5 = puVar5 + param_3;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
        param_2 = param_2 + iVar3;
        param_4 = param_4 + 1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  else if (0 < param_3) {
    param_1 = (undefined4 *)param_3;
    do {
      iVar3 = 0;
      if (0 < (int)param_2) {
        puVar5 = puVar4;
        do {
          iVar7 = *(int *)(&DAT_0083c4fc + (param_3 * 4 - (int)(auStack_21c + (0x80 - uVar2))) +
                          (int)puVar4) * (int)param_2 + iVar3;
          iVar3 = iVar3 + 1;
          *puVar5 = puVar8[iVar7];
          puVar5 = puVar5 + param_3;
        } while (iVar3 < (int)param_2);
      }
      puVar4 = puVar4 + 1;
      param_1 = (undefined4 *)((int)param_1 + -1);
    } while (param_1 != (undefined4 *)0x0);
  }
  puVar4 = auStack_21c + (0x80 - uVar2);
  for (uVar6 = uVar2 & 0x3fffffff; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar8 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  return;
}

