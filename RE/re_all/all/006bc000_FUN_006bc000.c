
void FUN_006bc000(byte *param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  int *local_27c;
  byte *local_278;
  int local_274;
  int *local_270;
  int *local_26c;
  int *local_268;
  byte *local_264;
  int local_260;
  byte *local_25c;
  int local_240 [8];
  int local_220 [48];
  int local_160 [8];
  int local_140 [8];
  int local_120 [7];
  int local_104 [8];
  int local_e4 [57];
  
  param_3 = ~param_3;
  iVar6 = (-(uint)((int)(uint)(byte)(&DAT_00832288)[param_6] < param_4 * 3) &
          (uint)(byte)(&DAT_00832288)[param_6] + param_4 * -3) + param_4 * 3;
  local_25c = param_1;
  bVar1 = (&DAT_0083228c)[param_6];
  local_274 = 0;
  piVar7 = local_120;
  pbVar10 = param_1 + -(-(param_3 >> 2 & 1) & param_2);
  pbVar11 = param_1;
  do {
    local_278 = (byte *)0x8;
    pbVar9 = pbVar11;
    do {
      uVar8 = (int)((uint)*pbVar9 - (uint)pbVar9[(int)pbVar10 - (int)pbVar11]) >> 0x1f;
      iVar4 = (param_4 -
              (((uint)*pbVar9 - (uint)pbVar9[(int)pbVar10 - (int)pbVar11] ^ uVar8) - uVar8 <<
              (bVar1 & 0x1f))) + 0x20;
      if (iVar4 < -0x40) {
        iVar4 = param_5;
      }
      else {
        iVar4 = iVar4 + (-(uint)(iVar6 < iVar4) & iVar6 - iVar4);
        iVar4 = -(-(uint)(0 < iVar4) & -iVar4);
      }
      *piVar7 = iVar4;
      piVar7 = piVar7 + 1;
      pbVar9 = pbVar9 + 1;
      local_278 = (byte *)((int)local_278 + -1);
    } while (local_278 != (byte *)0x0);
    bVar2 = local_274 < 7;
    local_274 = local_274 + 1;
    pbVar10 = pbVar11;
    pbVar11 = pbVar11 + (-(param_3 >> 3 & 1 | (uint)bVar2) & param_2);
  } while (local_274 < 9);
  local_264 = param_1;
  local_274 = 0;
  piVar7 = local_240;
  pbVar10 = param_1 + -(param_3 & 1);
  do {
    local_278 = (byte *)0x8;
    pbVar11 = local_264;
    do {
      uVar8 = (int)((uint)*pbVar11 - (uint)*pbVar10) >> 0x1f;
      iVar4 = (param_4 - (((uint)*pbVar11 - (uint)*pbVar10 ^ uVar8) - uVar8 << (bVar1 & 0x1f))) +
              0x20;
      if (iVar4 < -0x40) {
        iVar4 = param_5;
      }
      else {
        iVar4 = iVar4 + (-(uint)(iVar6 < iVar4) & iVar6 - iVar4);
        iVar4 = -(-(uint)(0 < iVar4) & -iVar4);
      }
      *piVar7 = iVar4;
      pbVar10 = pbVar10 + param_2;
      pbVar11 = pbVar11 + param_2;
      piVar7 = piVar7 + 1;
      local_278 = (byte *)((int)local_278 + -1);
    } while (local_278 != (byte *)0x0);
    bVar2 = local_274 < 7;
    local_274 = local_274 + 1;
    pbVar10 = local_264;
    local_264 = local_264 + (param_3 >> 1 & 1 | (uint)bVar2);
  } while (local_274 < 9);
  local_27c = local_220;
  local_26c = local_104 + 1;
  local_274 = 0;
  local_278 = param_1 + -(-(param_3 >> 2 & 1) & param_2);
  local_264 = param_1 + param_2;
  do {
    pbVar11 = param_1;
    local_260 = 6;
    uVar8 = (uint)pbVar11[-(param_3 & 1)] * local_27c[-8] + 0x40 + (uint)*local_278 * local_26c[-8]
            + (uint)*local_264 * *local_26c + (uint)pbVar11[1] * *local_27c +
            (uint)*pbVar11 * ((((0x80 - local_27c[-8]) - local_26c[-8]) - *local_26c) - *local_27c);
    uVar5 = uVar8 & 0xffffff80;
    *local_25c = (-(0x7f80 < (int)uVar5) | (byte)((int)uVar8 >> 7)) & ((int)uVar5 < 0) - 1U;
    pbVar10 = pbVar11;
    piVar7 = local_27c;
    piVar3 = local_26c;
    do {
      local_268 = piVar3 + 1;
      local_270 = piVar7 + 8;
      pbVar9 = pbVar10 + 1;
      uVar8 = (uint)*pbVar10 * *piVar7 + 0x40 +
              (uint)(pbVar9 + ((int)local_264 - (int)pbVar11))[(int)local_278 - (int)local_264] *
              piVar3[-7] + (uint)pbVar9[(int)local_264 - (int)pbVar11] * *local_268 +
              (uint)pbVar10[2] * *local_270 +
              (uint)*pbVar9 * ((((0x80 - *piVar7) - piVar3[-7]) - *local_268) - *local_270);
      uVar5 = uVar8 & 0xffffff80;
      pbVar9[(int)local_25c - (int)pbVar11] =
           (-(0x7f80 < (int)uVar5) | (byte)((int)uVar8 >> 7)) & ((int)uVar5 < 0) - 1U;
      local_260 = local_260 + -1;
      pbVar10 = pbVar9;
      piVar7 = local_270;
      piVar3 = local_268;
    } while (local_260 != 0);
    uVar8 = (uint)pbVar11[6] * local_27c[0x30] + 0x40 + (uint)local_278[7] * local_26c[-1] +
            (uint)local_264[7] * local_26c[7] +
            (uint)pbVar11[(param_3 >> 1 & 1) + 7] * local_27c[0x38] +
            (uint)pbVar11[7] *
            ((((0x80 - local_27c[0x30]) - local_26c[-1]) - local_26c[7]) - local_27c[0x38]);
    uVar5 = uVar8 & 0xffffff80;
    local_25c[7] = (-(0x7f80 < (int)uVar5) | (byte)((int)uVar8 >> 7)) & ((int)uVar5 < 0) - 1U;
    local_25c = local_25c + param_2;
    bVar2 = local_274 < 6;
    local_26c = local_26c + 8;
    local_274 = local_274 + 1;
    local_27c = local_27c + 1;
    param_1 = local_264;
    local_278 = pbVar11;
    local_264 = local_264 + (-((uint)bVar2 | param_3 >> 3 & 1) & param_2);
  } while (local_274 < 8);
  return;
}

