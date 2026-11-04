
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_007a3800(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 auStack_21c [128];
  int local_8;
  
  iVar3 = (int)param_2;
  uVar2 = (int)param_2 * param_3;
  if (param_4 == 0) {
    if (0 < param_3) {
      local_8 = param_3;
      puVar5 = param_1;
      param_2 = auStack_21c + (0x80 - uVar2);
      do {
        if (0 < iVar3) {
          puVar4 = param_2;
          puVar6 = puVar5;
          iVar8 = iVar3;
          do {
            uVar1 = *puVar6;
            puVar6 = puVar6 + param_3;
            *puVar4 = uVar1;
            puVar4 = puVar4 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        param_2 = param_2 + iVar3;
        puVar5 = puVar5 + 1;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
  }
  else if (0 < param_3) {
    param_4 = param_3;
    puVar5 = param_1;
    do {
      iVar3 = 0;
      puVar4 = puVar5;
      if (0 < (int)param_2) {
        do {
          iVar8 = *(int *)(&DAT_0083c4fc + (param_3 * 4 - (int)param_1) + (int)puVar5) *
                  (int)param_2 + iVar3;
          iVar3 = iVar3 + 1;
          auStack_21c[(iVar8 + 0x80) - uVar2] = *puVar4;
          puVar4 = puVar4 + param_3;
        } while (iVar3 < (int)param_2);
      }
      puVar5 = puVar5 + 1;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  puVar5 = auStack_21c + (0x80 - uVar2);
  for (uVar7 = uVar2 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
    *param_1 = *puVar5;
    puVar5 = puVar5 + 1;
    param_1 = param_1 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)param_1 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}

