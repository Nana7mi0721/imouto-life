
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b96d0(void)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  
  if (DAT_00f3a070 != 0) {
    iVar4 = 0;
    iVar1 = *(int *)(DAT_00ef1b84 + 8);
    if (-1 < DAT_00f07388) {
      pfVar3 = (float *)(iVar1 + 0x54);
      pfVar2 = (float *)&DAT_00f073cc;
      do {
        if ((&DAT_00f0738c)[iVar4] != 0) {
          pfVar3[-1] = pfVar2[-1] * _DAT_00f0762c;
          *pfVar3 = *pfVar2 * _DAT_00f07630;
          pfVar3[1] = pfVar2[1] * _DAT_00f07634;
          pfVar3[2] = pfVar2[2] * _DAT_00f07638;
        }
        iVar4 = iVar4 + 1;
        pfVar2 = pfVar2 + 0x1a;
        pfVar3 = pfVar3 + 0x1c;
      } while (iVar4 <= DAT_00f07388);
    }
    *(float *)(iVar1 + 0x2c0) = _DAT_00f07378 * _DAT_00f0762c + _DAT_00f0764c;
    *(float *)(iVar1 + 0x2c4) = _DAT_00f0737c * _DAT_00f07630 + _DAT_00f07650;
    *(float *)(iVar1 + 0x2c8) = _DAT_00f07380 * _DAT_00f07634 + _DAT_00f07654;
    *(float *)(iVar1 + 0x2cc) = _DAT_00f07384 * _DAT_00f07638 + _DAT_00f07658;
    *(undefined4 *)(DAT_00ef1b84 + 0xc) = 1;
  }
  return;
}

