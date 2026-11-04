
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_007a64a0(undefined1 *param_1,int param_2,float *param_3,int param_4,int param_5,int param_6,
            undefined4 param_7)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int aiStack_34 [6];
  float fStack_1c;
  
  iVar7 = param_6 - param_5;
  fStack_1c = 1.1240087e-38;
  piVar3 = aiStack_34 + (7 - param_6);
  if (param_4 == 0) {
    piVar3 = (int *)param_1;
  }
  else {
    if (0 < param_6) {
      iVar8 = param_6;
      do {
        *piVar3 = *(undefined4 *)(((int)param_1 - (int)(aiStack_34 + (7 - param_6))) + (int)piVar3);
        piVar3 = piVar3 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    piVar3 = aiStack_34 + (7 - param_6);
    if (0 < param_4) {
      iVar8 = (int)param_1 - (int)(aiStack_34 + (7 - param_6));
      param_1 = (undefined1 *)param_4;
      pfVar4 = param_3;
      pfVar5 = &fStack_1c;
      do {
        pfVar1 = (float *)((int)aiStack_34 + (param_6 * -4 - (int)param_3) + 0x1c + (int)pfVar4);
        *pfVar1 = *(float *)((int)pfVar1 + iVar8) * *pfVar4;
        param_1 = (undefined1 *)((int)param_1 + -1);
        *pfVar5 = *(float *)((int)pfVar5 + iVar8) * *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar5 = pfVar5 + -1;
      } while (param_1 != (undefined1 *)0x0);
      piVar3 = aiStack_34 + (7 - param_6);
    }
  }
  aiStack_34[6 - param_6] = param_7;
  aiStack_34[5 - param_6] = param_5 + 1;
  aiStack_34[4 - param_6] = iVar7;
  aiStack_34[3 - param_6] = param_2;
  aiStack_34[2 - param_6] = (int)piVar3;
  aiStack_34[1 - param_6] = (int)piVar3;
  aiStack_34[-param_6] = 0x7a654c;
  FUN_007a6fd0();
  iVar8 = 0;
  if (-1 < param_5) {
    param_4 = iVar7 * 4;
    param_1 = (undefined1 *)iVar7;
    do {
      fVar2 = _DAT_007d5344;
      if ((int)param_1 < param_6) {
        iVar6 = param_6 - (int)param_1;
        iVar7 = param_4;
        do {
          iVar6 = iVar6 + -1;
          fVar2 = *(float *)((int)piVar3 + iVar7 + iVar8 * -4) * *(float *)((int)piVar3 + iVar7) +
                  fVar2;
          iVar7 = iVar7 + 4;
        } while (iVar6 != 0);
      }
      iVar7 = iVar8 * 4;
      iVar8 = iVar8 + 1;
      param_1 = (undefined1 *)((int)param_1 + 1);
      param_4 = param_4 + 4;
      *(float *)(param_2 + -4 + iVar8 * 4) = fVar2 + *(float *)(param_2 + iVar7);
    } while (iVar8 <= param_5);
  }
  return 0;
}

