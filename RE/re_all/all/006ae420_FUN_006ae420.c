
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006ae420(int *param_1,int param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int aiStack_30 [3];
  float afStack_24 [4];
  
  pfVar4 = param_3;
  iVar3 = *param_1;
  afStack_24[3] = 9.816439e-39;
  iVar7 = param_1[6];
  afStack_24[3 - iVar3] = -NAN;
  afStack_24[2 - iVar3] = 140.0;
  afStack_24[1 - iVar3] = (float)param_3;
  afStack_24[-iVar3] = (float)param_2;
  aiStack_30[2 - iVar3] = iVar7;
  aiStack_30[1 - iVar3] = iVar3;
  aiStack_30[-iVar3] = 0x6ae45b;
  FUN_006ae510();
  if (0 < iVar3) {
    iVar6 = param_2 - (int)param_3;
    iVar7 = iVar3 * -4 - (int)param_3;
    pfVar5 = param_3;
    param_3 = (float *)iVar3;
    do {
      pfVar1 = (float *)(iVar6 + (int)pfVar5);
      fVar2 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      *(float *)((int)afStack_24 + iVar7 + 0xc + (int)pfVar5) = *pfVar1 - fVar2;
      param_3 = (float *)((int)param_3 + -1);
    } while (param_3 != (float *)0x0);
  }
  iVar7 = param_1[6];
  afStack_24[3 - iVar3] = (float)*(undefined4 *)(param_1[1] + 0x80);
  afStack_24[2 - iVar3] = 0.0;
  afStack_24[1 - iVar3] = (float)pfVar4;
  afStack_24[-iVar3] = (float)(afStack_24 + (4 - iVar3));
  aiStack_30[2 - iVar3] = iVar7;
  aiStack_30[1 - iVar3] = iVar3;
  aiStack_30[-iVar3] = 0x6ae4a6;
  FUN_006ae510();
  if (0 < iVar3) {
    pfVar5 = afStack_24 + (4 - iVar3);
    iVar7 = iVar3;
    do {
      iVar7 = iVar7 + -1;
      *pfVar5 = *(float *)((param_2 - (int)(afStack_24 + (4 - iVar3))) + (int)pfVar5) - *pfVar5;
      pfVar5 = pfVar5 + 1;
    } while (iVar7 != 0);
    if (0 < iVar3) {
      iVar7 = iVar3;
      pfVar5 = pfVar4;
      do {
        afStack_24[3 - iVar3] = 9.816655e-39;
        iVar6 = __ftol();
        if (iVar6 < 0x28) {
          if (iVar6 < 0) {
            iVar6 = 0;
          }
        }
        else {
          iVar6 = 0x27;
        }
        iVar7 = iVar7 + -1;
        *pfVar5 = *(float *)(param_1[1] + 0x150 + iVar6 * 4) +
                  *(float *)((int)pfVar5 + (int)afStack_24 + (iVar3 * -4 - (int)pfVar4) + 0x10);
        pfVar5 = pfVar5 + 1;
      } while (iVar7 != 0);
    }
  }
  return;
}

