
void FUN_0079ab10(short *param_1,short *param_2,short *param_3,short *param_4,int param_5,
                 int param_6)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  short *psVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  int local_18;
  short *local_10;
  int local_c;
  
  psVar7 = param_1;
  *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)param_3 = *(undefined4 *)(param_1 + 4);
  sVar1 = param_1[1];
  sVar2 = *param_1;
  *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + param_6);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + param_6);
  local_18 = (int)sVar1;
  iVar14 = param_5 * 8;
  iVar12 = (int)sVar2;
  sVar3 = *param_4;
  sVar4 = param_4[2];
  iVar9 = (int)(short)(0x10000 / (longlong)iVar14);
  if (0 < iVar14) {
    local_c = iVar14;
    psVar13 = param_2;
    while( true ) {
      local_10 = psVar13 + 1;
      uVar11 = (uint)*local_10;
      local_18 = local_18 + (((short)(sVar4 - sVar1) * iVar9 >> 0xf) + 1 >> 1);
      iVar12 = iVar12 + (((short)(sVar3 - sVar2) * iVar9 >> 0xf) + 1 >> 1);
      uVar10 = ((int)*psVar13 + uVar11 * 2 + (int)psVar13[2]) * 0x200;
      uVar10 = (((int)((uVar11 & 0x1f) * 0x800 * (int)(short)local_18) >> 0x10) +
                ((int)((uVar10 & 0xffff) * (int)(short)iVar12) >> 0x10) +
                ((int)(uVar11 << 0xb) >> 0x10) * (int)(short)local_18 +
                *(short *)((int)local_10 + ((int)param_3 - (int)param_2)) * 0x100 +
                ((int)uVar10 >> 0x10) * (int)(short)iVar12 >> 7) + 1;
      uVar11 = uVar10 & 0xfffffffe;
      if ((int)uVar11 < 0xffff) {
        if ((int)uVar11 < -0x10000) {
          uVar8 = 0x8000;
        }
        else {
          uVar8 = (undefined2)((int)uVar10 >> 1);
        }
      }
      else {
        uVar8 = 0x7fff;
      }
      *(undefined2 *)(((int)param_3 - (int)param_2) + (int)local_10) = uVar8;
      local_c = local_c + -1;
      if (local_c == 0) break;
      psVar13 = local_10;
    }
  }
  uVar5 = *(undefined4 *)param_4;
  uVar6 = *(undefined4 *)(param_4 + 2);
  if (iVar14 < param_6) {
    param_1 = (short *)(param_6 + param_5 * -8);
    psVar13 = param_2 + param_5 * 8 + 1;
    do {
      uVar11 = (uint)*psVar13;
      uVar10 = ((int)psVar13[-1] + uVar11 * 2 + (int)psVar13[1]) * 0x200;
      uVar10 = (((int)((uVar11 & 0x1f) * 0x800 * (int)(short)uVar6) >> 0x10) +
                ((int)(uVar11 << 0xb) >> 0x10) * (int)(short)uVar6 +
                ((int)((uVar10 & 0xffff) * (int)(short)uVar5) >> 0x10) +
                *(short *)(((int)param_3 - (int)param_2) + (int)psVar13) * 0x100 +
                ((int)uVar10 >> 0x10) * (int)(short)uVar5 >> 7) + 1;
      uVar11 = uVar10 & 0xfffffffe;
      if ((int)uVar11 < 0xffff) {
        if ((int)uVar11 < -0x10000) {
          uVar8 = 0x8000;
        }
        else {
          uVar8 = (undefined2)((int)uVar10 >> 1);
        }
      }
      else {
        uVar8 = 0x7fff;
      }
      psVar13 = psVar13 + 1;
      *(undefined2 *)(((int)param_3 - (int)param_2) + -2 + (int)psVar13) = uVar8;
      param_1 = (short *)((int)param_1 + -1);
    } while (param_1 != (short *)0x0);
  }
  *psVar7 = *param_4;
  psVar7[1] = param_4[2];
  if (0 < param_6) {
    iVar14 = (int)param_2 - (int)param_3;
    do {
      param_3 = param_3 + 1;
      iVar12 = (int)*(short *)(iVar14 + (int)param_3);
      iVar9 = iVar12 + *param_3;
      iVar12 = iVar12 - *param_3;
      if (iVar9 < 0x8000) {
        if (iVar9 < -0x8000) {
          iVar9 = -0x8000;
        }
      }
      else {
        iVar9 = 0x7fff;
      }
      *(short *)(iVar14 + (int)param_3) = (short)iVar9;
      if (iVar12 < 0x8000) {
        if (iVar12 < -0x8000) {
          iVar12 = -0x8000;
        }
      }
      else {
        iVar12 = 0x7fff;
      }
      *param_3 = (short)iVar12;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

