
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006aeb90(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,float param_6)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  iVar7 = 0;
  iVar2 = *param_1;
  fVar3 = *(float *)(param_1[1] + 0x1f0) - param_6;
  if (0 < iVar2) {
    do {
      iVar6 = iVar7 + 1;
      param_6 = *(float *)(param_3 + iVar7 * 4);
      iVar5 = *(int *)(param_1[5] + iVar7 * 4);
      pfVar4 = (float *)(param_3 + iVar7 * 4);
      if (iVar6 < iVar2) {
        piVar8 = (int *)(param_1[5] + iVar6 * 4);
        do {
          if (*piVar8 != iVar5) break;
          pfVar1 = pfVar4 + 1;
          pfVar4 = pfVar4 + 1;
          iVar7 = iVar7 + 1;
          piVar8 = piVar8 + 1;
          iVar6 = iVar6 + 1;
          if (param_6 < *pfVar1) {
            param_6 = *pfVar4;
          }
        } while (iVar6 < iVar2);
      }
      if (*(float *)(param_4 + iVar7 * 4) < param_6 + _DAT_00829894) {
        iVar5 = iVar5 >> ((byte)param_1[8] & 0x1f);
        if (iVar5 < 0x11) {
          if (iVar5 < 0) {
            iVar5 = 0;
          }
        }
        else {
          iVar5 = 0x10;
        }
        FUN_006aec70(param_5,*(undefined4 *)(param_2 + iVar5 * 4),param_6,
                     *(int *)(param_1[5] + iVar7 * 4) - param_1[7],param_1[10],param_1[9],fVar3);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar2);
  }
  return;
}

