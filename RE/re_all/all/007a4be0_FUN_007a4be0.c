
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a4be0(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7,float param_8)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  float *pfVar8;
  int iVar9;
  float local_10;
  float local_8 [2];
  
  local_8[0] = 0.0;
  local_8[1] = 0.0;
  iVar2 = (param_5 + (int)param_8 * 2) * 0x2a;
  if (param_5 == 0) {
    local_10 = *(float *)(&DAT_0083c648 + (int)param_8 * 4);
    param_8 = *(float *)(&DAT_0083c638 + (int)param_8 * 4);
  }
  else {
    param_8 = 0.0;
    local_10 = DAT_0083c658;
  }
  iVar4 = *(int *)(param_6 + 4);
  for (; param_2 < param_3; param_2 = param_2 + 1) {
    iVar9 = 0;
    pfVar8 = local_8;
    do {
      iVar6 = FUN_007a22e0(*(undefined4 *)(param_6 + 0x1c));
      iVar6 = iVar4 * 8 - (*(int *)(param_6 + 0x14) - iVar6);
      if (iVar6 < 0xf) {
        if (iVar6 < 2) {
          if (iVar6 < 1) {
            param_5 = 0xffffffff;
          }
          else {
            iVar6 = FUN_007a2130(param_6,1);
            param_5 = -iVar6;
          }
        }
        else {
          uVar7 = FUN_007a2170(param_6,&DAT_0083c7ac,2);
          param_5 = -(uVar7 & 1) ^ (int)uVar7 >> 1;
        }
      }
      else {
        iVar6 = param_2;
        if (0x13 < param_2) {
          iVar6 = 0x14;
        }
        param_5 = FUN_007a7680(param_6,(uint)(byte)(&DAT_0083c65c)[iVar6 * 2 + iVar2] << 7,
                               (uint)(byte)(&UNK_0083c65d)[iVar6 * 2 + iVar2] << 6);
      }
      fVar5 = (float)(int)param_5;
      iVar6 = *(int *)(param_1 + 8) * iVar9 + param_2;
      pfVar1 = (float *)(param_4 + iVar6 * 4);
      if (_DAT_0083c7b0 <= *(float *)(param_4 + iVar6 * 4)) {
        fVar3 = *pfVar1;
      }
      else {
        fVar3 = _DAT_0083c7b0;
      }
      *pfVar1 = fVar3;
      iVar6 = *(int *)(param_1 + 8) * iVar9 + param_2;
      iVar9 = iVar9 + 1;
      *(float *)(param_4 + iVar6 * 4) = *(float *)(param_4 + iVar6 * 4) * param_8 + *pfVar8 + fVar5;
      *pfVar8 = (fVar5 + *pfVar8) - fVar5 * local_10;
      pfVar8 = pfVar8 + 1;
    } while (iVar9 < param_7);
  }
  return;
}

